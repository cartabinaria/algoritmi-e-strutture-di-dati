---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 24-03-2024 17:56:14
links:
  - "[[lecture-21032024091145|Lecture 21032024091145]]"
---
# Tabella hash
---
## Introduzione
> Una **tabella hash** (o **hashmap**) è una [[struttura-dati|struttura dati]] fondamentale che permette un'[[prototipo-vs-implementazione|implementazione]] estremamente efficiente della struttura dati [[dizionario|dizionario]]. L'idea che caratterizza le tabelle hash è quella di _generalizzare l'indicizzazione di un [[array|array]] ordinario_. Il [[complessita-computazionale|costo]] medio di accesso/inserimento/rimozione di una tabella hash è $O(1)$, per cui costante.

### Utilità
Le tabelle hash sono usate ovunque per le loro formidabili proprietà, in particolare i [[compilatore|compilatori]] fanno uso delle cosiddette [[look-up-table|look-up tabels]] per creare un'associazione tra il nome degli [[identificatore|identificatori]] (_chiavi_) e il loro indirizzo in memoria (_dati_).

## Principio di funzionamento
Per poter studiare il funzionamento delle tabelle hash è necessario prima di tutto comprendere quando è il caso di usarle.

In particolare, preso in considerazione un [[dominio-di-interpretazione|dominio di interpretazione]]/caso di studio, si vanno a definire i 2 seguenti [[insieme|insiemi]]:
- $U =$ **universo di tutte le chiavi possibili**;
- $K =$ **insieme di tutte le chiavi effettivamente utilizzate**;

A seconda della [[cardinalita|cardinalità]] dei due insiemi si consiglia l'implementazione di un dizionario
- _ad indirizzamento diretto_, o
- _ad hash_

In particolare:
- se $U$ è relativamente piccolo e si ha $|K| \sim |U| \implies$ tabelle a indirizzamento diretto;
- se $U$ è invece grande e si ha $|K| << |U| \implies$ tabelle hash;

Andiamo a vedere nel dettaglio i due casi.

### Tabelle a indirizzamento diretto
Queste si implementano direttamente su un array `T` di dimensione $|U|$, tale che _la chiave $k$ è memorizzata nella posizione $k$ dell'array_[^1]. Ogni chiave è perciò distinta, e i costi sono:
- temporali: $O(1)$, di fatto l'array ha sempre un tempo di accesso costante
- spaziali: $O(T.\text{length})$

Ed è proprio la memoria occupata che crea problemi. Si analizzino infatti i seguenti casi:
- $|K| \sim |U| \implies$ la soluzione è accettabile;
- $|K| << |U| \implies$ la soluzione non è accettabile, se non irrealizzabile.

Si pensi per esempio all'insieme $U$ di tutti gli identificatori lunghi massimo 20 caratteri, e un array `T` di [[puntatore|puntatori]] a tali stringhe. La cardinalità di $U$ è $24^{20}$, per cui l'array `T` occuperà almeno
$$26^{20} \cdot 4 \text{ bytes} > 10^{19} \text{ Terabytes}$$

decisamente inaccettabile... E questo _imponendo una limitazione sulla lunghezza delle chiavi_!

### Tabelle hash
Un array di dimensione $\Theta(|U|)$ richiede troppa memoria se $U$ è grande. Per questo:
> L'idea alla base delle tabelle hash sta nell'_usare un array `T` di dimensione $m$ proporzionale al numero di chiavi che andremo ad usare_ (calcolato con una stima) e quindi una _funzione `hash` che mappa tutte le chiavi dell'universo in un intero compreso tra $0$ e $m-1$_ (un indice di `T`).

Quello che si va a fare è quindi **schiacciare una proto-infinità di chiavi possibili in $m$ chiavi effettivamente utilizzate**[^2]. E questo, ovviamente, ha vantaggi e svantaggi.

In particolare si consideri la funzione hash $h(k)$ che presa una chiave possibile $k$ restituisce un intero tra $0$ e $m-1$. Se scegliamo a caso delle chiavi di $U$ _è estremamente probabile che $h$ dia in uscita lo stesso indice/valore per due chiavi diverse_. Questo si chiama **collisione**, ed è un **problema che non può essere matematicamente evitato, ma solo minimizzato e gestito**.

<u>Nota bene</u>: in fin dei conti, pensandoci, il fenomeno delle collisioni è triviale. Stiamo comprimendo un'infinità di chiavi possibili a un _set_ finito di $m$ chiavi utilizzate, è normale che ci siano delle collisioni. Se non ci fossero _vorrebbe dire che $h$ è biiettiva, e perciò per la [[insieme-infinito|definizione di insieme infinito]] vorrebbe dire che anche l'array `T` è infinito, il che va in contrasto con le assunzioni iniziali_.

## Ingredienti
Visto il principio di funzionamento non resta che definire gli ingredienti che caratterizzano una tabella hash:
- **funzione `hash`**, che
	1. deve effettuare il calcolo/la mappatura velocemente
	2. deve garantire una buona distribuzione delle chiavi sull'array `T`
- **metodo per gestire le collisioni**, che
	1. sono inevitabili
	2. devono essere gestite
- **array `T` di dimensione $m = \Theta(|K|)$**, tale che
	1. $m$ sia proporzionale al numero di identificatori che stimiamo ci siano
	2. `T` sia eventualmente _ridimensionabile_
	3. $m$ sia scelta in base alla funzione `hash` e al metodo per gestire le collisioni

Nel dettaglio:
- [[funzione-hash|funzioni hash]]
- [[collisione-hash|collisioni hash]]

## Referenze
[^1]: proprio come se _$k$ agisse da indice di `T`_
[^2]: un po' come la [[sigmoide|sigmoide]], che mappa valori nel range $]-\infty, +\infty[$ a $[0, 1]$