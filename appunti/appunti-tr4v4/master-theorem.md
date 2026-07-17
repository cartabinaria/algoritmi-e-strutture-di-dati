---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 29-02-2024 16:09:49
links:
  - "[[lecture-27022024111544|Lecture 27022024111544]]"
---
# Master Theorem
---
## Introduzione
> Il **Master Theorem** è un teorema che permette di risolvere istantaneamente tutte le [[equazione-di-ricorrenza|equazioni di ricorrenza]] della forma
> $$T(n) = aT\left(\frac{n}{b}\right) + f(n)$$
> dove:
> - $a \geq 1$, $b \geq 1$ _costanti_;
> - $f(n)$ _asintoticamente positiva_ ([[funzione-di-costo|funzione di costo]]);

Ufficialmente il teorema è complesso, e i 3 casi risolutivi in cui sfocia sono difficili da verificare. Per questo motivo useremo una sua _versione semplificata_:
> Il **Master Theorem semplificato** è una versione del Master Theorem che permette di risolvere solo le equazioni di ricorrenza del tipo
> $$T(n) = \begin{cases} d & n = 1 \\ aT\left(\frac{n}{b}\right) + cn^{\beta} & n > 1 \end{cases}$$
> per cui $\alpha = \log_{b}(a)$. Vale quindi che
> - $\alpha > \beta \implies T(n) = \Theta(n^{\alpha})$
> - $\alpha = \beta \implies T(n) = \Theta(n^{\alpha} \log{n})$
> - $\alpha < \beta \implies T(n) = \Theta(n^{\beta})$

### Esempio
Prendiamo in caso l'algoritmo di [[ricerca-dicotomica|ricerca binaria]] ricorsivo
![[algoritmo-ricerca-binaria-ricorsivo.png]]

che ha seguente equazione di ricorrenza
$$T(n) = \begin{cases} 1 & n = 0 \\ T\left(\frac{n}{2}\right) + 1 & n > 0 \end{cases}$$
e calcoliamo il valore $\alpha = \log_{2}{1} = 0$. Avendo $\beta = 0$ siamo nel caso $\alpha = \beta$, per cui
$$T(n) = \Theta(n^{\alpha}\log{n}) = \Theta(n^{0}\log{n}) = \Theta(\log{n})$$

che è di fatto lo stesso risultato dell'algoritmo in [[ricerca-dicotomica-versione-iterativa|versione iterativa]].

<u>Nota bene</u>: si tratta di una tecnica estremamente veloce[^1].

## Referenze
[^1]: almeno se confrontata con il [[metodo-dell-iterazione|metodo dell'iterazione]]