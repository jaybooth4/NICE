#include <iostream>
#include "include/util.h"
#include "include/matrix.h"
#include "include/cpu_operations.h"
#include <fstream>
#include <sstream>

Eigen::IOFormat CommaInitFmt(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", ", ", "", "", " << ", ";");

int main() 
{
Nice::Matrix<float> m;
m = Nice::util::FromFile<float>("include/data_k3_p100_d2_c200.txt",300,2," ");
Nice::Matrix<float> m2 = m.transpose();
std::cout << m2.format(CommaInitFmt);
return 0;
}
