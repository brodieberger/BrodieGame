################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/GameStates/BattleState.cpp \
../src/GameStates/GameStateContext.cpp \
../src/GameStates/OverworldState.cpp 

OBJS += \
./src/GameStates/BattleState.o \
./src/GameStates/GameStateContext.o \
./src/GameStates/OverworldState.o 

CPP_DEPS += \
./src/GameStates/BattleState.d \
./src/GameStates/GameStateContext.d \
./src/GameStates/OverworldState.d 


# Each subdirectory must supply rules for building sources it contributes
src/GameStates/%.o: ../src/GameStates/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I/home/bberger/raylib-install/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


