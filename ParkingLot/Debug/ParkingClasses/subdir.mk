################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ParkingClasses/Bus.cpp \
../ParkingClasses/Car.cpp \
../ParkingClasses/Motorcycle.cpp \
../ParkingClasses/ParkingGarageOverview.cpp \
../ParkingClasses/ParkingLot.cpp \
../ParkingClasses/Runner.cpp \
../ParkingClasses/Vehicle.cpp 

OBJS += \
./ParkingClasses/Bus.o \
./ParkingClasses/Car.o \
./ParkingClasses/Motorcycle.o \
./ParkingClasses/ParkingGarageOverview.o \
./ParkingClasses/ParkingLot.o \
./ParkingClasses/Runner.o \
./ParkingClasses/Vehicle.o 

CPP_DEPS += \
./ParkingClasses/Bus.d \
./ParkingClasses/Car.d \
./ParkingClasses/Motorcycle.d \
./ParkingClasses/ParkingGarageOverview.d \
./ParkingClasses/ParkingLot.d \
./ParkingClasses/Runner.d \
./ParkingClasses/Vehicle.d 


# Each subdirectory must supply rules for building sources it contributes
ParkingClasses/%.o: ../ParkingClasses/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


