---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
  - topic/informatica-teorica
date: 21-04-2024 22:51:53
links:
  - "[[lecture-16042024112039|Lecture 16042024112039]]"
  - "[[lecture-17042024113805|Lecture 17042024113805]]"
  - "[[lecture-15042026141838|Lecture 15042026141838]]"
---
# Problema dello zaino
---
## Introduzione
> Il **problema dello zaino** (o **knapsack problem**) è uno dei problemi algoritmici più conosciuti, risolto con eleganza dalla [[tecniche-algoritmiche|tecnica algoritmica]] della [[programmazione-dinamica|programmazione dinamica]].
> Nel contesto della variante di decisione di informatica teorica, il problema si dimostra essere addirittura [[np-complete|NP-completo]].

## Descrizione
Avendo un insieme $X = \{1, \cdots, n\}$ di $n$ oggetti, ognuno dei quali ha un peso $p[i]$ e un valore $v[i]$, e disponendo di un contenitore in grado di trasportare al massimo un peso $P$, si vuole determinare un sottoinsieme $Y \subseteq X$ tale che:
- _il peso complessivo degli oggetti in $Y$ sia $\leq P$_
- _il valore complessivo degli oggetti in $Y$ sia il massimo possibile, tra tutti gli insiemi di oggetti che possiamo inserire nel contenitore

Fondamentalmente **vogliamo trovare l'[[insieme-massimale|insieme massimale]] di oggetti rispetto al valore che non sfori il peso massimo consentito**.

## Approcci
### Forza bruta
Andarci di [[attacco-bruteforce|forza bruta]] ha poco senso: dovremmo considerare ogni sottoinsieme possibile, ovvero l'[[assioma-dell-insieme-potenza|insieme delle parti]] di $X$:
$$2^{n}$$
sottoinsiemi.

### Greedy
Si può tentare di ottenere un risultato approssimativo usando un approccio [[algoritmi-greedy|greedy]]. In particolare possiamo, ad ogni passo, _scegliere tra gli oggetti ancora non scelti quello di valore massimo tra tutti quelli che hanno un peso minore o uguale alla capacità residua nello zaino_. Oppure di _scegliere ad ogni passo l'oggetto con valore specifico massimo tra quelli rimanenti che hanno un peso minore o uguale alla capacità residua nello zaino_, dove il valore specifico è definito come `$/kg`.

Entrambi gli algoritmi non forniscono sempre la soluzione ottima.

### Programmazione dinamica
Si dimostra che con questo approccio si ottiene invece la soluzione ottima, ma il vincolo è che **i pesi siano interi**.

Quindi definiamo un sottoproblema $P(i, j)$: _riempire uno zaino di capienza $j$ utilizzando un sottoinsieme di primi $i$ oggetti, in modo da massimizzare il valore degli oggetti usati_.
Ora, le soluzioni $V[i, j]$ (di fatto una [[matrice|matrice]]) saranno i **valori massimi ottenibili** da un sottoinsieme degli oggetti $i$ con zaino di capacità $j$.

Non ci resta che risolvere in modo efficiente il sottoproblema $P(i, j)$, per cui consideriamo i casi:
- _caso banale $j = 0$_ --> lo zaino ha capienza nulla, per cui $V[i, 0] = 0 \ \ \forall i \in \{1, \cdots, n\}$
- _caso banale $i = 1$_ --> si ha a disposizione solo il 1° oggetto, per cui semplicemente bisogna vedere se ci sta o meno nello zaino di dimensione $j$, e se ci sta mettere in $V[1, j]$ il suo valore $v[1]$, infatti
	- $V[1, j] = v[1]$ se $j \geq p[1]$;
	- $V[1, j] = 0$ se $j < p[1]$;
- _caso induttivo su $i > 1$_ --> si aprono due scenari principali:
	1. $j < p[i]$, quindi l'oggetto $i$-esimo da inserire nello zaino è troppo pesante, allora il bottino massimo che riesco a ottenere è $V[i-1, j]$, ovvero il valore nello zaino senza l'oggetto $i$-esimo
		- $V[i, j] = V[i-1, j]$
	2. $j \geq p[i]$, quindi l'oggetto $i$-esimo eventualmente ci sta nello zaino, allora non ci resta che capire se conviene prenderlo o meno
		- se non lo prendiamo il bottino massimo è sempre $V[i-1, j]$;
			- $V[i, j] = V[i-1, j]$
		- se decidiamo invece di prenderlo allora il bottino sarà sicuramente $v[i]$ sommato al bottino massimo ottenibile con uno zaino di peso $j - p[i]$
			- $V[i, j] = v[i] + V[i-1, j-p[i]]$

Riassumendo si hanno le seguenti formule:
$$\begin{align} V[i, 0] =& 0 \\ V[1, j] =& \begin{cases} v[1] & j \geq p[1] \\ 0 & j < p[1] \end{cases} \\ V[i, j] =& \begin{cases} V[i-1, j] & j < p[i] \\ \max(V[i-1, j], V[i-1, j-p[i]]+v[i]) & j \geq p[i] \end{cases} \end{align}$$

La soluzione si troverà nell'ultima cella in basso a destra, ovvero in $V(n, P)$.

Ma attenzione, **ci rimane da sapere quali oggetti consentono di ottenere il bottino massimo**! Per farlo usiamo una matrice ausiliaria $T$ della stessa grandezza di $V$ che per ogni soluzione $P(i, j)$ salva `True` se quell'oggetto è stato preso e `False` altrimenti. Quindi, partendo dalla cella finale andiamo a ritroso per trovare ogni oggetto nel seguente modo:
- se $T[i, j] = True$ allora quell'oggetto è stato preso, il prossimo si trova in $T[i-1, j-p[i]]$;
- se $T[i, j] = False$ allora quell'oggetto non è stato preso, il prossimo si trova in $T[i-1, j]$;

In ogni caso il costo computazionale dell'algoritmo è
$$T(n) = \Theta(n \cdot P)$$
dove $n$ è il numero di oggetti e $P$ il peso massimo. Questo perché _si deve riempire la tabella $V$ di grandezza $n \cdot P$, e ogni cella si riempie con costo costante_.

## Variante di decisione
> Dati i 3 insiemi:
> - $\{1, \cdots, n\}$ di oggetti;
> - $\{w_{1}, \cdots, w_{n}\}$ di pesi degli oggetti;
> - $\{k_{1}, \cdots, k_{n}\}$ di valori degli oggetti;
> 
> e i due valori di threshold $W, K$, la **variante di decisione del problema dello zaino** $KNAPSACK$ chiede se esista un sottoinsieme di oggetti cui somma dei pesi non ecceda $W$, e somma dei valori sia almeno $K$.

### NP-completezza
#### $KNAPSACK \in NP$
E' sufficiente mostrare una [[macchina-di-turing-non-deterministica|MdT non-deterministica]] che faccia:
- _guess_ sul sottoinsieme di oggetti, lineare;
- _check_ sulla somma dei pesi e dei valori in confronto ai threshold $W$ e $K$, lineare.

#### $KNAPSACK \in$ NP-hard
Lo dimostriamo tramite una [[riduzione-polinomiale|riduzione polinomiale]] da [[exact-cover|exact cover]]:
$$EC \leq_{p} KNAPSACK$$

##### Riduzione
Anzitutto, w.l.o.g., tutte le istanze di $KNAPSACK$ avranno le seguenti caratteristiche:
- $W = K$;
- $\forall i \in [1, n]. \ \ \ w_{i} = k_{i}$;

Quindi, gli array di pesi e di valori, sono la stessa cosa. Avendo impostato $W = K$, allora il problema di $KNAPSACK$ si riduce nel trovare un sottoinsieme degli oggetti $\{1, \cdots, n\}$ cui somma di pesi/valori faccia esattamente $W$ (o $K$).

Facciamo lo schemino delle riduzioni:
- problema di partenza - $EC$
	- istanze: $(U, F)$;
	- istanze si': $(U, F)$ tale che in $F$ c'e' una partizione di $U$;
- problema di arrivo - $KNAPSACK$
	- istanze: $(\{w_{1}, \cdots, w_{n}\}, \{k_{1}, \cdots, k_{n}\}, W, K)$;
	- istanze si': $(\{w_{1}, \cdots, w_{n}\}, \{k_{1}, \cdots, k_{n}\}, W, K)$ tale che esiste un sottoinsieme di oggetti cui somma dei pesi non supera $W$ e somma dei valori e' almeno $K$.

Dalla restrizione delle istanze di $KNAPSACK$ descritta in precedenza, possiamo ridurre le sue istanze alla sola coppia $(\{w_{1}, \cdots, w_{n}\}, W)$.

Notare la difficolta' della riduzione: dobbiamo passare da degli insiemi ($U$ e $F$), a dei numeri ($\{w_{1}, \cdots, w_{n}\}$ e $W$)!

L'idea e' mappare ogni sottoinsieme di $U$ in $F$ attraverso una codifica binaria che ci dica se l'oggetto e' considerato o meno!
Per esempio, consideriamo l'istanza
- $U = \{1, 2, 3, 4\}$
- $F = \{\{3, 4\}, \{2, 4\}, \{2, 3, 4\}\}$

che tra l'altro e' un'istanza no...
Dato che gli oggetti in $U$ sono 4, possiamo usare 4 cifre binarie per rappresentare ogni insieme di $F$, tale che ci dica se il numero e' presente o meno nell'insieme. E poi possiamo rappresentare ogni numero binario con la sua versione decimale:
![[Drawing 2026-04-21 17.50.24.excalidraw|1000]]

Di conseguenza, per ricostruire $U$ dovremo scegliere da $F$ quei numeri che formano $1111_{2} = 15$.
In questo modo, scegliere gli insiemi in $F$ corrisponde a sommare i numeri associati, in modo tale che il risultato sia esattamente il numero associato a $U$.

Quindi, per ora:
- $w_{i}$ sono i numeri in binario associati agli insiemi in $F$;
- $W$ e' il numero $1\cdots1$ associato a $U$.

Tuttavia **non funziona**! Nel caso precedente, l'istanza e' no, tuttavia se sommiamo $3 + 5 + 7$ otteniamo proprio $15$, per cui in $KNAPSACK$ creiamo un'istanza si'!
Il motivo per cui non funziona e' il **riporto**: dovremmo fare l'`OR` dei numeri degli insiemi di $F$, non la somma! Solo che in $KNAPSACK$ l'operazione e' la somma...
Quindi, dobbiamo **simulare tramite un'addizione, l'`OR` logico tra stringhe binarie**. Come?
Ci basta **cambiare base**!

In particolare, scegliamo come base della somma il numero $m$ di insiemi di $F$, piu' 1! In questo modo, se uno stesso elemento compare in tutti gli insiemi, male che vada lo scegliamo $m$ volte: $1 + \cdots + 1$ per $m$ volte fa $m$, che in base $m+1$ non genera alcun riporto!

Formalmente, la riduzione e' come segue:
- $$w_{i} = \sum\limits_{j \in F_{i}} (m+1)^{n-j} = k_{i}$$ che e' il modo formale per dire che interpreto ogni numero presente in $F_{i}$ con scrittura di 0 e 1 (sulla base della presenza degli elementi di $U$), in base $m+1$;
- $$W = \sum\limits_{j=1}^{n} (m+1)^{n-j} = K$$

Notiamo che la trasformazione si ottiene in tempo polinomiale. Dobbiamo verificare la veridicita' della riduzione:
- $P \subseteq F$ partizione di $U$, allora devo mostrare che esiste un sottoinsieme di pesi $w_{i}$ tali che la loro somma e' esattamente $W$; se $F_{i} \in P \implies$ seleziono $w_{i}$; devo mostrare $\sum\limits_{F_{i} \in P} w_{i} = W$;
	- questo accade perche' i numeri $w_{i}$ rappresentano nel loro complesso la partizione $P$
	- per cui, non avranno un oggetto in comune (nella somma in colonna non apparira' mai $1+1$), e copriranno tutti gli oggetti di $U$ (il risultato della somma e' $1\cdots1$)
- $\exists L = \{w_{i}, \cdots, w_{j}\}$ tali che sommano a $W$; allora seleziono $F_{i}$ se $w_{i} \in L$; e questa costituira' una partizione, perche' se ci fosse un buco allora non otterrei $W$, e se ci fossero elementi ripetuti non otterrei comunque $W$!

**Qed**.

#### Conseguenze
Dato che $KNAPSACK$ si risolve con la [[programmazione-lineare-intera|PLI]], allora il problema della PLI e' [[np-hard|NP-hard]]!
Se infatti cosi' non fosse, allora potremmo risolvere $KNAPSACK$ in tempo polinomiale deterministico, e quindi $P = NP$.

## Referenze