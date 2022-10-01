/*
 * File: GPT_cfg.h
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


#ifndef GPT_CFG_H_INCLUDED
#define GPT_CFG_H_INCLUDED

/************************************
 * INCLUDES
 ************************************/
#include "GPT.h"

/************************************
 * GLOBAL CONSTANT MACROS AND DEFINES
 ************************************/
/** Priority groups **/
/***
 * This indicates the lowest allowed priority
 * Any interrupt with priority lower than this (remember, higher priority means lower number) will be disabled
 * Set to 0x0 to not disable any interrupt
 * */
#define PRIBASE     0x3

/************************************
 * GLOBAL FUNCTION MACROS
 ************************************/

/************************************
 * GLOBAL TYPES
 ************************************/

#endif
/* GPT_CFG_H_INCLUDED */
