/*
* cognome:
* nome:
* matricola:
* numero_prova:
*/

#ifndef _FILEH_
#define _FILEH_

#include <stdio.h>
#include <stdlib.h>
#include "commondef.h"

//Funzione che legge da file una stringa finchè non incontra il carattere separatore
BOOLEAN readSeparator(FILE* pf, char separator, char* buffer, int size);

#endif