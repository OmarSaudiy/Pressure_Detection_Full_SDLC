   /*****************************************************************
    *[FILE NAME] 	: Main_Algorithm.c						  		*
    *											  					*
    *[AUTHOR(S)]    : OmarAhmed					  	  				*
    *										        				*
    *[DATE CREATED] : Sep 30, 2023						  			*
    * 										  						*
    *[DECRIPTION]   : Main_Algorithm   								*
    *****************************************************************/
#include "stdio.h"
#include "Platform_Types.h"
#include "state.h"
#include "Main_Algorithm.h"

/*global Ptr to Function*/   
void (*MA_State)(void);

/*MA Global Variables*/
uint32 MA_PressureVal = 0;

STATE_Define(MA_Idle)
{
    /*State ID -> MA_Idle*/
    MA_State_ID = MA_Idle;

    /*Loop Until Receive sendPressureVal Signal */
    MA_State = STATE(MA_Idle);
}


STATE_Define(MA_Check_Pressure)
{
    /*State ID -> MA_Check_Pressure*/
    MA_State_ID = MA_Check_Pressure;

    /*MA Local Variables*/
    uint32 threshold = 20;

    /*Check Distance*/
    if(MA_PressureVal > threshold)
        Alarm_State_ON();

    /****************************************************
     * The System Shall                                 *
     * (Optionally) Store PressureVal in Flash Memory   *
     * To  be Implemented in Version  2.2023            *
     ****************************************************/



    /*Back to Idle State*/
    MA_State = STATE(MA_Idle);
}

void sendPressureVal(int PressureVal)
{
    MA_PressureVal = PressureVal;
    MA_State = STATE(MA_Check_Pressure);
}