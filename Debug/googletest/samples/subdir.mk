################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../googletest/samples/sample1.cc \
../googletest/samples/sample10_unittest.cc \
../googletest/samples/sample1_unittest.cc \
../googletest/samples/sample2.cc \
../googletest/samples/sample2_unittest.cc \
../googletest/samples/sample3_unittest.cc \
../googletest/samples/sample4.cc \
../googletest/samples/sample4_unittest.cc \
../googletest/samples/sample5_unittest.cc \
../googletest/samples/sample6_unittest.cc \
../googletest/samples/sample7_unittest.cc \
../googletest/samples/sample8_unittest.cc \
../googletest/samples/sample9_unittest.cc 

OBJS += \
./googletest/samples/sample1.o \
./googletest/samples/sample10_unittest.o \
./googletest/samples/sample1_unittest.o \
./googletest/samples/sample2.o \
./googletest/samples/sample2_unittest.o \
./googletest/samples/sample3_unittest.o \
./googletest/samples/sample4.o \
./googletest/samples/sample4_unittest.o \
./googletest/samples/sample5_unittest.o \
./googletest/samples/sample6_unittest.o \
./googletest/samples/sample7_unittest.o \
./googletest/samples/sample8_unittest.o \
./googletest/samples/sample9_unittest.o 

CC_DEPS += \
./googletest/samples/sample1.d \
./googletest/samples/sample10_unittest.d \
./googletest/samples/sample1_unittest.d \
./googletest/samples/sample2.d \
./googletest/samples/sample2_unittest.d \
./googletest/samples/sample3_unittest.d \
./googletest/samples/sample4.d \
./googletest/samples/sample4_unittest.d \
./googletest/samples/sample5_unittest.d \
./googletest/samples/sample6_unittest.d \
./googletest/samples/sample7_unittest.d \
./googletest/samples/sample8_unittest.d \
./googletest/samples/sample9_unittest.d 


# Each subdirectory must supply rules for building sources it contributes
googletest/samples/%.o: ../googletest/samples/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/jason.b/Desktop/Github/NICE/Eigen -I/usr/include/ -I/usr/include/gtest -I/home/jason.b/Desktop/Github/NICE/cpp/include -O0 -g3 -Wall -c -fmessage-length=0 -std=c++14 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


