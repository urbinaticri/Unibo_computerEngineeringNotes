/*
* cognome:
* nome:
* matricola:
* numero_prova:
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "OGGETTO_ARRAY.h"

//ES. 1
/*OGGETTO_ARRAY leggi(FILE* fp) {
	int fscanfRes;
	OGGETTO_ARRAY tmp;
	tmp.cognome = (char*)malloc(sizeof(char)*32);
	if (fp != NULL) {
		do {
			fscanfRes = fscanf(fp, "%s %d %f", tmp.cognome, &(tmp.persone), &(tmp.importo));
		} while (fscanfRes != 3 && fscanfRes > 0);
		if (fscanfRes <= 0) {
			free(tmp.cognome);
			tmp.cognome = NULL;
		}
	}
	return tmp;
}
*/

/*OGGETTO_ARRAY* leggi(char* fileName, int* dim) {
	FILE* f = fopen(fileName, "r");
	OGGETTO_ARRAY tmp;
	OGGETTO_ARRAY* v = NULL;
	int i;
	*dim = 0;
	if (f != NULL) {
		while (tmp = leggi(f), tmp.cognome != NULL) {
			(*dim)++;
		}
		rewind(f);
		v = (OGGETTO_ARRAY*)malloc(sizeof(OGGETTO_ARRAY)*(*dim));
		for (i = 0; i < (*dim); i++) {
			v[i] = leggi(f);
		}
		fclose(f);
	}
	else {
		printf("Errore in apertura del file %s\n", fileName);
	}
	return v;
}*/

/*void stampa(OGGETTO_ARRAY * v, int dim) {
	int i = 0;
	for (i = 0; i < dim; i++) {
		printf("%s %u %.2f\n", v[i].cognome, v[i].persone, v[i].importo);
	}
}*/

//ES. 2

//ES. 3