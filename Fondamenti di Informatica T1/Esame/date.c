/*
* cognome:
* nome:
* matricola:
* numero_prova:
*/

#include <stdio.h>
#include <stdlib.h>
#include "date.h"

Date* initDate() {
	Date* d = (Date*)malloc(sizeof(Date));
	return d;
}

Date* initDatePar(int day, int month, int year) {
	Date* d = (Date*)malloc(sizeof(Date));
	d->day = day;
	d->month = month;
	d->year = year;
	d->isValid = isValidDate(d);
	return d;
}

BOOLEAN isValidDate(Date* d) {
	BOOLEAN isValid = TRUE;
	switch (d->month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (!(d->day > 0 && d->day <= 31)) {
				isValid = FALSE;
			}
			break;
		case 2:
			if (d->year % 4 == 0) {
				if (!(d->day > 0 && d->day <= 29)) {
					isValid = FALSE;
				}
			}
			else {
				if (!(d->day > 0 && d->day <= 28)) {
					isValid = FALSE;
				}
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (!(d->day > 0 && d->day <= 30)) {
				isValid = FALSE;
			}
			break;	
	}
	return isValid;
}

void printDate(Date* d) {
	printf("%d/%d/%d\n", d->day, d->month, d->year);
	return;
}

RESULT compareDate(Date d1, Date d2) {
	RESULT res;
	if (d1.year <= d2.year) {
		res = LESS;
		if (d1.year == d2.year) {
			if (d1.month <= d2.month) {
				res = LESS;
				if (d1.month == d2.month) {
					if (d1.day <= d2.day) {
						res = LESS;
						if (d1.day == d2.day) {
							res = EQUAL;
						}
					}
					else {
						res = GREATER;
					}
				}
			}
			else {
				res = GREATER;
			}
		}
	}
	else {
		res = GREATER;
	}
	return res;
}