/*
* cognome:
* nome:
* matricola:
* numero_prova:
*/

#ifndef _DATEH_
#define _DATEH_

#include "commondef.h"

struct date{
		int day;
		int month;
		int year;
		BOOLEAN isValid;
};

typedef struct date Date;	

Date* initDate();
Date* initDatePar(int day, int month, int year);
BOOLEAN isValidDate(Date* d);
void printDate(Date* d);
RESULT compareDate(Date d1, Date d2);

#endif
