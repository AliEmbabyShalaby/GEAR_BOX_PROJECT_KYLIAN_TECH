################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../EHAL/BLUE\ LED/BLUE_LED_Interface.c 

OBJS += \
./EHAL/BLUE\ LED/BLUE_LED_Interface.o 

C_DEPS += \
./EHAL/BLUE\ LED/BLUE_LED_Interface.d 


# Each subdirectory must supply rules for building sources it contributes
EHAL/BLUE\ LED/BLUE_LED_Interface.o: ../EHAL/BLUE\ LED/BLUE_LED_Interface.c EHAL/BLUE\ LED/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\aliae\eclipse-workspace\CAR_MC_MASTER\MCAL\Configrations" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_MASTER\MCAL\DIO" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_MASTER\MCAL\ADC" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_MASTER\MCAL\SPI" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_MASTER\MCAL\SPI" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_MASTER\MCAL\USART" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_MASTER\EHAL\KEYPAD Driver" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_MASTER\EHAL\Buzzer" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_MASTER\EHAL\BLUE LED" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_MASTER\EHAL\GREEN LED" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_MASTER\EHAL\LCD_4x20" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_MASTER\EHAL\Potentiometer" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_MASTER\EHAL\YELLOW LED" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_MASTER\APPLICATION" -Wall -g2 -gstabs -O1 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"EHAL/BLUE LED/BLUE_LED_Interface.d" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


