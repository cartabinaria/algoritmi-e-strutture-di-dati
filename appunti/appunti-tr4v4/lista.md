---
tags:
  - category/note
  - status/finished
  - topic/programmazione
  - topic/algoritmi-e-strutture-dati
date: 10-11-2023 19:08:58
links:
  - "[[lecture-08112023095400|Lecture 08112023095400]]"
  - "[[lecture-15112023091814|Lecture 15112023091814]]"
  - "[[lecture-17112023102404|Lecture 17112023102404]]"
  - "[[lecture-07032024091439|Lecture 07032024091439]]"
---
# Lista
---
## Introduzione
> Le **liste** sono [[strutture-dati-dinamiche|strutture dati dinamiche]] [[strutture-dati-elementari|elementari]] composte da _sequenze di nodi_, ovvero [[struttura-dati|strutture dati]] che contengono una serie di valori e un _[[puntatore|puntatore]] a il nodo successivo_. Dispongono di 3 principali operazioni: `ricerca`, `inserimento` e `rimozione`.

Graficamente parlando, una lista si presenta, a partire da un puntatore **head**, come una serie di nodi connessi in sequenza.
![[lista.png]]

<u>Nota bene</u>: il puntatore _head **non è un nodo**_, ma solo un puntatore al primo nodo. Se si ha _head_ si ha tutta la lista.

## Implementazioni
### Array
E' possibile implementare una lista con un [[array|array]], e anzi offre vantaggi notevoli. L'ordine degli elementi è determinato dagli _indici_, e l'accesso a un suo elemento avviene in tempo costante ($O(1)$). Tuttavia lo _spazio è allocato staticamente_, e quindi è limitato.

### Liste concatenate
L'ordinamento è in questo caso determinato da una _catena di [[puntatore|puntatori]]_, e lo [[allocazione-dinamica-della-memoria-dei-programmi|spazio viene allocato dinamicamente]]. Il [[complessita-computazionale|costo]] di accesso dipende dalla posizione in cui si trova l'elemento (per cui lineare).

Le liste concatenate sono attribuite a [[newell|Newell]], [[shaw|Shaw]], [[simon|Simon]] (sviluppatori di [[ipl|IPL]]), che le idearono come soluzione al problema della _rilocalizzazione di un array_ (necessaria al suo ridimensionamento), che non sempre è possibile.

#### Semplici
I nodi contengono:
- dati
- puntatore al nodo successivo (se è `NIL` allora è l'ultimo nodo)

Operazioni:
- `search` (come una ricerca lineare): $\Theta(n)$ (nell'ottimo $O(1)$, pessimo e medio $\Theta(n)$)
- `insert` (in testa): $O(1)$
- `append` (in coda): $\Theta(n)$
- `delete`: $\Theta(n)$ (nell'ottimo $O(1)$, pessimo e medio $\Theta(n)$)

#### Doppiamente concatenate
I nodi contengono:
- dati
- puntatore al nodo successivo (se è `NIL` è l'ultimo)
- puntatore al nodo precedente (se è `NIL` è il primo)

Tutte le operazioni hanno lo stesso costo delle liste concatenate semplici.

#### Circolari
In questo caso l'accesso alla testa dalla coda è costante, e viceversa. Il lato estremamente negativo di questa implementazione è che non c'è alcun valore `NIL` che indichi la fine della lista.

#### Con doppi puntatori
Si tratta dell'implementazione migliore, con gli stessi costi dell'implementazione circolare ma senza il problema del `NIL` mancante: è più semplice a livello implementativo.

Per cui ha costi:
- `search`: $\Theta(n)$ (nell'ottimo $O(1)$, pessimo e medio $\Theta(n)$)
- `insert` (in testa): $O(1)$
- `append` (in coda): $O(1)$
- `delete`: $\Theta(n)$ (nell'ottimo $O(1)$, pessimo e medio $\Theta(n)$)

#### Resoconto
Questa è la tabella riassuntiva dei costi complessivi (in $O$-[[o-grande|grande]]) delle operazioni di una lista per ogni implementazione con lista concatenata vista sopra:
![[implementazioni-lista.png]]

### In C++
In [[c|C++]] una lista (concatenata semplice) si realizza mediante una _struttura che con un campo che contiene un puntatore alla struttura stessa_, nel seguente modo:
```cpp
struct list {
	int val;
	list *next;
};
```

Si tratta a tutti gli effetti di una definizione [[ricorsione|ricorsiva]], ammessa in C++. Diremmo, in logica, che una lista così implementata è equivalente a
$$L = \epsilon \cup (\text{Int} \times L)$$

## Operazioni in C++
### Creazione
Per creare una lista **conviene sempre lavorare sulla testa**, quindi _partire dal fondo per poi risalire aggiungendo di volta in volta un nuovo nodo_. In pratica la lista viene creata al contrario.

Infatti, così facendo abbiamo _solo bisogno del puntatore a head_, che in ultimo sarà proprio quello che identifica il primo elemento della lista; invece, _se implementassimo la lista sulla coda_, quindi aggiungendo di volta in volta nodi a partire dall'inizio, _dovremmo salvarci head e tail_.

Se si segue la creazione in testa, allora il primo nodo da creare (che diventerà l'ultimo) dovrà puntare a `NULL`. Quindi la prima operazione da fare è:
```cpp
list *head;
head = new list;
head->val = 13;
head->next = NULL;
```

A questo punto, per procedere, basterà reiterare le fasi dell'[[lista-in-testa|inserimento in testa]].

### Accesso
Essendo una struttura che come campi ha puntatori, per accedere ad ogni elemento bisognerebbe usare la _[[puntatore-dereferenziazione|dereferenziazione]]_ di ogni puntatore per ogni nodo.

Se per esempio vessimo una lista del tipo
![[lista.png]]
e volessimo accedere al valore dell'ultimo nodo (senza usare [[iterazione|iterazioni]] di alcun tipo), dovremmo scrivere
```cpp
int val = (*(*(*head).next).next).val;
```

Per fortuna esiste l'**operatore di dereferenziazione automatica** `->`, che consente, di un puntatore, di accedere al campo della `struct` a cui punta.

Nel caso precedente si avrà quindi
```cpp
int val = head->next->next->val;
```

### Concatenazione
Sfruttando le potenzialità dei puntatori, _le liste si possono concatenare_: basta far puntare la _tail_ della prima lista alla _head_ della seconda - mettendo quindi il `next` della prima uguale a `head` della seconda.

### Inserimento
Si nota come, per alcuni casi come l'inserimento in testa o l'inserimento tra il primo e il secondo nodo, le liste siano _compiutazionalmente più efficienti degli [[array|array]]_.
#### In testa
Per inserire un nodo in testa basta:
1. creare un nuovo nodo
2. far puntare il nuovo nodo alla testa (puntatore)
3. assegnare alla testa (puntatore) il nuovo nodo

In codice:
```cpp
list *insert_head(list *head, int val) {
	list *tmp;
	tmp = new list;
	tmp->val = val;
	tmp->next = head;
	return tmp;
}
```

#### In mezzo
Per inserire un nodo in mezzo basta:
1. creare un nuovo nodo
2. far puntare il nuovo nodo all'i-esimo+1 nodo della lista
3. assegnare all'i-esimo elemento della lista il nuovo nodo

#### In coda
Per inserire un nodo in coda basta:
1. creare un nuovo nodo
2. scorrere fino all'ultimo elemento
3. assegnare al `next` dell'ultimo elemento il nuovo nodo

### Eliminazione
#### In testa
```cpp
head = head->next;
```
#### In mezzo
Mi salvo il nodo precedente a quello corrente e sovrascrivo il suo puntatore a `next` con il nodo successivo a quello corrente:
```cpp
list *prec;    // nodo precedente a "curr"
list *curr;
prec->next = curr->next;
```

#### In coda
Scorro fino al penultimo elemento e sovrascrivo il puntatore a `next` con `NULL` (supponiamo `head != NULL`):
```cpp
list *iter = head;
while (iter->next != NULL) {
	iter = iter->next;
}
iter->next = NULL;
```

#### Osservazioni
Nell'operazione di rimozione di un nodo dalla lista, è importante eliminare con `delete` il puntatore al nodo eliminato, altrimenti si incorre in [[memory-leak|memory leaks]].
Quindi, prima di sovrascrivere il valore del puntatore, _salvarlo in un'altro puntatore di copia e quindi fare il `delete` dello stesso_. Per esempio, la corretta eliminazione in testa sarebbe:
```cpp
list *tmp = head;
head = head->next;
delete tmp;
```

Un'altra cosa importante è sempre, per ogni operazione, **considerare il caso in cui la lista è vuota, ovvero `head` è `NULL`**.

## Referenze
- [[liste-bidirezionali|Liste bidirezionali]]