---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 28-03-2024 19:14:13
links:
  - "[[lecture-26032024111318|Lecture 26032024111318]]"
---
# Array heap
---
## Introduzione
> Un **array heap** è una [[struttura-heap|struttura heap]] che salva l'albero heap all'interno di un [[array|array]], per il quale la relazione padre-figlio è salvata all'interno di ogni nodo di esso.

<u>Nota bene</u>: questo spiega la proprietà topologica delle strutture heap. Il motivo per cui la struttura topologica dev'essere quella di un [[albero-quasi-perfetto|albero quasi perfetto]] è perché volendo schiacciare l'albero in un array _non vogliamo avere buchi in mezzo_, o tecnicamente _il prefisso dell'array dev'essere tutto occupato_.

## Struttura
### Array heap binario
#### Trasformazione
Per rappresentare un heap attraverso un array è necessario studiare il _mapping_ dei nodi dell'albero con le celle del vettore: la lettura dev'essere [[bfs|BFS]], e avvenire quindi _per livelli_.

Preso in esame il seguente albero binario heap
![[albero-heap.png]]

la sua forma equivalente in array è
![[array-heap.png]]

L'array `A` ha dimensione `A.length >= A.heapsize`, dove `A.heapsize` è il numero di nodi dell'albero heap.

#### Mappatura
Dobbiamo risolvere le relazioni padre-figlio dell'array che rappresenta l'albero heap. In questo caso trattandosi di un heap binario esistono delle formule verificabili che consentono di scoprire gli indici di _figlio sinistro, figlio destro e genitore_:
- `A[1]` ha la radice;
- `parent(i) = Math.floor(i/2)`;
- `left(i) = 2*i`;
- `right(i) = 2*i+1 = left(i)+1`.

<u>Nota bene</u>: il `left(i)` e `right(i)` se quando calcolati superano `A.heapsize` vengono posti a `-1`.

##### Dimostrazione
Dimostriamo [[induzione-strutturale|per induzione]] che `left(i) = 2*i`:
- _caso base_ --> `left(1) = 2*1 = 2`, che è vero;
- _caso induttivo_ --> per ipotesi induttiva supponiamo `left(i-1) = 2(i-1) = 2*i - 2`, allora dimostriamo che `left(i) = 2*i = left(i-1) + 2` che è vero. 

**Qed**.

## Operazioni
### Array heap binario max-heap
#### `findMax`
Individua il massimo, ossia `A[1]`. Il [[complessita-computazionale|costo]] è costante $O(1)$.

#### `fixHeap`
E' una funzione ausiliaria di `deleteMax`, che usando l'approccio [[divide-et-impera|divide et impera]] per mezzo della [[ricorsione|ricorsione]] ristabilisce la proprietà heap all'array.

Partendo dalla radice `A[1]`, se questa non è $\geq$ ai figli lo scambia con il _figlio maggiore_ (fondamentale per mantenere la proprietà heap) e richiama se stessa sul sottoalbero del nodo scambiato.
![[fixheap.png]]

L'upper-bound è l'altezza dell'albero $h$, ovvero trattandosi di un albero quasi perfetto $\Theta(\log{n})$.

#### `heapify`
Costruisce un heap a partire da un'array privo di ordine, lavorando _in-place_. E' definita per [[ricorsione-strutturale|ricorsione strutturale]] nel seguente modo:
![[heapify.png]]

<u>Nota bene</u>: si richiama su `left(i)` e su `right(i)`.

Per calcolarne il costo scriviamo l'[[equazione-di-ricorrenza|equazione di ricorrenza]] associata
$$T(n) = \begin{cases} 1 & n = 1 \\ 2T\left(\frac{n}{2}\right)+ \log{n} & n > 1 \end{cases}$$
che semplificata si riconduce a una forma risolvibile dalla versione semplificata del [[master-theorem|master theorem]], ottenendo un costo lineare $O(n)$.

#### `deleteMax`
Rimuove l'elemento massimo, ovvero `A[1]`. Per poterlo fare mantenendo la struttura di albero heap si procede nel seguente modo:
1. si prende l'ultima foglia `A[A.heapsize]` e la sostituisce al posto del padre, così da mantenere la struttura topologica dell'albero quasi perfetto;
2. quindi si richiama `fixHeap` per ristabilire la proprietà heap (relazione padre-figlio).

![[deletemax.png]]

Il costo ovviamente è lo stesso di `fixHeap`, perciò $\Theta(\log{n})$.

## Referenze