   /*****************************************************************
    *[FILE NAME] 	: main.c						  				*
    *											  					*
    *[AUTHOR(S)]    : OmarAhmed					  	  				*
    *										        				*
    *[DATE CREATED] : Sep 30, 2023                                  *
    * 										  						*
    *[DECRIPTION]   : Main		 								    *
    *****************************************************************/

#include "Platform_Types.h"
#include "common_macros.h"
#include "state.h"
#include "driver.h"
#include "Pressure_Sensor_Driver.h"
#include "Main_Algorithm.h"
#include "Alarm_Manager.h"
#include "Alarm_Driver.h"


void setup(void);


int main (){
	GPIO_INITIALIZATION();
    setup();

	while (1)
	{
	    PSD_State();
        MA_State();
        AM_State();
        AD_State();
	}

}

void setup(void)
{
    AD_State = STATE(AD_init);
    PSD_State = STATE(PSD_init);
    MA_State = STATE(MA_Idle);
    AM_State = STATE(AM_Idle);
}