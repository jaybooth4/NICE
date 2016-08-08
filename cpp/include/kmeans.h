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
 private:
  int k_;
  int dims_;
  int num_pts_;
  KMfilterCenters* ctrs_data_;
  int cluster_type_;

 public:
  KMterm* km_specs_;
  // This variable is made public to allow for KMterm class member setters

  /// This is a constructor that assigns default values to member variables to
  /// a Kmeans object
  Kmeans() {
    dims_ = 0;    // dimension
    num_pts_ = 0;    // max number of data points
    k_ = 4;    // number of centers
    cluster_type_ = 1;
    ctrs_data_ = NULL;
    km_specs_ = new KMterm(100, 0, 0, 0,   // run for 100 stages
                           0.10,     // min consec RDL
                           0.10,     // min accum RDL
                           3,      // max run stages
                           0.50,     // init. prob. of acceptance
                           10,     // temp. run length
                           0.95);      // temp. reduction factor
  }

  void SetK(int num_clusters) {
    k_ = num_clusters;
  }

  void SetClusterType(int clustering_method) {
    cluster_type_ = clustering_method;
  }

  /// This function calculates the cluster centers of a given set of points
  /// And stores them in a private member of the Kmeans class
  void Fit(const Nice::Matrix<double> &in_matrix) {
    dims_ = in_matrix.cols();    // dimension
    num_pts_ = in_matrix.rows();    // max number of data points
    KMdata data_pts(dims_, num_pts_);    // allocate data storage
    for (int pt = 0; pt < num_pts_; ++pt)
      for (int d = 0; d < dims_; ++d)
        data_pts[pt][d] = in_matrix.coeffRef(pt, d);
    data_pts.setNPts(num_pts_);      // set number of pts
    data_pts.buildKcTree();      // build filtering structure
    ctrs_data_ = new KMfilterCenters(k_, data_pts);   // allocate centers
    switch(cluster_type_) {
      case 1: {
        KMlocalLloyds km_lloyds((*ctrs_data_), (*km_specs_));   // Hybrid heuristic
        (*ctrs_data_) = km_lloyds.execute();
      }
      case 2: {
        KMlocalSwap km_swap((*ctrs_data_), (*km_specs_));   // Hybrid heuristic
        (*ctrs_data_) = km_swap.execute();
      }
      case 3: {
        KMlocalEZ_Hybrid km_ez_hybrid((*ctrs_data_), (*km_specs_));   // Hybrid heuristic
        (*ctrs_data_) = km_ez_hybrid.execute();
      }
      case 4: {
        KMlocalHybrid km_hybrid((*ctrs_data_), (*km_specs_));   // Hybrid heuristic
        (*ctrs_data_) = km_hybrid.execute();
      }
    }
    ctrs_data_->print();
  }

  /// This function calculates the K-Means centers and the cluster
  /// assignments for each data point.
  ///
  /// \return
  /// This function returns a pointer to a Vector with the cluster assignments
  Nice::Vector<int> GetLabels() {
    std::cout << "Hello-3\n\n";
    KMctrIdxArray close_ctr = new KMctrIdx[num_pts_];
    double* sq_dist = new double[num_pts_];
    std::cout << "Hello-2\n\n";
    ctrs_data_->print();
    ctrs_data_->getAssignments(close_ctr, sq_dist);  // Get data assignments
    std::cout << "Hello-1\n\n";
    Nice::Vector<int> cluster_labels;
    cluster_labels.setZero(num_pts_);
    std::cout << "Hello0\n\n";
    for (int i = 0; i < num_pts_; i++)
      (cluster_labels)(i) = close_ctr[i];  // Assign centers for return
    std::cout << "Hello1\n\n";
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
    double ** centers = ctrs_data_->getCtrPts();
    double * distance_to_centers = new double[k_];
    int * closest_centers = new int[num_pts_];
    double distance = 0;
    for (int points = 0; points < in_matrix.rows(); ++points) {
      for (int center = 0; center < k_; ++center) {
        for (int dim = 0; dim < dims_; ++dim) {
          distance += abs(centers[center][dim] - in_matrix(center, dim));
        }
        distance_to_centers[center] = distance;
      }
      distance = 0;
      for(int center = 0; center < k_-1; ++center) {
          if (distance_to_centers[center] < distance_to_centers[center+1]) {
              closest_centers[points] = center;
          }
      }
    }
    Nice::Vector<int> cluster_labels;
    cluster_labels.setZero(num_pts_);
    for (int i = 0; i < num_pts_; i++)
      (cluster_labels)(i) = closest_centers[i];
    return cluster_labels;
  }

  /// This function that calculates the K-Means centers and the cluster
  /// assignments for each data point.
  ///
  /// \return
  /// This function returns a pointer to a Vector with the cluster assignments
  ~Kmeans() {
    delete ctrs_data_;
    delete km_specs_;
  }
};

}  // namespace Nice
#endif  // CPP_INCLUDE_KMEANS2_H_
