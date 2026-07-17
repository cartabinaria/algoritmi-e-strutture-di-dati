---
tags:
  - category/note
  - status/finished
  - topic/programmazione
  - topic/algoritmi-e-strutture-dati
date: 25-10-2023 14:13:23
links:
  - "[[lecture-24102023100626|Lecture 24102023100626]]"
  - "[[lecture-04032024091423|Lecture 04032024091423]]"
---
# Selection sort
---
## Introduzione
> Il **selection sort** è un [[algoritmo-di-ordinamento-incrementale|algoritmo di ordinamento incrementale]], _in-place_ e _non stabile_, che funziona _cercando il minimo_ in $A[k+1, \cdots, n]$ (nel _postfisso_) e _spostandolo in posizione $k+1$_.

L'autore è sconosciuto, ma si sa che viene dagli anni '50.

## Algoritmo
Ad ogni passo $i = 1, \cdots, n-1$:
1. cerca la posizione $j$ della minima chiave $A[i, \cdots, n]$
2. swap tra $A[j]$ e $A[i]$

![[selection-sort.png]]

## Complessità
Per analizzare la [[complessita-computazionale|complessità computazionale]] dell'algoritmo ci serve anzitutto notare che a prescindere dalla condizione iniziale dell'array in input _il numero di operazioni non cambia_: significa che _caso ottimo_, _pessimo_ e _medio coincidono_.

Ora, scomponiamo l'algoritmo in 3 parti:
- `min` (ricerca del minimo), con costo $\Theta(n-i)$, dove $i$ è l'iterazione corrente
- `swap` (scambio di celle), con costo costante $O(1)$

Un'esecuzione media farà allora
$$(n-1) + (n-2) + (n-3) + \cdots + 1$$
operazioni in totale. Possiamo scrivere il risultato come la sommatoria
$$\sum\limits_{i=1}^{n-1} n - i = \sum\limits_{i=1}^{n-1} i = \frac{n(n-1)}{2}$$

Per cui il costo per tutti e 3 i casi sarà
$$\Theta(n^{2})$$

## Implementazione
In [[c|C]]/[[c|C++]] l'algoritmo è:
```cpp
void selection_sort(int v[], int n) {
	for (int i=0; i<n-1; i++) {
		int pos_min = i;
		for (int j=i+1; j<n; j++) {
			if (v[j] < v[pos_min])
				pos_min = j;
		}
		if (pos_min != i)
			swap(v[i], v[pos_min]);
	}
}
```

## Referenze