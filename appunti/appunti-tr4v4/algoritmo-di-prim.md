---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 10-06-2024 09:36:40
links:
  - "[[lecture-07052024111936|Lecture 07052024111936]]"
---
# Algoritmo di Prim
---
## Introduzione
> L'**algoritmo di Prim** è un [[algoritmo|algoritmo]] che consente di identificare il [[minimum-spanning-tree|minimum spanning tree]] di un [[grafo|grafo]], _facendo uso soltanto della regola del taglio_.

## Idea
L'idea è di, a partire da un vertice radice $r$, di _accrescere il minimum spanning tree mantenendo la proprietà di minimizzazione del peso_. In particolare si associa ad ogni nodo un valore di distanza, all'inizio $\infty$ per tutti; quindi a partire da $r$ si aggiungono le adiacenze in una [[struttura-dati|struttura dati]] che mantenga l'ordine dei vertici sulla base della loro distanza. Quindi, per ogni adiacenza:
- se tale nodo ha **distanza infinita si aggiunge alla struttura dati** (in fondo);
- se tale nodo ha una **distanza maggiore del peso dell'arco che collega il vertice analizzato a tale nodo**, allora si **aggiunge alla struttura dati con distanza uguale al peso dell'arco**.

## Algoritmo
Per implementare l'idea si ha bisogno fondamentalmente di una _struttura dati che consenta di mantenere dinamicamente l'ordine di una lista di vertici_, sulla base di una chiave (la loro distanza): possiamo usare una [[coda-con-priorita|coda con priorità]]!

Lo pseudocodice sarà il seguente:
```R
integer[] Prim-MST(Grafo G=(V,E,w), nodo s) {
	double d[1..n]
	integer p[1..n]
	boolean b[1..n]
	for v ← 1 to n {
		d[v] ← ∞
		p[v] ← -1
		b[v] ← false
	}
	d[s] ← 0
	CodaPriorita<integer, double> Q
	Q.insert(s, d[s])
	while (not Q.isEmpty()) {
		u ← Q.findMin()
		Q.deleteMin()
		b[u] ← true
		for each v ∈ (u.adj \ {z | b[z]}) {
			if (d[v] == ∞) {
				Q.insert(v, w(u,v))
				d[v] ← w(u,v)
				p[v] ← u
			} else if (w(u,v) < d[v]) {
				Q.decreaseKey(v, w(u,v))
				d[v] ← w(u,v)
				p[v] ← u
			}
		}
	}
	return p
}
```

### Costo computazionale
Il [[complessita-computazionale|costo]] dell'algoritmo dipende dal 1° `for`, dal `while` e dal `for` dentro esso, nonché dalle operazioni della coda con priorità.

In particolare il 1° `for` compie esattamente $n$ operazioni di assegnamento, per cui costerà $\Theta(n)$.

Il `while` complessivamente verrà eseguito $n$ volte, perché ogni ciclo eliminerà un vertice dagli $n$ totali. All'interno ritroviamo un `deleteMin` e un `for` che per $m$ volte (perché al peggio considereremo tutti gli archi per ogni nodo), eseguirà un `insert` o un `decreaseKey`. Assumendo di star lavorando con un [[d-heap|D-heap]], sia `deleteMin`, che `insert` che `decreaseKey` hanno un costo logaritmico. In particolare avremo:
- `deleteMin` eseguito $n$ volte --> $O(n\log{n})$
- `insert` eseguito sicuramente $n$ volte (dobbiamo inserire tutti i vertici) --> $O(n\log{n})$
- `decreaseKey` eseguito al massimo $m$ volte, ossia $O(m)$ volte `decreaseKey` --> $O(m) \cdot O(\log{n}) = O(m\log{n})$

In totale, allora, si avrà
$$O(n\log{n}) + O(n\log{n}) + O(m\log{n}) = O(\log{n} + n\log{n} + m\log{n}) = O(n\log{n} + m\log{n})$$

e sapendo che $m \geq n-1$ perché il grafo è connesso per ipotesi, allora
$$O(n\log{n} + m\log{n}) = O(m\log{n})$$

## Referenze