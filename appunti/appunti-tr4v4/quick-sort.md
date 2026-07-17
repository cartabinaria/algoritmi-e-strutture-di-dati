---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 05-03-2024 20:51:54
links:
  - "[[lecture-04032024091423|Lecture 04032024091423]]"
---
# Quick sort
---
## Introduzione
> Il **quick sort** è un [[algoritmo-di-ordinamento-divide-et-impera|algoritmo di ordinamento divide et impera]], _in-place_ e _non-stabile_ che prevede di _partizionare l'array da ordinare in due sotto-array sulla base di un **pivot** scelto, per poi richiamare [[ricorsione|ricorsivamente]] l'algoritmo sui due sotto-array, evitando alla fine di dover combinare le soluzioni (perché sono già ordinate)_.

L'autore è [[tony-hoare|Tony Hoare]], che lo scoprì nel 1959 come tesi di dottorato.

## Algoritmo
L'algoritmo si divide, come da programma, in 3 fasi:
- _divide_
	- partizioniamo $A[1, \cdots, n]$ in due metà $A_{1} = A[1, \cdots, q-1]$ e $A_{2} = A[q+1, \cdots, n]$ tali che tutte le chiavi in $A_{1}$ siano minori di $A[q]$, e tutte le chiavi di $A_{2}$ maggiori di $A[q]$, con $A[q]$ scelto durante il partizionamento
- _conquer_
	- dobbiamo ordinare i due array $A_{1}$ e $A_{2}$
	- quindi richiamiamo ricorsivamente l'algoritmo sui due sotto-array $A_{1}$ e $A_{2}$, fino ad ottenerne di due soli elementi
- _combine_
	- non è necessario combinare $A_{1}$ e $A_{2}$ perché saranno già ordinati in $A$

![[quick-sort.png]]
![[partition.png]]

## Complessità
Per analizzare la [[complessita-computazionale|complessità computazionale]] del quick sort partiamo col definire il costo di `partition`: è lineare, perciò $\Theta(n)$.
Il problema adesso è definire il costo computazionale di `quickSort`, perché questo _dipende da quanto bene `partition` riesce a partizionare l'array $A$ nei due sotto-array_. In particolare _la scelta del **pivot** $q$ determina interamente l'[[equazione-di-ricorrenza|equazione di ricorrenza]] associata all'algoritmo_: non sappiamo quanto sia centrale il valore del pivot, per cui _i sotto-array possono essere bilanciati o sbilanciati_. Di conseguenza risulta parecchio complesso analizzare la complessità dell'algoritmo[^1].

Ma proprio per questa complicazione siamo in grado di distinguere i casi in _ottimo_, _pessimo_ e _medio_.

### Caso pessimo
Nel caso pessimo l'algoritmo sceglie ogni volta il pivot peggiore: il minimo o il massimo numero dell'array, per il quale non è possibile partizionare l'array in parti bilanciate. Di fatto questo caso si chiama di _partizionamento sbilanciato_, di cui è facile scrivere l'equazione di ricorrenza:
$$T(n) = \begin{cases} 1 & n \leq 1 \\ T(n-1) + T(0) + n & n > 1 \end{cases}$$

Risolvendo tale equazione con il [[metodo-dell-iterazione|metodo dell'iterazione]] giungiamo a un costo del caso pessimo di
$$\Theta(n^{2})$$

### Caso ottimo
Anche del caso ottimo, quindi di _partizionamento bilanciato_ perfettamente, sappiamo scrivere e risolvere facilmente l'equazione di ricorrenza:
$$T(n) = \begin{cases} 1 & n \leq 1 \\ 2T\left(\frac{n}{2}\right)+ n & n > 1 \end{cases}$$

Con il [[master-theorem|master theorem]] l'equazione si risolve in
$$\Theta(n \log{n})$$

### Caso medio
E' con il caso medio che invece, purtroppo, le cose si complicano di molto. Infatti l'equazione generale di ricorrenza del quick sort è
$$T(n) = \begin{cases} 1 & n \leq 1 \\ T(i) + T(n-i-1) + n & n > 1 \end{cases}$$
dove $i$ è la lunghezza del primo sotto-array (che quindi dipende dal pivot). Il problema sta nel fatto che _ad ogni chiamata ricorsiva $i$_ (e quindi anche $n-i-1$) _può cambiare_.

Allora assumiamo probabilisticamente che le partizioni siano tutte _equiprobabili_, per cui sviluppiamo una media dei casi, e otteniamo
$$T(n) = \begin{cases} 1 & n \leq 1 \\ \frac{1}{n} \sum\limits_{i=0}^{n-1} [T(i) - T(n-i-1)] + n & n > 1 \end{cases}$$

Con una serie di passaggi, riusciamo a trovare almeno un _upper-bound_ del caso medio, che è
$$O(n \log{n})$$

### Osservazione
Il caso medio si basa sull'assunzione che le partizioni siano tutti equiprobabili, ma lo pseudo-codice di sopra prende come pivot sempre l'ultimo elemento: _questo porta il caso pessimo ad essere più probabile in caso di array quasi-ordinato o quasi-completamente disordinato_; e _porta il caso medio a non essere corretto_.
Perciò una soluzione sarebbe quella di modificare `partition` in modo da scegliere randomicamente il pivot nell'array. Questo infatti _aumenterebbe la probabilità di avere partizioni bilanciate_, o meglio, _di non avere partizioni sempre sbilanciate_.

## Referenze
[^1]: si può dimostrare anche con il [[metodo-della-sostituzione|metodo della sostituzione]]