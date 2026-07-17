---
tags:
  - category/note
  - status/finished
  - topic/programmazione
  - topic/algoritmi-e-strutture-dati
date: 30-11-2023 17:41:26
links:
  - "[[lecture-22112023092107|Lecture 22112023092107]]"
  - "[[lecture-04032024091423|Lecture 04032024091423]]"
---
# Merge sort
---
## Introduzione
> Il **merge sort** è un [[algoritmo-di-ordinamento-divide-et-impera|algoritmo di ordinamento divide et impera]], _non in-place_ e _stabile_, che funziona _dividendo l'array in due metà, ordinando [[ricorsione|ricorsivamente]] tali metà, e una volta ordinate combinarle in un unico array ordinato_.

L'autore è niente meno che [[john-von-neumann|John Von Neumann]][^1], che lo ha introdotto nel 1945.

## Algoritmo
L'algoritmo si divide, come da programma, in 3 fasi:
- _divide_
	- dividiamo $A[1, \cdots, n]$ in due metà $A_{1} = A[1, \cdots, q]$ e $A_{2} = A[q+1, \cdots, n]$ dove $q = \lfloor \frac{1+n}{2} \rfloor$
- _conquer_
	- dobbiamo ordinare i due array $A_{1}$ e $A_{2}$
	- quindi richiamiamo ricorsivamente l'algoritmo sui due sotto-array $A_{1}$ e $A_{2}$, fino ad ottenerne di due soli elementi
- _combine_
	- combiniamo i due array ordinati $A_{1}$ e $A_{2}$ in un unico array ordinato, anche detta fase di `merge`

<u>Nota bene</u>: l'algoritmo è _stabile_ perché `merge` preserva la stabilità, ma è _non in-place_ perché utilizza un array di appoggio, e trasformarlo _in-place_ lo rende complicatissimo e meno efficiente.

![[merge-sort.png]]
![[merge.png]]

## Complessità
Per analizzarne la [[complessita-computazionale|complessità computazionale]] definiamo prima la complessità di `merge`. Di un array di dimensione $n$ passato in input, tale che le due sotto-metà siano ordinate, l'algoritmo `merge` scorre linearmente l'array andando a copiare nell'ordine giusto gli elementi in un array di appoggio; quindi ricopia l'array di appoggio sull'array in input. In definitiva `merge` è $\Theta(n)$.

Essendo allora `mergeSort` un algoritmo ricorsivo, possiamo applicare il [[master-theorem|master theorem]] per risolvere la seguente [[equazione-di-ricorrenza|equazione di ricorrenza]] associata:
$$T(n) = \begin{cases} 1 & n \leq 1 \\ 2T(\frac{n}{2}) + n & n > 1 \end{cases}$$

che risolta ci dà
$$\Theta(n \log{n})$$

<u>Nota bene</u>: tale costo _coincide per caso ottimo_, _pessimo_ e _medio_.

## Implementazione
Un'implementazione in [[c|C]]/[[c|C++]] è del tipo:
```cpp
void merge(int A[], int l, int m, int r) {
	int i, j, k, B[length];
	i=l; k=l; j=m+1;
	while (i<=m && j<=r) {
		if(A[i] <= A[j]) {
			B[k]= A[i];
			i++;
		} else {
			B[k]= A[j];
			j++;
		}
		k++;
	}
	if (i<=m)
		for(int h=m; h>=i; h=h-1) A[h+r-m]=A[h];
	for(j=l; j<k; j++) A[j] = B[j];
}

void mergesort(int A[], int l, int r) {
	int m;
	if (l < r) {
		m = (l+r) / 2;
		mergesort(A, l, m);
		mergesort(A, m+1, r);
		merge(A, l, m, r);
	}
```

Spiegazione:
- _caso base_: un array di 0 o 1 elemento è già ordinato
- _caso induttivo_: dividi l'array a metà, ordinali ricorsivamente, quindi fondile (_merge_) ordinatamente

## Referenze
[^1]: l'inventore dell'omonima [[architettura-di-von-neumann|architettura]]