################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP_Program.c \
../main.c 

OBJS += \
./APP_Program.o \
./main.o 

C_DEPS += \
./APP_Program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\aliae\eclipse-workspace\CAR_MC_SLAVE\MCAL\Configrations" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_SLAVE" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_SLAVE\MCAL\DIO" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_SLAVE\MCAL\I2C" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_SLAVE\MCAL\SPI" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_SLAVE\EHAL\EEPROM" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_SLAVE\EHAL\BLUE LED" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_SLAVE\EHAL\GREEN LED" -I"C:\Users\aliae\eclipse-workspace\CAR_MC_SLAVE\EHAL\YELLOW LED" -Wall -g2 -gstabs -O2 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


