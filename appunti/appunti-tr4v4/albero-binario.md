---
tags:
  - category/note
  - status/finished
  - topic/programmazione
  - topic/algoritmi-e-strutture-dati
date: 30-11-2023 18:05:47
links:
  - "[[lecture-28112023101904|Lecture 28112023101904]]"
  - "[[lecture-29112023092601|Lecture 29112023092601]]"
  - "[[lecture-14032024091535|Lecture 14032024091535]]"
---
# Albero binario
---
## Introduzione
> Un **albero binario** è un tipo di [[albero|albero]] cui _ogni nodo può essere una foglia oppure diramarsi in un sottoalbero sinistro e un sottoalbero destro_.

![[albero-binario.png]]

Da un punto di vista [[algebra-astratta|algebrico]], l'albero binario è un [[adt|ADT]] definito dalla _tripla_
$$T' ::= \varnothing \ | \ \mathcal{N}(T', \mathbb{N}, T')$$

### Definizioni
Dizionario delle caratteristiche di un albero binario:
- _profondità di un nodo_ $u$: lunghezza del percorso unico dalla radice al nodo $u$;
- _livello_: l'insieme di tutti i nodi alla stessa profondità;
- _altezza_: massima profondità di un albero
	- l'albero vuoto ha altezza -1;
	- l'albero con solo radice ha altezza 0;

### Tipologie
Un albero binario può essere:
- _completo_ se ogni nodo intermedio ha due figli;
- _perfetto_ se è completo e tutte le foglie sono alla stessa profondità;

## Teoremi
### Caratterizzazione
> Ogni albero non vuoto con $n$ nodi ha esattamente $n-1$ archi.

Si dimostra [[induzione-strutturale|per induzione]], e può essere usato per capire se una struttura è un albero o meno.

### Profondità
Il numero di nodi di un albero binario _perfetto_ di profondità $h$ è pari a
$$\sum\limits_{i = 0}^{h} 2^{i} = 2^{h+1} - 1$$

## Implementazione
Ogni nodo ha:
- `parent` --> [[puntatore|puntatore]] al nodo padre
- `key`, `data` --> associazione chiave-valore
- `left`, `right` --> puntatore ai figli

### In [[c|C++]]
Si utilizzano [[struttura-dati|strutture]] con 3 campi:
```cpp
struct btree {
	int val;
	btree *ltree;
	btree *rtree;
};
```

## Operazioni
### Creazione

#### In C++
```cpp
pbtree create_btree(int n) {
	if (n == 0) return(NULL);
	else {
		pbtree t = new btree;
		t->val = rand()%50;
		t->ltree = create_btree(n-1);
		t->rtree = create_btree(n-1);
		return(t);
	}
}
```

### Visita
Ci sono due principali paradigmi di visita: [[dfs|DFS]] e [[bfs|BFS]].

#### DFS
In questo caso sappiamo di dover dividere la visita in 3 casi: _pre-fissa_, _post-fissa_, _in-fissa_.

##### Pre-ordine
![[dfs-pre-ordine.png]]

[[complessita-computazionale|Costo]]: $\Theta(n)$, tranquillamente verificabile con il [[master-theorem|master theorem]] ma triviale per il fatto che dobbiamo visitare tutti gli $n$ nodi dell'albero.

##### Post-ordine
![[dfs-post-ordine.png]]

Costo: $\Theta(n)$.

##### In-ordine
![[dfs-in-ordine.png]]

Costo: $\Theta(n)$.

<u>Nota bene</u>: nel caso di un _[[albero-non-binario|albero non-binario]]_, per la _verifica in-fissa bisogna stabilire una posizione nel quale stampare il nodo corrente_: tra il primo e tutti i rimanenti? Come penultimo?

#### BFS
Si utilizza una [[coda|coda]] come struttura di supporto per salvare i nodi da visitare:
![[bfs-tree.png]]

#### In C++
```cpp
// Visita prefissa
void pre_visit(pbtree t) {
	if (t != NULL) {
		cout << t->val << "\t";
		visit(t->ltree);
		visit(t->rtree);
	}
}

// Visita infissa
void in_visit(pbtree t) {
	if (t != NULL) {
		visit(t->ltree);
		cout << t->val << "\t";
		visit(t->rtree);
	}
}

// Visita postfissa
void post_visit(pbtree t) {
	if (t != NULL) {
		visit(t->ltree);
		visit(t->rtree);
		cout << t->val << "\t";
	}
}
```

### Ricerca
La ricerca di un valore in un albero, _per quanto elegante_, se implementata [[ricorsione|ricorsivamente]] ha una **complessità computazionale pessima**: di fatto _bisogna provare tutte le possibili strade dell'albero_, esattamente come avviene per la ricerca in un array disordinato.

Solitamente, infatti, la ricerca si computa su [[albero-binario-di-ricerca|alberi binari di ricerca]].

#### In C++
```cpp
bool search(btree *t, int n) {
	if (t == NULL) return false;
	else if (t->val == n) return true;
	else return search(t->ltree, n) || search(t->rtree, n);
}
```

## Referenze
- [[albero-non-binario|Albero non-binario]]