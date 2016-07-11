/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 2011 Heiko Strathmann
 * Copyright (C) 2011 Berlin Institute of Technology and Max-Planck-Society
 */

#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Core>
#include <iostream>
#include <fstream>
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

void print_message(FILE* target, const char* str)
{
	fprintf(target, "%s", str);
}


Eigen::Matrix<float64_t, 100, 4> FromFile(const std::string &input_file_path, int num_rows,
                   int num_cols) {
  std::ifstream input_file(input_file_path, std::ifstream::in);
  Eigen::Matrix<float64_t, 100, 4> m;
  if (input_file) {
    for (int i = 0; i < num_rows; i++)
      for (int j = 0; j < num_cols; j++)
        input_file >> m(i, j);
    input_file.close();
    return m;
  } else {
    std::cerr << "Cannot open file " + input_file_path + ", exiting...";
    exit(1);
  }
}


int main(int argc, char **argv)
{
	init_shogun(&print_message, &print_message, &print_message);
  //init_shogun();

	int32_t num_clusters=4;
	int32_t num_features=11;
	int32_t dim_features=4;
//	int32_t num_vectors_per_cluster=25;
	//float64_t cluster_std_dev=2.0;

	/* build random cluster centers */
	SGMatrix<float64_t> cluster_centers(dim_features, num_clusters);
	SGVector<float64_t>::random_vector(cluster_centers.matrix, dim_features*num_clusters,
			-500.0, 500.0);
	SGMatrix<float64_t>::display_matrix(cluster_centers.matrix, cluster_centers.num_rows,
			cluster_centers.num_cols, "cluster centers");

	/* initialize data */
	Eigen::Matrix<float64_t, 100, 4> mat_eig = FromFile("data_k4_p25_d4_c1.txt", 100, 4);
  Eigen::Matrix<float64_t, 4, 100> mat2_eig = mat_eig.transpose();
  SGMatrix<float64_t> * ptr = new SGMatrix<float64_t> (mat2_eig.data(), 4, 100);
  //SGMatrix<float64_t>* ptr = &data;
  //Eigen::Matrix<float64_t, 100000, 4> mat_eig;
  //Eigen::Matrix<float64_t, 100, 4> mat2_eig = mat_eig.cast <float64_t>;
  //std::cout << mat2_eig << std::endl;

  //  std::cout << "After initialization of the data" << std::endl;

	/* create features, SG_REF to avoid deletion */
	CDenseFeatures<float64_t>* features=new CDenseFeatures<float64_t> ();
	features->set_feature_matrix(*ptr);
//	std::cout << "After set_feature_matrix()" << std::endl;
	SG_REF(features);

	/* create labels for cluster centers */
	CMulticlassLabels* labels=new CMulticlassLabels(num_features);
	for (index_t i=0; i<num_features; ++i)
		labels->set_label(i, i%2==0 ? 0 : 1);

	/* create distance */
	CEuclideanDistance* distance=new CEuclideanDistance(features, features);

//  std::cout << "After CEuclideanDistance()" << std::endl;


	/* create distance machine */
	CKMeans* clustering=new CKMeans(num_clusters, distance);
	clustering->train(features);

//  std::cout << "After train()" << std::endl;

  /* build clusters */
	CMulticlassLabels* result=CLabelsFactory::to_multiclass(clustering->apply());
	for (index_t i=0; i<result->get_num_labels(); ++i)
		SG_SPRINT("cluster index of vector %i: %f\n", i, result->get_label(i));

//  std::cout << "Hello4" << std::endl;

	/* print cluster centers */
	CDenseFeatures<float64_t>* centers=
			(CDenseFeatures<float64_t>*)distance->get_lhs();

//  std::cout << "Hello5" << std::endl;

	SGMatrix<float64_t> centers_matrix=centers->get_feature_matrix();

//  std::cout << "Hello6" << std::endl;

	SGMatrix<float64_t>::display_matrix(centers_matrix.matrix, centers_matrix.num_rows,
			centers_matrix.num_cols, "learned centers");

//	std::cout << "Hello7" << std::endl;

	SGMatrix<float64_t>::display_matrix(cluster_centers.matrix, cluster_centers.num_rows,
			cluster_centers.num_cols, "real centers");

//  std::cout << "Hello8" << std::endl;

	//ptr->~SGMatrix();
  delete(ptr);

	/* clean up */
	SG_UNREF(result);
	SG_UNREF(centers);
	SG_UNREF(clustering);
	SG_UNREF(labels);
	SG_UNREF(features);

	exit_shogun();

	return 0;

}


