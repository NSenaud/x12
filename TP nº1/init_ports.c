#include "X12.h"

void init_ports (void);
void allume_led (void);

void main (void)
{
	MCU_init();
	init_ports();

	while(1)
	{
		allume_led();
	}

}

void init_ports(void)
{
	// Initialisation des ports P et J en entrée.
	DDRP &= ~0x30;	// ~0x30 = 0xCF.
	DDRJ &= ~0xC0;	// ~0xC0 = 0x3F.

	// Initialisation des résistances de tirage correspondantes.
	PERP |= 0x30;
	PERJ |= 0xC0;
}

void allume_led(void)
{
	if (PTP == 0xEF) PORTA = 0x55;
	else if (PTP == 0xDF) PORTA = 0xAA;
	else PORTA = 0x00;
}
