################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Ant.cpp \
../src/AntsAndDoodles.cpp \
../src/Cell.cpp \
../src/Doodlebug.cpp \
../src/Grid.cpp \
../src/Organism.cpp \
../src/Production.cpp \
../src/Tests2.cpp 

OBJS += \
./src/Ant.o \
./src/AntsAndDoodles.o \
./src/Cell.o \
./src/Doodlebug.o \
./src/Grid.o \
./src/Organism.o \
./src/Production.o \
./src/Tests2.o 

CPP_DEPS += \
./src/Ant.d \
./src/AntsAndDoodles.d \
./src/Cell.d \
./src/Doodlebug.d \
./src/Grid.d \
./src/Organism.d \
./src/Production.d \
./src/Tests2.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


