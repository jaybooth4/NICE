################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../cpp/src/util/util.cc 

OBJS += \
./cpp/src/util/util.o 

CC_DEPS += \
./cpp/src/util/util.d 


# Each subdirectory must supply rules for building sources it contributes
cpp/src/util/%.o: ../cpp/src/util/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/jason.b/Desktop/Github/NICE/Eigen -I/usr/include/ -I/usr/include/gtest -I/home/jason.b/Desktop/Github/NICE/cpp/include -O0 -g3 -Wall -c -fmessage-length=0 -std=c++14 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


