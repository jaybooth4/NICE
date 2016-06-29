#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main ()
{
	ifstream dataFile ("data1.txt");
	string ss;
	if (dataFile.is_open())
		cout << "open!" << endl;
	ofstream newFile ("newFile.txt");
	if (dataFile.is_open())
		while( getline(dataFile, ss))
		{
			for (int i = 0; i < 80; ++i)
				if (ss[i]==',')
					ss[i]=' ';
			newFile << ss << endl;
		}
	dataFile.close();
	newFile.close();
}

