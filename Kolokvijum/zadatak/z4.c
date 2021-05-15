/*
 * z4.c
 *
 *  Created on: May 15, 2021
 *      Author: User
 */
#include "z4.h"


void RepeatNumber(uint8_t tekst[])
{
            uint16_t duzina;
			uint8_t pom[64];
			uint16_t suma = 0;
			uint8_t str[64];

			for(duzina = 0; tekst[duzina] !='\0';duzina++);

				for(uint16_t i = 0;i<duzina; i++)
				{
					for(uint16_t j = 0;j<duzina; j++)
					{
					if(tekst[i] == tekst[j])
					{
						suma++;
						pom[i]=suma;
					}
					}
			}
			uint16_t s;
			uint16_t pomocna=pom[0];
			for(uint16_t k=0;k<duzina;k++)
			{
				if(pomocna<pom[k+1]){
					pomocna=pom[k+1];
					s=k+1;
				}

			}
			sprintf(str,"%c\0",tekst[s]);
			usartPutString(str);
			usartPutString_P(PSTR("\r\n"));

		}
/**
 * RemoveSpaces - Funkcija koja brise razmak
 * @param tekst - ulaz tipa uint8_t - unos teksta od strane korisnika
 * @return Nema povratne vrednosti
 */
void RemoveSpace(uint8_t tekst[])
{
	            uint16_t duzina2;
				uint16_t pom2;
				uint16_t suma2 = 0;
				uint8_t str2[64];

				for(duzina2 = 0; tekst[duzina2] !='\0';duzina2++);

					for(uint16_t i = 0;i<duzina2; i++)
					{
						if(tekst[i] == 32){
							pom2=i;
						}
					}
	for(uint16_t j=0;j<duzina2;j++){

		if(j>=pom2)
		{
		str2[j]=tekst[j+1];
		}else
		{
	     str2[j]=tekst[j];
		}

	}
	usartPutString(str2);


}
/**
 * RemoveRepeatingLetter - Funkcija koja brise kopije slova u tekstu
 * @param tekst - ulaz tipa uint8_t - tekst koji se unosi od strane korisnika
 * @return Nema povratne vrijednosti
 */
void RemoveRepeatingLetters(uint8_t tekst[])
{
	            uint16_t duzina3;
	            uint8_t str3[64];
	            uint8_t zvezda = '*';

				for(duzina3 = 0; tekst[duzina3] !='\0';duzina3++);

					for(uint16_t i = 0;i<duzina3; i++)
					{
						for(uint16_t j=i+1;j<duzina3; j++)
						{
						if(tekst[i] == tekst[j])
						{
							tekst[j]=zvezda;//oznacimo sva mjesta gdje imamo duplikate u tekstu
						}
						}
	}
					uint16_t p = 0;
					for(uint16_t k = 0; k < duzina3; k++)
					{
		                 	tekst[k] = tekst[k+p];
							if(tekst[k] == zvezda)
							{
								p++;
								k--;
							}
					}
	usartPutString(tekst);
}

/**
 * Choose_n - Funkcija koja na osnovu unesenog parametra n vrsi izbog odgovarajuce funkcije
 * @param n - ulaz tipa uint16_t - ceo broj n koji odredjuje operaciju
 * @param tekst - ulaz tipa uint8_t - tekst koji se unosi od strane korisnika
 * @return Nema povratne vrednosti
 */
void Choose_n(uint16_t n,uint8_t tekst[])
{
 switch(n){

        case 1: RepeatNumber(tekst);
                break;
        case 2: RemoveSpace(tekst);
                break;
        case 3: RemoveRepeatingLetters(tekst);
                break;

        default:
        	return -1;
        }

}

