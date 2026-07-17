---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 24-03-2024 15:54:33
links:
  - "[[lecture-19032024112453|Lecture 19032024112453]]"
---
# Albero di Fibonacci
---
## Introduzione
> L'**albero di Fibonacci** è un [[albero-binario|albero binario]] che è costruito [[ricorsione|ricorsivamente]] in modo da essere [[albero-bilanciato|bilanciato]] con il minor numero di nodi possibile, e quindi intrinsecamente l'albero sbilanciato più sbilanciato possibile[^1]. Si ha che ogni nodo $u$ non foglia ha [[fattore-di-bilanciamento|fattore di bilanciamento]] $|\beta(u)| = 1$.

![[albero-di-fibonacci.png]]

Si ha allora che il numero di nodi $n_{h}$ di un albero di Fibonacci di altezza $h$ è definito ricorsivamente da
$$n_{h} = n_{h-2}+n_{h-1}+1$$

## Teoremi
### Numero di nodi
> Il numero di nodi di un albero di Fibonacci di altezza $h$ è uguale a
> $$n_{h} = F_{h+3} - 1$$
> dove $F_{h+3}$ è il $h+3$-esimo numero di Fibonacci.

#### Dimostrazione
Dimostriamo [[induzione-strutturale|per induzione]], per cui analizziamo caso base e caso induttivo.

##### Caso base
Verifichiamo che un albero di Fibonacci di altezza pari a 0 ha 1 nodo. Abbiamo
$$F_{h+3} - 1 = F_{3} - 1 = 2 - 1 = 1$$
E ora che un albero di Fibonacci di altezza 1 ha 2 nodi, per cui
$$F_{h+3}-1 = F_{4}-1 = 3-1 = 2$$

##### Caso induttivo
Ora avendo un'altezza $h$ e sapendo che vale $n_{h-2} = F_{h+1}-1$ e $n_{h-1} = F_{h+2}-1$, dimostro
$$n_{h} = F_{h+3}-1$$
Sappiamo per costruzione dell'albero di Fibonacci che
$$n_{h} = n_{h-2} + n_{h-1} + 1$$

allora, per le ipotesi induttive ottengo
$$n_{h} = F_{h+1}-1 + F_{h+2}-1 + 1 = F_{h+3} - 1$$

**Qed**.

## Altezza
Lo studio dell'altezza (massima) dell'albero di Fibonacci si fonda sul precedente teorema. Infatti se $n_{h} = F_{h+3}-1$ e $F_{h} = \Theta(\phi^{h})$[^2], allora otteniamo che
$$n_{h} = \Theta(\phi^{h})$$
o equivalentemente, applicando $\log_{\phi}$ ad ambo i membri,
$$h = \Theta(\log{n})$$

## Referenze
[^1]: un [[insieme-minimale|minimale]] rispetto alla proprietà del bilanciamento (_borderline_ diciamo)
[^2]: formula nota