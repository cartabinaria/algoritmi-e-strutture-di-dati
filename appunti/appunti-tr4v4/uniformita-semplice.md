---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 28-03-2024 16:34:37
links:
  - "[[lecture-21032024091145|Lecture 21032024091145]]"
---
# Uniformità semplice
---
## Introduzione
> Una [[funzione-hash|funzione hash]] $h$ deve soddisfare (anche se approssimativamente) la proprietà di **uniformità semplice**, il che significa che deve distribuire uniformemente le chiavi all'interno dell'array `T` negli indici $0, \cdots, m-1$. Di conseguenza ogni indice dev'essere generato con probabilità
> $$\frac{1}{m}$$

Di fatto se alcuni indici sono scelti con maggiore probabilità da $h$ allora si avrà un numero maggiore di [[collisione-hash|collisioni]].

Teoricamente parlando per soddisfare tale proprietà _dovremmo conoscere la distribuzione di probabilità con cui le chiavi sono estratte da $U$_, il che è irrealistico: _sarebbe come prevedere quali nomi di variabili un programmatore sceglierà per il suo codice_. Solo in casi specifici tale distribuzione è nota (si pensi a $h(k) = \lfloor mk \rfloor$ con $k \in U = [0, 1[$).

## Referenze