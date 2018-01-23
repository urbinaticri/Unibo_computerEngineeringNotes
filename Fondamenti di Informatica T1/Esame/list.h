/*
* cognome:
* nome:
* matricola:
* numero_prova:
*/

#ifndef _LISTH_
#define _LISTH_

#include "element.h"

typedef struct listNode{
	ListElement value;
	struct listNode *next;
} ListNode;
typedef ListNode *list;


// ################  PRIMITIVE  ################

// Funzione costruttore della lista che aggiunge un nuovo elemento in testa
list cons(ListElement d, list l);
// Funzione che restituisce una lista vuota (puntatore a NULL)
list emptyList();
// Funzione che ripulisce una lista liberando la memoria, restituisce la nuova lista che è sostanzialmente un puntatore a NULL
list cleanList(list l);
// Funzione che verifica se la lista è vuota, restituisce TRUE se lo è, FALSE altrimenti
BOOLEAN empty(list);
// Funzione che restituisce la testa della lista (il primo elemento)
ListElement head(list);
// Funzione che restituisce la coda della lista (la lista puntata dal next della head)
list tail(list);

// ################  NON PRIMITIVE  ################

// Funzione per stampare a video la lista
void showList(list l);
// Funzione che verifica se un certo elemento è presente nella lista, in caso di esito positivo restituisce TRUE, altrimenti FALSE
BOOLEAN member(ListElement el, list l);
// Funzione che restituisce il numero di elementi presenti nella lista
int length(list l);
// Funzione che appende la lista src in coda alla lista dst
list append(list dst, list src);
// Funzione che inverte l'ordine della lista
list reverse(list l);
// Funzione che restituisce una lista copia di quella passata
list copy(list l);
// Funzione che elimina la prima occorrenza di un dato elemento dalla lista e se un elemento è stato eliminato il parametro deleted assume valore TRUE, altrimenti FALSE.
// La funzione restituisce una copia della lista di partenza. Se il parametro 'andUpdateList' ha valore TRUE allora la lista di partenza viene aggiornata liberando la memoria nel punto in cui era collocato il dato.
list deleteEl(ListElement el, list l, BOOLEAN* deleted, BOOLEAN andUpdateList);
// Funzione che elimina l' elemento nella posizione specificata nella lista e se un elemento è stato eliminato il parametro deleted assume valore TRUE, altrimenti FALSE.
// La funzione restituisce una copia della lista di partenza. Se il parametro 'andUpdateList' ha valore TRUE allora la lista di partenza viene aggiornata liberando la memoria nel punto in cui era collocato il dato.
list deleteInPos(int pos, list l, BOOLEAN* deleted, BOOLEAN andUpdateList);


// ################  OPERAZIONI LISTE ORDINATE  ################

// Funzione che inserisce un elemento nella lista in maniera ordinata
list insord(ListElement el, list l, BOOLEAN reverseOrder);
// Funzione che riceve in ingresso una lista ne restituisce una copia ordinata
list orderedList(list l, BOOLEAN reverseOrder);
// Funzione che esegue il merge ordinato di due liste in una terza lista e la restituisce
list mergeList(list l1, list l2);

#endif