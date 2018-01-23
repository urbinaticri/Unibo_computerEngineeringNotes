/*
* cognome:
* nome:
* matricola:
* numero_prova:
*/

#include <stdio.h>
#include <stdlib.h>
#include "time.h"

Time * initTime() {
	Time * t = (Time *)malloc(sizeof(Time));
	return (t);
}

Time * initTimePar(int hour, int minute, int second) {
	Time * t = (Time *)malloc(sizeof(Time));
	t->hour = hour;
	t->minute = minute;
	t->second = second;
	t->isValid = isValidTime(t);
	return (t);
}

BOOLEAN isValidTime(Time* t) {
	BOOLEAN isValid = TRUE;
	if (!(t->hour > 0 && t->hour <= 24 && t->minute > 0 && t->minute < 60 && t->second>0 && t->second < 60)) {
		isValid = FALSE;
	}
	return isValid;
}

void printTime(Time* t) {
	printf("%d:%d:%d\n", t->hour, t->minute, t->second);
	return;
}

Time* timeDifference(Time* t1, Time* t2) {
	int T1toSec = t1->second + t1->minute * 60 + t1->hour * 60 * 60;
	int T2toSec = t2->second + t2->minute * 60 + t2->hour * 60 * 60;
	int secSubstract;
	Time* to_return = initTime();
	if (T1toSec > T2toSec) {
		secSubstract = T1toSec - T2toSec;
	}
	else {
		secSubstract = T2toSec - T1toSec;
	}

	to_return->second = secSubstract % 60;
	secSubstract /= 60;
	to_return->minute = secSubstract % 60;
	secSubstract /= 60;
	to_return->hour = secSubstract;

	return to_return;
}

RESULT compareTime(Time t1, Time t2) {
	RESULT res;
	if (t1.hour <= t2.hour) {
		res = LESS;
		if (t1.hour == t2.hour) {
			if (t1.minute <= t2.minute) {
				res = LESS;
				if (t1.minute == t2.minute) {
					if (t1.second <= t2.second) {
						res = LESS;
						if (t1.second == t2.second) {
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