
#include  "Platform_Types.h"

extern vuint32 _stack_top;
extern vuint32 _E_text;
extern vuint32 _S_data;
extern vuint32 _E_data;
extern vuint32 _S_bss;
extern vuint32 _E_bss;

void Reset_Handler(void);
void Interrupt_Handler(void);


vuint32 vectors[] __attribute__((section(".vectors")))= {

	(uint32)&_stack_top,
	(uint32)&Reset_Handler,
	(uint32)&Interrupt_Handler,
	(uint32)&Interrupt_Handler,
	(uint32)&Interrupt_Handler,
	(uint32)&Interrupt_Handler,
	(uint32)&Interrupt_Handler,
	(uint32)&Interrupt_Handler,
	(uint32)&Interrupt_Handler,
	(uint32)&Interrupt_Handler,

};


void Reset_Handler(void)
{
	{
	unsigned int i = 0;
	uint32 section_size = (uint8*)&_E_data - (uint8*)&_S_data;
	uint8 * src_ptr	= (uint8*)&_E_text;
	uint8 * dst_ptr	= (uint8*)&_S_data;
	for(i = 0; i < section_size; i++)
	{
		*dst_ptr++ = *src_ptr++;
	}
	section_size = (uint8*)&_E_bss - (uint8*)&_S_bss;
	dst_ptr	= (uint8*)&_S_bss;
	for(i = 0; i < section_size; i++)
	{
		*dst_ptr++ = (uint8) 0;
	}
	}
	main ();
	while(1);
}

void Interrupt_Handler(void)
{
	Reset_Handler();
}
