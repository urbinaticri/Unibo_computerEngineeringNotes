/*
* cognome:
* nome:
* matricola:
* numero_prova:
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "element.h"

#include <stdio.h>
#include <string.h>


// AREA GLOBALE , FUNZIONI ACCESSORIE PER STATISTICHE SUL NUMERO DI SCAMBI E ASSEGNAMENTI FATTI
int compareCounter = 0;
int swapCounter = 0;

void incrementCompareCounter() { compareCounter++; }
void incrementSwapCounter() { swapCounter++; }
void printStatistics() {
	printf("Numero di scambi: %d\n", swapCounter);
	printf("Numero di confronti: %d\n", compareCounter);
}
void resetStatistics() {
	swapCounter = 0;
	compareCounter = 0;
}
/*********************************************************************************************/





/****************************************ARRAY****************************************/

// Funzione che confronta due elementi e restituisce 0 se sono equivalenti
RESULT equalsAE(ArrayElement e1, ArrayElement e2) {
	RESULT res = EQUAL;
	return res;
}

RESULT reverseResultAE(RESULT r) {
	if (r == GREATER) {
		r = LESS;
	}
	else if (r == LESS) {
		r = GREATER;
	}
	return r;
}
// Funzione che confronta due elementi e restituisce -1 se il primo è minore de secondo, 0 se sono equivalenti, 1 se il primo è maggiore del secondo
RESULT compareAE(ArrayElement a, ArrayElement b, BOOLEAN reverseOrder) {
	//-----------TO-DO------------//
	RESULT res = EQUAL;
	//----------------------------//
	// REVERSE RESULT IF REQUIRED //
	if (reverseOrder) {
		res = reverseResultAE(res);
	}
	incrementCompareCounter(); //Increment
	return res;
}

// Funzione che assegna l'elemento di destra (rvalue) all'elemento di sinistra (lvalue)
void assignAE(ArrayElement *lvalue, ArrayElement rvalue) {
	*lvalue = rvalue;
}

// Funzione che scambia due elementi per riferimento
void swapAE(ArrayElement *e1, ArrayElement *e2) {
	ArrayElement tmp;
	assignAE(&tmp, *e1);
	assignAE(e1, *e2);
	assignAE(e2, tmp);
	incrementSwapCounter(); //Increment
}






/****************************************LISTE****************************************/

// Funzione che confronta due elementi e restituisce 0 se sono equivalenti
RESULT equalsLE(ListElement e1, ListElement e2) {
	RESULT res = EQUAL;
	return res;
}

RESULT reverseResultLE(RESULT r) {
	if (r == GREATER) {
		r = LESS;
	}
	else if (r == LESS) {
		r = GREATER;
	}
	return r;
}
// Funzione che confronta due elementi e restituisce -1 se il primo è minore de secondo, 0 se sono equivalenti, 1 se il primo è maggiore del secondo
RESULT compareLE(ListElement a, ListElement b, BOOLEAN reverseOrder) {
	//-----------TO-DO------------//
	RESULT res = EQUAL;
	//----------------------------//
	// REVERSE RESULT IF REQUIRED //
	if (reverseOrder) {
		res = reverseResultLE(res);
	}
	return res;
}

// Funzione che assegna l'elemento di destra (rvalue) all'elemento di sinistra (lvalue)
void assignLE(ListElement *lvalue, ListElement rvalue) {
	*lvalue = rvalue;
}

// Funzione che scambia due elementi per riferimento
void swapLE(ListElement *e1, ListElement *e2) {
	ListElement tmp;
	assignLE(&tmp, *e1);
	assignLE(e1, *e2);
	assignLE(e2, tmp);
}

// Funzione che definisce il valore nullo per un dato elemento
ListElement nullValLE() {
	ListElement e;
	//
	return e;
}

// Funzione che controlla se un dato elemento corrisponde all'elemento nullo
BOOLEAN isNullValLE(ListElement el) {
	BOOLEAN isNull = FALSE;
	if (compareLE(el, nullValLE(), FALSE) == EQUAL) {
		isNull = TRUE;
	}
	return isNull;
}

// Funzione per la stampa a video dell'elemento
void printElementLE(ListElement e) {
	//printf("",);
}