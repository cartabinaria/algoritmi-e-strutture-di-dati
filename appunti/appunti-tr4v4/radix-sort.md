---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 10-03-2024 21:33:26
links:
  - "[[lecture-05032024111158|Lecture 05032024111158]]"
---
# Radix sort
---
## Introduzione
> Il **radix sort** è un [[algoritmo-di-ordinamento-non-comparativo|algoritmo di ordinamento non-comparativo]] che funziona _ordinando prima rispetto alla cifra meno significativa, poi rispetto alla penultima meno significativa, e così via fino ad arrivare alla più significativa_.

L'autore è [[harold-h. seward|Harold H. Seward]], 1954.

<u>Attenzione</u>: alla base dell'ordinamento del radix sort è necessario che **l'algoritmo di ordinamento usato per ordinare le singole cifre deve essere stabile**. Non per niente si utilizza spesso il [[counting-sort|counting sort]], all'interno del radix sort.

## Algoritmo
![[radix-sort.png]]
![[radix-sort-pseudo.png]]

<u>Nota bene</u>: questo algoritmo fa comprendere per bene la differenza tra chiave e valore. Infatti quasi si riordinano le chiavi, ovvero _le singole cifre_ (chiamate appunto **radici**), esse sono associate a dei valori, cioè l'_intero numero a cui appartengono_. In questo modo _si possono ordinare anche delle stringhe in modo estremamente efficiente_.

## Complessità
La [[complessita-computazionale|complessità computazionale]] dell'algoritmo, usato insieme al counting sort, dipende allora da un nuovo fattore (unito ai due del counting): $d$, ovvero il _numero massimo di cifre in una chiave_. Anche in questo caso, però, il costo nel caso ottimo, pessimo e medio non cambia, perciò si ha:
$$\Theta(d(n+k))$$
Come per il counting sort, _se $d$ e $k$ sono costanti allora il costo è lineare_[^1]; ma se per esempio $d = n$ allora ovviamente diventa $\Theta(n^{2})$ (sempre che $k$ non sia $n^{2}$!).

## Referenze
[^1]: dove per costante si intende che non mutano al variare di $n$