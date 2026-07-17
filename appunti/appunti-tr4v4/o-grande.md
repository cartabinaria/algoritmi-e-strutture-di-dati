---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 20-02-2024 19:03:05
links:
  - "[[lecture-20022024111057|Lecture 20022024111057]]"
  - "[[lecture-21022024111657|Lecture 21022024111657]]"
---
# O-grande
---
## Introduzione
> Data una [[funzione-di-costo|funzione di costo]] $g(n)$ definiamo l'[[insieme|insieme]] delle [[funzione-matematica|funzioni]] per cui $g(n)$ rappresenta un _limite asintotico superiore_ come
> $$O(g(n)) = \{f(n) | \exists c > 0, n_{0} \geq 0 : \forall n \geq n_{0}, f(n) \leq cg(n)\}$$
> dove $O(g(n))$ è l'**O-grande** di $g(n)$. Con abuso di notazione diciamo $f(n) = O(g(n))$ invece che dire $f(n) \in O(g(n))$.

Si dice in breve che $f$ è un $O$-grande di $g$ se oltre un certo valore ($n_{0}$) $f$ non supererà mai il _rate di crescita_ di $g$:
![[o-grande.png|600]]

## Referenze