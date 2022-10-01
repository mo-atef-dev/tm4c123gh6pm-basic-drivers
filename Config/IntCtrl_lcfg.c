/*
 * File: IntCtrl_lcfg.c
 * Created Date: 2022-07-05
 * Author: Mohamed Atef
 * -----
 * Last Modified: Fri Jul 15 2022
 * Modified By: Mohamed Atef
 * -----
 * Copyright (c) 2022
 * -----
 * Description:
 * -----
 * HISTORY:
 * Date      	By	Comments
 * ----------	---	---------------------------------------------------------
 */

/************************************
 * INCLUDES
 ************************************/
#include "IntCtrl_Types.h"
#include "IntCtrl.h"
#include "tm4c123gh6pm_hw.h"

/************************************
 * EXTERN VARIABLES
 ************************************/
 
 /* Each variable represents an interrupt
    To set the atributes of any interrupts use:
    interrupt_NAME = {ENABLE/DISABLE, GROUP PRIORITY, SUB-GROUP PRIORITY};*/
    
IntCtrl_InterruptType interrupt_GPIO_A = {DISABLE, 3, 1};
IntCtrl_InterruptType interrupt_GPIO_B = {DISABLE, 2, 0};
IntCtrl_InterruptType interrupt_GPIO_C = {DISABLE, 1, 1};
IntCtrl_InterruptType interrupt_GPIO_D = {DISABLE, 0, 0};
IntCtrl_InterruptType interrupt_GPIO_E = {DISABLE, 0, 0};

IntCtrl_InterruptType interrupt_UART0 = {ENABLE, 7, 0};
IntCtrl_InterruptType interrupt_UART1 = {ENABLE, 7, 0};
IntCtrl_InterruptType interrupt_SSI0 = {ENABLE, 7, 0};
IntCtrl_InterruptType interrupt_I2C = {ENABLE, 7, 0};

IntCtrl_InterruptType interrupt_PWM0_FAULT = {ENABLE, 7, 0};
IntCtrl_InterruptType interrupt_PWM0_GEN0 = {ENABLE, 7, 0};
IntCtrl_InterruptType interrupt_PWM0_GEN1 = {ENABLE, 7, 0};
IntCtrl_InterruptType interrupt_PWM0_GEN2 = {ENABLE, 7, 0};
IntCtrl_InterruptType interrupt_QEI0 = {ENABLE, 7, 0};

IntCtrl_InterruptType interrupt_ADC0_SEQ0 = {ENABLE, 7, 0};
IntCtrl_InterruptType interrupt_ADC0_SEQ1 = {ENABLE, 7, 0};
IntCtrl_InterruptType interrupt_ADC0_SEQ2 = {ENABLE, 7, 0};
IntCtrl_InterruptType interrupt_ADC0_SEQ3 = {ENABLE, 7, 0};

IntCtrl_InterruptType interrupt_GPT0_A = {ENABLE, 0, 0};

/************************************
 * PRIVATE MACROS AND DEFINES
 ************************************/

/************************************
 * PRIVATE TYPEDEFS
 ************************************/

/************************************
 * STATIC VARIABLES
 ************************************/

/************************************
 * GLOBAL VARIABLES
 ************************************/

/************************************
 * STATIC FUNCTION PROTOTYPES
 ************************************/

/************************************
 * STATIC FUNCTIONS
 ************************************/

/************************************
 * GLOBAL FUNCTIONS
 ************************************/
