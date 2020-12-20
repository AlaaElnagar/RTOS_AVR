################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS_Kernel/Portable/port.c 

OBJS += \
./FreeRTOS_Kernel/Portable/port.o 

C_DEPS += \
./FreeRTOS_Kernel/Portable/port.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS_Kernel/Portable/%.o: ../FreeRTOS_Kernel/Portable/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\Embedded\AVR\AVR_WORKINGSPACE\AVR_FreeRTOS\FreeRTOS_Kernel\Include" -I"E:\Embedded\AVR\AVR_WORKINGSPACE\AVR_FreeRTOS\FreeRTOS_Kernel\Portable" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


