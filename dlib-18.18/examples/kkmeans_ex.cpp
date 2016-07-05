// This is an example file that runs the kkmeans function within dlib
// The alterations made by me have been marked with four slashes (////)
// The alterations allow for an input file and change the dimensions,
// Number of clusters, and amount of information printed. The original
// Can be found at http://dlib.net/kkmeans_ex.cpp.html
// To compile this program run g++ filename -I (path to dlib folder)





// The contents of this file are in the public domain. See LICENSE_FOR_EXAMPLE_PROGRAMS.txt
/*
    This is an example illustrating the use of the kkmeans object 
    and spectral_cluster() routine from the dlib C++ Library.

    The kkmeans object is an implementation of a kernelized k-means clustering 
    algorithm.  It is implemented by using the kcentroid object to represent 
    each center found by the usual k-means clustering algorithm.  

    So this object allows you to perform non-linear clustering in the same way 
    a svm classifier finds non-linear decision surfaces.  
    
    This example will make points from 3 classes and perform kernelized k-means 
    clustering on those points.  It will also do the same thing using spectral 
    clustering.

    The classes are as follows:
        - points very close to the origin
        - points on the circle of radius 10 around the origin
        - points that are on a circle of radius 4 but not around the origin at all
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <dlib/clustering.h>
#include <dlib/rand.h>
#include <eigen3/Eigen/Dense>
#include <cstdlib>
#include <algorithm>
#include <string>

using namespace std;
using namespace dlib;

Eigen::MatrixXf FromFile(const std::string &input_file_path, int num_rows,
                   int num_cols);

matrix<float> TransformData(Eigen::MatrixXf EigenMatrix);

int main()
{
	//// Input stream to assign matrix
  Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic> EigenMatrix(100000, 4);
  EigenMatrix = FromFile("data_k4_p25000_d4_c100.txt", 100000, 4);

	//ifstream myfile ("data_k4_p100000_d4_c1.txt");
//	if (myfile.is_open())
	//	cout << "open!" << endl;
	//myfile >> InMatrix;
	//cout << rowm(InMatrix, range(0,100)) << endl;  //// For printing input
	//myfile.close();
  dlib::matrix<float> InMatrix;
  InMatrix = TransformData(EigenMatrix);
  dlib::matrix<float> TransposeInMatrix = trans(InMatrix);
    //// Transpose matrix to allow for easy transition to a dataset
	//// For the kkmeans function


    // Here we declare that our samples will be 2 dimensional column vectors.  
    // (Note that if you don't know the dimensionality of your vectors at compile time
    // you can change the 2 to a 0 and then set the size at runtime)

	typedef matrix<double,4,1> sample_type;

    // Now we are making a typedef for the kind of kernel we want to use.  I picked the
    // radial basis kernel because it only has one parameter and generally gives good
    // results without much fiddling.
    typedef radial_basis_kernel<sample_type> kernel_type;

    // Here we declare an instance of the kcentroid object.  It is the object used to 
    // represent each of the centers used for clustering.  The kcentroid has 3 parameters 
    // you need to set.  The first argument to the constructor is the kernel we wish to 
    // use.  The second is a parameter that determines the numerical accuracy with which 
    // the object will perform part of the learning algorithm.  Generally, smaller values 
    // give better results but cause the algorithm to attempt to use more dictionary vectors 
    // (and thus run slower and use more memory).  The third argument, however, is the 
    // maximum number of dictionary vectors a kcentroid is allowed to use.  So you can use
    // it to control the runtime complexity.  
    kcentroid<kernel_type> kc(kernel_type(0.1),0.01, 8);

    // Now we make an instance of the kkmeans object and tell it to use kcentroid objects
    // that are configured with the parameters from the kc object we defined above.
    kkmeans<kernel_type> test(kc);

    std::vector<sample_type> samples;
    std::vector<sample_type> initial_centers;


    sample_type m;  //// Declare a data point variable
    for (int i=0; i < 10000; ++i) {
    	dlib::matrix <float> ColumnVector = colm(TransposeInMatrix, i);
    	m(0)=ColumnVector(0);
    	m(1)=ColumnVector(1);
    	m(2)=ColumnVector(2);
    	m(3)=ColumnVector(3);  //// Assign elements to a data point
    	samples.push_back(m);  //// Add data point to the data vector
    }

    //// Commented out section assigns clusters based on rand() function
/*
    dlib::rand rnd;


    // we will make 50 points from each class
    const long num = 50;

    // make some samples near the origin
    double radius = 0.5;
    for (long i = 0; i < num; ++i)
    {
        double sign = 1;
        if (rnd.get_random_double() < 0.5)
            sign = -1;
        m(0) = 2*radius*rnd.get_random_double()-radius;
        m(1) = sign*sqrt(radius*radius - m(0)*m(0));

        // add this sample to our set of samples we will run k-means 
        samples.push_back(m);
    }

    // make some samples in a circle around the origin but far away
    radius = 10.0;
    for (long i = 0; i < num; ++i)
    {
        double sign = 1;
        if (rnd.get_random_double() < 0.5)
            sign = -1;
        m(0) = 2*radius*rnd.get_random_double()-radius;
        m(1) = sign*sqrt(radius*radius - m(0)*m(0));

        // add this sample to our set of samples we will run k-means 
        samples.push_back(m);
    }

    // make some samples in a circle around the point (25,25) 
    radius = 4.0;
    for (long i = 0; i < num; ++i)
    {
        double sign = 1;
        if (rnd.get_random_double() < 0.5)
            sign = -1;
        m(0) = 2*radius*rnd.get_random_double()-radius;
        m(1) = sign*sqrt(radius*radius - m(0)*m(0));

        // translate this point away from the origin
        m(0) += 25;
        m(1) += 25;

        // add this sample to our set of samples we will run k-means 
        samples.push_back(m);
    }
*/


    // tell the kkmeans object we made that we want to run k-means with k set to 3. 
    // (i.e. we want 3 clusters)
    test.set_number_of_centers(4);

    // You need to pick some initial centers for the k-means algorithm.  So here
    // we will use the dlib::pick_initial_centers() function which tries to find
    // n points that are far apart (basically).  
    pick_initial_centers(4, initial_centers, samples, test.get_kernel());

    // now run the k-means algorithm on our set of samples.  
    test.train(samples,initial_centers);

    // now loop over all our samples and print out their predicted class.  In this example
    // all points are correctly identified.

    /*  //// For printing assignments
    for (unsigned long i = 0; i < 25; ++i)
    {
        cout << test(samples[i*4]) << " ";
        cout << test(samples[1+i*41]) << " ";
        cout << test(samples[2+i*4]) << " ";
        cout << test(samples[3+i*4]) << "\n";
    }
	*/

/*  //// Dictionary vector determine the accuracy of your result. More can be
 *  //// Enable if you alter the source code, but it will take more time
    // Now print out how many dictionary vectors each center used.  Note that 
    // the maximum number of 8 was reached.  If you went back to the kcentroid 
    // constructor and changed the 8 to some bigger number you would see that these
    // numbers would go up.  However, 8 is all we need to correctly cluster this dataset.
    cout << "num dictionary vectors for center 0: " << test.get_kcentroid(0).dictionary_size() << endl;
    cout << "num dictionary vectors for center 1: " << test.get_kcentroid(1).dictionary_size() << endl;
    cout << "num dictionary vectors for center 2: " << test.get_kcentroid(2).dictionary_size() << endl;
    cout << "num dictionary vectors for center 3: " << test.get_kcentroid(3).dictionary_size() << endl;
*/

/*
    // Finally, we can also solve the same kind of non-linear clustering problem with
    // spectral_cluster().  The output is a vector that indicates which cluster each sample
    // belongs to.  Just like with kkmeans, it assigns each point to the correct cluster.
    std::vector<unsigned long> assignments = spectral_cluster(kernel_type(0.1), samples, 4);
    cout << mat(assignments) << endl;
*/
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


matrix<float> TransformData(Eigen::MatrixXf EigenMatrix) {
  matrix<float> InMatrix;
  InMatrix = mat(EigenMatrix);
  return InMatrix;
}
