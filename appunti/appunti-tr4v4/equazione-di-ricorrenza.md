---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 29-02-2024 15:38:32
links:
  - "[[lecture-27022024111544|Lecture 27022024111544]]"
---
# Equazione di ricorrenza
---
## Introduzione
> Un'**equazione di ricorrenza** è un'[[equazione|equazione]] _descritta in termini di se stessa_, ovvero per mezzo della [[ricorsione|ricorsione]]. Solitamente si associano ad [[algoritmo|algoritmi]] ricorsivi, e se risolte possono determinare la loro [[complessita-computazionale|complessità compiutazionale]].

## Composizione
L'equazione di ricorrenza associata a un algoritmo ricorsivo dev'essere scritta:
1. sostituendo le _notazioni asintotiche_ con _espressioni positive_;
2. sostituendo tutte le _costanti_, moltiplicative e additive, _con 1_ (perché ci importa del comportamento asintotico);
3. semplificando ogni tipo di _arrotondamento_;

Presa per esempio la seguente equazione
$$T(n) = \begin{cases} \Theta(1) & n=1 \\ 2T\left(\lfloor\frac{n}{3}\rfloor\right)+ O(n) & n > 1 \end{cases}$$

andiamo a sostituire le notazioni asintotiche con [[funzione-di-costo|funzioni di costo]] generiche (espressioni positive), del tipo
$$T(n) = \begin{cases} 1 & n=1 \\ 2T\left(\lfloor\frac{n}{3}\rfloor\right)+ cn & n > 1 \end{cases}$$

quindi sostituiamo tutte le costanti, in questo caso l'unica è $c$, con 1, ottenendo
$$T(n) = \begin{cases} 1 & n=1 \\ 2T\left(\lfloor\frac{n}{3}\rfloor\right)+ n & n > 1 \end{cases}$$

infine non ci rimane che togliere l'arrotondamento _floor_ nella chiamata induttiva, per cui ci rimane
$$T(n) = \begin{cases} 1 & n=1 \\ 2T\left(\frac{n}{3}\right)+ n & n > 1 \end{cases}$$

## Risoluzione
I metodi principali utilizzati per risolvere equazioni di ricorrenza sono:
- [[metodo-dell-iterazione|metodo dell'iterazione]]
- [[master-theorem|master theorem]]
- [[metodo-della-sostituzione|metodo della sostituzione]] (che non faremo)
- [[metodo-dell-albero-di-ricorsione|metodo dell'albero di ricorsione]] (che non faremo)

<u>Nota bene</u>: ci sono casi particolari in cui comunque risulta _impossibile risolvere equazioni di ricorrenza_, a prescindere dal metodo usato. In tal caso si procede con l'aiuto di calcolatori.

## Referenze