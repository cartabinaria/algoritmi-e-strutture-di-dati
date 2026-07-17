---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 06-04-2024 18:23:58
links:
  - "[[lecture-03042024130843|Lecture 03042024130843]]"
  - "[[lecture-04042024091934|Lecture 04042024091934]]"
---
# Quick find
---
## Introduzione
> Il **Quick find** è un'[[prototipo-vs-implementazione|implementazione]] della [[struttura-union-find|struttura union-find]] che _privilegia l'operazione di `find` in termini di efficienza a discapito di `union`_.

## Implementazione
Si implementa usando [[albero|alberi]] di _altezza uno_ per rappresentare gli [[insieme|insiemi]] disgiunti, tali che le foglie contengono tutti gli elementi dell'insieme e il rappresentante è la radice, come da immagine.
![[quick-find.png|700]]

### `makeSet`
Il `makeSet` è sempre un'operazione elementare, con [[complessita-computazionale|costo]] costante $O(1)$.

### `find`
L'operazione di `find`, assumendo di avere accesso diretto al nodo-foglia in questione, consiste nell'accedere al [[puntatore|puntatore]] `father` e ricavare così il rappresentante.

Il costo è costante, $O(1)$.

### `union`
L'operazione di `union`, invece richiede, una volta ottenuti i rappresentanti dei due insiemi da fondere, di _far puntare tutti gli elementi del secondo insieme al rappresentante del primo_.
![[quick-find-union.png]]

Considerando che _il numero di elementi del secondo insieme nel caso pessimo è $n-1$_, avremo un costo lineare rispetto a $n$: $O(n)$.


## Miglioramento
E' possibile migliorare questa implementazione usando delle tecniche euristiche molto elementari, in questo caso l'**euristica sul peso**.

L'idea è quella di diminuire il costo della `union`, e lo facciamo memorizzando nella radice di ogni albero-insieme il numero di elementi che ci appartengono (_peso_). Tale dimensione può essere mantenuta in tempo $O(1)$[^1].

Una volta che sappiamo di ogni insieme il suo peso, quando facciamo l'unione tra due insiemi **scegliamo di appendere l'insieme con meno elemento a quello con più elementi**. Ovviamente, per rispettare il prototipo della struttura, _scambiamo il nome del rappresentante in modo da avere sempre il primo dei due rappresentanti degli insiemi come nuovo rappresentante_ (anche questo non influisce sul costo, in quanto costante).
![[quick-find-euristica.png]]

### Analisi del costo
Questa modifica che impatto ha sul costo di `union`?

#### Osservazione
> Ogni volta che una foglia acquista un nuovo padre, _fa parte di un insieme che ha almeno il doppio di elementi di quello a cui apparteneva_.

Consideriamo infatti una `union(A, B)` con `size(A) >= size(B)`, allora ho che
$$size(A) + size(B) \geq size(B) + size(B) = 2 size(B)$$
E per una `union(A, B)` con `size(A) <= size(B)` invece si ha
$$size(A) + size(B) \geq size(A) + size(A) = 2 size(A)$$

E da questo possiamo concludere che **ogni foglia cambia il proprio padre al più $\log_{2}{n}$ volte**. Infatti prendendo una generica foglia `x` della struttura, e _assumendo che ogni `union` crei sempre un albero di grandezza doppia_, si avrà che l'albero a cui appartiene `x` crescerà esponenzialmente rispetto al numero di unioni $u$ sulla foglia `x`: $2^{u}$. Le unioni dell'albero a cui appartiene `x` si fermeranno solo quando
$$2^{u} = n \iff u = \log_{2}{n}$$
Ciò significa che `x` avrà subito $\log_{2}{n}$ unioni, e quindi $\log_{2}{n}$ cambi di padre.

#### Conclusione
Per analizzare il costo di questa nuova implementazione usiamo l'[[analisi-ammortizzata|analisi ammortizzata]], e in particolare il [[metodo-dell-aggregazione|metodo dell'aggregazione]].

Consideriamo di eseguire $n-1$ unioni (il numero massimo possibile), tale che alla fine si avrà un unico insieme con tutti gli elementi. Ogni unione costerà $O(w)$, dove $w$ è il numero di cambi di padre da effettuare, per cui per il metodo dell'aggregazione avremo un costo ammortizzato pari a
$$\frac{O(w_{1}) + \cdots + O(w_{n-1})}{n-1}$$
Sapendo dall'osservazione di prima che ogni elemento cambia padre al più $\log_{2}{n}$ volte, avremo che la somma
$$O(w_{1}) + \cdots + O(w_{n-1}) = O(n\log_{2}{n})$$
e che allora il costo ammortizzato è
$$\frac{O(n\log_{2}{n})}{n-1} = O(\log{n})$$

Per cui il miglioramento ottenuto è ottimo: _abbiamo ridotto il costo di `union` dal lineare al logaritmico_.

## Referenze
- [[quick-union|Quick union]]

[^1]: si tratta alla fine di un _aggiornamento di [[identificatore|variabile]]_