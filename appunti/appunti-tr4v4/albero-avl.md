---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 24-03-2024 15:34:36
links:
  - "[[lecture-19032024112453|Lecture 19032024112453]]"
---
# Albero AVL
---
## Introduzione
> Un **albero AVL** ([[adelson-velsky|Adelson-Velsky]] e [[landis|Landis]], 1962) è un [[albero-binario-di-ricerca|albero binario di ricerca]] _quasi perfettamente bilanciato_, tale che con $n$ nodi supporta le operazioni di `search`, `insert` e `delete` con [[complessita-computazionale|costo]] _$O(\log{n})$ nel caso pessimo_. In particolare le operazioni di _inserimento e rimozione sono implementate in modo da essere auto-bilancianti_.

Per studiare il comportamento degli AVL è necessario conoscere i seguenti concetti:
- [[fattore-di-bilanciamento|fattore di bilanciamento]];
- [[albero-bilanciato|albero bilanciato]].

Un albero AVL è un **albero bilanciato in altezza**.

## Altezza massima
Ricordando che l'algoritmo di ricerca di un albero binario di ricerca ha un costo proporzionale all'altezza $h$ dell'albero $\Theta(h)$, e che si ha
$$h = \Omega(\log{n}) \ \ \ \land \ \ \ h = O(n)$$
allora l'**obiettivo dell'albero AVL è proprio quello di mantenere logaritmica rispetto a $n$** (numero di nodi) tale altezza, in modo da non renderla lineare ($O(n)$) nel caso pessimo.

Sapendo che _un albero AVL ha come proprietà fondamentale quella di essere sempre bilanciato in altezza_, scopriamo se questo è _sufficiente a garantire che l'altezza sia logaritmica rispetto a $n$_, ovvero $h = \Theta(\log{n})$.

Per dimostrare quindi che l'altezza di un albero AVL è $\Theta(\log{n})$ prendiamo in considerazione l'[[albero-di-fibonacci|albero di Fibonacci]], che risulta essere intrinsecamente l'_albero bilanciato più sbilanciato possibile_, e quindi l'albero bilanciato "meno bilanciato": in questo modo, _conoscendo l'altezza massima di tale albero sappiamo nel caso pessimo l'altezza di un albero AVL_.

La teoria ci dice che l'altezza di un albero di Fibonacci è proprio
$$h = \Theta(\log{n})$$

## Bilanciamento
Il bilanciamento è la fase cruciale di un albero AVL, che _consente di mantenere_, a seguito di un inserimento o rimozione di un nodo, il _fattore di bilanciamento di ogni nodo compreso tra -1 e 1_.

<u>Nota bene</u>: l'implementazione di un albero AVL richiede un piccolo overhead per ogni nodo $u$ dell'albero. E' _necessario infatti che ogni nodo mantenga informazioni relative all'altezza del proprio sottoalbero_, per poter _calcolare il fattore di bilanciamento_ $\beta$ senza dover contare i nodi dei sottoalberi destro e sinistro ogni volta.

### Rotazione
Il bilanciamento si implementa attraverso una semplice operazione fondamentale: la **rotazione**.
![[avl-rotazione.png]]

#### Esempi
![[rotazioni-semplici.png]]

### Casi
Ci sono 4 principali casistiche che è necessario analizzare per capire quale rotazione applicare. Di fatto inserendo un nuovo nodo $u$ a un AVL bilanciato (o rimuovendone uno) si può incorrere in:
- _sbilanciamento SS_: $\beta(u) = 2 \land \beta(u.\text{left}) \geq 0$ ---> rotazione DX su $u$
- _sbilanciamento DD_: $\beta(u) = -2 \land \beta(u.\text{right}) \leq 0$ ---> rotazione SX su $u$
- _sbilanciamento SD_: $\beta(u) = 2 \land \beta(u.\text{left}) = -1$ ---> rotazione SX su $u.\text{left}$ e rotazione DX su $u$
- _sbilanciamento DS_: $\beta(u) = -2 \land \beta(u.\text{right}) = 1$ ---> rotazione DX su $u.\text{right}$ e rotazione SX su $u$

#### SS
![[sbilanciamento-ss.png]]

#### SD
Non basta una semplice rotazione DX perché porterebbe a uno sbilanciamento DS! Per cui doppia rotazione:
![[sbilanciamento-sd.png]]
![[sbilanciamento-sd-2.png]]

## Operazioni
### `balance`
![[balance.png]]

Il costo è costante: $O(1)$.

### `insert`
![[avl-insert.png]]

Avendo che `btsinsert` costa sempre $\Theta(\log{n})$ perché l'altezza di un albero AVL è sempre $\Theta(\log{n})$, si ha che il costo si `insert` è proprio $\Theta(\log{n})$.

### `delete`
![[avl-delete.png]]

Anche in questo caso il costo dipende da `btsinsert`, che è $\Theta(\log{n})$, e dal `while`, che viene eseguito per tutto il percorso foglia-radice, per cui (in quanto bilanciato) $\log{n}$ volte. Il costo complessivo di `delete` è allora $\Theta(\log{n})$.

<u>Nota bene</u>: la `delete` può provocare _rotazioni a cascata_.

## Referenze
