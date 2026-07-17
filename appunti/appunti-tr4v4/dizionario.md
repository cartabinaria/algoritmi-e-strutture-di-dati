---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 10-03-2024 22:07:10
links:
  - "[[lecture-07032024091439|Lecture 07032024091439]]"
  - "[[lecture-18032024091043|Lecture 18032024091043]]"
  - "[[lecture-19032024112453|Lecture 19032024112453]]"
  - "[[lecture-25032024091657|Lecture 25032024091657]]"
---
# Dizionario
---
## Introduzione
> Il **dizionario** (o **array associativo**) è una [[struttura-dati|struttura dati]] che contiene un _[[insieme|insieme]] di chiavi univoche, ognuna delle quali è associata a dei dati_. Il [[prototipo-vs-implementazione|prototipo]] di dizionario prevede i dati possano essere duplicati, mentre le chiavi no.

## Operazioni
Le operazioni esposte dal dizionario sono:
- `search(Key k)`, cerca e ritorna i dati associati alla chiave `k` nel dizionario, e se `k` non compare ritorna `NIL`;
- `insert(Key k, Data d)`, aggiunge la coppia `(k, d)` al dizionario, e se `k` è già presente nel dizionario sostituisce il dato associato con quello nuovo (sovrascrivendolo);
- `delete(Key k)`, elimina la coppia `(k, d)` dal dizionario, e se `k` non è nel dizionario non fa nulla;

## Implementazioni
### Array non ordinato
L'ordinamento delle chiavi è casuale.
#### `search(Key k)`
Cerca la chiave `k` tramite [[complessita-computazionale-ricerca-sequenziale|ricerca lineare]] sull'array, ritornando i dati associati a `k` oppure `NIL`.

I casi della [[complessita-computazionale|complessità computazionale]] sono:
- caso ottimo: $O(1)$
- caso pessimo: $\Theta(n)$
- caso medio: $\Theta(n)$

#### `insert(Key k, Data d)`
Verifichiamo con la ricerca lineare se `k` è presente nell'array, e se `k` è presente sostituiamo i dati altrimenti inseriamo la coppia `(k, d)` nella prima cella libera, ovvero quella in fondo all'array.

I casi della complessità computazionale sono:
- caso ottimo: $O(1)$
- caso pessimo: $\Theta(n)$
- caso medio: $\Theta(n)$

#### `delete(Key k)`
Verifichiamo con la ricerca lineare se `k` è presente nell'array, e se è presente sostituiamo la coppia in fondo all'array con quella da rimuovere (riducendo la dimensione di 1).
- caso ottimo: $O(1)$
- caso pessimo: $\Theta(n)$
- caso medio: $\Theta(n)$

#### Resoconto
Senza considerare le distinzioni tra i vari caso (e solo l'upper-bound con l'$O$-[[o-grande|grande]]), abbiamo:
- `search`: $O(n)$
- `insert`: $O(n)$
- `delete`: $O(n)$

### Array ordinato
Il limite dell'array non ordinato è dovuto alla ricerca lineare, perciò sostituiamola con quella [[ricerca-dicotomica|binaria]] (a patto di mantenere ordinato l'array sulle chiavi).

#### `search(Key k)`
E' una ricerca binaria sulle chiavi _per cui il costo delle operazioni dipende dalla ricerca binaria_: $\Theta(\log{n})$.

#### `insert(Key k, Data d)`
Cerca la chiave con _ricerca binaria modificata_ in modo che se non esiste returni la posizione in cui dev'essere inserita. Per cui se `k` è nell'array sostituiamo i dati, _altrimenti dobbiamo shiftare l'array per fare spazio alla nuova chiave_. Il costo delle operazioni dipende dalla ricerca binaria modificata e da `rightshift`.

I casi allora sono:
- caso pessimo: $\Theta(\log{n} + n) = \Theta(n)$
- caso ottimo: $O(\log{n})$, e non è banale, infatti `binsearchpos` e `rightshift` sono in contrasto tra di loro (il caso pessimo di uno è l'ottimo dell'altro)
- caso medio: $\Theta(n)$

#### `delete(Key k)`
Cerca la chiave con ricerca binaria, e se `k` è presente fa uno shift (`leftshift`) di tutto il sotto-array per `k` > 1. Si avrà una situazione analoga all'`insert`.

I costi sono:
- caso pessimo: $\Theta(n)$
- caso ottimo: $O(\log{n})$ (stesso ragionamento di `insert`)
- caso medio: $\Theta(n)$

#### Resoconto
Nonostante il costo logaritmico della ricerca binaria, il costo è comunque dominato dalle operazioni di `shift`, che di per se sono lineari. Infatti si ha:
- `search`: $O(\log{n})$
- `insert`: $O(n)$
- `delete`: $O(n)$

<u>Nota bene</u>: l'_unico effettivo miglioramento dalla prima implementazione con array non ordinato si è verificato in `search`_.

Scopriremo che la migliore soluzione è attraverso [[tabella-hash|tabelle hash]].

### Albero binario di ricerca
Possiamo decidere di implementare il dizionario usando un [[albero-binario-di-ricerca|albero binario di ricerca]] come struttura d'appoggio! Le 3 operazioni assumono il seguente aspetto:
![[dizionario-bst.png]]

Per cui i costi diventano:
- `search`: $O(\log{n})$ medio e $\Theta(h)$ pessimo
- `insert`: $O(\log{n})$ medio e $\Theta(h)$ pessimo
- `delete`: $O(\log{n})$ medio e $\Theta(h)$ pessimo

L'idea è che il costo allora dipende dall'altezza (ricordando che anche nel caso medio $\log{n}$ è l'[[albero-binario-di-ricerca-caso-medio|altezza media dell'albero binario]]), e l'altezza è $O(n)$, per cui nel caso di un albero-lista è proprio $n$: **dobbiamo mantenere tale altezza logaritmica per cercare di non rendere lineare ogni operazione nel caso pessimo**. L'unico modo per farlo è attraverso l'implementazione di [[albero-avl|alberi AVL]].

### Riassunto
In definitiva, aggiungendo un'implementazione con gli alberi AVL, i costo di ogni implementazione della struttura dati dizionari si riassumono nella seguente tabella:
![[costi-implementazione-dizionario.png]]

Si noti come _gli alberi AVL in particolare assicurino un costo logaritmico per tutte le operazioni_. Invece le [[tabella-hash|tabelle hash]] garantiscano nel caso medio per ogni operazione un costo costante $O(1)$.

Di fatto nonostante queste abbiano un costo pessimo lineare, la maggior parte delle implementazioni di dizionari fanno tipicamente uso di tabelle hash.

## Referenze