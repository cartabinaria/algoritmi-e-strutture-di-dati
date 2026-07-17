---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 12-03-2024 17:41:17
links:
  - "[[lecture-11032024094827|Lecture 11032024094827]]"
---
# Pila
---
## Introduzione
> Una **pila** è una [[struttura-dati|struttura dati]] [[strutture-dati-elementari|elementare]] basata sul modello [[lifo|LIFO]] che supporta due operazioni principali: `PUSH` e `POP`. Viene utilizzata in ambiti dell'informatica piuttosto disparati, dalla gestione dei [[record-di-attivazione|record di attivazione]], a numerosi [[linguaggio-di-programmazione|linguaggi di programmazione]] _stack-oriented_[^1], fino all'implementazione di specifici [[algoritmo|algoritmi]][^2].

## Implementazioni
### [[lista|Lista]] concatenata semplice
E' possibile implementare questa struttura mediante una lista concatenata semplice. Anzi, si tratta di una delle migliori opzioni, con i seguenti vantaggi e svantaggi:
- _pro_: dimensione illimitata;
- _con_: piccolo overhead di memoria (i [[puntatore|puntatori]])

Inoltre i [[complessita-computazionale|costi]] delle operazioni di `PUSH` e `POP` sono costanti.
![[pila-lista.png]]

### [[array|Array]]
Un'altra possibile implementazione è con array:
- _pro_: nessun overhead;
- _con_: dimensione limitata;

Anche in questo caso i costi di `PUSH` e `POP` sono costanti.
![[pila-array.png]]

<u>Attenzione</u>: bisogna gestire i casi di _overflow_ e _underflow_.

### Array dinamico
L'array rimane comunque una scelta comoda visto l'overhead nullo, per cui perché non lavorare solo sul difetto della dimensione statica? Attraverso un _ridimensionamento adattivo dell'array_ è possibile _renderlo_ (per così dire) _dinamico_.

La strategia è allora quello di ridimensionare l'array a seconda di determinate situazioni:
- _ogni volta che l'array si riempie ne raddoppiamo la grandezza_;
- _ogni volta che l'array è riempito di 1/4 della dimensione totale ne dimezziamo la grandezza_;

Con questo paradigma otteniamo un array a tutti gli effetti dinamico. Le operazioni allora modificate risultano essere:
![[push-dinamico.png]]
![[pop-dinamico.png]]

#### Analisi
E' ora di analizzare la complessità computazionale dell'algoritmo, per capire se effettivamente conviene implementare la pila in questo modo oppure no. Di seguito i costi per casi:
- `PUSH`: $\Theta(n)$ nel caso pessimo, $O(1)$ nel caso ottimo;
- `POP`: $\Theta(n)$ nel caso pessimo, $O(1)$ nel caso ottimo;

Purtroppo questi risultati, per quanto corretti, _non catturano il reale comportamento dell'algoritmo_: infatti _non si possono avere più casi pessimi di fila_, perché il ridimensionamento avviene in condizioni che logicamente non possono avvenire in modo contiguo. Di conseguenza si tratta di _stime piuttosto pessimiste_.

Per casi del genere si è soliti calcolare il [[analisi-ammortizzata|costo ammortizzato]], ovvero il costo medio di una sequenza di $n$ operazioni. Per il `PUSH`, per esempio, possiamo usare il [[metodo-dell-aggregazione|metodo dell'aggregazione]]. Infatti basta notare che il costo dell'i-esima `PUSH` è
$$c_{i} = \begin{cases} i & \text{se i-1 è una potenza esatta di 2} \\ 1 & \text{altrimenti} \end{cases}$$

Allora il metodo degli aggregati vuole che la somma di $n$ costi diviso $n$ sia il costo ammortizzato. Per cui lavoriamo sulla somma di $n$ costi per ottenere un _upper-bound_:
$$\sum\limits_{i=1}^{n} c_{i} \leq n + \sum\limits_{j=0}^{\log_{2}{n}} 2^{j} = n + \frac{2^{\log_{2}{n}+1}-1}{2-1} = 3n-1 = O(n)$$

Dividiamo ora il risultato per $n$, e otteniamo:
$$\frac{O(n)}{n} = O(1)$$

Per cui _il costo ammortizzato della `PUSH` dinamica è costante_!

Usando il più complesso [[metodo-degli-accantonamenti|metodo degli accantonamenti]] per la _`POP` si scopre fondamentalmente che anche lei ha costo costante_.

## Referenze
[^1]: come per esempio [[postscript|PostScript]] o [[bibtex|BibTex]]
[^2]: per le operazioni di `undo` e `redo`, o anche semplicemente per il _Syntax parsing_ quando si vuole verificare il bilanciamento delle parentesi