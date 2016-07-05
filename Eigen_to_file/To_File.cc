// This is a test file which is used to demonstrate the functionality 
// of the transpose() function from the Eigen library.
// The function has been drafted in the cpu_operations.cc


#include <eigen3/Eigen/Dense>  // Relative path to Eigen library in project
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <fstream>


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

void ToFile(Eigen::MatrixXf m)
{
  std::ofstream writtenFile ("Formatted.txt");
  const static Eigen::IOFormat CSVFormat(Eigen::StreamPrecision, Eigen::DontAlignCols, " ", ",\n");
  writtenFile << m.format(CSVFormat);

}

int main()
{
  // Creates a randomly initialized 2 by 2 matrix
  Eigen::MatrixXf m;
  m = FromFile("data_k4_p25000_d4_c100.txt", 100000, 4);
 
  //std::cout << "Here is the matrix m:" << std::endl << m << std::endl;
  
  ToFile(m);

  return 0;
}

