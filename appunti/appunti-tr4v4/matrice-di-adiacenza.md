---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 28-04-2024 22:52:01
links:
  - "[[lecture-24042024111954|Lecture 24042024111954]]"
---
# Matrice di adiacenza
---
## Introduzione
> Per **[[matrice|matrice]] di adiacenza** si intende una [[struttura-dati|struttura dati]] per la rappresentazione di [[grafo|grafi]].

## Implementazione
Dividiamo l'implementazione a seconda del tipo di grafo in questione, nonostante in realtà si tratti di una differenza prettamente teorica.

### Grafo non orientato
Per i [[grafo-non-orientato|grafi non orientati]] si utilizza una matrice $n \times n$[^1] compilata secondo la seguente equazione:
$$M(u, v) = \begin{cases}1 & \{u, v\} \in E \\ 0 & \{u, v\} \notin E \end{cases}$$

Trattandosi di un grafo non orientato, nella posizione $(u, v)$ e $(v, u)$ il valore dell'arco sarà identico: il risultato è che _$M$ è una [[matrice-simmetrica|matrice simmetrica]]_!

### Grafo orientato
Per i [[grafo-orientato|grafi orientati]] la questione è bene o male la stessa, ma la matrice viene compilata secondo la seguente equazione:
$$M(u, v) = \begin{cases}1 & (u, v) \in E \\ 0 & (u, v) \notin E \end{cases}$$

perciò $M$ non è simmetrica.

### Costi e operazioni
In entrambi i casi lo spazio occupato in memoria ha [[complessita-computazionale|costo]]
$$\Theta(n^{2}) = \Theta(|V|^{2})$$

il che non è sicuramente ottimale: _si utilizza di fatto memoria anche per gli spazi negativi, ovvero i non-archi_.

Analizziamo ora i costi computazionali dei principali metodi esposti dalla struttura:
- `grado(vertice v)` --> guardiamo la riga del vertice `v` e contiamo quanti 1 appaiono --> costo $\Theta(n)$
- `archiIncidenti(vertice v)` --> guardiamo la riga del vertice `v` e ogni volta che trovo un 1 aggiungo la coppia corrispondente al risultato da restituire --> costo $\Theta(n)$
- `sonoAdiacenti(vertice x, vertice y)` --> guardiamo la cella corrispondente a `M[x,y]` e restituiamo il risultato (1 o 0) --> costo $O(1)$
- `aggiungiVertici(vertice v)` --> dobbiamo _ridimensionare la matrice_ --> $\Theta(n^{2})$
- `aggiungiArco(vertice x, vertice y)` --> basta accedere a `M[x,y]` e mettere 1 --> $O(1)$
- `rimuoviVertice(vertice v)` --> dobbiamo ridimensionare la matrice --> $\Theta(n^{2})$
- `rimuoviArco(arco e)` --> basta accedere a `M[x, y]` e mettere 0 --> $O(1)$

## Referenze
[^1]: dove $n = |V|$