################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../EHAL/EEPROM/EEPROM_Program.c 

OBJS += \
./EHAL/EEPROM/EEPROM_Program.o 

C_DEPS += \
./EHAL/EEPROM/EEPROM_Program.d 


# Each subdirectory must supply rules for building sources it contributes
EHAL/EEPROM/%.o: ../EHAL/EEPROM/%.c EHAL/EEPROM/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\aliae\eclipse-workspace\CAR_MC_SLAVE\MCAL\Configrations" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_SLAVE" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_SLAVE\MCAL\DIO" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_SLAVE\MCAL\I2C" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_SLAVE\MCAL\SPI" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_SLAVE\EHAL\EEPROM" -Wall -g2 -gstabs -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


