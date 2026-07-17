---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 29-02-2024 15:54:04
links:
  - "[[lecture-27022024111544|Lecture 27022024111544]]"
---
# Metodo dell'iterazione
---
## Introduzione
> Il **metodo dell'iterazione** è un _approccio [[attacco-bruteforce|brute force]]_ utilizzato per risolvere [[equazione-di-ricorrenza|equazioni di ricorrenza]], che consiste nel _sostituire iterativamente la parte [[ricorsione|ricorsiva]] nell'equazione finché non appare uno schema ricorsivo legato al passo di iterazione_.

### Esempio
Preso in considerazione l'equazione
$$T(n) = \begin{cases} 1 & n = 1 \\ T\left(\frac{n}{2}\right)+ 1 & n > 1 \end{cases}$$
possiamo reiterare l'uguaglianza
$$T(n) = T\left(\frac{n}{2}\right) + 1$$
fino a che non vediamo un pattern. Nella fattispecie:
$$\begin{align} T(n) & = T\left(\frac{n}{2}\right) + 1 \\ & = T\left(\frac{n}{4}\right) + 1 + 1 \\ & = T\left(\frac{n}{8}\right) + 1 + 1 + 1 \\ & = \cdots \\ & = T\left(\frac{n}{2^{i}}\right) + i \end{align}$$

Quella ricavata è la _formula che ci dice quante operazioni vengono svolte all'$i$-esima chiamata ricorsiva_. Non ci rimane che capire fino a che valore può arrivare $i$, ovvero quando si arriva al caso base.
Per la definizione di $T(n)$ il caso base appare quando $n = 1$, ovvero quando
$$\frac{n}{2^{i}} = 1 \implies i = \log_{2}{n}$$
Abbiamo scoperto che l'algoritmo termina alla $\log_{2}{n}$-esima iterazione, per cui si arriverà al caso base con
$$T\left(\frac{n}{2^{\log_{2}{n}}}\right) + \log_{2}{n} = T(1) + \log_{2}{n} = 1 + \log_{2}{n}$$
operazioni eseguite. Di conseguenza la complessità computazionale dell'algoritmo sarà
$$\Theta(\log{n})$$

## Referenze
- [[sommatorie-notevoli|Sommatorie notevoli]]