/*
 * File: IntCtrl_cfg.h
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


#ifndef INTRCTRL_CFG_H_INCLUDED
#define INTRCTRL_CFG_H_INCLUDED

/************************************
 * INCLUDES
 ************************************/
#include "IntCtrl.h"

/************************************
 * GLOBAL CONSTANT MACROS AND DEFINES
 ************************************/
/** Priority groups **/
#define PRIGROUP    PRIGROUP_XXY

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
/* INTRCTRL_CFG_H_INCLUDED */
