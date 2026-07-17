---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 28-04-2024 22:33:59
links:
  - "[[lecture-23042024111652|Lecture 23042024111652]]"
  - "[[lecture-24042024111954|Lecture 24042024111954]]"
  - "[[lecture-29042024091854|Lecture 29042024091854]]"
---
# Grafo
---
## Introduzione
> Un **grafo** è una [[struttura-dati|struttura dati]] molto importante da cui si originano [[albero|alberi]] e [[lista|liste]]. E' caratterizzata da _nodi interconnessi da archi_. Matematicamente si dice che si tratta di una [[coppia-ordinata|coppia]] $(V, E)$ dove $V$ è un [[insieme-finito|insieme finito]] di vertici (nodi) e $E$ un insieme degli archi, ovvero di coppie (o insiemi) di due vertici.

### Notazione
Si userò per indicare la [[cardinalita|cardinalità]] di $V$ la lettera $n$, e per la cardinalità di $E$ la lettera $m$, perciò
$$n = |V|, \ \ m = |E|$$

## Tipologie
I grafi si distinguono principalmente in due categorie:
- [[grafo-orientato|grafi orientati]]
- [[grafo-non-orientato|grafi non orientati]]

Ce ne sono poi altre che riguardano la struttura interna dei grafi:
- [[grafo-pesato|grafi pesati]]
- [[grafo-aciclico|grafi aciclici]]
- [[grafo-completo|grafi completi]]
- [[albero-libero|alberi liberi]]
- [[albero-radicato|alberi radicati]]

## Definizioni
Per descrivere i grafi e gli [[algoritmo|algoritmi]] che operano su di essi si fa ricorso a termini specifici.

### Grado
> In un grafo non orientato il grado di un vertice è il _numero di archi che partono da esso_.
> In un grafo orientato il grado di un vertice è la _somma del suo grado entrante_ (archi in entrata) _e del suo grado uscente_ (archi in uscita).

### Incidenza
> L'_incidenza_ è una relazione tra archi e vertici, e si dice in un grafo orientato che l'arco $(v, w)$ è incidente da $v$ in $w$;

### Adiacenza
> L'_adiacenza_ è una relazione tra vertici e vertici, e si dice in un grafo orientato che un vertice $w$ è adiacente a $v$ sse $(v, w) \in E$.

L'adiacenza è utile quando si vuole ricavare la lista delle adiacenze di un certo nodo, ovvero i nodi che puntano ad esso.

<u>Nota bene</u>: in un grafo non orientato la relazione di adiacenza tra vertici è simmetrica.

### Raggiungibilità
> Se esiste un cammino $c$ tra i vertici $v$ e $w$ si dice che $w$ è _raggiungibile_ da $v$ tramite $c$.

<u>Nota bene</u>: in un grafo orientato il cammino non è simmetrico.

### Connessione
> Un grafo $G$ non orientato è connesso se esiste un cammino da ogni vertice ad ogni altro vertice.

### Connessione forte
> Un grafo $G$ orientato è fortemente connesso se esiste un cammino da ogni vertice ad ogni altro vertice. Un grafo orientato si dice invece debolmente connesso quando la sua versione non orientata è connessa.

Di fatto per vedere _se un grafo orientato è debolmente connesso lo converto in un grafo non orientato e controllo la proprietà di connessione_.

### Ciclo
> Un ciclo è un cammino cui _punto di partenza coincide con il punto di arrivo_.

Più dettagliatamente è un cammino $<w_{0}, w_{1}, \cdots, w_{n}>$ di lunghezza:
- $\geq 1$ nei grafi orientati, perché possono esistere i _cappi_;
- $\geq 3$ nei grafi non orientati, tale che $w_{0} = w_{n}$, perché non possono esistere i cappi.

Esistono due tipologie di cicli:
- _cicli semplici_ --> se i nodi $w_{0}, \cdots, w_n-1$ sono tutti distinti;
- _cicli non semplici_ --> quando non è semplice[^1].

### Altri termini
- [[cammino|cammino]]

## Operazioni
Le operazioni che una struttura che rappresenta grafi deve supportare sono:
- `numVertici() → intero`, restituisce la cardinalità di $V$
- `numArchi() → intero`, restituisce la cardinalità di $E$
- `grado(vertice v) → intero`, restituisce il numero di archi di un certo vertice, sia entranti che uscenti
- `archiIncidenti(vertice v) → (arco, arco, ... arco)`, restituisce gli _archi incidenti_ da un certo vertice `v` (che partono da `v`)
- `estremi(arco e) → (vertice, vertice)`, restituisce i vertici agli estremi di un arco
- `opposto(vertice x, arco e) → vertice`, ricavabile da `estremi` (perciò ridondante)
- `sonoAdiacenti(vertice x, vertice y) → booleano`, dati due vertici verifica se esiste un arco che li collega
- `aggiungiVertice(vertice v)`
- `aggiungiArco(vertice x, vertice y)`
- `rimuoviVertice(vertice v)`
- `rimuoviArco(arco e)`

## Implementazioni
Le principali implementazioni della struttura dati grafo sono:
- [[matrice-di-adiacenza|matrici di adiacenza]]
- [[lista-di-adiacenza|liste di adiacenza]]

## Algoritmi
Sui grafi ci sono una serie di algoritmi importanti da conoscere:
- [[algoritmi-di-visita-su-grafi|Algoritmi di visita su grafi]]
- [[componenti-connesse|Componenti connesse]]
- [[minimum-spanning-tree|Minimum spanning tree]]
- [[cammino-minimo|Cammino minimo]]

## Referenze
[^1]: un po' come l'insieme finito, che semplicemente non è [[insieme-infinito|infinito]]