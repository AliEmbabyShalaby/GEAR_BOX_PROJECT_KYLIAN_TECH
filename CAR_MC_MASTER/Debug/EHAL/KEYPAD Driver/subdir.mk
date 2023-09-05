################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../EHAL/KEYPAD\ Driver/KEYPAD_Program.c 

OBJS += \
./EHAL/KEYPAD\ Driver/KEYPAD_Program.o 

C_DEPS += \
./EHAL/KEYPAD\ Driver/KEYPAD_Program.d 


# Each subdirectory must supply rules for building sources it contributes
EHAL/KEYPAD\ Driver/KEYPAD_Program.o: ../EHAL/KEYPAD\ Driver/KEYPAD_Program.c EHAL/KEYPAD\ Driver/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\aliae\eclipse-workspace\CAR_MC_MASTER\MCAL\Configrations" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_MASTER\MCAL\DIO" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_MASTER\MCAL\ADC" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_MASTER\MCAL\SPI" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_MASTER\MCAL\SPI" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_MASTER\MCAL\USART" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_MASTER\EHAL\KEYPAD Driver" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_MASTER\EHAL\Buzzer" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_MASTER\EHAL\BLUE LED" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_MASTER\EHAL\GREEN LED" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_MASTER\EHAL\LCD_4x20" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_MASTER\EHAL\YELLOW LED" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_MASTER\EHAL\Potentiometer\Engine_Limit_Sensor" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_MASTER\EHAL\Potentiometer\Engine_Sensor" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_MASTER\APPLICATION" -Wall -g2 -gstabs -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"EHAL/KEYPAD Driver/KEYPAD_Program.d" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


