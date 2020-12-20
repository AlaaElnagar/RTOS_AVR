################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS_Kernel/croutine.c \
../FreeRTOS_Kernel/event_groups.c \
../FreeRTOS_Kernel/heap_1.c \
../FreeRTOS_Kernel/list.c \
../FreeRTOS_Kernel/queue.c \
../FreeRTOS_Kernel/stream_buffer.c \
../FreeRTOS_Kernel/tasks.c \
../FreeRTOS_Kernel/timers.c 

OBJS += \
./FreeRTOS_Kernel/croutine.o \
./FreeRTOS_Kernel/event_groups.o \
./FreeRTOS_Kernel/heap_1.o \
./FreeRTOS_Kernel/list.o \
./FreeRTOS_Kernel/queue.o \
./FreeRTOS_Kernel/stream_buffer.o \
./FreeRTOS_Kernel/tasks.o \
./FreeRTOS_Kernel/timers.o 

C_DEPS += \
./FreeRTOS_Kernel/croutine.d \
./FreeRTOS_Kernel/event_groups.d \
./FreeRTOS_Kernel/heap_1.d \
./FreeRTOS_Kernel/list.d \
./FreeRTOS_Kernel/queue.d \
./FreeRTOS_Kernel/stream_buffer.d \
./FreeRTOS_Kernel/tasks.d \
./FreeRTOS_Kernel/timers.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS_Kernel/%.o: ../FreeRTOS_Kernel/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\Embedded\AVR\AVR_WORKINGSPACE\AVR_FreeRTOS\FreeRTOS_Kernel\Include" -I"E:\Embedded\AVR\AVR_WORKINGSPACE\AVR_FreeRTOS\FreeRTOS_Kernel\Portable" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


