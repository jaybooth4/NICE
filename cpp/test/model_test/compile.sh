g++ -std=c++11 -c -g -pthread kmeans_test.cc -I /home/jason.b/NICE/cpp/build/eigen/src/eigen/ -isystem ~/NICE/cpp/build/gtest/src/googletest/googletest/include -I /home/jason.b/NICE/cpp/ -I ~/NICE/cpp/build/kmlocal/kmlocal-1.7.2/src 

#~/NICE/cpp/build/gtest/src/googletest-build/googlemock/gtest/libgtest.a 

g++ -std=c++11 kmeans_test.o -L/home/jason.b/NICE/cpp/build/kmlocallib/ -lkmlocal -pthread ~/NICE/cpp/build/gtest/src/googletest-build/googlemock/gtest/libgtest.a
