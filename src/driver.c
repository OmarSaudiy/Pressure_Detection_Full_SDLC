   /*****************************************************************
    *[FILE NAME] 	: driver.c						  				*
    *											  					*
    *[AUTHOR(S)]    : OmarAhmed					  	  				*
    *										        				*
    *[DATE CREATED] : Sep 30, 2023                                  *
    * 										  						*
    *[DECRIPTION]   : SW Drivers 								    *
    *****************************************************************/

#include "Platform_Types.h"
#include "common_macros.h"
#include "driver.h"

int getPressureVal(void){
	return (GPIOA_IDR & 0xFF);
}

void GPIO_INITIALIZATION (void)
{
	SET_BIT(APB2ENR, 2);
	GPIOA_CRL &= 0xFF0FFFFF;
	GPIOA_CRL |= 0x00000000;
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x22222222;
}
