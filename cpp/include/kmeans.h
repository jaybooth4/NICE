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

#include <iostream>
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

#include <cstring>
#include <string.h>
#include <cstdlib>      // C standard includes
#include <iostream>     // C++ I/O
#include <string>     // C++ strings
#include "KMlocal.h"      // k-means algorithms

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

  void assignData() {
    for (int pt = 0; pt < numPts; ++pt) {
      for (int d = 0; d < dim; ++d) {
        (*dataPts)[pt][d] = m->coeffRef(pt, d);
      }
    }
  }

 public:

  Kmeans(int numClusters, int numStages, Nice::Matrix<T> &inMatrix) {
    k = numClusters;    // number of centers
    dim = inMatrix.cols();    // dimension
    numPts = inMatrix.rows();    // max number of data points
    stages = numStages;   // number of stages
    m = &inMatrix;
    dataPts = new KMdata(dim, numPts);    // allocate data storage
    assignData();
    ctrsData = NULL;
    //
    // std::cout << "Data Points:\n";     // echo data points
    // for (int i = 0; i < numPts; i++) {
    //   std::cout << "(" << dataPts[i][0];
    //   for (int j = 1; j < dim; j++) {
    //     std::cout << ", " << dataPts[i][j];
    //   }
    //   std::cout << ")\n";
    //}
    term = new KMterm(100, 0, 0, 0,   // run for 100 stages
                      0.10,     // min consec RDL
                      0.10,     // min accum RDL
                      3,      // max run stages
                      0.50,     // init. prob. of acceptance
                      10,     // temp. run length
                      0.95);      // temp. reduction factor

    term->setAbsMaxTotStage(stages);   // set number of stages

  }

  void Fit() {

    dataPts->setNPts(numPts);      // set number of pts
    dataPts->buildKcTree();      // build filtering structure
    KMfilterCenters ctrs(k, (*dataPts));   // allocate centers

    //  cout << "\nExecuting Clustering Algorithm: Hybrid\n";
    KMlocalHybrid kmHybrid(ctrs, (*term));   // Hybrid heuristic
    ctrs = kmHybrid.execute();
    ctrsData = ctrs.getCtrPts();
  }

  Nice::Vector<int> Predict(Nice::Matrix<T> &inMatrix) {
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
         //   std::cout << closeCtr[i] << std::endl;
       }

    delete[] closeCtr;
    return (*assignments);
  }

  Nice::Vector<int> FitPredict() {

    dataPts->setNPts(numPts);      // set number of pts
    dataPts->buildKcTree();      // build filtering structure
    ctrsData = new KMfilterCenters(k, (*dataPts));   // allocate centers

//  cout << "\nExecuting Clustering Algorithm: Hybrid\n";
    KMlocalHybrid kmHybrid((*ctrsData), (*term));   // Hybrid heuristic
    (*ctrsData) = kmHybrid.execute();

//    ctrsData->print();

//   cout << "Number of stages: " << kmHybrid.getTotalStages() << "\n";
//   cout << "Average distortion: " <<
//   centerObj.lse)/double(centerObj.getNPts()) << "\n";

//    std::cout << ctrs2[0][0] << std::endl;
//    std::cout << ctrs2[0][1] << std::endl;
//    std::cout << ctrs2[0][2] << std::endl;
//    std::cout << ctrs2[0][3] << std::endl;
//    std::cout << ctrs2[1][0] << std::endl;
//    std::cout << ctrs2[1][1] << std::endl;
//    std::cout << ctrs2[1][2] << std::endl;
//    std::cout << ctrs2[1][3] << std::endl;

//    // print final center points
//   cout << "(Final Center Points:\n";
//   ctrs.print();
//   cout << ")\n";

    // get/print final cluster assignments

    KMctrIdxArray closeCtr = new KMctrIdx[dataPts->getNPts()];

    double* sqDist = new double[dataPts->getNPts()];

    (*ctrsData).getAssignments(closeCtr, sqDist);

    assignments = new Nice::Vector<int>;
    assignments->setZero(dataPts->getNPts());

    for (int i = 0; i < dataPts->getNPts(); i++) {
      (*assignments)(i) = closeCtr[i];
      //   std::cout << closeCtr[i] << std::endl;
    }

    std::ofstream outfile;
    outfile.open("output.txt");
    outfile << *assignments;
    outfile.close();


    delete[] closeCtr;
    return (*assignments);
  }

  ~Kmeans() {
//  kmExit(0);
  }
};

}  // Namespace Nice
#endif // CPP_INCLUDE_KMEANS_H

