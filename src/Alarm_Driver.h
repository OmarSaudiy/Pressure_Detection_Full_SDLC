   /*****************************************************************
    *[FILE NAME] 	  : Alarm_Driver.h						  		        *
    *											  					                 *
    *[AUTHOR(S)]    : OmarAhmed					  	  				        *
    *										        				                 *
    *[DATE CREATED] : Sep 30, 2023                                  *
    * 										  						              *
    *[DECRIPTION]   : Alarm_Driver   								        *
    *****************************************************************/

#ifndef _Alarm_Driver_H_
#define _Alarm_Driver_H_

/*extern global Ptr to Function*/   
extern void (*AD_State)(void);


/*AD State ID enum*/
enum
{
   AD_init,AD_idle,AD_Receive_CMD
}AD_State_ID;

/*State APIs Declaration*/
STATE_Define(AD_init);
STATE_Define(AD_idle);
STATE_Define(AD_Receive_CMD);
   
#endif