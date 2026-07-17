---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 28-03-2024 16:29:30
links:
  - "[[lecture-25032024091657|Lecture 25032024091657]]"
---
# Ispezione lineare
---
## Introduzione
> L'**ispezione lineare** è una [[funzione-informatica|funzione]] d'ispezione adottata dalla tecnica di mitigazione delle [[collisione-hash|collisioni hash]] dell'[[indirizzamento-aperto|indirizzamento aperto]], nel contesto delle [[tabella-hash|tabelle hash]], e si formulizza in
> $$h(k, i) = (h'(k) + i) \mod{m}$$
> dove:
> - $k$ è la chiave di $U$;
> - $i$ è il passo d'ispezione;
> - $h'(k)$ è la [[funzione-hash|funzione hash]] adottata.
> 
> In breve prevede, in caso di collisione, di andare ad _ispezionare l'indice successivo di $h'(k)$ della tabella, fino a che non se ne trova uno disponibile_.

E' importante notare come l'_indice $h'(k)$ determini l'intera sequenza di ispezione_ ($i = 0$).

## Problema
L'ispezione lineare genera **clustering primario**, ovvero la perdità della proprietà di [[uniformita-semplice|hashing uniforme semplice]]. Questo perché dopo una serie di inserimenti le probabilità che la funzione di ispezione $h(k, i)$ scelga una cella $r$ che si trova in prossimità di determinate sequenze lineari è la somma di tutte le probabilità delle celle $r-1, r-2, \cdots, h(k)$ che appartengono a tali sequenze.

### Esempio
Si consideri, su $h(k, i) = (h'(k) + 1) \mod{10}$ e $h'(k) = k \mod{10}$ ([[metodo-della-divisione|metodo della divisione]]), l'algoritmo in funzione definito dalla seguente immagine:
![[ispezione-lineare.png]]

A seguito del penultimo inserimento, `insert 13`, la _cella 9 ha una probabilità del 60% di essere scelta dalla prossima ispezione lineare_: è infatti la somma di $6 \cdot 10\%$ celle, ovvero la 3, 4, 5, 6, 7, 8. Ma anche la cella 1 ha il 20% di probabilità di essere scelta; di fatto l'unica cella che rimane uniformemente semplice è la numero 2, con un 10%.

## Referenze