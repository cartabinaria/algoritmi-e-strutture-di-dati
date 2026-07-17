---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 21-04-2024 21:19:10
links:
  - "[[lecture-16042024112039|Lecture 16042024112039]]"
  - "[[lecture-17042024113805|Lecture 17042024113805]]"
  - "[[lecture-18042024093835|Lecture 18042024093835]]"
---
# Programmazione dinamica
---
## Introduzione
> Per **programmazione dinamica** si intende una [[tecniche-algoritmiche|tecnica algoritmica]] sviluppata negli anni '50 da [[richard-e. bellman|Bellman]] nell'ambito dei problemi di ottimizzazione, e consiste nel _trovare la soluzione ottima secondo un indice di qualità assegnato ad ognuna delle soluzioni possibili_, attraverso un [[approccio-bottom-up|approccio bottom-up]].

### Relazione con divide et impera
La programmazione dinamica è speculare alla tecnica [[divide-et-impera|divide et impera]]:
- _divide-et-impera_ ---> [[approccio-top-down|approccio top-down]], tecnica [[ricorsione|ricorsiva]], vantaggiosa quando i sottoproblemi sono indipendenti;
- _programmazione dinamica_ ---> approccio bottom-up, tecnica [[iterazione|iterativa]], vantaggiosa quando ci sono sottoproblemi ripetuti.

Se volessimo rappresentare un problema come [[albero|alberi]] cui nodi e foglie sono sottoproblemi della radice (problema di partenza), allora l'_approccio dinamico consiste nel partire con il risolvere le foglie che sin da subito devono essere identificate, quindi combinarle per ottenere la soluzione alla radice_.

## Ingredienti
Il processo risolutivo di un algoritmo di programmazione dinamica involve sempre 4 passaggi fondamentali:
1. **identificazione dei sottoproblemi**;
2. **risoluzione dei sottoproblemi** sfruttando un approccio [[induzione-strutturale|induttivo]] --> si risolvono i casi base, poi si trova un meccanismo per risolvere tutti gli altri sottoproblemi usando le soluzioni calcolate in precedenza;
3. **ricostruzione della soluzione effettiva** --> questo perché la soluzione ottenuta è come se fosse un risultato in [[logica-classica|logica classica]], per cui _fornisce un valore ma non il modo per ottenerlo_;

## Esempi
### Fibonacci
#### Divide et impera
La soluzione divide et impera per calcolare l'$n$-esimo [[successione-di-fibonacci|numero di Fibonacci]] è di derivazione matematica, del tipo:
$$F(n) = \begin{cases}
1 & n \leq 2 \\
F(n-1) + F(n-2) & n > 2
\end{cases}$$

Il [[complessita-computazionale|costo computazionale]] di questo algoritmo, seguendo un'[[equazione-di-ricorrenza|equazione di ricorrenza]] pressoché identica alla funzione $F(n)$, è
$$T(n) = O(2^{n})$$

Il problema, di fatto, sta nella ripetizione dei calcoli per ogni $F(n)$. Possiamo infatti usare la tecnica della [[memoization|memoization]] per memorizzare in [[cache|cache]][^1] i risultati ottenuti, così da non doverli ripetere per ogni chiamata ricorsiva. In tal caso si dimostra ([[induzione-strutturale|per induzione]]) che il numero di chiamate ricorsive del divide et impera è $2n-3$, per cui viene
$$T(n) = O(n)$$

#### Programmazione dinamica
Con la programmazione dinamica, invece, l'idea è di partire dal basso. Quindi calcoliamo gli $n$ numeri di Fibonacci a partire dal 1°, poi con il 2°, il 3°, 4°, e così via fino ad arrivare all'$n$-esimo: questo perché **sappiamo dai risultati precedenti come ottenere i successivi**. Infatti, banalmente, se sappiamo il 1° e il 2°, allora 3° = 1° + 2°, ecc...

La soluzione è quella iterativa standard di calcolo dell'$n$-esimo numero di Fibonacci. Si può usare un'array lungo $n$, o anche solo 3 variabili[^2]. Nel secondo caso, infatti, si ha un costo computazionale di $O(n)$ e uno spazio occupato costante $O(1)$!

### Sottovettore massimo
Un altro problema risolto facilmente con l'approccio divide et impera era quello del sottovettore massimo. Il costo era risultato essere $O(n\log{n})$, ma si può fare meglio di così: usando la programmazione dinamica.

L'idea, seguendo i passaggi standard della programmazione dinamica, è prima di tutto di identificare il sottoproblema.
Allora fissiamo $P(i)$ come il _problema che consiste nel determinare il valore massimo della somma degli elementi dei sottovettori non vuoti $V[1, \cdots, i]$ che hanno $V[i]$ come ultimo elemento_.
Quindi, in una struttura di supporto $S$, salviamo in $S[i]$ la soluzione di $P(i)$. Quindi, _il problema $S$ (quello di partenza) può essere visto come il massimo tra gli $S[i]$_!
Per risolvere $S$, allora, non ci resta che trovare uno stratagemma efficiente per _calcolare $P(i)$ sfruttando_, secondo i dettami della programmazione dinamica, _i risultati precedentemente calcolati_, ovvero $S[i-1], S[i-2], \cdots$.

Notiamo che la soluzione ottimale di $P(i)$ (che sarà salvata in $S[i]$) non è altro che il massimo tra $v[i]$ e $S[i-1] + v[i]$. Mettiamo caso di essere nella seguente situazione:

| S[i-1] | S[i] |
| ------ | ---- |
| -3     | ?    |

| v[i] |
| ---- |
| 10   |

In questo caso se il sottovettore migliore fino a $i-1$ ha valore $-3$, è ovvio che il sottovettore migliore fino a $i$ è semplicemente $v[i]$, perché quest'ultimo ha valore $10$ e anche sommando $v[i] + S[i-1] = -7$ otteniamo appunto un valore minore.

Se invece ci si trova nella situazione

| S[i-1] | S[i] |
| ------ | ---- |
| 5      | ?    |

| v[i] |
| ---- |
| 4    |

allora il sottovettore di somma massima avrà proprio valore $S[i-1] + v[i] = 9 = S[i]$.

<u>Nota bene</u>: qui il caso base è semplicemente $S[1] = v[1]$, triviale.

Così facendo **ci si costruisce $S[]$ con costo lineare, e se ci salviamo il valore di $S[i]$ massimo otteniamo proprio il valore del sottovettore massimo**.

Ma come sappiamo dagli ingredienti, **questo non ci consente di determinare quale sia questo sottovettore**. Per farlo, allora, sapendo la posizione della cella finale di questo sottoarray, ovvero $i$ di $S[i]$, per sapere la cella d'inizio ci basta scorrere all'indietro $S[]$ fino a che $S[i] \neq V[i]$: quando avverrà $S[i] = V[i]$ significherà che la soluzione parte da quella cella, perché _rappresenta l'inizio della successione "vittoriosa" di celle appartenenti al sottovettore massimo_.

Ad ogni modo il costo dell'algoritmo non cambia:
$$T(n) = O(n)$$

### Problema dello zaino
Il problema più famoso risolto dalla programmazione dinamica è il [[problema-dello-zaino|problema dello zaino]].

### Seam carving
Un altro algoritmo che sfrutta la programmazione dinamica è il [[seam-carving|seam carving]] per il ridimensionamento delle immagini.

### Distanza di Levenshtein
Un ultimo algoritmo importante che utilizza la programmazione dinamica è il calcolo della [[distanza-di-levenshtein|distanza di Levenshtein]].

## Referenze
[^1]: ovviamente non fisica, intesa come _porzione di memoria ausiliaria_
[^2]: anche 2 volendo, ma poco importa, l'importante è che sia indipendente da $n$!