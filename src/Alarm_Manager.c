   /*****************************************************************
    *[FILE NAME] 	: Alarm_Manager.c						  		*
    *											  					*
    *[AUTHOR(S)]    : OmarAhmed					  	  				*
    *										        				*
    *[DATE CREATED] : Sep 30, 2023						  			*
    * 										  						*
    *[DECRIPTION]   : Alarm_Manager   								*
    *****************************************************************/

#include "stdio.h"
#include "Platform_Types.h"
#include "common_macros.h"
#include "state.h"
#include "Alarm_Manager.h"

static void make_Delay(int nCount);

/*global Ptr to Function*/   
void (*AM_State)(void);

/*MA Global Variables*/
uint32 AM_speed = 0;
uint32 DC_Motor_State;




STATE_Define(AM_Idle)
{
    /*State ID -> AM_Idle*/
    AM_State_ID = AM_Idle;

    /*Loop Until Receive Alarm_State_ON Signal */
    AM_State = STATE(AM_Idle);
}

STATE_Define(AM_Alarm_ON)
{
    /*State ID -> Check_Distance*/
    AM_State_ID = AM_Alarm_ON;

    Set_Alarm_actuator((int)LOGIC_LOW);
    make_Delay(1000);
    /******************************************************************
    If Alarm_State_ON signal is Received again -> Do the following
        1-reset Timer0
        2-Set Timer0  again for 60sec
        3-Back to AM_Alarm_ON State
    This procedure is useless here because we are not using OS nor ISRs
    the system is sequencetial in superloop
    *******************************************************************/

    /*Timer0 Expiration*/
    Set_Alarm_actuator((int)LOGIC_HIGH);



    /*Back to Idle State*/
    AM_State = STATE(AM_Idle);
}


void Alarm_State_ON(void)
{
     AM_State = STATE(AM_Alarm_ON);
}

static void make_Delay(int nCount)
{
    for(; nCount != 0; nCount--);

}