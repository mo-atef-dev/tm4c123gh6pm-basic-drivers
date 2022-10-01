/*
 * File: RCC.h
 * Created Date: 2022-07-18
 * Author: Mohamed Atef
 * -----
 * Last Modified: Mon Jul 18 2022
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


#ifndef RCC_H_INCLUDED
#define RCC_H_INCLUDED

/************************************
 * INCLUDES
 ************************************/
#include "tm4c123gh6pm_hw.h"
#include "Bit_Op.h"

/************************************
 * GLOBAL CONSTANT MACROS AND DEFINES
 ************************************/
#define RCC_OSC_SOURCE_MOSC         0x00u
#define RCC_OSC_SOURCE_PIOSC        0x01u
#define RCC_OSC_SOURCE_PIOSCdiv4    0x02u
#define RCC_OSC_SOURCE_LFIOSC       0x03u
#define RCC_OSC_SOURCE_32KHOSC      0x07u

#define RCC_DIV_SYSCLK_BY_1     0x00u
#define RCC_DIV_SYSCLK_BY_2     0x01u
#define RCC_DIV_SYSCLK_BY_3     0x02u
#define RCC_DIV_SYSCLK_BY_4     0x03u
#define RCC_DIV_SYSCLK_BY_5     0x04u
#define RCC_DIV_SYSCLK_BY_6     0x05u
#define RCC_DIV_SYSCLK_BY_7     0x06u
#define RCC_DIV_SYSCLK_BY_8     0x07u
#define RCC_DIV_SYSCLK_BY_9     0x08u
#define RCC_DIV_SYSCLK_BY_10    0x09u
#define RCC_DIV_SYSCLK_BY_11    0x0Au
#define RCC_DIV_SYSCLK_BY_12    0x0Bu
#define RCC_DIV_SYSCLK_BY_13    0x0Cu
#define RCC_DIV_SYSCLK_BY_14    0x0Du
#define RCC_DIV_SYSCLK_BY_15    0x0Eu
#define RCC_DIV_SYSCLK_BY_16    0x0Fu

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
void RCC_Init(void);
void RCC_SetOSCSource(uint8 oscSource, uint8 usePLL, uint8 sysClkDiv);

/************************************
 * EXTERNAL VARIABLES
 ************************************/

#endif
/* RCC_H_INCLUDED */
