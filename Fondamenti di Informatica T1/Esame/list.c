/*
* cognome:
* nome:
* matricola:
* numero_prova:
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// ################  PRIMITIVE  ################

// Funzione costruttore della lista che aggiunge un nuovo elemento in testa
list cons(ListElement e, list l) {
	list t = (list)malloc(sizeof(ListNode));
	t->value = e;
	t->next = l;
	return t;
}
// Funzione che restituisce una lista vuota (puntatore a NULL)
list emptyList(void){
	return NULL;
}
// Funzione che ripulisce una lista liberando la memoria, restituisce la nuova lista che è sostanzialmente un puntatore a NULL
list cleanList(list l) {
	if (!empty(l)) {
		cleanList(l->next);
		free(l);
	}
	return NULL;
}
// Funzione che verifica se la lista è vuota, restituisce TRUE se lo è, FALSE altrimenti
BOOLEAN empty(list l){
	BOOLEAN isEmpty = FALSE;
	if(l == NULL){
		isEmpty = TRUE;
	}
	return isEmpty;
}
// Funzione che restituisce la testa della lista (il primo elemento)
ListElement head(list l){
	ListElement node = nullValLE();
	if(!empty(l)){
		node = l->value;
	}
	return node;
}
// Funzione che restituisce la coda della lista (la lista puntata dal next della head)
list tail(list l){
	list l_tail = emptyList();
	if(!empty(l)){
		l_tail = l->next;
	}
	return l_tail;
}

// ################  NON PRIMITIVE  ################

// Funzione per stampare a video la lista
void showList(list l){
	printf("[");
	while(!empty(l)){
		printElementLE(head(l));
		l = tail(l);
		if(!empty(l)){
			printf(", ");
		}
	}
	printf("]\n");
}
// Funzione che verifica se un certo elemento è presente nella lista, in caso di esito positivo restituisce TRUE, altrimenti FALSE
BOOLEAN member(ListElement el, list l) {
	BOOLEAN isMember = FALSE;
	while (!empty(l) && !isMember) {
		if (equalsLE(el, head(l)) == EQUAL) {
			isMember = TRUE;
		}
		else {
			l = tail(l);
		}
	}
	return isMember;
}
// Funzione che restituisce il numero di elementi presenti nella lista
int length(list l) {
	int len = 0;
	while (!empty(l)) {
		len++;
		l = tail(l);
	}
	return len;
}
// Funzione che appende la lista src in coda alla lista dst
list append(list dst, list src) {
	list list_toReturn = emptyList();
	if (!empty(dst)) {
		list_toReturn = cons(head(dst), append(tail(dst), src));		
	}
	else {
		list_toReturn = src;
	}
	return list_toReturn;
}
// Funzione che inverte l'ordine della lista
list reverse(list l) {
	list list_toReturn = emptyList();
	if (!empty(l)) {
		list_toReturn = append(reverse(tail(l)), cons(head(l), emptyList()));
	}
	else {
		list_toReturn = emptyList();
	}
	return list_toReturn;
}
// Funzione che restituisce una lista copia di quella passata
list copy(list l) {
	list list_toReturn = emptyList();
	if (!empty(l)) {
		list_toReturn = cons(head(l), copy(tail(l)));
	}
	else {
		list_toReturn = l;
	}
	return list_toReturn;
}
// Funzione che elimina la prima occorrenza di un dato elemento dalla lista e se un elemento è stato eliminato il parametro deleted assume valore TRUE, altrimenti FALSE.
//La funzione restituisce una copia della lista di partenza. Se il parametro 'andUpdateList' ha valore TRUE allora la lista di partenza viene aggiornata liberando la memoria nel punto in cui era collocato il dato.
list deleteEl(ListElement el, list l, BOOLEAN* deleted, BOOLEAN andUpdateList) {
	list list_toReturn = emptyList();
	*deleted = FALSE;
	if (!empty(l)) {
		if (equalsLE(el, head(l)) == EQUAL) {
			list_toReturn = tail(l);
			*deleted = TRUE;
			if(andUpdateList){
				free(l);
			}
		}
		else {
			list_toReturn = cons(head(l), deleteEl(el, tail(l), deleted,andUpdateList));
		}
	}	
	return list_toReturn;
}
// Funzione che elimina l' elemento nella posizione specificata nella lista e se un elemento è stato eliminato il parametro deleted assume valore TRUE, altrimenti FALSE.
//La funzione restituisce una copia della lista di partenza. Se il parametro 'andUpdateList' ha valore TRUE allora la lista di partenza viene aggiornata liberando la memoria nel punto in cui era collocato il dato.
list deleteInPos(int pos, list l, BOOLEAN* deleted, BOOLEAN andUpdateList) {
	list list_toReturn = emptyList();
	*deleted = FALSE;
	if (!empty(l)) {
		if (pos == 0) {
			list_toReturn = tail(l);
			*deleted = TRUE;
			if(andUpdateList){
				free(l);
			}
		}
		else {
			list_toReturn = cons(head(l), deleteInPos(pos-1, tail(l), deleted, andUpdateList));
		}
	}	
	return list_toReturn;
}


// ################  OPERAZIONI LISTE ORDINATE  ################

// Funzione che inserisce un elemento nella lista in maniera ordinata
list insord(ListElement el, list l, BOOLEAN reverseOrder) {
	list list_toReturn = emptyList();
	if (empty(l) || compareLE(el, head(l), reverseOrder) == LESS) {
		list_toReturn = cons(el, l);
	}
	else {
		list_toReturn = cons(head(l), insord(el, tail(l), reverseOrder));
	}
	return list_toReturn;
}

// Funzione che riceve in ingresso una lista ne restituisce una copia ordinata
list orderedList(list l, BOOLEAN reverseOrder) {
	list list_toReturn = emptyList();
	list tmp = l;
	while (!empty(tmp)) {
		list_toReturn = insord(tmp->value, list_toReturn, reverseOrder);
		tmp = tmp->next;
	}
	return list_toReturn;
}

// Funzione che esegue il merge ordinato di due liste in una terza lista e la restituisce
list mergeList(list l1, list l2) {
	RESULT resCompare;
	list list_toReturn = emptyList();
	if (empty(l1))
		list_toReturn = l2;
	else if (empty(l2))
		list_toReturn = l1;
	else {
		resCompare = compareLE(head(l1), head(l2), FALSE);
		switch (resCompare) {
			case LESS: 
				list_toReturn = cons(head(l1), mergeList(tail(l1), l2));
				break;
			case EQUAL:
				list_toReturn = cons(head(l1), mergeList(tail(l1), tail(l2)));
				break;
			case GREATER:
				list_toReturn = cons(head(l2), mergeList(l1, tail(l2)));
				break;
			default:
				break;
		}		
	}
	return list_toReturn;
}