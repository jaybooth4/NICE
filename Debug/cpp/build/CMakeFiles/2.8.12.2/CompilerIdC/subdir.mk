################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../cpp/build/CMakeFiles/2.8.12.2/CompilerIdC/CMakeCCompilerId.c 

OBJS += \
./cpp/build/CMakeFiles/2.8.12.2/CompilerIdC/CMakeCCompilerId.o 

C_DEPS += \
./cpp/build/CMakeFiles/2.8.12.2/CompilerIdC/CMakeCCompilerId.d 


# Each subdirectory must supply rules for building sources it contributes
cpp/build/CMakeFiles/2.8.12.2/CompilerIdC/%.o: ../cpp/build/CMakeFiles/2.8.12.2/CompilerIdC/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


