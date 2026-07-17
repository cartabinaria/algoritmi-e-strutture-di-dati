---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 24-03-2024 19:43:04
links:
  - "[[lecture-21032024091145|Lecture 21032024091145]]"
---
# Funzione hash
---
## Introduzione
> Una **funzione hash** è una [[funzione-matematica|funzione]] $h$ usata da [[tabella-hash|tabelle hash]] che preso in input una chiave $k \in U$ dove $U$ è l'insieme di tutte le possibili chiavi, restituisce un valore $v \in [0, m-1]$, dove $m$ è la grandezza dell'array `T` della tabella hash.

## Proprietà
La proprietà fondamentale che ogni funzione hash dovrebbe rispettare è quella di [[uniformita-semplice|uniformità semplice]].

### Assunzioni probabilistiche
Possiamo definire alcune assunzioni che, anche se concretamente non possono essere tutte soddisfatte, idealmente definiscono un corretto criterio per implementari funzioni hash:
1. _tutte le chiavi sono equiprobabili_ (uniformità semplice) --> ovviamente quasi impossibile da attuare, è necessaria una semplificazione;
2. _la funzione hash può essere calcolata in [[complessita-computazionale|tempo costante]]_ $O(1)$ --> se così non fosse tale codifica dominerebbe il costo delle operazioni della tabella hash, ma ci accontentiamo di hashing sufficientemente veloci;
3. _tutte le chiavi sono valori interi non negativi_ --> vero perché possiamo sempre trasformare una qualsiasi chiave $k$ in un intero;

## Metodi
Tra le funzioni hash che analizziamo si trovano:
- [[metodo-della-divisione|Metodo della divisione]]
- [[metodo-della-moltiplicazione|Metodo della moltiplicazione]]
- [[metodo-della-codifica-algebrica|Metodo della codifica algebrica]]

## Referenze