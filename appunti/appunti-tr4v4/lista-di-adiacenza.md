---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 28-04-2024 23:03:28
links:
  - "[[lecture-24042024111954|Lecture 24042024111954]]"
---
# Lista di adiacenza
---
## Introduzione
> Per **[[lista|lista]] di adiacenza** si intende una [[struttura-dati|struttura dati]] per la rappresentazione di [[grafo|grafi]].

## Implementazione
Dividiamo l'implementazione per i due tipi di grafo, nonostante la differenza sia solo concettuale.

### Grafo non orientato
Per i [[grafo-non-orientato|grafi non orientati]] la lista di adiacenza si compone di un **insieme di vertici ognuno dei quali è testa di una lista di vertici, di fatto i nodi ad esso adiacenti**.
$$v.adj = \{w | \{v, w\} \in E\}$$

Trattandosi di un grafo non orientato, _due vertici adiacenti hanno i rispettivi nodi nelle loro liste di adiacenza_.

<u>Nota bene</u>: la struttura dati designata per contenere i vertici-teste è a discrezione del programmatore. E', ovviamente, consigliato l'uso di [[tabella-hash|tabelle hash]] per una questione di efficienza.

### Grafo orientato
Per i [[grafo-orientato|grafi orientati]] la questione è la stessa, semplicemente la formula delle adiacenze di un vertice è
$$v.adj = \{w | (v, w) \in E\}$$

### Costi e operazioni
In entrambe le implementazioni lo spazio occupato in memoria è:
$$\Theta(n + m) = \Theta(|V| + |E|)$$

Assumendo che _$\delta(x)$ è la funzione che associa al nodo $x$ il suo grado_ (numero di vertici ad esso adiacenti), le principali operazioni esposte dalla struttura hanno costo:
- `grado(vertice v)` --> dobbiamo contare i nodi della lista associata al vertice --> $\Theta(\delta(v))$
- `archiIncidenti(vertice v)` --> stessa questione del grado --> $\Theta(\delta(v))$
- `sonoAdiacenti(vertice x, vertice y)` --> scorro entrambe le liste in parallelo fino a che non trovo una corrispondenza (non devo terminare l'altro scorrimento, perché il grafo non è orientato) --> $O(\min(\delta(x), \delta(y)))$
- `aggiungiVertici(vertice v)` --> aggiungi alla struttura dati un nuovo vertice --> $O(1)$
- `aggiungiArco(vertice x, vertice y)` --> $O(1)$
- `rimuoviVertice(vertice v)` --> bisogna scorrere tutte le liste di ogni vertice ed eliminare l'arco associato al vertice eliminato `v` --> $O(m)$
- `rimuoviArco(arco e)` --> scorro le liste degli estremi dell'arco `e` e rimuovo le rispettive corrispondenze --> $O(\delta(x) + \delta(y))$

## Referenze