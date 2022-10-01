/*
 * File: IntCtrl_Types.h
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

#ifndef INTRCTRL_TYPES_H_INCLUDED
#define INTRCTRL_TYPES_H_INCLUDED

/************************************
 * INCLUDES
 ************************************/
 #include "Std_Types.h"

/************************************
 * GLOBAL CONSTANT MACROS AND DEFINES
 ************************************/

/************************************
 * GLOBAL FUNCTION MACROS
 ************************************/

/************************************
 * GLOBAL TYPES
 ************************************/
typedef enum IntCtrl_IntEnableType {DISABLE, ENABLE} IntCtrl_IntEnableType;
typedef uint8 IntCtrl_GroupPriType;
typedef uint8 IntCtrl_SubGroupPriType;
 
typedef struct
{
    IntCtrl_IntEnableType gate;
    IntCtrl_GroupPriType groupPriority;
    IntCtrl_SubGroupPriType subGroupPriority;
} IntCtrl_InterruptType;

enum
{
    INTR_GPIO_A,
    INTR_GPIO_B,
    INTR_GPIO_C,
    INTR_GPIO_D,
    INTR_GPIO_E,
    INTR_UART0,
    INTR_UART1,
    INTR_SSI0,
    INTR_I2C,
    INTR_PWM0_FAULT,
    INTR_PWM0_GEN0,
    INTR_PWM0_GEN1,
    INTR_PWM0_GEN2
};

/************************************
 * GLOBAL DATA PROTOTYPES
 ************************************/

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/

/************************************
 * EXTERNAL VARIABLES
 ************************************/

#endif
/* INTRCTRL_TYPES_H_INCLUDED */
