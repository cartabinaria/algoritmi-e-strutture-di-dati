---
tags:
  - category/note
  - status/finished
  - topic/programmazione
  - topic/algoritmi-e-strutture-dati
date: 03-12-2023 16:07:13
links:
  - "[[lecture-29112023092601|Lecture 29112023092601]]"
  - "[[lecture-18032024091043|Lecture 18032024091043]]"
---
# Albero binario di ricerca
---
## Introduzione
> Un **albero binario di ricerca** è un [[albero-binario|albero binario]] cui _nodi sono ordinati in modo crescente da sinistra a destra_. Si ha che ogni nodo centrale è maggiore di tutti i nodi del sottoalbero sinistro e minore di tutti i nodi del sottoalbero destro. In altre parole un albero binario di ricerca è un albero binario cui ogni nodo contiene una chiave confrontabile e dati associati alla chiave, e per il quale tutte le chiavi nel sottoalbero sinistro di `v` sono $\leq$ `v.key`, e tutte le chiavi nel sottoalbero destro di `v` sono $\geq$ `v.key`.

Risalgono al 1960. Applicando una [[dfs|visita in-order]] dell'albero _otteniamo gli elementi ordinati in modo crescente_.

![[albero-binario-di-ricerca.png]]

## Operazioni
### Ricerca - `search(Key k)`
L'algoritmo di ricerca di un valore all'interno di tali alberi si riduce ad una versione bidimensionale della [[ricerca-dicotomica|ricerca binaria]] degli [[array|array]]: è molto semplice e si può facilmente implementare con la [[ricorsione|ricorsione]] in coda (se supportata dal [[linguaggio-di-programmazione|linguaggio]]); ovviamente c'è anche la soluzione iterativa.

I [[complessita-computazionale|costi]] sono, perciò:
- $O(1)$ nel _caso ottimo_, ovvero quando la radice ha l'elemento cercato;
- $\Theta(h) = O(n)$ nel _caso pessimo_, ovvero quando l'elemento cercato non è presente nell'albero o è una foglia, ed è $\Theta(n)$ quando l'albero è una lista.

Perciò nel caso peggiore il costo è equivalente al cammino più lungo dell'albero.

#### In [[c|C++]]
```cpp
bool search(btree *t, int n) {
	if (t == NULL) return false;
	else if (t->val == n) return true;
	else if (t->val > n) return search(t->ltree, n);
	else return search(t->rtree, n);
}
```

### Inserimento - `insert(Key k, Data d)`
L'inserimento di un nuovo elemento in un albero di ricerca si implementa facilmente con un[[algoritmo|algoritmo]] ricorsivo. Iterativo è scomodo.

I costi sono:
- $O(1)$ nel _caso ottimo_, quando l'albero è solo la radice;
- $\Theta(h) = O(n)$ nel _caso pessimo_, quando il nodo da inserire ha come padre una foglia.

#### In C++
```cpp
btree *t_insert(btree *t, int n) {
	if (t == NULL) {
		btree *tmp = new btree;
		tmp->val = n;
		tmp->ltree = NULL;
		tmp->rtree = NULL;
	} else if (t->val > n) t->ltree = t_insert(t->ltree, n);
	else t->rtree = t_insert(t->rtree, n);
	return t;
}
```

### Minimo e massimo - `min(Node T), max(Node T)`
Vogliamo sapere il nodo minimo e il nodo massimo di un albero, che può essere sottoalbero (per cui _minimo/massimo locale_) o direttamente la radice (per cui _minimo/massimo assoluto_). Nota che:
- il nodo minimo in un albero binario di ricerca è quello più a sinistra;
- il nodo massimo in un albero binario di ricerca è quello più a destra;

Gli algoritmi sono quindi semplici da implementare, e i costi sono:
- $O(1)$ nel _caso ottimo_, dove
	- massimo --> la radice non ha figlio destro;
	- minimo --> la radice non ha figlio sinistro;
- $\Theta(h) = O(n)$ nel _caso pessimo_.

### Predecessore - `predecessor(Node T)`
Quest'operazione deve, di un nodo in input `T`, restituire il nodo che lo precede in una visita _in-order_. Si distinguono due casi per il quale possiamo identificare un algoritmo per trovare il predecessore di un nodo `T`:
1. `T.left != NULL` --> il predecessore è il _massimo_ del sottoalbero sinistro di un nodo, ovvero `max(T.left)`;
2. `T.left == NULL` --> il predecessore è il primo antenato tale che `T` stia nel sottoalbero destro dell'antenato.

![[bst-predecessor.png]]

I costi, uguali per entrambi i casi, sono:
- $O(1)$ nel _caso ottimo_;
- $\Theta(h) = O(n)$ nel _caso pessimo_.

### Successore - `successor(Node T)`
Quest'operazione, _simmetrica a `predecessor`_ deve, di un nodo in input `T`, restituire il nodo che lo procede in una visita _in-order_. Si distinguono due casi per il quale possiamo identificare un algoritmo per trovare il successore di un nodo `T`:
1. `T.right != NULL` --> il predecessore è il _minimo_ del sottoalbero destro di un nodo, ovvero `min(T.right)`;
2. `T.right == NULL` --> il predecessore è il primo antenato tale che `T` stia nel sottoalbero sinistro dell'antenato.

I costi, uguali per entrambi i casi, sono:
- $O(1)$ nel _caso ottimo_;
- $\Theta(h) = O(n)$ nel _caso pessimo_.

### Eliminazione - `delete(Key k)`
Le operazioni soprastanti sono fondamentalmente propedeutiche a quella dell'eliminazione. Infatti, a differenza di quanto avverrebbe per un albero binario, l'**eliminazione di un nodo in un albero binario di ricerca deve mantenere stabile il criterio di ordinamento dell'albero**. Si distinguono allora 3 casi per l'eliminazione di un nodo `T` con chiave `k`:
1. `T` è una foglia --> si elimina semplicemente `T`;
2. `T` ha un solo figlio (non importa se destro o sinistro) --> si fa ereditare al padre di `T` il figlio di `T`;
3. `T` ha entrambi i figli --> si individua il predecessore (o anche il successore) di `T` e si scambia `T` con quel predecessore, che si elimina poi come se fosse un nodo del caso 1 (o 2[^1]).

![[bst-delete.png]]
![[bts-disconnect.png]]

I costi dell'operazione, dipendenti unicamente da `search`, `predecessor` e `disconnect`, saranno allora:
- $O(1)$ nel _caso ottimo_;
- $\Theta(h) = O(n)$ nel _caso pessimo_.

### Caso medio
Tutti i casi pessimi delle operazioni descritte sopra dipendono da $h$, ovvero l'altezza dell'albero. Perciò **il costo medio dipenderà dall'altezza media di un albero binario di ricerca**. Se sappiamo l'altezza media possiamo determinare il costo medio di tutte le operazioni viste.

Sappiamo individuare molto facilmente i due casi di _altezza massima_ e _altezza minima_ di un albero binario di ricerca:
1. l'altezza massima di un albero di $n$ nodi è proprio $n$, nel caso in cui si presenti come una _lista_: ![[albero-lista.png]]
2. l'altezza minima di un albero di $n$ nodi è invece $\log_{2}{n}$, come da [[albero-binario-profondita|formula]], nel caso in cui l'_albero è perfetto_: ![[albero-perfetto.png]]

Allora si può dimostrare in modo facile che con $n$ inserimenti casuali, l'altezza media di un albero binario di ricerca risulti essere
$$avg(h) = O(\log{n})$$

## Referenze
- [[albero-avl|Albero AVL]]

[^1]: nota che in questo caso, con `T` avente entrambi i figli, il predecessore/successore non sarà mai un antenato