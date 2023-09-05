   /*****************************************************************
    *[FILE NAME] 	  : Pressure_Sensor_Driver.h						  	  *
    *											  					                 *
    *[AUTHOR(S)]    : OmarAhmed					  	  				        *
    *										        				                 *
    *[DATE CREATED] : Sep 30, 2023						  			        *
    * 										  						              *
    *[DECRIPTION]   : Pressure_Sensor_Driver 							  *
    *****************************************************************/

#ifndef _Pressure_Sensor_Driver_H_
#define _Pressure_Sensor_Driver_H_

/*extern global Ptr to Function*/   
extern void(*PSD_State)(void);

/*PSD State ID enum*/
enum
{
   PSD_init,PSD_Measuring_Pressure,PSD_idle
}PSD_State_ID;

/*State APIs Declaration*/
STATE_Define(PSD_init);
STATE_Define(PSD_Measuring_Pressure);
STATE_Define(PSD_idle);

#endif