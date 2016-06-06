################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../googletest/src/gtest-all.cc \
../googletest/src/gtest-death-test.cc \
../googletest/src/gtest-filepath.cc \
../googletest/src/gtest-port.cc \
../googletest/src/gtest-printers.cc \
../googletest/src/gtest-test-part.cc \
../googletest/src/gtest-typed-test.cc \
../googletest/src/gtest.cc \
../googletest/src/gtest_main.cc 

OBJS += \
./googletest/src/gtest-all.o \
./googletest/src/gtest-death-test.o \
./googletest/src/gtest-filepath.o \
./googletest/src/gtest-port.o \
./googletest/src/gtest-printers.o \
./googletest/src/gtest-test-part.o \
./googletest/src/gtest-typed-test.o \
./googletest/src/gtest.o \
./googletest/src/gtest_main.o 

CC_DEPS += \
./googletest/src/gtest-all.d \
./googletest/src/gtest-death-test.d \
./googletest/src/gtest-filepath.d \
./googletest/src/gtest-port.d \
./googletest/src/gtest-printers.d \
./googletest/src/gtest-test-part.d \
./googletest/src/gtest-typed-test.d \
./googletest/src/gtest.d \
./googletest/src/gtest_main.d 


# Each subdirectory must supply rules for building sources it contributes
googletest/src/%.o: ../googletest/src/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/jason.b/Desktop/Github/NICE/Eigen -I/usr/include/ -I/usr/include/gtest -I/home/jason.b/Desktop/Github/NICE/cpp/include -O0 -g3 -Wall -c -fmessage-length=0 -std=c++14 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


