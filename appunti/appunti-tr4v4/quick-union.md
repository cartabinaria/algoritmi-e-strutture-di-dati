---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 06-04-2024 18:38:13
links:
  - "[[lecture-03042024130843|Lecture 03042024130843]]"
  - "[[lecture-04042024091934|Lecture 04042024091934]]"
---
# Quick union
---
## Introduzione
> Il **Quick union** è un'[[prototipo-vs-implementazione|implementazione]] della [[struttura-union-find|struttura union-find]] che _privilegia l'operazione di `union` in termini di efficienza a discapito di `find`_.

## Implementazione
La quick union si implementa usando [[albero|alberi]] _generali_ (implementazione basata su _foresta_), tale che ogni albero rappresenta un insieme e il rappresentante è la radice, e gli elementi sono tutti i nodi dell'albero (foglie comprese). Si veda la figura:
![[quick-union.png|500]]

### `makeSet`
Il `makeSet` è un'operazione elementare, con [[complessita-computazionale|costo]] costante $O(1)$.

### `union`
L'operazione di `union` tra due insiemi `A` e `B` prevede semplicemente di impostare come padre della radice di `B` la radice di `A`, come nel seguente modo
![[quick-union-union.png]]

Il costo è quindi costante, $O(1)$.

### `find`
L'operazione di `find`, invece, risulta svantaggiata in questa implementazione perché anche assumendo di avere accesso diretto al nodo dell'albero-insieme, _per arrivare alla radice è necessario risalire tutto l'albero_. La profondità di questo generico albero nel caso pessimo questa è proprio $n$: basta considerare il caso di un albero-lista ([[albero-bilanciato|completamente sbilanciato]]), ottenibile da delle _`union` dei singoletti da destra a sinistra_.

![[quick-union-find.png]]

<u>Nota bene</u>: la reale _conformazione dell'albero dipende dall'ordine di esecuzione delle `union`_.

## Miglioramento
E' possibile migliorare questa implementazione usando tecniche euristiche elementari, in questo caso l'**euristica sul rank**.

Se la nostra intenzione infatti è quella di diminuire il costo di `find`, _sapendo che questo è lineare rispetto all'altezza dell'albero dovremmo cercare di limitarne la crescita_.

L'idea allora, è di agire sull'`union` **rendendo la radice dell'albero più basso figlia della radice dell'albero più alto**. Per farlo assumiamo che ogni radice mantenga il proprio _rank_, ovvero l'altezza del suo albero. E anche in questo caso _vogliamo cambiare il nome del rappresentante ogni qualvolta ci sia un ordine di unione che non rispetta quello stabilito dal prototipo_.
![[quick-union-euristica.png]]

### Analisi costo
Questa modifica ha impatto sul costo di `find`?

#### Osservazione
Ci basta dimostrare che un albero costruito in questa maniera ha
$$n \geq 2^{rk(x)}$$
nodi, dove $rk(x)$ è il rank della radice $x$.

##### Dimostrazione
Lo dimostriamo [[induzione-strutturale|per induzione]] sui 3 casi di `union` elencati sopra:
- _caso base_: non sono state effettuate operazioni di union, ogni singoletto ha esattamente 1 nodo (la radice), e altezza/rango 0, per cui $1 \geq 2^{0}$, che è vero;
- _caso induttivo_: se denotiamo $A \cup B$ come l'albero ottenuto dall'unione di $A$ e $B$, e $|A \cup B| = |A| + |B|$ come il numero di nodi di tale albero (perché trattiamo insiemi disgiunti), allora si hanno i 3 casi:
	1. _$rk(A) < rk(B)$_ --> per ipotesi induttiva sappiamo che $|A| \geq 2^{rk(A)}$ e $|B| \geq 2^{rk(B)}$, mentre avendo $rk(A) < rk(B)$ allora per definizione avremo che $rk(A \cup B) = rk(B)$, perciò $$|A \cup B| = |A| + |B| \geq 2^{rk(A)} + 2^{rk(B)} > 2^{rk(B)} = 2^{rk(A \cup B)}$$
	2. $rk(A) > rk(B)$ --> per ipotesi induttiva sappiamo che $|A| \geq 2^{rk(A)}$ e $|B| \geq 2^{rk(B)}$, mentre avendo $rk(A) > rk(B)$ per definizione sappiamo che $rk(A \cup B) = rk(A)$, per cui $$|A \cup B| = |A| + |B| \geq 2^{rk(A)} + 2^{rk(B)} > 2^{rk(A)} = 2^{rk(A \cup B)}$$
	3. $rk(A) = rk(B)$ --> per ipotesi induttiva sappiamo che $|A| \geq 2^{rk(A)}$ e $|B| \geq 2^{rk(B)}$, mentre avendo $rk(A) = rk(B)$ per definizione sappiamo che $rk(A \cup B) = rk(A) + 1$, per cui $$|A \cup B| = |A| + |B| \geq 2^{rk(A)} + 2^{rk(B)} = 2 \cdot 2^{rk(A)} = 2^{rk(A)+1} = 2^{rk(A \cup B)}$$

**Qed**.

#### Conclusione
Sapendo che ogni albero ha $n \geq 2^{rk(x)}$ nodi, dove $rk(x)$ è il rango della radice $x$, allora invertendo si ottiene
$$rk(x) \leq \log_{2}{n}$$

ed essendo il rango di $x$ proprio l'altezza massima dell'albero, si avrà che `find` ha un costo superiormente limitato da $\log_{2}{n}$, e perciò è
$$O(\log{n})$$

## Referenze
- [[quick-find|Quick find]]