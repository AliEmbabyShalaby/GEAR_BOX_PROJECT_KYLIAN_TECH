################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP_Interface.c \
../main.c 

OBJS += \
./APP_Interface.o \
./main.o 

C_DEPS += \
./APP_Interface.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\aliae\eclipse-workspace\CAR_MC_SLAVE\MCAL\Configrations" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_SLAVE" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_SLAVE\MCAL\DIO" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_SLAVE\MCAL\I2C" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_SLAVE\MCAL\SPI" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_SLAVE\EHAL\EEPROM" -Wall -g2 -gstabs -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


