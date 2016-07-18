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

// This file tests the CpuOperations::Transpose() function by checking to
// See if a matrix passed is transposed in the test IsTransposed
// A transposed Nice matrix is compared to a transposed Eigen Matrix in
// Transpose Eigen
// Behavior with oddly shaped matrices is also tested with test DifferentShapes
// And TransposeZeroRows
// All tests are made using a templated test fixture which attempts
// Integer, float, and double data types

#include <iostream>
#include <cmath>

#include "include/gpu_operations.h"
#include "include/cpu_operations.h"

#include "Eigen/Dense"
#include "gtest/gtest.h"
#include "include/matrix.h"
#include "include/vector.h"
#include "include/gpu_util.h"


// This is a template test fixture class containing test matrices
template<class T>  // Template
class GpuNormTest : public ::testing::Test {  // Inherits testing::Test
 public:  // Members must be public to be accessed by tests
  Nice::Matrix<T> a_;
  Nice::Vector<T> norm_;
  Nice::Vector<T> a_col;
  int row_;
  int col_;

  // Constructor
  void CreateTestData(int m, int n) {
    // Check matrix
    if (a_.rows() != 0 && a_.cols() != 0)
      return;

    // Set up dimension
    row_ = m;
    col_ = n;

    // Create matrix
    a_ = Nice::Matrix<T>::Random(row_, col_);
    norm_.resize(n);
    a_col.resize(m);
    Nice::CpuOperations<T> cpu_op;

    // Solve in CPU
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        a_col(j) = a_(j, i);
      }
      norm_(i) = cpu_op.FrobeniusNorm(a_col);
    }
  }
};
// Establishes a test case with the given types, Char and short types will
// Throw compiler errors
typedef ::testing::Types<float, double> dataTypes;
TYPED_TEST_CASE(GpuNormTest, dataTypes);

TYPED_TEST(GpuNormTest, FuncionalityTest) {
  // Create test data
  int m = 5;
  int n = 10;
  srand(time(NULL));
  this->CreateTestData(m, n);
  Nice::Vector<TypeParam> gpu_norm(n);
  // Test gpu matrix matrix multiply in Nice
  Nice::GpuOperations<TypeParam> gpu_op;
  gpu_norm = gpu_op.Norm(this->a_);

  // Verify the result
  for (int i = 0; i < n; ++i)
  EXPECT_NEAR(this->norm_(i), gpu_norm(i), 0.001);
}

