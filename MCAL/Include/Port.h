/*
 * File: Port.h
 * Created Date: 2022-07-19
 * Author: Mohamed Atef
 * -----
 * Last Modified: Tue Jul 19 2022
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


#ifndef PORT_H_INCLUDED
#define PORT_H_INCLUDED

/************************************
 * INCLUDES
 ************************************/
#include "Std_Types.h"
#include "Port_Types.h"
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
extern const Port_ConfigType portConfig[NUM_PINS];

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/
void Port_EnablePortClock(Port_PortType port);
void Port_Init();

/************************************
 * EXTERNAL VARIABLES
 ************************************/

#endif
/* PORT_H_INCLUDED */
