// The MIT License (MIT)
//
// Copyright (c) 2016 Northeastern University
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

//----------------------------------------------------------------------
//  Programmer: David Mount
//  Last modified:  05/14/04
//  Description:  Sample program for kmeans
//----------------------------------------------------------------------
// Copyright (C) 2004-2005 David M. Mount and University of Maryland
// All Rights Reserved.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or (at
// your option) any later version.  See the file Copyright.txt in the
// main directory.
//
// The University of Maryland and the authors make no representations
// about the suitability or fitness of this software for any purpose.
// It is provided "as is" without express or implied warranty.
//----------------------------------------------------------------------

#ifndef CPP_INCLUDE_KMEANS2_H_
#define CPP_INCLUDE_KMEANS2_H_

#include <string.h>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <fstream>
#include "KCtree.h"
#include "KCutil.h"
#include "KMcenters.h"
#include "KMdata.h"
#include "KMeans.h"
#include "KMfilterCenters.h"
#include "KMlocal.h"
#include "KMrand.h"
#include "KMterm.h"
#include "include/matrix.h"
#include "include/vector.h"

namespace Nice {

class Kmeans {
 public:
  enum cluster_type {
    lloyds,
    swap,
    simple_hybrid,
    hybrid
  };
  enum {        // entry names
    KM_TERM_CONST,    // constant term
    KM_TERM_LIN_K,    // linear k multiplier
    KM_TERM_LIN_N,    // linear n multiplier
    KM_TERM_POW,    // power exponent
    KM_TERM_VEC_LEN
  };   // length of termination param vector

  /// This is a constructor that assigns default values to member variables to
  /// a Kmeans object
  Kmeans() {
    dims_ = 0;    // dimension
    num_pts_ = 40;    // max number of data points
    k_ = 4;    // number of centers
    cluster_type_ = lloyds;
    data_pts_ = NULL;
    ctrs_data_ = NULL;
    max_tot_stage_vec_[0] = 100;  // max total stages
    max_tot_stage_vec_[1] = 0;
    max_tot_stage_vec_[2] = 0;
    max_tot_stage_vec_[3] = 0;

    min_consec_rdl_ = .10;      // min consecutive RDL
    min_accum_rdl_ = .10;     // min accumulated RDL
    max_run_stage_ = 3;     // max stages/run for Lloyd's
    init_prob_accept_ = .5;      // initial prob. of acceptance
    temp_run_length_ = 10;     // length of temp run
    temp_reduc_fact_ = 0.95;     // temperature reduction factor
  }

  void SetK(int num_clusters) {
    k_ = num_clusters;
  }

  void SetClusterType(cluster_type clustering_method) {
    cluster_type_ = clustering_method;
  }

  void setMaxTotStage(int i, double val) {  // set max stage parameters
    assert(i >= 0 && i < KM_TERM_VEC_LEN);
    max_tot_stage_vec_[i] = val;
  }

  void setAbsMaxTotStage(int s) {   // set max number of stages
    max_tot_stage_vec_[KM_TERM_CONST] = s;
    max_tot_stage_vec_[KM_TERM_POW] = 0;
  }

  int getMaxTotStage() const  // max total stages
  {
    double count = max_tot_stage_vec_[KM_TERM_CONST];
    if (max_tot_stage_vec_[KM_TERM_POW] != 0) {
      double sum = max_tot_stage_vec_[KM_TERM_LIN_K] * k_
          + max_tot_stage_vec_[KM_TERM_LIN_N] * num_pts_;
      count += pow(sum, max_tot_stage_vec_[KM_TERM_POW]);
    }
    assert(count >= 0 && count <= INT_MAX);  // should be positive integer
    if (count <= 0)
      count = INT_MAX;    // 0 means infinity
    return int(count);
  }

  double getMinConsecRDL() const    // return min consec RDL
  {
    return min_consec_rdl_;
  }

  double getMinAccumRDL() const   // return min accum RDL
  {
    return min_accum_rdl_;
  }

  int getMaxRunStage() const      // return max runs per stage
  {
    return max_run_stage_;
  }

  void setMinConsecRDL(double rdl)    // set min consec RDL
      {
    min_consec_rdl_ = rdl;
  }

  void setMinAccumRDL(double rdl)   // set min accum RDL
      {
    min_accum_rdl_ = rdl;
  }

  void setMaxRunStage(int ms)     // set max runs per stage
      {
    max_run_stage_ = ms;
  }

  double getInitProbAccept() const    // return init. prob. accept
  {
    return init_prob_accept_;
  }

  void setInitProbAccept(double ipa)    // set init. prob. accept
      {
    init_prob_accept_ = ipa;
  }

  int getTempRunLength() const    // return temperature run len.
  {
    return temp_run_length_;
  }

  void setTempRunLength(int trl)    // set temperature run length
      {
    temp_run_length_ = trl;
  }

  double getTempReducFact() const   // return temp. reduction fact.
  {
    return temp_reduc_fact_;
  }

  void setTempReducFact(double trf)   // set temp. reduction fact.
      {
    temp_reduc_fact_ = trf;
  }

  /// This function calculates the cluster centers of a given set of points
  /// And stores them in a private member of the Kmeans class
  void Fit(const Nice::Matrix<double> &in_matrix) {
    dims_ = in_matrix.cols();    // dimension
    num_pts_ = in_matrix.rows();    // max number of data points
    data_pts_ = new KMdata(dims_, num_pts_);    // allocate data storage
    KMterm km_specs(max_tot_stage_vec_[0], max_tot_stage_vec_[1],
                    max_tot_stage_vec_[2], max_tot_stage_vec_[3],  // run for 100 stages
                    min_consec_rdl_,     // min consec RDL
                    min_accum_rdl_,     // min accum RDL
                    max_run_stage_,      // max run stages
                    init_prob_accept_,     // init. prob. of acceptance
                    temp_run_length_,     // temp. run length
                    temp_reduc_fact_);      // temp. reduction factor
    for (int pt = 0; pt < num_pts_; ++pt)
      Eigen::Map<Nice::Matrix<double>>((*data_pts_)[pt], 1, dims_) = in_matrix
          .row(pt);
    data_pts_->setNPts(num_pts_);      // set number of pts
    data_pts_->buildKcTree();      // build filtering structure
    ctrs_data_ = new KMfilterCenters(k_, (*data_pts_));   // allocate centers
    switch (cluster_type_) {
      case lloyds: {
        KMlocalLloyds km_lloyds((*ctrs_data_), km_specs);   // Hybrid heuristic
        (*ctrs_data_) = km_lloyds.execute();
      }
      case swap: {
        KMlocalSwap km_swap((*ctrs_data_), km_specs);   // Hybrid heuristic
        (*ctrs_data_) = km_swap.execute();
      }
      case simple_hybrid: {
        KMlocalEZ_Hybrid km_ez_hybrid((*ctrs_data_), km_specs);  // Hybrid heuristic
        (*ctrs_data_) = km_ez_hybrid.execute();
      }
      case hybrid: {
        KMlocalHybrid km_hybrid((*ctrs_data_), km_specs);   // Hybrid heuristic
        (*ctrs_data_) = km_hybrid.execute();
      }
    }
  }

  /// This function calculates the K-Means centers and the cluster
  /// assignments for each data point.
  ///
  /// \return
  /// This function returns a pointer to a Vector with the cluster assignments
  Nice::Vector<int> GetLabels() {
    KMctrIdxArray close_ctr = new KMctrIdx[num_pts_];
    double* sq_dist = new double[num_pts_];
    ctrs_data_->getAssignments(close_ctr, sq_dist);  // Get data assignments
    Nice::Vector<int> cluster_labels = Eigen::Map<Nice::Vector<int>>(close_ctr,
                                                                     num_pts_,
                                                                     1);
    delete[] close_ctr;
    delete sq_dist;
    return (cluster_labels);
  }

  /// This function calculates the cluster assignments of a given set of points
  /// based on previously calculated centers from the Fit() function
  ///
  /// \param in_matrix
  /// Input Matrix passed by reference
  ///
  /// \return
  /// This function returns a Nice Vector with the cluster assignments
  Nice::Vector<int> Predict(const Nice::Matrix<double> &in_matrix) {
    num_pts_ = in_matrix.rows();
    double ** centers = ctrs_data_->getCtrPts();
    double * distance_to_centers = new double[k_];
    int * closest_centers = new int[num_pts_];
    double distance = 0;
    for (int points = 0; points < in_matrix.rows(); ++points) {
      for (int center = 0; center < k_; ++center) {
        for (int dim = 0; dim < dims_; ++dim) {
          distance += abs(centers[center][dim] - in_matrix(points, dim));
        }
        distance_to_centers[center] = distance;
        distance = 0;
      }
      int center_min_dist = INT_MAX;
      for (int center = 0; center < k_; ++center) {
        if (distance_to_centers[center] < center_min_dist) {
          closest_centers[points] = center;
          center_min_dist = distance_to_centers[center];
        }
      }
    }
    Nice::Vector<int> cluster_labels = Eigen::Map<Nice::Vector<int>>(
        closest_centers, num_pts_, 1);
    delete distance_to_centers;
    delete closest_centers;
    return cluster_labels;
  }

  /// This function that calculates the K-Means centers and the cluster
  /// assignments for each data point.
  ///
  /// \return
  /// This function returns a pointer to a Vector with the cluster assignments
  ~Kmeans() {
    delete data_pts_;
    delete ctrs_data_;
  }

 private:
  int k_;
  int dims_;
  int num_pts_;
  KMfilterCenters* ctrs_data_;
  KMdata* data_pts_;  // Stored because it's part of the KMfilterCenters object
  cluster_type cluster_type_;
  double max_tot_stage_vec_[KM_TERM_VEC_LEN];  // max total stages
  double min_consec_rdl_;      // min consecutive RDL
  double min_accum_rdl_;     // min accumulated RDL
  int max_run_stage_;     // max stages/run for Lloyd's
  double init_prob_accept_;      // initial prob. of acceptance
  int temp_run_length_;     // length of temp run
  double temp_reduc_fact_;     // temperature reduction factor
};

}  // namespace Nice
#endif  // CPP_INCLUDE_KMEANS2_H_
