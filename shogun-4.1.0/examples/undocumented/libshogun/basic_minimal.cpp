#include <shogun/base/init.h>
#include <iostream>
#include <eigen3/Eigen/Dense>
#include <shogun/features/DenseFeatures.h>
#include <shogun/lib/common.h>
#include <fstream>
#include <string.h>
#include <stdio.h>

using namespace shogun;

int main(int argc, char** argv)
{
  init_shogun_with_defaults();
  FILE* fp;
  fp = fopen("input.txt", "r");
  SGMatrix<int32_t> matrix(2,2);
  CFile infile(fp, "r");
//  std::size_t length;
//  char * buffer = infile.read_whole_file("input.txt", length);
//  std::cout << length << std::endl;
  matrix.load(&infile);
  matrix.display_matrix();
  SGMatrix<int32_t> matrix2 = matrix.clone();
  matrix2.display_matrix();
	exit_shogun();
	std::cout << "Hello!" << std::endl;
	infile.close();
	return 0;
}

//Eigen::Matrix2f mat = Eigen::Matrix2f::Random();


//std::ifstream myfile ("input.txt");
  //if (myfile.is_open())
  //  std::cout << "open!" << std::endl;
 // FILE *fp = &myfile;

// CFile(fp, "r", "Yayy");
// matrix.load(myfile);
 //myfile.close();

//int array[4];
//for (int i = 0; i < 4; i++)
//  array[i]=i;
//matrix = &array;
//
//~/Desktop/Github/NICE/shogun-4.1.0/examples/undocumented/libshogun/input.txt
