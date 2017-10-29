################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../src/APP/Window_Lifter_Routine.c" \

C_SRCS += \
../src/APP/Window_Lifter_Routine.c \

OBJS_OS_FORMAT += \
./src/APP/Window_Lifter_Routine.o \

C_DEPS_QUOTED += \
"./src/APP/Window_Lifter_Routine.d" \

OBJS += \
./src/APP/Window_Lifter_Routine.o \

OBJS_QUOTED += \
"./src/APP/Window_Lifter_Routine.o" \

C_DEPS += \
./src/APP/Window_Lifter_Routine.d \


# Each subdirectory must supply rules for building sources it contributes
src/APP/Window_Lifter_Routine.o: ../src/APP/Window_Lifter_Routine.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/APP/Window_Lifter_Routine.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "src/APP/Window_Lifter_Routine.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


