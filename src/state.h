   /*****************************************************************
    *[FILE NAME] 	: state.h						  		        *
    *											  					*
    *[AUTHOR(S)]    : OmarAhmed					  	  				*
    *										        				*
    *[DATE CREATED] : Sep 30, 2023						  			*
    * 										  						*
    *[DECRIPTION]   : State 								        *
    *****************************************************************/
#ifndef _state_H_
#define _state_H_
    


#define STATE_Define(_STATE_)   void ST_##_STATE_(void)
#define STATE(_STATE_)    ST_##_STATE_




/*Connection Between BSW Modules*/

void sendPressureVal(int PressureVal);
void Alarm_State_ON(void);
void FlashMemory_Write(int PressureVal);
void Set_Alarm_actuator(int AlarmVal);
    
#endif
