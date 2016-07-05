#include <iostream>
#include <fstream>
#include <vector>
#include <eigen3/Eigen/Dense>
#include "dlib/clustering.h"
#include "dlib/rand.h"
//#include <string.h>

#include <cstdlib>
#include <algorithm>
#include <string>

using namespace std;
using namespace dlib;


Eigen::MatrixXf FromFile(const std::string &input_file_path, int num_rows,
                   int num_cols);
int main() {
	Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> TestMatrix;
	TestMatrix.setRandom(10,3);
	cout << TestMatrix << endl;
  ofstream outfile;
  outfile.open("EigenWrite.txt");
  outfile << TestMatrix;
  outfile.close();
//	//ifstream myfile ("EigenWrite.txt");
//	//if (myfile.is_open())
//		//cout << "open!" << endl;
	Eigen::Matrix<float, 10, 3> InTest;
  InTest = FromFile("EigenWrite.txt", 10, 3);
  dlib::matrix<float, 10, 3> Test = mat(InTest);
  cout << InTest << endl;
  cout << rowm(InTest, range(1,7)) << endl;
  //myfile.close();
	return 0;
}

Eigen::MatrixXf FromFile(const std::string &input_file_path, int num_rows,
                   int num_cols) {
  std::ifstream input_file(input_file_path, std::ifstream::in);
  Eigen::MatrixXf m(num_rows, num_cols);
  if (input_file) {
    for (int i = 0; i < num_rows; i++)
      for (int j = 0; j < num_cols; j++)
        input_file >> m(i, j);
    return m;
  } else {
    std::cerr << "Cannot open file " + input_file_path + ", exiting...";
    exit(1);
  }
}


//  dlib::matrix<int, 1, 2> TransTest = trans(Test);
//  cout << TransTest << endl;
//  Test = Test + 5;
//  cout << Test << endl;
