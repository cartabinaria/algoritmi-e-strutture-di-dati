---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 05-03-2024 20:06:01
links:
  - "[[lecture-04032024091423|Lecture 04032024091423]]"
---
# Insertion sort
---
## Introduzione
> L'**insertion sort** è un [[algoritmo-di-ordinamento-incrementale|algoritmo di ordinamento incrementale]], _in-place_ e _stabile_, che funziona _inserendo di volta in volta l'elemento successivo all'interno della porzione di array già ordinata, in modo ordinato_.

L'autore è [[john-mauchly|John Mauchly]], ed è stato pubblicato nel 1946.

<u>Nota bene</u>: intuitivamente l'insertion sort è lo _stesso algoritmo che usiamo per ordinare delle carte da gioco_.

## Algoritmo
Ad ogni passo $i = 2, \cdots, n$:
1. $A[1, \cdots, i-1]$ è ordinato
2. inserisci $A[i]$ nella posizione corretta $A[1, \cdots, i]$

![[insertion-sort.png]]

<u>Nota bene</u>: tra tutti gli algoritmi studiati, l'_insertion sort è l'unico in grado di essere eseguito anche in-live_, ovvero con un inserimento _a runtime_ di un elemento nuovo in un array già ordinato;

## Complessità
Per analizzare la [[complessita-computazionale|complessità computazionale]] dell'algoritmo bisogna prima di ogni cosa verificare se c'è una condizione nello _pseudo-codice_ che possa creare distinzioni tra _caso ottimo_, _pessimo_ e _medio_.
In effetti, mentre il _ciclo `for` viene eseguito sempre interamente_, il _ciclo `while` potrebbe_, per via della seconda condizione $A[j] < A[j-1]$, _non essere eseguito affatto_. Di conseguenza intuiamo come i casi si diversifichino.

### Caso ottimo
Nel caso ottimo l'array è già ordinato, per cui il ciclo `while` non viene mai eseguito. Rimane solo il `for`, eseguito sempre $n-1$ volte. La complessità computazionale sarà
$$\Theta(n)$$

Ma non è così semplice. Di fatto, preso un array ordinato e scombinati solo $k$ elementi di esso, avremo $\Theta(n)$ cicli per il `for`, e un massimo di $O(nk)$ cicli per il `while` (perché per riordinare quei $k$ elementi al massimo ci vorranno $n$ iterazioni). Per cui per array quasi ordinati il costo computazionale sarà
$$\Theta(n) + O(nk) = O(nk)$$
per cui l'insertion sort avrà un costo lineare $\Theta(n)$ per $k$ costante, ovvero $k = O(1)$.
Solitamente gli array quasi ordinati sono più frequenti di quelli completamente disordinati (decrescenti), perciò: **il caso ottimo è più frequente del caso pessimo**, quindi nella maggior parte dei casi **si può dire che l'insertion sort ha un costo lineare**[^1].

### Caso pessimo
In questo caso, invece, con un array ordinato in ordine decrescente, il ciclo `while` viene eseguito sempre il numero massimo di volte, ovvero $i$ volte. Avremo infatti
$$1 + 2 + 3 + \cdots + n = \sum\limits_{i=2}^{n} i-1 = \sum\limits_{i=1}^{n-1} i = \frac{n(n-1)}{2}$$

quindi una complessità di
$$\Theta(n^{2})$$

### Caso medio
Per analizzare questo caso basta notare che, essendo nel caso medio, possiamo contare il numero medio di iterazioni del ciclo `while`: se il minimo è 0, e il massimo è $i$ iterazioni, la media sarà $\frac{i}{2}$. Usando la stessa formula di prima otteniamo
$$\frac{2}{2} + \frac{3}{2} + \cdots + \frac{n}{2} = \sum\limits_{i=2}^{n} \frac{i-1}{2}$$
ovvero una complessità di
$$\Theta(n^{2})$$

## Referenze
[^1]: si potrebbe dimostrare con l'[[analisi-ammortizzata|analisi ammortizzata]]