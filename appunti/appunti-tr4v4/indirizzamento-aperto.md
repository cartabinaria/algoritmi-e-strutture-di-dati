---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 28-03-2024 15:49:27
links:
  - "[[lecture-25032024091657|Lecture 25032024091657]]"
---
 # Indirizzamento aperto
---
## Introduzione
> Per **indirizzamento aperto** si intende una tecnica di mitigazione delle [[collisione-hash|collisioni hash]] nel contesto delle [[tabella-hash|tabelle hash]], che _consiste nell'inserire tutte le chiavi all'interno della tabella, e in caso di collisione di cercare uno slot libero_.

![[indirizzamento-aperto.png]]

## Strategie di ispezione
Ciò che si deve analizzare di questa strategia è l'[[algoritmo|algoritmo]] di ispezione usato per cercare uno slot libero all'interno della tabella. Guardiamo i seguenti:
- [[ispezione-lineare|ispezione lineare]]
- [[ispezione-quadratica|ispezione quadratica]]
- [[doppio-hashing|doppio hashing]]

## Pseudocodice
Prima di tutto tra la funzione `hash` $h$ e le operazioni `search`, `insert` e `delete` deve interporsi la **funzione di ispezione** $h(k, i)$, ovvero la [[funzione-informatica|funzione]] che implementa la strategia di ispezione adottata. Questa deve prendere _chiave_ $k$ e _passo di ispezione_ $i$. Questo passo di ispezione è fondamentalmente l'offset che a seconda della strategia di ispezione adottata separa $h(k)$ dall'indice che gli sarà effettivamente assegnato da tale funzione di ispezione.

<u>Nota bene</u>: la funzione d'ispezione è delicata. Se fatta male _potrebbe non visitare ogni slot solo una volta, ed entrare in un loop senza uscirne_: questo non consentirebbe la visita di ogni casella della tabella. Si dice allora che tale funzione **deve fornire una [[permutazione|permutazione]] degli indici $0, \cdots, m-1$ della tabella hash**.

In secondo luogo, la rimozione `delete` dev'essere gestita con criterio. Non possiamo infatti semplicemente mettere a `NIL` la cella da rimuovere, perché questo andrebbe a corrompere il funzionamento della funzione di ispezione $h(k, i)$: _se questa smette di cercare $k$ non appena trova una cella `NIL`, non possiamo sapere se questa identifica la fine della sequenza da ricercare o se si tratta di un buco_. Allora l'idea è di **usare un marcatore `DELETED` per identificare le chiavi che sono state rimosse, in modo da non interrompere l'ispezione**.

![[indirizzamento-aperto-search.png]]
![[indirizzamento-aperto-insert.png]]
![[indirizzamento-aperto-delete.png]]

### Costi
I [[complessita-computazionale|costi]] delle operazioni sono:
- _caso ottimo_: $O(1)$;
- _caso pessimo_: $O(m)$ dove $m$ è la dimensione della tabella;
- _caso medio_: complesso da analizzare, dipende infatti sia dalla _funzione hash_ ($h(k)$) che dalla _funzione di ispezione_ ($h(k, i)$);

## Analisi caso medio
Usiamo sempre il [[fattore-di-carico|fattore di carico]] $\alpha$, che in questo caso essendo $n \leq m$ è $$\alpha < 1$$
(se $\alpha = 1$ la tabella è piena).

Assumendo [[uniformita-semplice|hashing uniforme semplice]], otteniamo due _teoremi che valgono per l'ispezione quadratica e il doppio hashing_: quella _lineare non soddisfa infatti l'assunzione che le permutazioni degli indici siano equiprobabili_.

### Ricerca senza successo
> Sotto l’assunzione di hashing uniforme semplice e sequenze di ispezione equiprobabili, il numero medio di ispezioni di una ricerca senza successo in una tabella hash con indirizzamento aperto e fattore di carico $\alpha < 1$ è al massimo
> $$\frac{1}{1 - \alpha}$$

### Ricerca con successo
> Sotto l’assunzione di hashing uniforme semplice e sequenze di ispezione equiprobabili, il numero medio di ispezioni di una ricerca con successo in una tabella hash con indirizzamento aperto e fattore di carico $\alpha < 1$ è al massimo
> $$\frac{1}{\alpha}\ln{\frac{1}{1-\alpha}}$$

### Caso medio
Di conseguenza per entrambi casi si ha che se $\alpha$ è costante il tempo di accesso è $O(1)$, e invece:
- $\alpha = 0.5 \implies$ la ricerca senza successo richiede in media al massimo 2 ispezioni; la ricerca con successo meno di 2;
- $\alpha = 0.9 \implies$ la ricerca senza successo richiede in media al massimo 10 ispezioni; la ricerca con successo meno di 3;

## Referenze