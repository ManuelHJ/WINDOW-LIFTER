################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../src/HAL/CLOCKS.c" \
"../src/HAL/Inputs_Outputs.c" \
"../src/HAL/TIMERS.c" \
"../src/HAL/WDOG.c" \

C_SRCS += \
../src/HAL/CLOCKS.c \
../src/HAL/Inputs_Outputs.c \
../src/HAL/TIMERS.c \
../src/HAL/WDOG.c \

OBJS_OS_FORMAT += \
./src/HAL/CLOCKS.o \
./src/HAL/Inputs_Outputs.o \
./src/HAL/TIMERS.o \
./src/HAL/WDOG.o \

C_DEPS_QUOTED += \
"./src/HAL/CLOCKS.d" \
"./src/HAL/Inputs_Outputs.d" \
"./src/HAL/TIMERS.d" \
"./src/HAL/WDOG.d" \

OBJS += \
./src/HAL/CLOCKS.o \
./src/HAL/Inputs_Outputs.o \
./src/HAL/TIMERS.o \
./src/HAL/WDOG.o \

OBJS_QUOTED += \
"./src/HAL/CLOCKS.o" \
"./src/HAL/Inputs_Outputs.o" \
"./src/HAL/TIMERS.o" \
"./src/HAL/WDOG.o" \

C_DEPS += \
./src/HAL/CLOCKS.d \
./src/HAL/Inputs_Outputs.d \
./src/HAL/TIMERS.d \
./src/HAL/WDOG.d \


# Each subdirectory must supply rules for building sources it contributes
src/HAL/CLOCKS.o: ../src/HAL/CLOCKS.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/HAL/CLOCKS.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/HAL/CLOCKS.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/HAL/Inputs_Outputs.o: ../src/HAL/Inputs_Outputs.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/HAL/Inputs_Outputs.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/HAL/Inputs_Outputs.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/HAL/TIMERS.o: ../src/HAL/TIMERS.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/HAL/TIMERS.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/HAL/TIMERS.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/HAL/WDOG.o: ../src/HAL/WDOG.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/HAL/WDOG.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/HAL/WDOG.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


