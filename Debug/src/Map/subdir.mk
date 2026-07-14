################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Map/Grid.cpp \
../src/Map/Tile.cpp 

OBJS += \
./src/Map/Grid.o \
./src/Map/Tile.o 

CPP_DEPS += \
./src/Map/Grid.d \
./src/Map/Tile.d 


# Each subdirectory must supply rules for building sources it contributes
src/Map/%.o: ../src/Map/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/home/bberger/raylib-install/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


