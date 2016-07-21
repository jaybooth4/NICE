#include(ExternalProject)

set(CMDARG0 mkdir kmlocal kmlocallib)
  execute_process(COMMAND ${CMDARG0}
       WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
       )
message(STATUS "Command :  " ${CMDARG0})

set(CMDARG wget https://www.cs.umd.edu/~mount/Projects/KMeans/kmlocal-1.7.2.tar.gz)
  execute_process(COMMAND ${CMDARG}
       WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/kmlocal
       )
message(STATUS "Command :  " ${CMDARG})

set(CMDARG2 tar -xvf kmlocal-1.7.2.tar.gz)
  execute_process(COMMAND ${CMDARG2}
       WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/kmlocal
       )
message(STATUS "Command :  " ${CMDARG2})

set(KMLOCAL_INCLUDE_DIRS ${CMAKE_CURRENT_BINARY_DIR}/kmlocal/kmlocal-1.7.2/src)

set(KMSOURCES ${KMLOCAL_INCLUDE_DIRS}/KCtree.cpp ${KMLOCAL_INCLUDE_DIRS}/KCutil.cpp ${KMLOCAL_INCLUDE_DIRS}/KM_ANN.cpp ${KMLOCAL_INCLUDE_DIRS}/KMcenters.cpp ${KMLOCAL_INCLUDE_DIRS}/KMdata.cpp ${KMLOCAL_INCLUDE_DIRS}/KMeans.cpp ${KMLOCAL_INCLUDE_DIRS}/KMfilterCenters.cpp ${KMLOCAL_INCLUDE_DIRS}/KMlocal.cpp ${KMLOCAL_INCLUDE_DIRS}/KMrand.cpp ${KMLOCAL_INCLUDE_DIRS}/KMterm.cpp)


set(CMDARG3 g++ -c ${KMSOURCES})

execute_process(COMMAND ${CMDARG3}
       WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/kmlocal/kmlocal-1.7.2/src
       )
message(STATUS "Command :  " ${CMDARG3})

set(KMBINARIES ${KMLOCAL_INCLUDE_DIRS}/KCtree.o ${KMLOCAL_INCLUDE_DIRS}/KCutil.o ${KMLOCAL_INCLUDE_DIRS}/KM_ANN.o ${KMLOCAL_INCLUDE_DIRS}/KMcenters.o ${KMLOCAL_INCLUDE_DIRS}/KMdata.o ${KMLOCAL_INCLUDE_DIRS}/KMeans.o ${KMLOCAL_INCLUDE_DIRS}/KMfilterCenters.o ${KMLOCAL_INCLUDE_DIRS}/KMlocal.o ${KMLOCAL_INCLUDE_DIRS}/KMrand.o ${KMLOCAL_INCLUDE_DIRS}/KMterm.o)

set(CMDARG4 ar rvs libkmlocal.a ${KMBINARIES})

execute_process(COMMAND ${CMDARG4}
       WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/kmlocal/kmlocal-1.7.2/src
       )
message(STATUS "Command :  " ${CMDARG4})

set(CMDARG5 mv libkmlocal.a ${CMAKE_CURRENT_BINARY_DIR}/kmlocallib)

execute_process(COMMAND ${CMDARG5}
       WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/kmlocal/kmlocal-1.7.2/src
       )
message(STATUS "Command :  " ${CMDARG5})


