python genKmeansData.py 3 100 2 200
rm include/data_k3*
mv data* include/
g++ -std=c++11 test.cc -I /home/jason.b/NICE/cpp/ -I /home/jason.b/NICE/cpp/build/eigen/src/eigen
./a.out

