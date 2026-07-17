---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 24-03-2024 21:56:14
links:
  - "[[lecture-21032024091145|Lecture 21032024091145]]"
---
# Metodo della divisione
---
## Introduzione
> Il **metodo della divisione** è una [[funzione-hash|funzione hash]] $h$ che presa in input una chiave $k$ è definita come
> $$h(k) = k \mod{m}$$
> dove $m$ è la dimensione dell'[[array|array]] `T` della [[tabella-hash|tabella hash]].

E' molto efficiente in quanto richiede solo una divisione intera, ma è estremamente suscettibile a specifici valori di $m$: il valore di output di $h$ potrebbe non dipendere da tutto $k$ ma solo dai suoi ultimi bit (se $m = 2^{p}$) o dall'ultima cifra decimale di $k$ (se $m = 10$).

Una soluzione a questi svantaggi potrebbe essere quella di scegliere _$m$ come numero primo_ distante da potenze di 2 e 10.

## Referenze