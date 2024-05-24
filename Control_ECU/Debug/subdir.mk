################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Buzzer.c \
../Control_main.c \
../DC_MOTOR.c \
../External_EEPROM.c \
../GPI0.c \
../TIMER1.c \
../TWI.c \
../Timer0.c \
../UART.c 

OBJS += \
./Buzzer.o \
./Control_main.o \
./DC_MOTOR.o \
./External_EEPROM.o \
./GPI0.o \
./TIMER1.o \
./TWI.o \
./Timer0.o \
./UART.o 

C_DEPS += \
./Buzzer.d \
./Control_main.d \
./DC_MOTOR.d \
./External_EEPROM.d \
./GPI0.d \
./TIMER1.d \
./TWI.d \
./Timer0.d \
./UART.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


