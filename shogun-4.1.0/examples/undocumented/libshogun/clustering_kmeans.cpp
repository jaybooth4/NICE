/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 2011 Heiko Strathmann
 * Copyright (C) 2011 Berlin Institute of Technology and Max-Planck-Society
 */
#include <time.h>
#include <iostream>
#include <fstream>
#include <eigen3/Eigen/Dense>
#include <shogun/base/init.h>
#include <shogun/io/CSVFile.h>
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

#define HAVE_EIGEN3 1  //// Use this to enable changing from Eigen to Shogun matrix

using namespace shogun;

Eigen::Matrix<float64_t, Eigen::Dynamic, Eigen::Dynamic> FromFile(const std::string &input_file_path, int num_rows,
                   int num_cols);  //// (Unused) Function to read into Eigen matrix

void print_message(FILE* target, const char* str);

int main(int argc, char **argv)
{
  clock_t begin = clock();
	init_shogun(&print_message, &print_message, &print_message);  //// Seems to prevent gprof analysis

	int32_t num_clusters=20; //// Parameters must be changed for each compilation
	int32_t num_features=11;
	int32_t dim_features=4;
//	int32_t num_vectors_per_cluster=250000;
	float64_t cluster_std_dev=2.0;
	int num_points = 100000;

	/* build random cluster centers */
	SGMatrix<float64_t> cluster_centers(dim_features, num_clusters);
	SGVector<float64_t>::random_vector(cluster_centers.matrix, dim_features*num_clusters,
			0, 500.0);
//	SGMatrix<float64_t>::display_matrix(cluster_centers.matrix, cluster_centers.num_rows,
//			cluster_centers.num_cols, "cluster centers");


//// Example (Unused) demonstrating ways to convert an Eigen matrix to a shogun matrix
//  Eigen::Matrix<float64_t, Eigen::Dynamic, Eigen::Dynamic> mat_eig = FromFile("data_k4_p2500_d4_c1.txt", 10000, 4);
//  Eigen::Matrix<float64_t, Eigen::Dynamic, Eigen::Dynamic> mat2_eig = mat_eig.transpose(); //// Transpose data
//  Eigen::Matrix<float64_t, Eigen::Dynamic, Eigen::Dynamic> mat2_eig = Eigen::Matrix<float64_t, Eigen::Dynamic, Eigen::Dynamic>::Constant(4, 100, 1);
//  SGMatrix<float64_t> data(&mat2_eig(0), 4, 100); //// Works with macro
//  float64_t* raw_buffer = &mat2_eig(0); //// Does not work!
//  SGMatrix<float64_t> data(mat2_eig);  //// Works with macro


	//// Read in Data
  int32_t feats;
  int32_t vecs;
  float64_t* mat; //// = new float64_t[num_points]; (Safer way to specify points)
  CCSVFile* infile = new CCSVFile("data_k20_p5000_d4_c1.txt", 'r');
  infile->get_matrix(mat, feats, vecs);
  SGMatrix<float64_t> data(mat, num_points, 4);
  data.transpose_matrix(data.matrix, data.num_rows, data.num_cols);


	/* create data around clusters */
//	SGMatrix<float64_t> data(dim_features, num_clusters*num_vectors_per_cluster);

//	for (index_t i=0; i<num_clusters; ++i)
//	{
//		for (index_t j=0; j<dim_features; ++j)
//		{
//			for (index_t k=0; k<num_vectors_per_cluster; ++k)
//			{
//				index_t idx=i*dim_features*num_vectors_per_cluster;
//				idx+=j;
//				idx+=k*dim_features;
//				float64_t entry=cluster_centers.matrix[i*dim_features+j];
//				data.matrix[idx]=CMath::normal_random(entry, cluster_std_dev);
//			}
//		}
//	}

	/* create features, SG_REF to avoid deletion */
	CDenseFeatures<float64_t>* features=new CDenseFeatures<float64_t> ();
	features->set_feature_matrix(data);
	SG_REF(features);

//// This is unused and somewhat confusing. It seems unused in the rest of the program
//// And commenting it out still results in clustering
//	/* create labels for cluster centers */
//	CMulticlassLabels* labels=new CMulticlassLabels(num_features);
//	for (index_t i=0; i<num_features; ++i)
//		labels->set_label(i, i%2==0 ? 0 : 1);

	/* create distance */
	CEuclideanDistance* distance=new CEuclideanDistance(features, features);

	/* create distance machine */
	CKMeans* clustering=new CKMeans(num_clusters, distance);
	clustering->set_use_kmeanspp(true);
	clustering->train(features);

	/* build clusters */
	CMulticlassLabels* result=CLabelsFactory::to_multiclass(clustering->apply());
//	for (index_t i=0; i<result->get_num_labels(); ++i)
//		SG_SPRINT("cluster index of vector %i: %f\n", i, result->get_label(i));

	/* print cluster centers */
	CDenseFeatures<float64_t>* centers=
			(CDenseFeatures<float64_t>*)distance->get_lhs();

	SGMatrix<float64_t> centers_matrix=centers->get_feature_matrix();

//	SGMatrix<float64_t>::display_matrix(centers_matrix.matrix, centers_matrix.num_rows,
//			centers_matrix.num_cols, "learned centers");

//	SGMatrix<float64_t>::display_matrix(cluster_centers.matrix, cluster_centers.num_rows,
//			cluster_centers.num_cols, "real centers");

	/* clean up */
	SG_UNREF(result);
	SG_UNREF(centers);
	SG_UNREF(clustering);
	//SG_UNREF(labels);
	SG_UNREF(features);

	exit_shogun();

  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  std::cout << time_spent << std::endl;
	return 0;
}


void print_message(FILE* target, const char* str)
{
  fprintf(target, "%s", str);
}


Eigen::Matrix<float64_t, Eigen::Dynamic, Eigen::Dynamic> FromFile(const std::string &input_file_path, int num_rows,
                   int num_cols) {
  std::ifstream input_file(input_file_path, std::ifstream::in);
  Eigen::Matrix<float64_t, Eigen::Dynamic, Eigen::Dynamic> m(num_rows, num_cols);
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


