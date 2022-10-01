/*
 * File: GPT_lcfg.c
 * Created Date: 2022-07-27
 * Author: Mohamed Atef
 * -----
 * Last Modified: Wed Jul 27 2022
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
#include "GPT_Types.h"
#include "GPT.h"
#include "tm4c123gh6pm_hw.h"

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
extern const GPT_ConfigType gptConfig[NUM_TIMER] =
    {
        /* Channel          Value               Prescale            Mode */
        {GPT_CHNL_TIMER0,   500u,               250u,              GPT_CH_MODE_CONTINUOUS},
        {GPT_CHNL_TIMER0,   500u,               250u,              GPT_CH_MODE_CONTINUOUS},
        {GPT_CHNL_TIMER0,   500u,               250u,              GPT_CH_MODE_CONTINUOUS},
        {GPT_CHNL_TIMER0,   500u,               250u,              GPT_CH_MODE_CONTINUOUS},
        {GPT_CHNL_TIMER0,   500u,               250u,              GPT_CH_MODE_CONTINUOUS},
        {GPT_CHNL_TIMER0,   500u,               250u,              GPT_CH_MODE_CONTINUOUS},
        {GPT_CHNL_TIMER0,   500u,               250u,              GPT_CH_MODE_CONTINUOUS},
        {GPT_CHNL_TIMER0,   500u,               250u,              GPT_CH_MODE_CONTINUOUS},
        {GPT_CHNL_TIMER0,   500u,               250u,              GPT_CH_MODE_CONTINUOUS},
        {GPT_CHNL_TIMER0,   500u,               250u,              GPT_CH_MODE_CONTINUOUS},
        {GPT_CHNL_TIMER0,   500u,               250u,              GPT_CH_MODE_CONTINUOUS},
        {GPT_CHNL_TIMER0,   500u,               250u,              GPT_CH_MODE_CONTINUOUS}
    };

/************************************
 * STATIC FUNCTION PROTOTYPES
 ************************************/

/************************************
 * STATIC FUNCTIONS
 ************************************/

/************************************
 * GLOBAL FUNCTIONS
 ************************************/
