---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 12-03-2024 18:13:46
links:
  - "[[lecture-11032024094827|Lecture 11032024094827]]"
---
# Coda
---
## Introduzione
> La **coda** è una [[struttura-dati|struttura dati]] [[strutture-dati-elementari|elementare]] basata sul modello [[fifo|FIFO]] che supporta due operazioni: `ENQUEUE` e `DEQUEUE`. Viene utilizzata per esempio nello [[scheduling|scheduling]] dei processi nei [[sistema-operativo|sistemi operativi]], o nella visita [[bfs|breadth-first-search]] su [[grafo|grafi]].

## Implementazioni
### [[lista|Liste]] concatenate circolari
Si può implementare una coda attraverso liste concatenate circolari, e ciò comporta i seguenti vantaggi e svantaggi:
- _pro_: dimensione illimitata
- _con_: overhead di memoria (addirittura 2 [[puntatore|puntatori]])

### Liste concatenate semplici con puntatore a testa e a coda
Anche in questo casi i vantaggi e gli svantaggi sono simili a quelli delle liste circolari, con l'unica differenza che non c'è overhead.

### [[array|Array]] circolari
L'opzione che andiamo ad analizzare però è con gli array circolari. Bisogna stare attenti ad una serie di aspetti, tra cui l'operatore `%`[^1] per permettere la visita circolare dell'array.
![[enqueue-array.png]]
![[dequeue-array.png]]

E' addirittura possibile implementare questa soluzione con un array circolare dinamico. Ma bisogna fare particolare _attenzione durante la fase di ridimensionamento dell'array per mantenere l'ordine degli elementi_: _bisogna prima copiare a partire da head, e poi da tail_.

## Referenze
[^1]: il modulo