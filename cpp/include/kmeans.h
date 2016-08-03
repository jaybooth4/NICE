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

#ifndef CPP_INCLUDE_KMEANS_H_
#define CPP_INCLUDE_KMEANS_H_

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

template<typename T>
class Kmeans {
 private:
  int k_;
  int dims_;
  int num_pts_;
  KMfilterCenters* ctrs_data_;
  int stages_;
  KMterm* km_specs_;
  KMdata* data_pts_;    // allocate data storage

 public:
  /// This is a constructor that assigns values to member variables to a
  /// Kmeans object
  ///
  /// \param num_clusters
  /// Number of clusters
  /// \param num_stages
  /// Number of stages used in Hybrid algorithm
  /// \param in_matrix
  /// Input matrix passed by reference
  Kmeans(int num_clusters, int num_stages, const Nice::Matrix<T> &in_matrix) {
    k_ = num_clusters;    // number of centers
    dims_ = in_matrix.cols();    // dimension
    num_pts_ = in_matrix.rows();    // max number of data points
    stages_ = num_stages;   // number of stages
    ctrs_data_ = NULL;
    km_specs_ = new KMterm(100, 0, 0, 0,   // run for 100 stages
                           0.10,     // min consec RDL
                           0.10,     // min accum RDL
                           3,      // max run stages
                           0.50,     // init. prob. of acceptance
                           10,     // temp. run length
                           0.95);      // temp. reduction factor
    km_specs_->setAbsMaxTotStage(stages_);   // set number of stages
    data_pts_ = new KMdata(dims_, num_pts_);    // allocate data storage
    for (int pt = 0; pt < num_pts_; ++pt) {
      for (int d = 0; d < dims_; ++d) {
        (*data_pts_)[pt][d] = in_matrix.coeffRef(pt, d);
      }
    }
  }

  /// This function calculates the cluster centers of a given set of points
  /// And stores them in a private member of the Kmeans class
  void Fit() {
    data_pts_->setNPts(num_pts_);      // set number of pts
    data_pts_->buildKcTree();      // build filtering structure
    KMfilterCenters ctrs(k_, (*data_pts_));   // allocate centers
    KMlocalHybrid km_hybrid(ctrs, (*km_specs_));   // Hybrid heuristic
    ctrs = km_hybrid.execute();
    ctrs_data_ = ctrs.getCtrPts();
  }

  /// This function calculates the cluster assignments of a given set of points
  /// based on previously calculated centers from fit() or fitPredict()
  ///
  /// \param in_matrix
  /// Input Matrix passed by reference
  ///
  /// \return
  /// This function returns a pointer to a Vector with the cluster assignments
  Nice::Vector<int>* Predict(const Nice::Matrix<T> &in_matrix) {
    if (ctrs_data_ == NULL) {
      std::cerr << "ERROR: NO CENTERS CALCULATED\n";
      return (1);
    }
    num_pts_ = in_matrix.rows();
    dims_ = in_matrix.cols();
    data_pts_ = new KMdata(dims_, num_pts_);    // allocate data storage
    for (int pt = 0; pt < num_pts_; ++pt) {
      for (int d = 0; d < dims_; ++d) {
        (*data_pts_)[pt][d] = in_matrix.coeffRef(pt, d);
      }
    }
    KMctrIdxArray close_ctr = new KMctrIdx[data_pts_->getNPts()];
    double* sq_dist = new double[data_pts_->getNPts()];
    ctrs_data_->getAssignments(close_ctr, sq_dist);
    Nice::Vector<int>* cluster_labels_ = new Nice::Vector<int>;
    cluster_labels_->setZero(data_pts_->getNPts());
    for (int i = 0; i < data_pts_->getNPts(); i++) {
      (*cluster_labels_)(i) = close_ctr[i];
    }
    delete[] close_ctr;
    delete sq_dist;
    return (cluster_labels_);
  }

  /// This function that calculates the K-Means centers and the cluster
  /// assignments for each data point.
  ///
  /// \return
  /// This function returns a pointer to a Vector with the cluster assignments
  Nice::Vector<int>* FitPredict() {
    data_pts_->setNPts(num_pts_);      // set number of pts
    data_pts_->buildKcTree();      // build filtering structure
    ctrs_data_ = new KMfilterCenters(k_, (*data_pts_));   // allocate centers
    KMlocalHybrid kmHybrid((*ctrs_data_), (*km_specs_));   // Hybrid heuristic
    (*ctrs_data_) = kmHybrid.execute();  // Get centers from hybrid algorithm
    KMctrIdxArray close_ctr = new KMctrIdx[data_pts_->getNPts()];
    double* sq_dist = new double[data_pts_->getNPts()];
    (*ctrs_data_).getAssignments(close_ctr, sq_dist);  // Get data assignments
    Nice::Vector<int>* cluster_labels_ = new Nice::Vector<int>;
    cluster_labels_->setZero(data_pts_->getNPts());
    for (int i = 0; i < data_pts_->getNPts(); i++) {
      (*cluster_labels_)(i) = close_ctr[i];  // Assign centers for return
    }
    delete[] close_ctr;
    delete sq_dist;
    return (cluster_labels_);
  }

  /// This function that calculates the K-Means centers and the cluster
  /// assignments for each data point.
  ///
  /// \return
  /// This function returns a pointer to a Vector with the cluster assignments
  ~Kmeans() {
    delete data_pts_;
    delete km_specs_;
    delete ctrs_data_;
  }
};

}  // namespace Nice
#endif  // CPP_INCLUDE_KMEANS_H_

