---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 29-03-2024 10:24:02
links:
  - "[[lecture-27032024112108|Lecture 27032024112108]]"
---
# D-heap
---
## Introduzione
> Un **d-heap** è una [[struttura-dati|struttura dati]] che [[prototipo-vs-implementazione|implementa]] la [[coda-con-priorita|coda con priorità]] attraverso la [[struttura-heap|struttura heap]]. Si tratta quindi di un _[[albero|albero]] d-ario_ con le seguenti proprietà:
> 1. è un _min-heap_ d-ario;
> 2. ogni nodo è costituito da una coppia chiave-elemento (_key_, _data_).

Per esempio si osservi questo d-heap con $d = 3$:
![[d-heap-3.png]]

## Altezza
Trattandosi di un albero _$d$-ario_ [[albero-quasi-perfetto|quasi perfetto]] sappiamo che ogni nodo fino al livello $h-1$ ha $d$ figli, per cui se volessimo calcolare quanti nodi $n$ sono presenti fino all'$h-1$-esimo livello useremmo la [[sommatorie-notevoli|sommatoria notevole]]:
$$\sum\limits_{i=0}^{h-1} d^{i} = \frac{d^{h}-1}{d-1}$$

Vogliamo allora trovare un **upper-bound all'altezza $h$ rispetto al numero di nodi $n$** dell'albero. Sappiamo di aver saltato l'ultimo livello ($h$), allora si ha
$$\frac{d^{h}-1}{d-1} < n$$

Attraverso le opportune trasformazioni si ha
$$h < \log_{d}{(n(d-1)+1)} \ \iff \ h = O(\log_{d}{n})$$

Per cui l'**altezza $h$ di un albero $d$-ario è limitata superiormente da $\log_{d}{n}$**, dove $n$ è il numero di nodi dell'albero.

## Implementazione
Vogliamo rappresentare un $d$-heap su array, e ottenere quindi un [[array-heap|array heap]]. Applichiamo allora lo stesso tipo di [[array-heap-trasformazione|trasformazione]] che con una visita [[bfs|BFS]] traduce un albero in un array, ottenendo questo:
![[d-heap-array.png]]

Quindi ricaviamo delle formule per poter risolvere le relazioni padre-figlio. In questo caso, non essendo in un heap binario, _non ha senso identificare un `left` e un `right` di un nodo, ma bensì il `first` e il `last`_. Non sappiamo infatti a priori il valore di $d$: potrebbe essere $d=2$, e allora `first=left` e `last=right`; ma per valori di $d$ più grandi non vale più questo discorso, perciò dobbiamo essere i più generici possibile.

Le formule sono:
- `last(i) = (i * d) + 1`;
- `first(i) = ((i - 1) * d) + 2`;
- `parent(i) = Math.ceil((i - 1) / d)`;

### Dimostrazione
Dimostriamo [[induzione-strutturale|per induzione]] che `last(i) = (i * d) + 1`:
- _caso base_: `last(1) = 1*d+1 = d+1`, che è vero;
- _caso induttivo_: per ipotesi induttiva supponiamo `last(i-1) = ((i-1)*d) + 1 = i*d - d + 1`; dimostriamo quindi che `last(i) = (i*d) + 1 = last(i-1) + d`, che è vero.

Di conseguenza si ha che `first(i) = last(i) - d + 1 = (i*d)+1-d+1 = (i-1)*d + 2`, ovvero proprio la formula di sopra.

**Qed**.

## Operazioni
Le operazioni [[coda-con-priorita-operazioni|implementano quelle esposte dalla coda con priorità]], più altre ausiliarie.

### `findMin()`
Restituisce l'elemento associato alla radice dell'heap, che _se implementato con array min-heap è semplicemente `A[1]`_.

Il [[complessita-computazionale|costo]] è costante $O(1)$.

### `insert(Elem e, Key k)`
Crea un nuovo nodo `v` con chiave `k` e valore `e`. Per rispettare le proprietà del min-heap si procede nel seguente modo:
1. si posiziona momentaneamente questo nuovo nodo come ultima foglia a destra dell'ultimo livello (`A[A.heapsize+1]`) per mantenere la struttura topologica;
2. si sistema l'ordinamento padre-figlio attraverso la funzione `moveUp` sulla foglia inserita per mantenere la proprietà heap.

Il costo è direttamente legato a quello di `moveUp`, che costa $O(\log_{d}{n})$ nel caso pessimo.

### `delete(Elem e)`
Assumendo di avere accesso diretto al nodo `v` che ha come elemento `e`, per rispettare le proprietà del min-heap si procede nel seguente modo:
1. si sostituisce al nodo da eliminare l'ultima foglia dell'albero (`A[A.heapsize]`), così da mantenere la struttura topologica;
2. si sistema l'ordinamento padre-figlio attraverso la funzione `moveDown` o `moveUp` sul nodo con il valore sostituito (_non sappiamo a priori se questo nodo dovrà "scendere" o "salire"_).

<u>Nota bene</u>: volendo essere pignoli, _se si elimina un nodo che appartiene ai primi $h-1$ livelli, allora al massimo si dovrà usare `moveDown`_; _se invece si elimina una foglia, ovvero un nodo al livello $h$, allora al massimo si dovrà usare `moveUp`_.

Il costo dipende unicamente dalle funzioni `moveDown` e `moveUp`. Non sapendo quale delle due verrà chiamata, consideriamo quella con costo peggiore, ovvero `moveDown` con $O(dh) = O(d\log_{d}{n})$.

### `deleteMin()`
E' l'unione di `findMin()` con `delete(Elem e)`, per cui costa quanto `delete` (dato il costo costante di `findMin`): $O(d\log_{d}{n})$.

### `increaseKey(Elem e, Key k)`
Assumendo di avere accesso diretto al nodo `v` con valore `e`, allosa se `k` è maggiore della chiave di `v`, questa viene settata come nuova chiave di `v` e viene eseguito un `moveDown` su `v` (_nel caso si rompa la proprietà heap_).

Il costo allora è quello di `moveDown`: $O(d\log_{d}{n})$.

### `decreaseKey(Elem e, Key k)`
Assumendo di avere accesso diretto al nodo `v` con valore `e`, allora se `k` è minore della chiave di `v`, questa viene settata come nuova chiave di `v` e viene eseguito un `moveUp` su `v` (_nel caso si rompa la proprietà heap_).

Il costo allora è quello di `moveUp`: $O(\log_{d}{n})$.

### `moveUp(Node v)`
E' una _funzione ausiliaria usata per sistemare la relazione padre-figlio e quindi la proprietà heap dell'albero min-heap_. In particolare risale controllando se il nodo in esame `v` (a patto che non sia la radice) abbia chiave minore del padre; se sì allora lo scambia di posto con il padre e ripete l'algoritmo sempre per `v`.

<u>Nota bene</u>: può scambiare tranquillamente il figlio `v` con il padre se la chiave di `v` è minore di quella del padre perché si assume di essere già in un min-heap, e quindi di avere un padre con chiave minore di tutti i figli a patto di `v`.

#### Pseudocodice
```R
function moveUp(Node v) {
	while (v != T.root && v.key < v.parent.key) {
		swap(v, v.parent);
		v = v.parent;
	}
}
```
<u>Attenzione</u>: questo pseudocodice lavora a nodi di un albero, ma sappiamo che l'implementazione è tramite array heap.

Il costo di `moveUp` è, nel caso pessimo, l'altezza dell'albero $h$, ovvero
$$O(h) = O(\log_{d}{n})$$

### `moveDown(Node v)`
Come `moveUp` si tratta di una funzione che ripara la proprietà heap dell'albero min-heap, ma è meno semplice della sorella. Infatti in questo caso non c'è un solo nodo da comparare a `v` per capire se scambiarlo o meno: dobbiamo trovare tra i figli di `v` quello minore e, in caso tale figlio abbia chiave minore di `v`, scambiarlo con `v`, e proseguire finché la proprietà non è soddisfatta o `v` non ha più figli (è una foglia).

<u>Nota bene</u>: _dobbiamo trovare il figlio `u` di `v` con chiave minore da sostituire per mantenere la proprietà heap sul sottoalbero in esame_.

#### Pseudocodice
```R
function moveDown(Node v) {
	while (true) {
		if (noKids(v))
			return;
		else {
			u = minKid(v);
			if (u.key < v.key) {
				swap(u, v);
				v = u;
			} else
				return;
		}
	}
}
```

Il costo di `moveDown`, a differenza di quello di `moveUp`, non è nel caso pessimo dettato solo dall'altezza dell'albero: un totale di $h$ scambi prevede per ogni scambio anche una ricerca del figlio di `v` con chiave minima, e se siamo in un $d$-heap allora i figli saranno $d$. Per cui il costo sarà
$$O(dh) = O(d\log_{d}{n})$$

### Riassunto
Abbiamo allora che i costi sono:
- `findMin`: $O(1)$;
- `insert`: $O(\log_{d}{n})$;
- `delete`: $O(d\log_{d}{n})$;
- `deleteMin`: $O(d\log_{d}{n})$;
- `increaseKey`: $O(d\log_{d}{n})$;
- `decreaseKey`: $O(\log_{d}{n})$;

Nota che $d$, nel momento in cui si implementa un $d$-heap, **assume un valore costante**, perciò in definita possiamo dire che i **costi** (a esclusione di `findMin`) siano **logaritmici**.

## Referenze