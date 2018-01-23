/*
* cognome:
* nome:
* matricola:
* numero_prova:
*/

#ifndef _ARRAYH_
#define _ARRAYH_

#include "commondef.h"
#include "element.h"
#include "sort.h"

// Funzione che verifica se un dato elemento el è contenuto nell'array v
BOOLEAN contains(ArrayElement* v, int dim, ArrayElement el);
// Funzione che elimina da un array tutte le ripetizioni di elementi uguali (la condizione di uguaglianza è quella specificata nella funzione equalsAE)
ArrayElement* deleteRip(ArrayElement* v, int dim_v, int* dim_ret);

#endif