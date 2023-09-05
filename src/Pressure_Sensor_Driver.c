   /*****************************************************************
    *[FILE NAME]    : Pressure_Sensor_Driver.c                      *
    *                                                               *
    *[AUTHOR(S)]    : OmarAhmed                                     *
    *                                                               *
    *[DATE CREATED] : Sep 30, 2023                                  *
    *                                                               *
    *[DECRIPTION]   : Pressure_Sensor_Driver                        *
    *****************************************************************/

#include "stdio.h"
#include "Platform_Types.h"
#include "common_macros.h"
#include "state.h"
#include "driver.h"
#include "Pressure_Sensor_Driver.h"

/*global Ptr to Function*/   
void(*PSD_State)(void);

/*PSD Global Variables*/



STATE_Define(PSD_init)
{
    /*State ID -> PSD_init*/
    PSD_State_ID = PSD_init;

    /*Init Driver Module
    Aleady initialized in main
    */

    /*go to PSD_Measuring_Pressure State*/
    PSD_State = STATE(PSD_Measuring_Pressure);
}

STATE_Define(PSD_Measuring_Pressure)
{
    /*State ID -> PSD_Measuring_Pressure*/
    PSD_State_ID = PSD_Measuring_Pressure;

    /*Measure Distance*/
    uint32 PressureVal = getPressureVal();


    /*Send sendPressureVal Signal*/
    sendPressureVal(PressureVal);

    /**************************************************
    The system shall set Timer1 for 100 sec
    this requirement is useless here because we dont use OS to run tasks round-robin
    the code running sequencetional no OS nor ISRs
    ***************************************************/
    /*go to Measuring_Distance State*/
    PSD_State = STATE(PSD_idle);

}

STATE_Define(PSD_idle)
{
    /*State ID -> Measuring_Distance*/
    PSD_State_ID = PSD_idle;

    /*poll untill Timer1 Expiration then reset Timer1*/

    /*go to Measuring_Distance State*/
    PSD_State = STATE(PSD_Measuring_Pressure);

}
