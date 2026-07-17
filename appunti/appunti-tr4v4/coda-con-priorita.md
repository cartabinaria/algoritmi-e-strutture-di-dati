---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 29-03-2024 10:09:39
links:
  - "[[lecture-27032024112108|Lecture 27032024112108]]"
---
# Coda con priorità
---
## Introduzione
> Una **coda con priorità** (o **priority queue**) è una [[struttura-dati|struttura dati]] che _restituisce il minimo in un insieme dinamico di coppie_ (_key_, _data_) _ordinate secondo una relazione d'ordine totale definita sulle chiavi_.

A differenza di [[coda|code]] e [[pila|pile]], per le quali _la scelta di chi dev'essere estratto dipende da quanto tempo ogni elemento è presente nella lista_, una coda con priorità _sceglie chi estrarre in base alla priorità_ (_chiave_) assegnata a ogni elemento[^1].

<u>Nota bene</u>: le code con priorità sono un [[prototipo-vs-implementazione|prototipo]], non un'implementazione.

## Operazioni
Le operazioni esposte da una coda con priorità sono:
- `findMin()`;
- `insert(Elem e, Key k)`;
- `delete(Elem e)`;
- `deleteMin()`;
- `increaseKey(Elem e, Key k)`: rimpiazza la chiave dell'elemento `e` con la nuova chiave `k`, se `k` è maggiore della chiave di `e`;
- `decreaseKey(Elem e, Key k)`: rimpiazza la chiave dell'elemento `e` con la nuova chiave `k`, se `k` è minore della chiave di `e`;

## Implementazioni
Le implementazioni principali di una coda con priorità sono:
- [[d-heap|D-heap]]
- [[heap-binomiale|Heap-binomiale]]
- [[heap-di-fibonacci|Heap di Fibonacci]]

## Referenze
[^1]: si pensi alla gestione della [[interrupt-tipologie|gerarchia degli interrupt]]!