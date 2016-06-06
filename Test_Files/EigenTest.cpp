//This program is a simple test of an Eigen operation

#include <iostream>
#include "Eigen/Eigen/Dense"


int main(int argc, char **argv)
{
 // Eigen::MatrixXd m = Eigen::Matrix<int>::Random(3,3); 
 // Eigen::MatrixXd m2;
 // m2 = m + m;
  Eigen::MatrixXd m;
  m.setRandom(3,3);
  std::cout << "m=" << std::endl << m << std::endl;
  return 0;
}
