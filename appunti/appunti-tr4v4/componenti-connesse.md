---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 04-05-2024 23:51:29
links:
  - "[[lecture-02052024091854|Lecture 02052024091854]]"
---
# Componenti connesse
---
## Introduzione
> La ricerca delle **componenti connesse** di un [[grafo|grafo]] $G$ _consiste nella identificazione del gruppo connesso di appartenenza per ogni vertice_, dove _per gruppo connesso si intende un sottografo connesso_.

## Grafo non orientato
Per i grafi non orientati è semplice cercare le componenti connesse per ogni vertice: _basta suddividere in gruppi i vertici tali che tra i gruppi non ci siano archi che li connettono e che i vertici di uno stesso gruppo siano connessi_.

Si può basare l'algoritmo sulla [[dfs-su-grafi|visita DFS]] modificata:
```R
function CC(G) {
	for each u in V {
		u.cc := -1;
		u.parent := NIL;
	}
	k := 0;
	for each u in V {
		if (u.cc < 0) {
			CC-visit(u,k);
			k := k+1;
		}
	}
}

function CC-visit(u, k) {
	u.cc := k;
	for each v adiacente a u {
		if (v.cc < 0) {
			v.parent := u;
			CC-visit(v, k);
		}
	}
}
```

`CC`:
1. per ogni vertice $u$ settiamo la sua componente connessa `u.cc` a `-1`;
2. impostiamo il contatore delle componenti connesse $k$ a $0$ (`k = 0`);
3. per ogni vertice $u$:
	1. se la componente ancora non è stata impostata (`u.cc < 0`):
		1. richiamiamo la funzione di visita ricorsiva `CC-visit` di quel vertice con la componente connessa corrente;
		2. quindi, una volta compilata ricorsivamente tutto il gruppo connesso del vertice $u$, incrementiamo $k$ (`k = k+1`);

`CC-visit`:
1. settiamo il valore della componente connessa del vertice $u$ a $k$ (`u.cc = k`);
2. per ogni nodo $v$ adiacente a $u$:
	1. se la componente di $v$ ancora non è stata impostata (`v.cc < 0`):
		1. impostiamo il padre di $v$ come $u$ (`v.parent = u`);
		2. richiamiamo ricorsivamente `CC-visit` su $v$, passando sempre $k$ come valore della componente;

## Grafo orientato
Per i grafi orientati, invece, la questione si complica non di poco: _un grafo $G$ orientato può essere debolmente connesso ma non fortemente_, per cui _all'interno di una stessa componente debolmente connessa è possibile avere distinte componenti fortemente connesse_ che non sono facili da individuare.
![[scc.png]]

### Analisi matematica
E' doveroso anzitutto chiedersi se sia matematicamente possibile trovare sempre un _criterio per poter identificare le componenti fortemente connesse di un grafo orientato_. In particolare ci chiediamo se sia possibile _partizionare i vertici sulla relazione di connessione forte_: per farlo bisogna verificare che tale [[relazione-di-equivalenza|relazione sia di equivalenza]].

Affinché la relazione di connessione forte tra due vertici connessi $u, v$ sia di equivalenza questa dev'essere:
- _riflessiva_: $u$ è raggiungibile da se stesso;
- _simmetrica_: da $u$ raggiungo $v$ e da $v$ raggiungo $u$, per definizione di connessione forte;
- _transitiva_: da $u$ raggiungo $v$, e da $v$ raggiungo $w$, allora da $u$ posso raggiungere $w$.

Per cui sì: la relazione di connessione forte è di equivalenza. E questo ci dice matematicamente che **è sempre possibile [[insieme-quoziente|quozientare]] un insieme di vertici $V$ sulla relazione di equivalenza di connessione forte**.

### Algoritmi
Ci sono molti algoritmi che consentono di fare questo partizionamento su grafo orientati, alcuni poco e altri molto efficienti. Noi ne analizziamo uno appartenente alla prima categoria.

#### Idea
Con una visita qualsiasi, anche la [[bfs-su-grafi|BFS]], calcolo di un vertice $x$ l'insieme dei nodi da esso raggiungibili $D(x)$ (discendenti). Quindi inverto la direzione di tutti gli archi del grafo e calcolo sempre a partire da $x$ l'insieme dei nodi da esso raggiungibili $A(x)$ (ascendenti).

A questo punto la componente fortemente connessa di $x$ non sarà altro che l'[[definizione-di-intersezione|intersezione]] tra il primo e il secondo insieme, ovvero
$$D(x) \cap A(x)$$

#### Implementazione
L'algoritmo allora dovrà eseguire i seguenti passi:
1. per ogni vertice $v \in V$:
	1. inizializzo una lista $L$ vuota di nodi fortemente connessi a $v$;
	2. eseguo la BFS su $v$, marcando i nodi visitati;
	3. calcolo $G^{T}$, ovvero il grafo trasposto (con gli archi invertiti);
	4. eseguo la BFS su $v$, mettendo in $L$ solo i nodi già marcati dalla visita precedente, ottenendo di fatto l'intersecazione tra $D(x)$ e $A(x)$;
	5. restituisco $L$.

#### Costo computazionale
Questa implementazione prevede di scorrere tutti i nodi $v \in V$ ($O(n)$), e per ognuno di essi svolgere 3 operazioni di costo $O(n+m)$ (eseguire la BFS, calcolare $G^{T}$ e rieseguire la BFS), per un [[complessita-computazionale|costo]] complessivo di:
$$O(n(n+m)) = O(n^{2} + nm)$$

#### Idee migliori...
Algoritmi in grado di fare lo stesso ma in tempo lineare rispetto al numero di vertici e di archi ($O(n + m)$) sono:
- [[algoritmo-di-kosaraju|algoritmo di Kosaraju]]
- [[algoritmo-di-tarjan|algoritmo di Tarjan]]

## Referenze