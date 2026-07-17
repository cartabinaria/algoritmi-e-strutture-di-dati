---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 21-02-2024 22:40:54
links:
  - "[[lecture-21022024111657|Lecture 21022024111657]]"
---
# Omega-grande
---
## Introduzione
> Data una [[funzione-di-costo|funzione di costo]] $g(n)$ definiamo l'[[insieme|insieme]] delle funzioni per cui $g(n)$ rappresenta un _limite asintotico inferiore_ come
> $$\Omega(g(n)) = \{f(n) | \exists c > 0, n_{0} \geq 0 : \forall n \geq n_{0}, f(n) \geq cg(n)\}$$
> dove $\Omega(g(n))$ è l'**Omega-grande** di $g(n)$.
> Nello studio degli [[algoritmo|algoritmi]] (in particolare nella [[notazione-asintotica|notazione asintotica]]) si tratta di fatto del simmetrico di [[o-grande|O-grande]].

Significa fondamentalmente che se $f$ è un $\Omega$-grande di $g$ allora $f$, oltre un certo punto $n_{0}$, supererà sempre il _rate di crescita_ di $g$:
![[omega-grande.png]]

## Referenze