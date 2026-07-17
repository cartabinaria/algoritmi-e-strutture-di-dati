---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 12-05-2024 22:21:40
links:
  - "[[lecture-06052024092734|Lecture 06052024092734]]"
---
# Algoritmo di Kruskal
---
## Introduzione
> L'**algoritmo di Kruskal** è un [[algoritmo|algoritmo]] che consente di identificare il [[minimum-spanning-tree|minimum spanning tree]] di un [[grafo|grafo]], _fissando un ordine di applicazione delle regole del taglio e del ciclo_.

## Idea
L'idea è di _considerare gli archi in ordine non decrescente di peso_, e:
- se l'arco $e = \{u, v\}$ **connette due alberi blu non della stessa [[componenti-connesse|componente]]** (sconnessi, disgiunti) --> lo coloriamo di **blu**;
- se l'arco $e = \{u, v\}$ **connette due alberi blu della stessa componente** (connessi) --> lo coloriamo di **rosso**.

Quindi _ripetiamo lo stesso procedimento per $n-1$ volte, oppure fino a che tutti gli archi non sono colorati_.

## Algoritmo
Sono necessari due semplici ingredienti per implementare Kruskal in modo semplice:
- sappiamo intanto di _dover ordinare gli archi in ordine non decrescente_, per cui sicuramente dovremmo tirare in gioco un [[algoritmo-di-ordinamento|algoritmo di ordinamento]];
- ci serve poi _verificare dei due vertici di un arco se sono fondamentalmente connessi_ in modo efficiente: possiamo benissimo usare le [[struttura-union-find|strutture union-find]]!

Lo pseudocodice complessivo allora sarà il seguente:
```R
Tree Kruskal-MST(Grafo G=(V,E,w)) {
	UnionFind UF
	Tree T ← albero vuoto
	for i ← 1 to G.numNodi() {
		UF.makeSet(i)
	}
	sort(E, w)
	for each {u,v} in E {
		Tu ← UF.find(u)
		Tv ← UF.find(v)
		if (Tu ≠ Tv) {
			T ← T ∪ {u, v}
			UF.union(Tu, Tv)
		}
	}
	return T
}
```

### Costo computazionale
Il [[complessita-computazionale|costo]] dell'algoritmo dipende dal 1° `for`, dall'operazione di `sort`, dal 2° `for` e dalle operazioni `find` e `union` della struttura union-find di supporto all'interno di questo.

In particolare si ha che il 1° `for` compie esattamente $n$ `makeSet`, che per qualunque [[struttura-union-find-implementazioni|implementazione]] della union-find è sempre costante: $\Theta(n)$.

Il `sort`, assumendo di star usando un [[algoritmo-di-ordinamento-comparativo|algoritmo di ordinamento comparativo]][^1] ottimale, agendo su $m$ archi ha costo: $O(m \log{m})$.

Il 2° `for` per $m$ volte invocherà, non tenendo conto dell'`if`, le operazioni `find` e `union` della union-find sugli $n$ nodi, per cui _a prescindere dall'implementazione[^2] ma assumendo si basi sull'euristica_ sappiamo che il costo massimo è $O(\log{n})$.

In totale avremo allora un costo:
$$O(n + m\log{m} + m\log{n})$$
e considerando che il numero di archi ha un upper-bound $n^{2}$, per cui $m = O(n^{2})$, si ha che $O(m\log{m}) = O(m\log{n^{2}}) = O(m\log{n})$. Per cui si ottiene un costo:
$$O(n + 2m\log{n})$$

e sapendo che $m \geq n-1$ perché siamo in un grafo connesso per ipotesi si ha:
$$O(m\log{n})$$

## Referenze
[^1]: come il [[merge-sort|merge sort]]
[^2]: che sia [[quick-find|Quick find]] o [[quick-union|Quick union]]