/*
* cognome:
* nome:
* matricola:
* numero_prova:
*/

#ifndef _TIMEH_
#define _TIMEH_

#include "commondef.h"

struct time{
		int hour;
		int minute;
		int second;
		BOOLEAN isValid;
};

typedef struct time Time;	

Time* initTime();
Time* initTimePar(int hour, int minute, int second);
BOOLEAN isValidTime(Time* t);
void printTime(Time* t);
Time* timeDifference(Time* t1, Time* t2);
RESULT compareTime(Time t1, Time t2);

#endif