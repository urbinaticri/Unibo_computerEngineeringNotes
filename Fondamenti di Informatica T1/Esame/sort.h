/*
* cognome:
* nome:
* matricola:
* numero_prova:
*/

#ifndef _SORTH__
#define _SORTH_

#include <stdlib.h>
#include <string.h>
#include "element.h"

void naiveSort(ArrayElement v[], int dim, BOOLEAN reverseOrder);
void bubbleSort(ArrayElement v[], int dim, BOOLEAN reverseOrder);
void insertSort(ArrayElement v[], int dim, BOOLEAN reverseOrder);
void mergeSort(ArrayElement v[], int dim, BOOLEAN reverseOrder);
void quickSort(ArrayElement v[], int dim, BOOLEAN reverseOrder);

#endif