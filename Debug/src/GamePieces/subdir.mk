################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/GamePieces/GamePiece.cpp \
../src/GamePieces/Player.cpp \
../src/GamePieces/Zombie.cpp 

OBJS += \
./src/GamePieces/GamePiece.o \
./src/GamePieces/Player.o \
./src/GamePieces/Zombie.o 

CPP_DEPS += \
./src/GamePieces/GamePiece.d \
./src/GamePieces/Player.d \
./src/GamePieces/Zombie.d 


# Each subdirectory must supply rules for building sources it contributes
src/GamePieces/%.o: ../src/GamePieces/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/home/bberger/raylib-install/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


