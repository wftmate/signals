################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/display.cpp \
../src/fourier.cpp \
../src/generation.cpp \
../src/main.cpp 

OBJS += \
./src/display.o \
./src/fourier.o \
./src/generation.o \
./src/main.o 

CPP_DEPS += \
./src/display.d \
./src/fourier.d \
./src/generation.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/will/eclipse-workspace/gnuplot-iostream -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


