---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 10-03-2024 19:43:49
links:
  - "[[lecture-05032024111158|Lecture 05032024111158]]"
---
# Counting sort
---
## Introduzione
> Il **counting sort** è un [[algoritmo-di-ordinamento-non-comparativo|algoritmo di ordinamento non-comparativo]], _non in-place_ e _stabile_, che funziona _contando il numero di apparenze di ogni chiave intera appartenente all'intervallo $[\min, \max]$, per poi riorganizzare le chiavi stampandole in ordine_. 

<u>Attenzione</u>: quella di poter _ordinare solo interi è una grande limitazione necessaria al funzionamento dell'algoritmo_. Bisogna infatti definire un range finito di numeri possibili da contare.

L'autore è [[harold-h. seward|Harold H. Seward]], 1954.

## Algoritmo
L'algoritmo si struttura nelle seguenti fasi:
1. trova il minimo e il massimo
2. crea un array di conteggio per ogni numero compreso tra il minimo e il massimo
3. conta il numero di volte in cui appaiono tutti i numeri presenti nell'array
4. sovrascrivi l'array con il numero di volte in cui appare ogni numero in ordine crescente

![[counting-sort.png]]
![[counting-sort-pseudo.png]]

## Complessità
Per analizzare la [[complessita-computazionale|complessità computazionale]] dell'algoritmo ci basta notare che questa dipende da due fattori:
- $n$, ovvero la lunghezza dell'array;
- $k$, ovvero la grandezza del range $\max-\min$;

Le funzioni `min` e `max` hanno costo $\Theta(n)$; il primo ciclo viene eseguito $k$ volte; il secondo $n$ e infine il terzo $n+k$ volte. Per cui _non c'è differenza tra caso ottimo, pessimo e medio_: **tutto dipende da chi è più grande tra $n$ e $k$**, per cui si ha
$$\Theta(n + k) = \Theta(\max(n, k))$$

<u>Nota bene</u>: il _costo_ è quindi **lineare** _fintanto che $k$ non dipende da $n$ o viceversa_. Se infatti avessimo $k = n^{2}$ allora il costo diventerebbe $\Theta(n^{2})$.

<u>Nota bene</u>: è comunque _possibile adattare l'algoritmo in modo da renderlo più generale_, e quindi funzionante anche su array chiave-valore.

## Referenze