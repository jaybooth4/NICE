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
//  File:   kmlsample.cpp
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
#include "include/model.h"
#include "include/matrix.h"
#include "include/vector.h"

#include <cstring>
#include <string.h>
#include <cstdlib>      // C standard includes
#include <iostream>     // C++ I/O
#include <string>     // C++ strings
#include "KMlocal.h"      // k-means algorithms

//  dim   Dimension of the space (default = 2)
//  nctrs   The number of centers (default = 4)
//  mpts    Maximum number of data points (default = 1000)
//  data    File containing data points
//      (If omitted mpts points are randomly generated.)
//  stages    Number of stages to run (default = 100)
//

//----------------------------------------------------------------------
//  Termination conditions
//  These are explained in the file KMterm.h and KMlocal.h.  Unless
//  you are into fine tuning, don't worry about changing these.
//----------------------------------------------------------------------

namespace Nice{

class Kmeans
{
 private:
  int k;
  int dim;
  int maxPts;
  int stages;
  istream* dataIn;   // input data stream
  //KMdata dataPts;    // allocate data storage
  std::string fileLocation;

 public:

 Kmeans(int numClusters, int dimensions, int maximumPoints, int numStages, std::string inputFile) {

  k   = numClusters;    // number of centers
  dim   = dimensions;    // dimension
  maxPts    = maximumPoints;    // max number of data points
  stages    = numStages;   // number of stages
  fileLocation = inputFile;
  dataIn = NULL;   // input data stream

  //// This method of assigning creates a KMterm and then reassigns the
  //// Number of stage. It seems as though the 100, 0, 0, 0 is an initial
  //// Value and 2 linear multipliers and a power value, where max stages
  //// Is equal to a*b + a*c + a^d (see KMterm)

 }


 Vector <int> FitPredict() {

  KMdata dataPts{dim, maxPts};    // allocate data storage
  int nPts = 0;       // actual number of points
  static ifstream dataStream;     // data file stream
  dataStream.open(fileLocation, ios::in);
  if (!dataStream) {
    cerr << "Cannot open data file\n";
    kmExit(1);
      }
  else {
      dataIn = &dataStream;
  }
  if (dataIn != NULL) {     // read points from file
    bool readPt = true;
  while (nPts < maxPts && readPt) {
    for (int d = 0; d < dim; d++) {
    if(!(*dataIn >> dataPts[nPts][d]))
      readPt = false;
    }
    readPt = true;
    nPts++;
  }
  }
  else {
//    std::cout<<"Issues here"<<std::endl;
  }

//  std::cout << "Data Points:\n";     // echo data points
//  for (int i = 0; i < nPts; i++) {
//    std::cout << "(" << dataPts[i][0];
//    for (int j = 1; j < dim; j++) {
//      std::cout << ", " << dataPts[i][j];
//    }
//    std::cout << ")\n";
// }

  dataPts.setNPts(nPts);      // set actual number of pts
  dataPts.buildKcTree();      // build filtering structure

  KMfilterCenters ctrs{k, dataPts};   // allocate centers

  KMterm  term(100, 0, 0, 0,   // run for 100 stages
      0.10,     // min consec RDL
      0.10,     // min accum RDL
      3,      // max run stages
      0.50,     // init. prob. of acceptance
      10,     // temp. run length
      0.95);      // temp. reduction factor

  term.setAbsMaxTotStage(stages);   // set number of stages

//  cout << "\nExecuting Clustering Algorithm: Hybrid\n";
  KMlocalHybrid kmHybrid{ctrs, term};   // Hybrid heuristic
  ctrs = kmHybrid.execute();

//   cout << "Number of stages: " << kmHybrid.getTotalStages() << "\n";
//   cout << "Average distortion: " <<
//   ctrs.getDist(false)/double(ctrs.getNPts()) << "\n";

   // print final center points
//   cout << "(Final Center Points:\n";
//   ctrs.print();
//   cout << ")\n";

   // get/print final cluster assignments

   KMctrIdxArray closeCtr = new KMctrIdx[dataPts.getNPts()];

   double* sqDist = new double[dataPts.getNPts()];

   ctrs.getAssignments(closeCtr, sqDist);

   Nice::Vector<int> assignments;
   assignments.setZero(dataPts.getNPts());

   for (int i = 0; i < dataPts.getNPts(); i++) {
     assignments(i) = closeCtr[i];
  //   std::cout << closeCtr[i] << std::endl;
   }

   delete [] closeCtr;
   return assignments;
 }

 ~Kmeans() {
//  kmExit(0);
 }
};

} // Namespace Nice
#endif // CPP_INCLUDE_KMEANS_H

