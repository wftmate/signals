################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/display.cpp \
../src/generation.cpp \
../src/main.cpp \
../src/my_fourier.cpp 

OBJS += \
./src/display.o \
./src/generation.o \
./src/main.o \
./src/my_fourier.o 

CPP_DEPS += \
./src/display.d \
./src/generation.d \
./src/main.d \
./src/my_fourier.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/will/eclipse-workspace/gnuplot-iostream -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


