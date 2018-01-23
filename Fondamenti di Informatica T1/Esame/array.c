/*
* cognome:
* nome:
* matricola:
* numero_prova:
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "array.h"

// Funzione che verifica se un dato elemento el è contenuto nell'array v
BOOLEAN contains(ArrayElement* v, int dim, ArrayElement el) {
	int i = 0;
	BOOLEAN trovato = FALSE;
	while (i < dim && !trovato) {
		if (equalsAE(v[i], el) == EQUAL) {
			trovato = TRUE;
		}
		i++;
	}
	return trovato;
}

// Funzione che elimina da un array tutte le ripetizioni di elementi uguali (la condizione di uguaglianza è quella specificata nella funzione equalsAE)
ArrayElement* deleteRip(ArrayElement* v, int dim_v, int* dim_ret) {
	ArrayElement* ret = (ArrayElement*)malloc(sizeof(ArrayElement)*dim_v);
	int i;
	*dim_ret = 0;
	for (i = 0; i < dim_v; i++) {
		if (!contains(ret, *dim_ret, v[i])) {
			ret[(*dim_ret)++] = v[i];
		}
	}
	return ret;
}