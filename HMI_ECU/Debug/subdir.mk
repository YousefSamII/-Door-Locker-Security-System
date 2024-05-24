################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GPI0.c \
../HMI_main.c \
../LCD.c \
../TIMER1.c \
../UART.c \
../keypad.c 

OBJS += \
./GPI0.o \
./HMI_main.o \
./LCD.o \
./TIMER1.o \
./UART.o \
./keypad.o 

C_DEPS += \
./GPI0.d \
./HMI_main.d \
./LCD.d \
./TIMER1.d \
./UART.d \
./keypad.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


