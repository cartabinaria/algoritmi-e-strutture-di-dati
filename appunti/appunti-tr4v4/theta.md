---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 21-02-2024 22:47:06
links:
  - "[[lecture-21022024111657|Lecture 21022024111657]]"
---
# Theta
---
## Introduzione
> Data una [[funzione-di-costo|funzione di costo]] $g(n)$ definiamo l'[[insieme|insieme]] delle funzioni _asintoticamente equivalenti_ a $g(n)$ come
> $$\Theta(g(n)) = \{f(n) | \exists c_{1}, c_{2} > 0, n_{0} \geq 0 : \forall n \geq n_{0}, c_{1}g(n) \leq f(n) \leq c_{2}g(n)\}$$
> dove $\Theta(g(n))$ è l'**Theta** di $g(n)$.
> Ovviamente, per un teorema, vale che
> $$f = \Theta(g) \iff f = O(g) \land f = \Omega(g)$$
> ovvero che $f$ è $\Theta(g)$ sse $f$ è [[o-grande|O-grande]] di $g$ e $f$ è [[omega-grande|Omega-grande]] di $g$.

## Referenze