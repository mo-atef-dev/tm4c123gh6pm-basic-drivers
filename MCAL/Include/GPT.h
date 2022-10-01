/*
 * File: GPT.h
 * Created Date: 2022-07-26
 * Author: Mohamed Atef
 * -----
 * Last Modified: Tue Jul 26 2022
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


#ifndef GPT_H_INCLUDED
#define GPT_H_INCLUDED

/************************************
 * INCLUDES
 ************************************/
#include "Std_Types.h"
#include "GPT_Types.h"
#include "tm4c123gh6pm_hw.h"

/************************************
 * GLOBAL CONSTANT MACROS AND DEFINES
 ************************************/

/************************************
 * GLOBAL FUNCTION MACROS
 ************************************/

/************************************
 * GLOBAL TYPES
 ************************************/

/************************************
 * GLOBAL DATA PROTOTYPES
 ************************************/
extern const GPT_ConfigType gptConfig[NUM_TIMER];

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/
void GPT_Init();
void GPT_StartTimer(const GPT_ChannelType gptChannelid, const GPT_ValueType value);
void GPT_EnableNotification(void (*fun_ptr)(void), GPT_ChannelType gptChannelid);

/************************************
 * EXTERNAL VARIABLES
 ************************************/

#endif
/* GPT_H_INCLUDED */
