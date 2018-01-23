/*
* cognome:
* nome:
* matricola:
* numero_prova:
*/

#include "sort.h"

int trovaPosMax(ArrayElement v[], int dim, BOOLEAN reverseOrder) {
	int i, posMax = 0;
	for (i = 1; i < dim; i++) {
		if (compareAE(v[posMax], v[i], reverseOrder) == LESS) {
			posMax = i;
		}
	}
	return posMax;
}

void naiveSort(ArrayElement v[], int dim, BOOLEAN reverseOrder) {
	int posMax;
	while (dim>1) {
		posMax = trovaPosMax(v, dim, reverseOrder);
		if (posMax < (dim - 1)) {
			swapAE(&(v[posMax]), &(v[dim - 1]));
		}
		dim--;
	}
}

void bubbleSort(ArrayElement v[], int dim, BOOLEAN reverseOrder) {
	int i;
	BOOLEAN ordinato = FALSE;
	while (dim > 1 && !ordinato) {
		ordinato = TRUE;
		for (i = 0; i < dim - 1; i++) {
			if (compareAE(v[i], v[i + 1], reverseOrder) == GREATER) {
				swapAE(&v[i], &v[i + 1]);
				ordinato = FALSE;
			}
		}
		dim--;
	}
}

void insOrd(ArrayElement v[], int pos, BOOLEAN reverseOrder) {
	int i = pos - 1;
	ArrayElement x;
	assignAE(&x, v[pos]);
	while (i >= 0 && compareAE(x, v[i], reverseOrder) == LESS) {
		assignAE(&(v[i + 1]), v[i]);
		i--;
	}
	assignAE(&(v[i + 1]), x);
}

void insertSort(ArrayElement v[], int dim, BOOLEAN reverseOrder) {
	int k;
	for (k = 1; k < dim; k++) {
		insOrd(v, k, reverseOrder);
	}
}

void merge(ArrayElement v[], int i1, int i2, int fine, ArrayElement vout[], BOOLEAN reverseOrder) {
	int i = i1, j = i2, k = i1;
	while (i <= (i2 - 1) && j <= fine) {
		if (compareAE(v[i], v[j], reverseOrder) == LESS) {
			assignAE(&(vout[k]), v[i++]);
		}
		else {
			assignAE(&(vout[k]), v[j++]);
		}
		k++;
	}
	while (i <= i2 - 1) { assignAE(&(vout[k]), v[i++]); k++; }
	while (j <= fine) { assignAE(&(vout[k]), v[j++]); k++; }
	for (i = i1; i <= fine; i++) { assignAE(&(v[i]), vout[i]); }
}

void mergeSortR(ArrayElement v[], int first, int last, ArrayElement vout[], BOOLEAN reverseOrder) {
	int mid;
	if (first < last) {
		mid = (last + first) / 2;
		mergeSortR(v, first, mid, vout, reverseOrder);
		mergeSortR(v, mid + 1, last, vout, reverseOrder);
		merge(v, first, mid + 1, last, vout, reverseOrder);
	}
}

void mergeSort(ArrayElement v[], int dim, BOOLEAN reverseOrder) {
	ArrayElement * v_toReturn = (ArrayElement*) malloc(dim * sizeof(ArrayElement));
	mergeSortR(v, 0, dim - 1, v_toReturn, reverseOrder);
	free(v_toReturn);
}

void quickSortR(ArrayElement v[], int iniz, int fine, BOOLEAN reverseOrder) {
	int i, j, iPivot;
	ArrayElement pivot;
	RESULT res;
	if (iniz < fine) {
		i = iniz; j = fine;
		iPivot = fine;
		assignAE(&pivot, v[iPivot]);
		do {
			while (res = compareAE(v[i], pivot, reverseOrder), i < j && (res == LESS || res == EQUAL)) { i++; }
			while (res = compareAE(v[j], pivot, reverseOrder), j > i && (res == GREATER || res == EQUAL)) { j--; }
			if (i < j) { swapAE(&(v[i]), &(v[j])); }
		} while (i < j);
		
		if (i != iPivot && compareAE(v[i], v[iPivot], reverseOrder) != EQUAL) {
			swapAE(&(v[i]), &(v[iPivot]));
			iPivot = i;
		}

		if (iniz < iPivot - 1) {
			quickSortR(v, iniz, iPivot - 1, reverseOrder);
		}
		if (iPivot + 1 < fine) {
			quickSortR(v, iPivot + 1, fine, reverseOrder);
		}
	}
}

void quickSort(ArrayElement v[], int dim, BOOLEAN reverseOrder) {
	quickSortR(v, 0, dim - 1, reverseOrder);
}