/*
* cognome:
* nome:
* matricola:
* numero_prova:
*/

#ifndef _ELEMENTH_
#define _ELEMENTH_

#include "commondef.h"
#include "date.h"
#include "time.h"

/****************************************ARRAY****************************************/
typedef struct {
	int campo;
}OGGETTO_ARRAY;

typedef OGGETTO_ARRAY ArrayElement;

// Funzione che confronta due elementi e restituisce 0 se sono equivalenti
RESULT equalsAE(ArrayElement e1, ArrayElement e2);
// Funzione che confronta due elementi e restituisce -1 se il primo è minore de secondo, 0 se sono equivalenti, 1 se il primo è maggiore del secondo
RESULT compareAE(ArrayElement e1, ArrayElement e2, BOOLEAN reverseOrder);
// Funzione che assegna l'elemento di destra (rvalue) all'elemento di sinistra (lvalue)
void assignAE(ArrayElement * lvalue, ArrayElement rvalue);
// Funzione che scambia due elementi per riferimento
void swapAE(ArrayElement * e1, ArrayElement * e2);

// FUNZIONI ACCESSORIE PER STATISTICHE SUL NUMERO DI SCAMBI E ASSEGNAMENTI FATTI
void printStatistics(void);
void resetStatistics(void);





/****************************************LISTE****************************************/
typedef struct {
	int campo;
}OGGETTO_LISTA;

typedef OGGETTO_LISTA ListElement;

// Funzione che confronta due elementi e restituisce 0 se sono equivalenti
RESULT equalsLE(ListElement e1, ListElement e2);
// Funzione che confronta due elementi e restituisce -1 se il primo è minore de secondo, 0 se sono equivalenti, 1 se il primo è maggiore del secondo
RESULT compareLE(ListElement e1, ListElement e2, BOOLEAN reverseOrder);
// Funzione che assegna l'elemento di destra (rvalue) all'elemento di sinistra (lvalue)
void assignLE(ListElement * lvalue, ListElement rvalue);
// Funzione che scambia due elementi per riferimento
void swapLE(ListElement * e1, ListElement * e2);
// Funzione che definisce il valore nullo per un dato elemento
ListElement nullValLE(void);
// Funzione che controlla se un dato elemento corrisponde all'elemento nullo
BOOLEAN isNullValLE(ListElement el);
// Funzione per la stampa a video dell'elemento
void printElementLE(ListElement e);

#endif