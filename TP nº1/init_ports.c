#include "X12.h"

void init_ports (void);
char valeur(char num_bit);
void allume_led (char num_led, char valeur);

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

void allume_led(char num_led, char valeur)
{
	if (valeur)
	switch (num_led)
	{
		case 0:	PORTA |= 0x01;
			break;

		case 1:	PORTA |= 0x02;
			break;

		case 2:	PORTA |= 0x04;
			break;

		case 3:	PORTA |= 0x08;
			break;

		case 4:	PORTA |= 0x10;
			break;

		case 5:	PORTA |= 0x20;
			break;

		case 6:	PORTA |= 0x40;
			break;

		case 7:	PORTA |= 0x80;
			break;
	}

	else
	switch (num_led)
	{
		case 0:	PORTA &= ~0x01;
			break;

		case 1:	PORTA &= ~0x02;
			break;

		case 2:	PORTA &= ~0x04;
			break;

		case 3:	PORTA &= ~0x08;
			break;

		case 4:	PORTA &= ~0x10;
			break;

		case 5:	PORTA &= ~0x20;
			break;

		case 6:	PORTA &= ~0x40;
			break;

		case 7:	PORTA &= ~0x80;
			break;
	}
}
