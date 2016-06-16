#include <iostream>
#include <fstream>
#include <vector>
#include <Eigen/Eigen/Dense>
#include "dlib/clustering.h"
#include "dlib/rand.h"

using namespace std;
using namespace dlib;

int main() {
//	Eigen::Matrix<int, 2, 1> TestMatrix;
//	TestMatrix.setZero();
//	dlib::matrix<int, 2, 1> Test = mat(TestMatrix);
//	cout << Test << endl;
//	dlib::matrix<int, 1, 2> TransTest = trans(Test);
//	cout << TransTest << endl;
//	Test = Test + 5;
//	cout << Test << endl;
	ifstream myfile ("SpaceSeparated.txt");
	if (myfile.is_open())
		cout << "open!" << endl;
	dlib::matrix <float> InTest;
	myfile >> InTest;
	cout << rowm(InTest, range(1,7)) << endl;
	myfile.close();
}
