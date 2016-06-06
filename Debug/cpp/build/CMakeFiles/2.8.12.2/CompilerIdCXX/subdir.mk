################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../cpp/build/CMakeFiles/2.8.12.2/CompilerIdCXX/CMakeCXXCompilerId.cpp 

OBJS += \
./cpp/build/CMakeFiles/2.8.12.2/CompilerIdCXX/CMakeCXXCompilerId.o 

CPP_DEPS += \
./cpp/build/CMakeFiles/2.8.12.2/CompilerIdCXX/CMakeCXXCompilerId.d 


# Each subdirectory must supply rules for building sources it contributes
cpp/build/CMakeFiles/2.8.12.2/CompilerIdCXX/%.o: ../cpp/build/CMakeFiles/2.8.12.2/CompilerIdCXX/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/jason.b/Desktop/Github/NICE/Eigen -I/usr/include/ -I/usr/include/gtest -I/home/jason.b/Desktop/Github/NICE/cpp/include -O0 -g3 -Wall -c -fmessage-length=0 -std=c++14 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


