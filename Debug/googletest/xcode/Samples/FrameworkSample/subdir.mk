################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../googletest/xcode/Samples/FrameworkSample/widget.cc \
../googletest/xcode/Samples/FrameworkSample/widget_test.cc 

OBJS += \
./googletest/xcode/Samples/FrameworkSample/widget.o \
./googletest/xcode/Samples/FrameworkSample/widget_test.o 

CC_DEPS += \
./googletest/xcode/Samples/FrameworkSample/widget.d \
./googletest/xcode/Samples/FrameworkSample/widget_test.d 


# Each subdirectory must supply rules for building sources it contributes
googletest/xcode/Samples/FrameworkSample/%.o: ../googletest/xcode/Samples/FrameworkSample/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/jason.b/Desktop/Github/NICE/Eigen -I/usr/include/ -I/usr/include/gtest -I/home/jason.b/Desktop/Github/NICE/cpp/include -O0 -g3 -Wall -c -fmessage-length=0 -std=c++14 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


