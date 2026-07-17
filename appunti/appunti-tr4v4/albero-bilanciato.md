---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 24-03-2024 15:57:34
links:
  - "[[lecture-19032024112453|Lecture 19032024112453]]"
---
# Albero bilanciato
---
## Introduzione
> Un [[albero-binario|albero binario]] si dice **bilanciato** (o **bilanciato in altezza**) se per ogni nodo $v$ il [[fattore-di-bilanciamento|fattore di bilanciamento]] $\beta(v)$ è compreso tra -1 e 1:
> $$|\beta(v)| \leq 1$$

### Esempi
![[albero-bilanciato.png]]
![[albero-sbilanciato.png]]

## Tipi
Ci sono una serie di alberi autobilancianti che sono state ideate e implementate, tra cui:
- [[albero-avl|Albero AVL]]
- [[b-albero|B-albero]]
- [[albero-2-3|Albero 2-3]]
- [[rb-albero|RB-albero]]

Tutte queste supportano operazioni di inserimento, ricerca e rimozione in [[complessita-computazionale|tempo logaritmico]].

## Referenze