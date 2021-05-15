/*
 * z4.h
 *
 *  Created on: May 15, 2021
 *      Author: User
 */

//Standardna arduino biblioteka
#include <avr/io.h>
//Biblioteka koja omgucava koriscenje funkcije _delay_ms()
#include <util/delay.h>
//Bibliteka koja omogucava pristup podacima u flash memoriji
#include <avr/pgmspace.h>
//Standardna C biblioteka
#include <stdio.h>
//Pristup statickoj usart biblioteci
#include "../usart/usart.h"
//Biblioteka koja sadrži definicije standardnih oznacenih i neoznacenih tipova podataka
#include <stdint.h>



#ifndef Z4_H_
#define Z4_H_

void RepeatNumber(uint8_t tekst[]);

/**
 * RemoveSpaces - Funkcija koja brise razmak
 * @param tekst - ulaz tipa uint8_t - unos teksta od strane korisnika
 * @return Nema povratne vrednosti
 */
void RemoveSpace(uint8_t tekst[]);

/**
 * RemoveRepeatingLetter - Funkcija koja brise kopije slova u tekstu
 * @param tekst - ulaz tipa uint8_t - tekst koji se unosi od strane korisnika
 * @return Nema povratne vrijednosti
 */
void RemoveRepeatingLetters(uint8_t tekst[]);


/**
 * Choose_n - Funkcija koja na osnovu unesenog parametra n vrsi izbog odgovarajuce funkcije
 * @param n - ulaz tipa uint16_t - ceo broj n koji odredjuje operaciju
 * @param tekst - ulaz tipa uint8_t - tekst koji se unosi od strane korisnika
 * @return Nema povratne vrednosti
 */
void Choose_n(uint16_t n,uint8_t tekst[]);



#endif /* Z4_H_ */
