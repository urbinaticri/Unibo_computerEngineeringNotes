/*
* cognome:
* nome:
* matricola:
* numero_prova:
*/

#include "file.h"

BOOLEAN readSeparator(FILE* pf, char separator, char* buffer, int size)
{
	int i = 0;
	char ch;
	BOOLEAN fileOpened = FALSE;
	if (pf != NULL) {
		ch = fgetc(pf);
		while ((ch != separator) && (ch != '\n') && (ch != EOF) && (i < (size-1))) { //(size-1) tenendo conto del carattere separatore
			buffer[i] = ch;
			i++;
			ch = fgetc(pf);
		}

		buffer[i] = '\0';
		fileOpened = TRUE;
	}

	return fileOpened;
}