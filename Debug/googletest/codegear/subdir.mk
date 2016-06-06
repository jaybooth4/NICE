################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../googletest/codegear/gtest_all.cc \
../googletest/codegear/gtest_link.cc 

OBJS += \
./googletest/codegear/gtest_all.o \
./googletest/codegear/gtest_link.o 

CC_DEPS += \
./googletest/codegear/gtest_all.d \
./googletest/codegear/gtest_link.d 


# Each subdirectory must supply rules for building sources it contributes
googletest/codegear/%.o: ../googletest/codegear/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/jason.b/Desktop/Github/NICE/Eigen -I/usr/include/ -I/usr/include/gtest -I/home/jason.b/Desktop/Github/NICE/cpp/include -O0 -g3 -Wall -c -fmessage-length=0 -std=c++14 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


