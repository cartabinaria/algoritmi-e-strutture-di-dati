---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 15-03-2024 17:26:31
links:
  - "[[lecture-14032024091535|Lecture 14032024091535]]"
---
# Albero non-binario
---
## Introduzione
> Un **albero non-binario** è un tipo di [[albero|albero]] cui ogni nodo può essere una foglia o diramarsi in $n$ figli.

## Implementazione
### 1° metodo
Si può implementare con la seguente [[struttura-dati|struttura dati]]:
- `parent` --> [[puntatore|puntatore]] al nodo padre
- `key`, `data` --> associazione chiave-valore
- `array` di puntatori ai figli`

Non è una soluzione molto usata perché se il numero massimo di figli è molto alto l'[[array|array]] spreca tanta memoria. Allo stesso tempo è limitante.

### 2° metodo
Altrimenti, e di solito si fa così, si implementa nel seguente modo:
- `parent`
- `key`, `data`
- `first`, `next` dove _first_ è il puntatore al primo nodo figlio, mentre _next_ ai nodi fratelli (una [[lista|lista]] concatenata semplice)

## Operazioni
### Visita
#### [[dfs|DFS]]
La visita in profondità è equivalente a quella degli [[albero-binario-dfs|alberi binari]].

#### [[bfs|BFS]]
![[bfs-non-binary-tree.png]]

## Referenze
- [[albero-binario|Albero binario]]