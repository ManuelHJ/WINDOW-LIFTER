################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../src/LEDS_IDLE.c" \
"../src/Mode_Routine.c" \
"../src/clocks_and_modes.c" \
"../src/initproyect.c" \
"../src/main.c" \
"../src/time100ms.c" \
"../src/time400ms.c" \

C_SRCS += \
../src/LEDS_IDLE.c \
../src/Mode_Routine.c \
../src/clocks_and_modes.c \
../src/initproyect.c \
../src/main.c \
../src/time100ms.c \
../src/time400ms.c \

OBJS_OS_FORMAT += \
./src/LEDS_IDLE.o \
./src/Mode_Routine.o \
./src/clocks_and_modes.o \
./src/initproyect.o \
./src/main.o \
./src/time100ms.o \
./src/time400ms.o \

C_DEPS_QUOTED += \
"./src/LEDS_IDLE.d" \
"./src/Mode_Routine.d" \
"./src/clocks_and_modes.d" \
"./src/initproyect.d" \
"./src/main.d" \
"./src/time100ms.d" \
"./src/time400ms.d" \

OBJS += \
./src/LEDS_IDLE.o \
./src/Mode_Routine.o \
./src/clocks_and_modes.o \
./src/initproyect.o \
./src/main.o \
./src/time100ms.o \
./src/time400ms.o \

OBJS_QUOTED += \
"./src/LEDS_IDLE.o" \
"./src/Mode_Routine.o" \
"./src/clocks_and_modes.o" \
"./src/initproyect.o" \
"./src/main.o" \
"./src/time100ms.o" \
"./src/time400ms.o" \

C_DEPS += \
./src/LEDS_IDLE.d \
./src/Mode_Routine.d \
./src/clocks_and_modes.d \
./src/initproyect.d \
./src/main.d \
./src/time100ms.d \
./src/time400ms.d \


# Each subdirectory must supply rules for building sources it contributes
src/LEDS_IDLE.o: ../src/LEDS_IDLE.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/LEDS_IDLE.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/LEDS_IDLE.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Mode_Routine.o: ../src/Mode_Routine.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/Mode_Routine.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/Mode_Routine.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/clocks_and_modes.o: ../src/clocks_and_modes.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/clocks_and_modes.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/clocks_and_modes.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/initproyect.o: ../src/initproyect.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/initproyect.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/initproyect.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/main.o: ../src/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/main.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/time100ms.o: ../src/time100ms.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/time100ms.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/time100ms.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/time400ms.o: ../src/time400ms.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/time400ms.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/time400ms.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


