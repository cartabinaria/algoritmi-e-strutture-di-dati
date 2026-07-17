---
tags:
  - category/note
  - status/finished
  - topic/programmazione
  - topic/algoritmi-e-strutture-dati
date: 30-11-2023 17:46:29
links:
  - "[[lecture-28112023101904|Lecture 28112023101904]]"
  - "[[lecture-14032024091535|Lecture 14032024091535]]"
  - "[[lecture-18032024091043|Lecture 18032024091043]]"
---
# Albero
---
## Introduzione
> Un **albero** in informatica è una [[struttura-dati|struttura dati]] (in particolare [[strutture-dati-dinamiche|dinamica]]) che si presenta come una _collezione di nodi e archi_, dove:
> - ogni _nodo_ contiene un valore e, eccetto la _radice_, ha un solo predecessori e 0 (_foglia_) o più successori;
> - ogni _arco_ unisce un _nodo padre_ a un _nodo figlio_.
> 
> <u>Attenzione</u>: si ha _un unico cammino dalla radice a ogni altro nodo_, ed è questo a contraddistinguere gli alberi dai [[grafo|grafi]].

![[albero-informatico.png|500]]

Si definisce _profondità di un nodo_ la sua distanza dalla radice.

## Tipologie
Esistono differenti tipologie di alberi, tra cui:
- [[albero-binario|alberi binari]]
- [[albero-binario-di-ricerca|alberi binari di ricerca]]
- [[albero-non-binario|alberi non-binari]]
- [[albero-bilanciato|alberi bilanciati]]

### Topologie
- [[albero-quasi-perfetto|alberi quasi perfetti]]

## Osservazione
Se ci viene chiesto di implementare un [[algoritmo|algoritmo]] su alberi, binari o non-binari che siano, se l'algoritmo richiesto è [[ricorsione|ricorsivo]] il suggerimento è di partire dalla base delle visite [[dfs|DFS]] (solitamente post-ordine); se invece l'algoritmo richiesto è iterativo, si suggerisce di partire dalla base delle visite [[bfs|BFS]] (ovvero usando una [[coda|coda]]).

## Referenze