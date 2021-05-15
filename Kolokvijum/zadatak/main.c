/**
 * @file	main.c
 * @brief	3 funkcije
 * @author	Milica Panic
 * @date    05-12-2021
 */

/**
 * main - Funkcija koja implementira glavnu operaciju
 * @param Nema parametera
 * @return Nema povratne vrijednosti
 */
#include "z4.h"

int main()
{
	//inicijalizacija
	usartInit(9600);
	//ulaz
	uint8_t tekst[64];
    uint16_t n;


	//glavna petlja
	while(1)
	{
        //PSTR() makro za smjestanje stringa u programsku memoriju (stednja)
		usartPutString_P(PSTR("Unesite tekst: \r\n"));
		while(!usartAvailable())
	    ;
		_delay_ms(50);//kasnjenje

		usartGetString(tekst);//prijem celog broja od strane korisnika

		usartPutString_P(PSTR("Izaberite opciju za modifikaciju unetog stringa: \r\n"));
		usartPutString_P(PSTR("1.Slovo koje se najvise ponavlja?: \r\n"));
		usartPutString_P(PSTR("2. Ukloni sve ‘ ’ karaktere. \r\n"));
		usartPutString_P(PSTR("3.Ukloni sve duplikate karaktera. \r\n"));


		while(!usartAvailable())
		;
		_delay_ms(50);
		uint16_t n = usartParseInt();

		Choose_n(n,tekst);


	}
   return 0;

}
