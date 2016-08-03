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
#include <cstdlib>      // C standard includes
#include <cstring>
#include <iostream>     // C++ I/O
#include <string>     // C++ strings
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
  int k;
  int dim;
  int numPts;
  int stages;
  KMdata* dataPts;    // allocate data storage
  Nice::Matrix<T>* m;
  KMterm* term;
  KMfilterCenters* ctrsData;
  Nice::Vector<int>* assignments;

  /// This is a private function that assigns data to the KMdata member object
  ///
  void assignData() {
    for (int pt = 0; pt < numPts; ++pt) {
      for (int d = 0; d < dim; ++d) {
        (*dataPts)[pt][d] = m->coeffRef(pt, d);
      }
    }
  }

 public:
  /// This is a constructor that assigns values to member variables to a
  /// Kmeans object
  ///
  /// \param numClusters
  /// Number of clusters
  /// \param numStages
  /// Number of stages used in Hybrid algorithm
  /// \param inMatrix
  /// Input matrix passed by reference
  Kmeans(int numClusters, int numStages, const Nice::Matrix<T> &inMatrix) {
    k = numClusters;    // number of centers
    dim = inMatrix.cols();    // dimension
    numPts = inMatrix.rows();    // max number of data points
    stages = numStages;   // number of stages
    m = &inMatrix;
    dataPts = new KMdata(dim, numPts);    // allocate data storage
    assignData();
    ctrsData = NULL;
    term = new KMterm(100, 0, 0, 0,   // run for 100 stages
                      0.10,     // min consec RDL
                      0.10,     // min accum RDL
                      3,      // max run stages
                      0.50,     // init. prob. of acceptance
                      10,     // temp. run length
                      0.95);      // temp. reduction factor
    term->setAbsMaxTotStage(stages);   // set number of stages
  }

  /// This function calculates the cluster centers of a given set of points
  /// And stores them in a private member of the Kmeans class
  void Fit() {
    dataPts->setNPts(numPts);      // set number of pts
    dataPts->buildKcTree();      // build filtering structure
    KMfilterCenters ctrs(k, (*dataPts));   // allocate centers
    KMlocalHybrid kmHybrid(ctrs, (*term));   // Hybrid heuristic
    ctrs = kmHybrid.execute();
    ctrsData = ctrs.getCtrPts();
  }

  /// This function calculates the cluster assignments of a given set of points
  /// based on previously calculated centers from fit() or fitPredict()
  ///
  /// \param inMatrix
  /// Input Matrix passed by reference
  ///
  /// \return
  /// This function returns a pointer to a Vector with the cluster assignments
  Nice::Vector<int> Predict(const Nice::Matrix<T> &inMatrix) {
    if (ctrsData == NULL) {
      std::cerr << "ERROR: NO CENTERS CALCULATED\n";
      return (1);
    }
    numPts = inMatrix.rows();
    dim = inMatrix.cols();
    m = &inMatrix;
    dataPts = new KMdata(dim, numPts);    // allocate data storage
    assignData();
    KMctrIdxArray closeCtr = new KMctrIdx[dataPts->getNPts()];
    double* sqDist = new double[dataPts->getNPts()];
    ctrsData->getAssignments(closeCtr, sqDist);
    assignments = new Nice::Vector<int>;
    assignments->setZero(dataPts->getNPts());
    for (int i = 0; i < dataPts->getNPts(); i++) {
      (*assignments)(i) = closeCtr[i];
    }
    delete[] closeCtr;
    return (assignments);
  }

  /// This function that calculates the K-Means centers and the cluster
  /// assignments for each data point.
  ///
  /// \return
  /// This function returns a pointer to a Vector with the cluster assignments
  Nice::Vector<int> FitPredict() {
    dataPts->setNPts(numPts);      // set number of pts
    dataPts->buildKcTree();      // build filtering structure
    ctrsData = new KMfilterCenters(k, (*dataPts));   // allocate centers
    KMlocalHybrid kmHybrid((*ctrsData), (*term));   // Hybrid heuristic
    (*ctrsData) = kmHybrid.execute();  // Get centers from hybrid algorithm
    ctrsData->print();  // Print
    KMctrIdxArray closeCtr = new KMctrIdx[dataPts->getNPts()];
    double* sqDist = new double[dataPts->getNPts()];
    (*ctrsData).getAssignments(closeCtr, sqDist);  // Get data assignments
    assignments = new Nice::Vector<int>;
    assignments->setZero(dataPts->getNPts());
    for (int i = 0; i < dataPts->getNPts(); i++) {
      (*assignments)(i) = closeCtr[i];  // Assign centers for return
    }
    delete[] closeCtr;
    return (assignments);
  }

  /// This is a destructor for the Kmeans class
  ///
  ~Kmeans() {
//  kmExit(0);
  }
};

}  // namespace Nice
#endif  // CPP_INCLUDE_KMEANS_H_

