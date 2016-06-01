################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../cpp/src/core/Transpose_Test/TransposeTest.o \
../cpp/src/core/Transpose_Test/cpu_operations.o 

CC_SRCS += \
../cpp/src/core/Transpose_Test/TransposeTest.cc \
../cpp/src/core/Transpose_Test/TransposeTestClass.cc \
../cpp/src/core/Transpose_Test/cpu_operations.cc 

OBJS += \
./cpp/src/core/Transpose_Test/TransposeTest.o \
./cpp/src/core/Transpose_Test/TransposeTestClass.o \
./cpp/src/core/Transpose_Test/cpu_operations.o 

CC_DEPS += \
./cpp/src/core/Transpose_Test/TransposeTest.d \
./cpp/src/core/Transpose_Test/TransposeTestClass.d \
./cpp/src/core/Transpose_Test/cpu_operations.d 


# Each subdirectory must supply rules for building sources it contributes
cpp/src/core/Transpose_Test/%.o: ../cpp/src/core/Transpose_Test/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/ -I/home/jason.b/Desktop/Github/NICE/Eigen -I/usr/include/gtest -I/home/jason.b/Desktop/Github/NICE/cpp/src/ -I/home/jason.b/Desktop/Github/NICE/ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++14 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


