################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/factory/EnemyFactory.cpp \
../src/factory/PlayerFactory.cpp 

OBJS += \
./src/factory/EnemyFactory.o \
./src/factory/PlayerFactory.o 

CPP_DEPS += \
./src/factory/EnemyFactory.d \
./src/factory/PlayerFactory.d 


# Each subdirectory must supply rules for building sources it contributes
src/factory/%.o: ../src/factory/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/home/bberger/raylib-install/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


