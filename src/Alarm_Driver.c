   /*****************************************************************
    *[FILE NADE] 	: Alarm_Driver.c						  		*
    *											  					*
    *[AUTHOR(S)]    : OmarAhmed					  	  				*
    *										        				*
    *[DATE CREATED] : Sep 30, 2023                                  *
    * 										  						*
    *[DECRIPTION]   : Alarm_Driver   								*
    *****************************************************************/

#include "Platform_Types.h"
#include "common_macros.h"
#include "state.h"
#include "driver.h"
#include "Alarm_Driver.h"

/*global Ptr to Function*/   
void (*AD_State)(void);

/*AD Private Functions */
void Set_Alarm_actuator(int i);

STATE_Define(AD_init)
{
    /*State ID -> AD_idle*/
    AD_State_ID = AD_init;

    /*Initialize GPIO Pins*/
    SET_BIT(GPIOA_ODR,13);
    

    /*go to AD_idle State*/
    AD_State = STATE(AD_idle);
}

STATE_Define(AD_idle)
{
    /*State ID -> AD_idle*/
    AD_State_ID = AD_idle;



    /*Loop Until Receive Set_Alarm_actuator Signal */
    AD_State = STATE(AD_idle);
}

STATE_Define(AD_Receive_CMD)
{
    /*State ID -> AD_idle*/
    AD_State_ID = AD_idle;

    /*go to AD_idle State*/
    AD_State = STATE(AD_idle);
}


void Set_Alarm_actuator(int i)
{
    if (i == 1)
        SET_BIT(GPIOA_ODR,13);
    
    else if (i == 0)
        CLEAR_BIT(GPIOA_ODR,13);
    
    AD_State = STATE(AD_Receive_CMD);
}

