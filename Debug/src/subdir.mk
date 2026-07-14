################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Action.cpp \
../src/ActionProcessor.cpp \
../src/EnemyManager.cpp \
../src/Game.cpp \
../src/Main.cpp \
../src/Renderer.cpp 

OBJS += \
./src/Action.o \
./src/ActionProcessor.o \
./src/EnemyManager.o \
./src/Game.o \
./src/Main.o \
./src/Renderer.o 

CPP_DEPS += \
./src/Action.d \
./src/ActionProcessor.d \
./src/EnemyManager.d \
./src/Game.d \
./src/Main.d \
./src/Renderer.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/home/bberger/raylib-install/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


