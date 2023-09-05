   /*****************************************************************
    *[FILE NAME] 	: driver.h						  				*
    *											  					*
    *[AUTHOR(S)]    : OmarAhmed					  	  				*
    *										        				*
    *[DATE CREATED] : Sep 30, 2023                                  *
    * 										  						*
    *[DECRIPTION]   : SW Drivers 								    *
    *****************************************************************/

#ifndef driver_H_
#define driver_H_



#define GPIO_PORTA 0x40010800
#define BASE_RCC   0x40021000

#define APB2ENR   *(vuint32 *)(BASE_RCC + 0x18)

#define GPIOA_CRL *(vuint32 *)(GPIO_PORTA + 0x00)
#define GPIOA_CRH *(vuint32 *)(GPIO_PORTA + 0X04)
#define GPIOA_IDR *(vuint32 *)(GPIO_PORTA + 0x08)
#define GPIOA_ODR *(vuint32 *)(GPIO_PORTA + 0x0C)


int getPressureVal(void);
void GPIO_INITIALIZATION (void);


#endif 
