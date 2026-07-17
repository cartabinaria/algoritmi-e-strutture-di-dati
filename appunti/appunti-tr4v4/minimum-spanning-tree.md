---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 12-05-2024 14:46:50
links:
  - "[[lecture-02052024091854|Lecture 02052024091854]]"
  - "[[lecture-06052024092734|Lecture 06052024092734]]"
---
# Minimum spanning tree
---
## Introduzione
> In un [[grafo|grafo]] [[grafo-non-orientato|non orientato]] ma [[grafo-pesato|pesato]] e (per semplicità) connesso, il **minimum spanning tree** (o **MST**) è un _sottografo aciclico, in particolare un albero di copertura (spanning tree), cui somma del peso degli archi è la minore possibile_.

<u>Nota bene</u>: _esiste più di un albero di copertura_, ma si vuole trovare quello con peso complessivo degli archi minore.

<u>Osservazione</u>: in un minimum spanning tree il _numero di archi possibili è esattamente $n-1$_ (con $n = |V|$); infatti è il _[[insieme-massimale|massimale]] di archi che crea un albero di copertura aciclico, in quanto se fosse $n$ ci sarebbe per forza un ciclo_.

## Idea
Entrambi gli [[algoritmo|algoritmi]] che andremo ad affrontare si basano su [[algoritmi-greedy|approccio greedy]]. Sfruttano in particolare due _regole_ "ingorde" che consentono, con fondamenti matematici, di selezionare archi appartenenti al futuro MST e di scartarne invece altri che mai potranno appartenerci: in questo modo, alternando l'uso delle regole, è possibile far _accrescere il sottoinsieme $T$ di archi fino ad arrivare alla conclusione del minimum spanning tree_, quando per esempio si ha $|T| = n-1$.

Il problema è capire allora come selezionare _archi sicuri_, ossia che faranno parte di $T$, e come escludere _archi insicuri_, che non faranno parte di $T$.

### Regola del taglio
Ragioniamo [[induzione-strutturale|induttivamente]] partendo da una situazione in cui già esistono degli archi sicuri già selezionati, che indicheremo come **archi blu**.

Definiamo allora un **taglio** $(S, V-S)$ come una _partizione di $V$ in due [[definizione-di-essere-sottoinsieme|sottoinsieme]] [[definizione-di-intersezione|disgiunti]] tale che nessuno degli archi attraversati dal taglio sia blu_.

La regola del taglio ci dice allora che:
> Dopo aver tracciato un taglio, **possiamo scegliere tra quelli selezionati quello con peso minimo** (scelta ingorda), detto arco leggero.

Questo è corretto perché _dividendo il taglio in due sottoinsiemi di $V$ disgiunti è normale che, dovendo creare un MST, prima o poi gli insiemi debbano essere uniti da un qualche arco_: scegliendo quello leggero, ossia di peso minimo, si assicura la creazione di un MST.

![[regola-taglio-1.png]]
![[regola-taglio-2.png]]

### Regola del ciclo
Ragionando sempre induttivamente partiamo da una situazione in cui sono già presenti nel grafo archi che sicuramente non faranno parte dell'MST, detti **archi rossi**.

La regola del ciclo ci dice allora che:
> Dopo aver identificato un ciclo semplice del grafo che non contenga archi rossi, **tra tutti gli archi del ciclo si può selezionare come rosso quello di peso massimo** (scelta ingorda).

Questo è corretto perché _in un MST non devono essere presenti cicli, per cui se esiste un ciclo nel grafo si può tranquillamente escludere l'arco di peso massimo_ appartenente al ciclo garantendo così una corretta costruzione dell'MST.

![[regola-ciclo-1.png]]
![[regola-ciclo-2.png]]

## Algoritmo
Vediamo due principali algoritmi che sfruttano i principi delle due regole per creare, regola dopo regola, un MST di un grafo:
- [[algoritmo-di-kruskal|algoritmo di Kruskal]]
- [[algoritmo-di-prim|algoritmo di Prim]]

## Referenze