/*
 * File: IntCtrl.h
 * Created Date: 2022-07-05
 * Author: Mohamed Atef
 * -----
 * Last Modified: Tue Jul 12 2022
 * Modified By: Mohamed Atef
 * -----
 * Copyright (c) 2022
 * -----
 * HISTORY:
 * Date      	By	Comments
 * ----------	---	---------------------------------------------------------
 */


#ifndef INTRCTRL_H_INCLUDED
#define INTRCTRL_H_INCLUDED

/************************************
 * INCLUDES
 ************************************/
#include "tm4c123gh6pm_hw.h"
#include "Bit_Op.h"
#include "IntCtrl_Types.h"

/************************************
 * GLOBAL CONSTANT MACROS AND DEFINES
 ************************************/
#define PRIGROUP_XXX    0x00u
#define PRIGROUP_XXY    0x05u
#define PRIGROUP_XYY    0x06u
#define PRIGROUP_YYY    0x07u

/************************************
 * GLOBAL FUNCTION MACROS
 ************************************/

/************************************
 * GLOBAL TYPES
 ************************************/

/************************************
 * GLOBAL DATA PROTOTYPES
 ************************************/

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/
void IntCtrl_Init(void);

/************************************
 * EXTERNAL VARIABLES
 ************************************/
extern IntCtrl_InterruptType interrupt_GPIO_A;
extern IntCtrl_InterruptType interrupt_GPIO_B;
extern IntCtrl_InterruptType interrupt_GPIO_C;
extern IntCtrl_InterruptType interrupt_GPIO_D;
extern IntCtrl_InterruptType interrupt_GPIO_E;

extern IntCtrl_InterruptType interrupt_UART0;
extern IntCtrl_InterruptType interrupt_UART1;
extern IntCtrl_InterruptType interrupt_SSI0;
extern IntCtrl_InterruptType interrupt_I2C;

extern IntCtrl_InterruptType interrupt_PWM0_FAULT;
extern IntCtrl_InterruptType interrupt_PWM0_GEN0;
extern IntCtrl_InterruptType interrupt_PWM0_GEN1;
extern IntCtrl_InterruptType interrupt_PWM0_GEN2;
extern IntCtrl_InterruptType interrupt_QEI0;

extern IntCtrl_InterruptType interrupt_ADC0_SEQ0;
extern IntCtrl_InterruptType interrupt_ADC0_SEQ1;
extern IntCtrl_InterruptType interrupt_ADC0_SEQ2;
extern IntCtrl_InterruptType interrupt_ADC0_SEQ3;

extern IntCtrl_InterruptType interrupt_GPT0_A;

#endif
/* INTRCTRL_H_INCLUDED */
