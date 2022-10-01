/*
 * File: GPT_Types.h
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


#ifndef GPT_TYPES_H_INCLUDED
#define GPT_TYPES_H_INCLUDED

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
typedef enum
{
    GPT_MODE_NORMAL,
    GPT_MODE_SLEEP
} GPT_ModeType;

typedef enum
{
    GPT_CH_MODE_CONTINUOUS,
    GPT_CH_MODE_ONESHOT
} GPT_ChannelModeType;

typedef enum
{
    GPT_CHNL_TIMER0,
    GPT_CHNL_TIMER1,
    GPT_CHNL_TIMER2,
    GPT_CHNL_TIMER3,
    GPT_CHNL_TIMER4,
    GPT_CHNL_TIMER5,
    GPWT_CHNL_TIMER0,
    GPWT_CHNL_TIMER1,
    GPWT_CHNL_TIMER2,
    GPWT_CHNL_TIMER3,
    GPWT_CHNL_TIMER4,
    GPWT_CHNL_TIMER5
} GPT_ChannelType;

typedef enum
{
    GPT_PREDEF_TIMER_1US_16BIT,
    GPT_PREDEF_TIMER_1US_24BIT,
    GPT_PREDEF_TIMER_1US_32BIT,
    GPT_PREDEF_TIMER_100US_32BIT
} GPT_PredefTimerType;

typedef uint32 GPT_ValueType;

typedef uint8 GPT_PrescaleType;

typedef struct
{
    GPT_ChannelType gptChannelid;
    GPT_ValueType value;
    GPT_PrescaleType prescaler;
    GPT_ChannelModeType channelMode;
} GPT_ConfigType;

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
/* GPT_TYPES_H_INCLUDED */
