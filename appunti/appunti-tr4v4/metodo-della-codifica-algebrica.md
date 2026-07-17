---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 24-03-2024 22:06:15
links:
  - "[[lecture-21032024091145|Lecture 21032024091145]]"
---
# Metodo della codifica algebrica
---
## Introduzione
> Il **metodo della codifica algebrica** è una [[funzione-hash|funzione hash]] $h$ che presa in ingresso una chiave $k$ è definita come
> $$h(k) = (k_{n}x^{n} + k_{n-1}x^{n-1} + \cdots + k_{1}x + k_{0}) \mod{m}$$
> dove $k_{n}, k_{n-1}, \cdots, k_{i}, \cdots, k_{1}, k_{0}$ sono le cifre binarie (o decimali, o [[ascii|ASCII]]) di $k$, e $x$ è costante.

A differenza del [[metodo-della-divisione|metodo della divisione]] e del [[metodo-della-moltiplicazione|metodo della moltiplicazione]], questo è _l'unico per cui $h(k)$ dipende da tutti i bit/caratteri di $k$_. Ma è costoso da calcolare, di fatto il [[complessita-computazionale|costo]] è $\Theta(\log^{2}{k})$[^1].

Tuttavia con la [[regola-di-horner|regola di Horner]] è possibile ridurre questo costo fino a $\Theta(\log{k})$, decisamente più accettabile.

## Referenze
- la funzione `java.lang.String.hashCode()` di [[java|Java]] è basata esattamente sulla codifica algebrica implementata con la regola di Horner, e utilizza i codici ascii dei caratteri;

[^1]: polilogaritmico