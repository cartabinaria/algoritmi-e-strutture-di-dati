---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 28-03-2024 19:53:20
links:
  - "[[lecture-26032024111318|Lecture 26032024111318]]"
---
# Heap sort
---
## Introduzione
> L'**heap sort** è un [[algoritmo-di-ordinamento-incrementale|algoritmo di ordinamento incrementale]], _in-place_ e _non stabile_, che utilizza un [[array-heap|array heap]] e le sue operazioni per ordinare l'array.

## Algoritmo
L'idea in particolare è quella di
1. costruire un _max-heap_ binario su array a partire dal vettore `A` originale attraverso l'operazione `heapify`;
2. estrarre il massimo con `findMax` e `deleteMax`, decrementando la dimensione dell'heap;
3. inserire il massimo nell'ultima posizione di `A`, e tornare al punto 2 finché l'heap non è vuoto.

### Pseudocodice
```R
function heapSort(int S[]) {
	heapify(S, S.length, 1);
	for (int c=S.length; c>1; c--) {
		int k = findMax(S);
		deleteMax(S, c);
		S[c] = k;
	}
}
```

## Complessità
La [[complessita-computazionale|complessità computazionale]] dell'algoritmo dipende unicamente dal [[iterazione|ciclo]] `for` e dai costi di `heapify`, `findMax` e `deleteMax`. In particolare:
- `heapify`: $O(n)$;
- `findMax`: $O(1)$;
- `deleteMax`: $n$ volte $\log{n}$ per il `for`, per cui $\Theta(n\log{n})$.

Per cui sommando ci viene
$$\Theta(n \log{n})$$

## Referenze