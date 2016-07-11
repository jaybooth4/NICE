#include <shogun/base/init.h>

using namespace shogun;
#include <iostream>
#include <eigen3/Eigen/Dense>
#include <shogun/lib/common.h>
#include <shogun/io/File.h>
#include <shogun/io/CSVFile.h>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <shogun/base/init.h>
#include <shogun/evaluation/CrossValidation.h>
#include <shogun/evaluation/ContingencyTableEvaluation.h>
#include <shogun/evaluation/StratifiedCrossValidationSplitting.h>
#include <shogun/modelselection/GridSearchModelSelection.h>
#include <shogun/modelselection/ModelSelectionParameters.h>
#include <shogun/modelselection/ParameterCombination.h>
#include <shogun/labels/MulticlassLabels.h>
#include <shogun/features/DenseFeatures.h>
#include <shogun/clustering/KMeans.h>
#include <shogun/distance/EuclideanDistance.h>
#include <shogun/distance/MinkowskiMetric.h>

using namespace shogun;

int main(int argc, char** argv)
{
  //init_shogun_with_defaults();
  Eigen::Matrix<float64_t, 2, 3> mat_eig = Eigen::Matrix<float64_t, 2, 3>::Random();
  Eigen::Matrix<float64_t, 3, 2> mat2_eig = mat_eig.transpose();
  SGMatrix<float64_t> mat_sg(mat2_eig.data(), 3, 2);
  std::cout << mat_eig << std::endl;
  std::cout << mat2_eig << std::endl;
  std::cout << mat_sg(0,0) << std::endl;
  std::cout << mat_sg(0,1) << std::endl;
  std::cout << mat_sg(1,0) << std::endl;
  std::cout << mat_sg(1,1) << std::endl;
  std::cout << mat_sg(2,0) << std::endl;
  std::cout << mat_sg(2,1) << std::endl;
    //SGMatrix<int32_t>::display_matrix(mat_sg.matrix, mat_sg.num_rows, mat_sg.num_cols, "SGMAT", "Yup");
  //init_shogun_with_defaults();
//	FILE * fp;
//	fp = fopen("input.txt", "r");
//	int32_t fd = fileno(fp);
//	int x, y;
//	fscanf (fp, "%i,%i", &x,&y);
//	std::cout << "x = " << x << " y = " << y << "fileno: " << fd << std::endl;

	//CCSVFile* infile = new CCSVFile("input.txt", 'r');
	//CCSVFile* infile = new CCSVFile(fp, (char*)"input.txt");
  //CCSVFile* infile = new CCSVFile(fd, "r", "input.txt");
  //int32_t feats;
  //int32_t vecs;
  //SGMatrix<int32_t> mat(3,3);
  //int32_t* point = &mat(0,0);
  //get_matrix(point, 3, 3);
  //int32_t* matrix1;
  //matrix1 = SG_MALLOC(int32_t, 30);
  //infile->get_matrix(matrix1, feats, vecs);
	//std::cout<<matrix1[2];
  //matrix.display_matrix();
	//std::cout << "Hello!" << std::endl;
	//infile.close();
  //fclose(fp);
	//exit_shogun();
  return 0;
}

// matrix = matrix3.clone();
// std::size_t length;
// char * buffer = infile.read_whole_file("input.txt", length);
// std::cout << length << std::endl; matrix.load(&infile); matrix.display_matrix();

//Eigen::Matrix2f mat = Eigen::Matrix2f::Random();
//std::ifstream myfile ("input.txt");
//if (myfile.is_open())
// std::cout << "open!" << std::endl;
// FILE *fp = &myfile;
// CFile(fp, "r", "Yayy");
// matrix.load(myfile);
//myfile.close();
//int array[4];
//for (int i = 0; i < 4; i++)
// array[i]=i;
//matrix = &array;
//~/Desktop/Github/NICE/shogun-4.1.0/examples/undocumented/libshogun/input.txt
