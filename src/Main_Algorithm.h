   /*****************************************************************
    *[FILE NAME]    : Main_Algorithm.h                              *
    *                                                               *
    *[AUTHOR(S)]    : OmarAhmed                                     *
    *                                                               *
    *[DATE CREATED] : Sep 30, 2023                                  *
    *                                                               *
    *[DECRIPTION]   : Main_Algorithm                                *
    *****************************************************************/
#ifndef _Main_Algorithm_H_
#define _Main_Algorithm_H_


/*extern global Ptr to Function*/   
extern void (*MA_State)(void);


/*MA State ID enum*/
enum
{
   MA_Idle,MA_Check_Pressure 
}MA_State_ID;

/*State APIs Declaration*/
STATE_Define(MA_Idle);
STATE_Define(MA_Check_Pressure);



    
#endif