#include "X12.h"

void init_ports 		(void);
char detecte_front_montant	(char num_bit);
char valeur			(char num_bit);
void allume_led 		(char num_led, char valeur);

char cacheP = 0;

void main (void)
{
	MCU_init();
	init_ports();

	while(1)
	{
		cacheP = PTP;

		if (detecte_front_montant(3)) allume_led(2, 1);
		
		allume_led(7, valeur(0)); 
	}

}


void init_ports (void)
{
	// Initialisation des ports P et J en entrée.
	DDRP &= ~0x30;	// ~0x30 = 0xCF.
	DDRJ &= ~0xC0;	// ~0xC0 = 0x3F.

	// Initialisation des résistances de tirage correspondantes.
	PERP |= 0x30;
	PERJ |= 0xC0;
}


char detecte_front_montant (char num_bit)
{
	char front = 0;

	if ((PTP != cacheP) && !((PTP >> num_bit) & 0x01))
		front = 1;
	return front; 
}


char valeur (char num_bit)
{
	int val_lue = 0;

	if (!(PTJ >> num_bit) & 0x00) val_lue = 1;

	return val_lue;
}


void allume_led (char num_led, char valeur)
{
	if (valeur)
		PORTA |=  0x01 << num_led;
	else
		PORTA &= ~0x01 << num_led;
}
