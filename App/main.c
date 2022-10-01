#include "tm4c123gh6pm_hw.h"
#include "Bit_Op.h"
#include "IntCtrl.h"
#include "RCC.h"
#include "Port.h"
#include "DIO.h"
#include "GPT.h"

#define DEBOUNCE_LIMIT	100u
#define TINCREMENT	10u

#define PIN_LED		PIN_F3
#define PIN_INC_ON	PIN_F4
#define PIN_INC_OFF	PIN_F0

uint32 ms_counter = 0;

uint32 t_on = 20u;
uint32 t_off = 30u;

void TimerLed(void);

void TimerLed(void)
{
	if(ms_counter < t_on)
	{
		DIO_WriteChannel(PIN_LED, HIGH);
	}
	else
	{
		DIO_WriteChannel(PIN_LED, LOW);
	}
	
	ms_counter++;
	
	if(ms_counter >= (t_on + t_off))
	{
		ms_counter = 0;
	}
}

int main()
{  
	/* RCC initialization */
	RCC_Init();
	
	/* Port initialization */
	Port_Init();
	
	/* Timer initialization */
	GPT_Init();
	GPT_EnableNotification(TimerLed, GPT_CHNL_TIMER0);
	GPT_StartTimer(GPT_CHNL_TIMER0, 264u);
	
	/* Interrupt Initialization */
	IntCtrl_Init();
	
	/* Debouncing counters */
	uint8 debounce1 = 0;
	uint8 debounce2 = 0;
	
	/* Button states */
	uint8 sw1_prevstate = 0;
	uint8 sw2_prevstate = 0;
    
	while(1)
    {	
		/* Poll for user input */
		if(DIO_ReadChannel(PIN_INC_ON) == LOW)
		{
			debounce1++;
			if((debounce1 > DEBOUNCE_LIMIT) && (sw1_prevstate == 0))
			{
				debounce1 = 0;
				sw1_prevstate = 1;
				
				if(t_off >= TINCREMENT)
				{
					t_on += TINCREMENT;
					t_off -= TINCREMENT;
				}
			}
		}
		else
		{
			debounce1 = 0;
			sw1_prevstate = 0;
		}
		
		if(DIO_ReadChannel(PIN_INC_OFF) == LOW)
		{
			debounce2++;
			if((debounce2 > DEBOUNCE_LIMIT) && (sw2_prevstate == 0))
			{
				debounce2 = 0;
				sw2_prevstate = 1;
				
				if(t_on >= TINCREMENT)
				{
					t_on -= TINCREMENT;
					t_off += TINCREMENT;
				}
			}
		}
		else
		{
			debounce2 = 0;
			sw2_prevstate = 0;
		}
    }
}
