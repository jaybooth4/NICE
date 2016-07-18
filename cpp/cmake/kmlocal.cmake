#cmake_minimum_required(VERSION 2.8.9)
#project(kmlocal_builder C CXX)
include(ExternalProject)

ExternalProject_Add(kmlocal
   URL https://www.cs.umd.edu/~mount/Projects/KMeans/kmlocal-1.7.2.tar.gz
   PREFIX "${CMAKE_CURRENT_BINARY_DIR}/kmlocal"
   CONFIGURE_COMMAND ""
   INSTALL_COMMAND ""
   BUILD_COMMAND ""
)

set(KMLOCAL_INCLUDE_DIRS ${CMAKE_CURRENT_BINARY_DIR}/kmlocal/src/kmlocal/src)
