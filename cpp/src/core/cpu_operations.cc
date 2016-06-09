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

#include "include/cpu_operations.h"
#include <unistd.h>
#include <iostream>
#include "Eigen/Dense"
#include "include/matrix.h"
#include "include/vector.h"


namespace Nice {

// This function creates the transpose of a matrix
template<typename T>
Matrix<T> CpuOperations<T>::Transpose(const Matrix<T> &a) {
  Matrix<T> at = a.transpose();
  return at;
}

template<typename T>
Vector<T> CpuOperations<T>::Transpose(const Vector<T> &a) {
  // Same function because both are matrices
  Vector<T> at = a.transpose();
  return at;
}

template class CpuOperations<int>;
template class CpuOperations<float>;
template class CpuOperations<double>;

}  //  namespace Nice
