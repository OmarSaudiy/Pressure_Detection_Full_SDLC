   /*****************************************************************
    *[FILE NAME] 	: Platform_Types.h						  		*
    *											  					*
    *[AUTHOR(S)]    : OmarAhmed					  	  				*
    *										        				*
    *[DATE CREATED] : Mar 14, 2023						  			*
    * 										  						*
    *[DECRIPTION]   : Platform_Types 								*
    *****************************************************************/

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_
/*#include <stdint.h>*/
#ifndef FALSE
#define FALSE       (0u)
#endif
#ifndef TRUE
#define TRUE        (1u)
#endif
#ifndef LOGIC_HIGH
#define LOGIC_HIGH        (1u)
#endif
#ifndef LOGIC_LOW
#define LOGIC_LOW         (0u)
#endif
#define NULL_PTR    ((void*)0)


typedef unsigned char                           	uint8;
typedef unsigned short int                          uint16;
typedef unsigned long int                           uint32;
typedef unsigned long long    						uint64;


typedef volatile unsigned char                      vuint8;
typedef volatile unsigned short int                 vuint16;
typedef volatile unsigned long int                  vuint32;
typedef volatile unsigned long long    				vuint64;


typedef signed char                            		sint8;
typedef signed short int                            sint16;
typedef signed long int                             sint32;
typedef signed long long    						sint64;


typedef float                             		 	float32;
typedef double                             			float64;

#endif /* PLATFORM_TYPES_H_ */
