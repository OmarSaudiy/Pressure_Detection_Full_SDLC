   /*****************************************************************
    *[FILE NAME] 	  : Alarm_Manager.h						  		        *
    *											  					                 *
    *[AUTHOR(S)]    : OmarAhmed					  	  				        *
    *										        				                 *
    *[DATE CREATED] : Sep 21, 2023						  			        *
    * 										  						              *
    *[DECRIPTION]   : Alarm_Manager   								        *
    *****************************************************************/
#ifndef _Alarm_Manager_H_
#define _Alarm_Manager_H_
    
/*extern global Ptr to Function*/   
extern void (*AM_State)(void);


/*MA State ID enum*/
enum
{
   AM_Idle,AM_Alarm_ON 
}AM_State_ID;

/*State APIs Declaration*/
STATE_Define(AM_Idle);
STATE_Define(AM_Alarm_ON);



    
#endif