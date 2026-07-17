---
tags:
  - "#category/note"
  - "#status/finished"
  - topic/programmazione
  - topic/algoritmi-e-strutture-dati
date: 19-09-2023 20:26:17
links:
  - "[[lecture-19092023091712|Lecture 19092023091712]]"
  - "[[lecture-19022024090000|Lecture 19022024090000]]"
  - "[[lecture-20022024111057|Lecture 20022024111057]]"
---
# Algoritmo
---
## Definizione
> Un **algoritmo** è una sequenza di [[istruzione|istruzioni]], di numero finito, che risolve un dato problema.

Di per sé un algoritmo può essere scritto in qualunque linguaggio, ma solitamente è molto comune l'utilizzo di [[diagrammi-di-flusso|diagrammi di flusso]].

## Storia
Deriva da [[al-khwarizmi|Al-Khwarizmi]], un matematico persiano che diffuse in occidente il _sistema di numerazione posizionale_. La stessa somma algebrica tra due numeri codificati in numerazione posizionale costituisce a tutti gli effetti un algoritmo vero e proprio. E' qui che gli algoritmi incontrano l'[[algebra-astratta|algebra]].

Sin dall'antichità sono stati sviluppati algoritmi matematici per risolvere svariati problemi, tra cui:
- l'[[algoritmo-di-euclide|algoritmo di Euclide]]
- l'[[algoritmo-di-eulero|algoritmo di Eulero]]
- Al-Khwarizmi stesso ne ha inventati
- così come [[isaac-newton|Netwon]]
- e [[alan-turing|Turing]]

## Algoritmo vs. Programma
Algoritmo:
- descrizione ad alto livello
- esiste da prima dei computer
- si può assumere una quantità illimitata di memoria

Programma:
- è l'_implementazione_ di un algoritmo
- scritto su un linguaggio di programmazione
- eseguito su un computer, e quindi con memoria finita

## Caratteristiche
La definizione di un algoritmo definisce i vincoli di:
- _input_
- _sequenza finita di istruzioni_ (anche ripetute, ovvero in loop)
- _output_

<u>Attenzione</u>: utilizzeremo lo _pseudo-codice_ per scrivere un algoritmo.

### Affrontare un algoritmo
Nonostante i vincoli, **per risolvere uno stesso problema ci sono infiniti algoritmi**. Per cui in base a quali criteri dovremmo scegliere quello da implementare?

Quando si affronta un algoritmo si deve perciò:
- **capire** bene gli input, gli output e le proprietà matematiche ad esso correlato
- **apprendere** attraverso delle stime l'efficienza dell'algoritmo in termini di _tempo e memoria_ (esistono tecniche per valutare l'efficienza di un algoritmo senza testarlo praticamente)
- **studiare** tecniche algoritmiche, perché _spesso problemi differenti condividono la stessa struttura di base_[^1]
	- ad esempio gli [[algoritmo-di-ordinamento|algoritmi di ordinamento]] sono correlati ad [[albero|alberi]]
	- quindi si cerca di _mappare un problema da un dominio a un altro_

<u>Attenzione</u>: si deve fare tutto ciò per la sola ragione che **non esiste un algoritmo che genera una soluzione a partire da un problema**.

#### Esempio
Vogliamo implementare un algoritmo che ci dice l'$n$-esimo [[successione-di-fibonacci|numero di Fibonacci]]. Esistono diversi approcci risolutivi.

##### Algoritmo 1
Usiamo la formula
$$F_{n} = \frac{1}{\sqrt{5}}(\phi^{n} - \hat{\phi}^{n})$$
dove:
- $\phi = 1.618...$
- $\hat{\phi} = -0.618...$

Si tratta di una soluzione molto elegante e veloce, ma _l'irrazionalità di $\phi$ e $\hat{\phi}$ rende impreciso il calcolo_, in quanto non essendo possibile salvare ogni infinita cifra delle due costanti è necessario troncare dei decimali, creando un _errore che viene propagato dalle potenze_.

##### Algoritmo 2
Usiamo la formula [[ricorsione|ricorsiva]]
$$F_{n} = \begin{cases} 1 && n \leq 2 \\ F_{n-1} + F_{n-2} && n > 2 \end{cases}$$
E' una soluzione semplice e compatta, ma che nasconde problematiche non ovvie. Per rendercene conto andiamo ad analizzare l'occupazione della memoria e il tempo d'esecuzione.

###### Occupazione della memoria
Le chiamate ricorsive, come sappiamo, riempiono lo [[stack|stack]] di sistema di [[record-di-attivazione|record di attivazione]]. L'albero delle chiamate ricorsive avrà perciò una forma del seguente tipo:
![[fibonacci-ricorsivo.png]]

Notiamo come il ramo più lungo è e sempre sarà lungo $n-1$. Questo è quindi lo spazio massimo occupato di memoria: si dice essere _proporzionale ad $n$_.

###### Tempo di esecuzione
Per stimare il tempo di esecuzione _non possiamo semplicemente contare quanto ci mette in secondi_, perché ciò dipende dall'hardware e anche dal software della macchina su cui è eseguito l'algoritmo; così come _non possiamo contare il numero di istruzioni-macchina_, perché dipende dal linguaggio di programmazione in cui è implementato l'algoritmo e dal compilatore usato.

L'unico modo per fare una buona stima del tempo di esecuzione è quello di _contare il numero di operazioni elementari nello pseudo-codice_, perché ciò è indipendente da tutto (e solo dall'algoritmo stesso). Questo si chiama **costo compiutazionale**, e per calcolarlo spostiamo il dominio del problema nel conteggio del numero di nodi dell'albero delle chiamate ricorsive.

Per il calcolo di tale numero facciamo una stima usando una _relazione di ricorrenza_, ovvero attraverso lo studio matematico di una funzione ricorsiva che conta i nodi di un tale albero. Andiamo quindi a produrre un _lower-bound_ e un _upper-bound_: una stima di quanti nodi, all'incirca, produce l'albero rispetto a $n$ (l'input).

In particolare il numero di nodi di un albero di chiamate ricorsive per il calcolo di un $n$-esimo numero di Fibonacci è
$$2^{\frac{n}{2}} \leq T(n) \leq 2^{n}$$

Si tratta di una stima approssimativa, ma che è sufficiente a rispondere alla domanda: "l'algoritmo è veloce?". Per rispondere infatti ci basti pensare che assumendo di poter fare $100.000.000$ di chiamate ricorsive al secondo il tempo necessario al calcolo in secondi sarebbe $\geq \frac{2^{\frac{n}{2}}}{1000000} sec$: _per il 100° numero di Fibonacci ci vorrebbero 3 mesi, mentre per il 200° numero 400 miliardi di millenni_!

L'algoritmo è lento, perché il _tempo di esecuzione ha una crescita esponenziale rispetto ad $n$_. E' perciò inutilizzabile.

##### Algoritmo 3
Questo algoritmo prevede di memorizzare in un [[array|array]] i valori man mano calcolati, e di inserire di volta in volta nell'array la somma delle due celle precedenti. Il risultato finale sarà in $F[n]$[^2].
![[fibonacci-array.png]]

###### Tempo di calcolo
Contando il numero di operazioni elementari otteniamo un complesso di $4 + (n-2) + (n-2) + (n-2)$ operazioni, ovvero $3n - 2$. Il _tempo di calcolo sarà allora proporzionale ad $n$_.

###### Memoria usata
Sommiamo la dimensione delle variabili usate: $1 + n + 1 = n + 2$. Anche la memoria usata sarà proporzionale a $n$.

##### Algoritmo 4
Il problema dell'algoritmo 3 sta nel fatto che è inutile salvare tutti i numeri di Fibonacci precedenti all'$n$-esimo. Per cui implementiamo un algoritmo che memorizzi solo i numeri necessari al calcolo del successivo: i due precedenti.
![[fibonacci-iterativo.png]]

###### Tempo di calcolo
Il numero totale di operazioni elementari è $5n - 7$, per cui il _tempo è proporzionale a $n$_.

###### Memoria usata
Il numero di variabili invece è _costante_: 5.

##### Confronto tra 3° e 4°
Su grandi numeri, nonostante il 3° algoritmo faccia "matematicamente" meno operazioni, il 4° risulta essere più veloce. Questo può dipendere da una serie di motivi che riguardano il dettaglio implementativo dei compilatori, ovvero il modo in cui vengono per esempio gestiti gli array...

In ogni caso questo ci fa comprendere l'_inutilità del calcolo preciso dei tempi di esecuzione_: ci basta sapere che _entrambi gli algoritmi hanno un tempo di calcolo proporzionale a $n$_.

Inoltre, per quanto riguarda la memoria, l'_algoritmo 3 su grandi numeri rischia di occupare troppa memoria_, impedendo l'esecuzione del programma.

##### Algoritmo 5
L'algoritmo 5 sfrutta un teorema matematico sulla seguente [[matrice|matrice]] binaria:
$$A = \begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix}$$
In particolare ci dice che
$$A^{n-1} = \begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix}^{n-1} = \begin{pmatrix} F_{n} & F_{n-1} \\ F_{n-1} & F_{n-2} \end{pmatrix} \ \ \ \ \ \ \ \ \forall n \geq 2$$
Quindi sfruttiamo il teorema per andare a creare un algoritmo semplice, [[iterazione|iterativo]]:
![[fibonacci-matrix.png]]

###### Tempo di calcolo
Il numero di operazioni è difficile da calcolare perché non siamo in grado di stabilire a priori in quante operazioni consista il _prodotto matriciale_, ovvero la sua implementazione, ma possiamo dire che è _proporzionale a $n$_.

###### Memoria usata
La memoria usata, anche in questo algoritmo, è _costante_, indipendente da $n$. Quindi non sembra esserci alcun miglioramento dall'algoritmo 4. Ma la tecnica utilizzata può costituire il punto di partenza per l'algoritmo finale.

##### Algoritmo 6
Quest'ultimo algoritmo prende ispirazione dal 5°, e va semplicemente a velocizzare di molto l'operazione di moltiplicazioni di matrici usando una tecnica chiamata **exponentiation by squaring**, che consiste nella seguente funzione ricorsiva:
$$A^{n} = \begin{cases} (A^{\frac{n}{2}})^{2} & n \text{ pari} \\ A \cdot (A^{\frac{n-1}{2}})^{2} & n \text{ dispari} \end{cases}$$

Implementiamo allora il seguente algoritmo:
![[fibonacci-fast.png]]

###### Tempo di calcolo
Il tempo di calcolo è _proporzionale a $\log_{2}{n}$_, un risultato ottimo.

###### Memoria usata
Anche la memoria usata è _proporzionale a $\log_{2}{n}$_.

##### Riassunto
Usando la [[notazione-asintotica|notazione asintotica]] possiamo andare a riassumere i risultati nella seguente tabella:
![[confronto-algoritmi.png|500]]

## Referenze
[^1]: esattamente come avviene nell'[[algebra-astratta|algebra universale]]
[^2]: attenzione: gli indici nello pseudo-codice partono da 1