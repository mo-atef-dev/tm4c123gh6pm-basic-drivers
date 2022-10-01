/*
 * File: Port_Types.h
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


#ifndef PORT_TYPES_H_INCLUDED
#define PORT_TYPES_H_INCLUDED

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
    PORT_A,
    PORT_B,
    PORT_C,
    PORT_D,
    PORT_E,
    PORT_F
} Port_PortType;

typedef enum
{
    PIN_NC = -1, /* Sentinel value to detect an unvalid pin */

    PIN_A0 = 0,
    PIN_A1 = 1,
    PIN_A2 = 2,
    PIN_A3 = 3,
    PIN_A4 = 4,
    PIN_A5 = 5,
    PIN_A6 = 6,
    PIN_A7 = 7,

    PIN_B0 = 8,
    PIN_B1 = 9,
    PIN_B2 = 10,
    PIN_B3 = 11,
    PIN_B4 = 12,
    PIN_B5 = 13,
    PIN_B6 = 14,
    PIN_B7 = 15,

    PIN_C0 = 16,
    PIN_C1 = 17,
    PIN_C2 = 18,
    PIN_C3 = 19,
    PIN_C4 = 20,
    PIN_C5 = 21,
    PIN_C6 = 22,
    PIN_C7 = 23,

    PIN_F0 = 40,
    PIN_F1 = 41,
    PIN_F2 = 42,
    PIN_F3 = 43,
    PIN_F4 = 44
} Port_PinType;

typedef enum
{
    PIN_OUTPUT,
    PIN_INPUT
} Port_PinDirectionType;

typedef enum
{
    PIN_DIO,
    PIN_DIO_INTERRUPT
} Port_PinDModeType;

typedef enum
{
    PIN_OPENDRAIN,
    PIN_PULLUP,
    PIN_PULLDOWN
} Port_PiInternalAttachType;

typedef enum
{
    PIN_CURRENT_2mA,
    PIN_CURRENT_4mA,
    PIN_CURRENT_8mA
} Port_PinOutputCurrentType;

typedef struct
{
    Port_PinType pin;
    Port_PinDirectionType direction;
    Port_PinDModeType mode;
    Port_PiInternalAttachType internalAttach;
    Port_PinOutputCurrentType outputCurrent;
} Port_ConfigType;


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
/* PORT_TYPES_H_INCLUDED */
