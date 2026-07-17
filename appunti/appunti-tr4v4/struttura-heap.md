---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 28-03-2024 19:02:59
links:
  - "[[lecture-26032024111318|Lecture 26032024111318]]"
---
# Struttura heap
---
## Introduzione
> Un **heap** è una [[struttura-dati|struttura dati]] basata su [[albero|alberi]] che rispetta due proprietà:
> 1. _proprietà topologica_ --> la sua _forma_ dev'essere quella di un _[[albero-quasi-perfetto|albero quasi perfetto]]_;
> 2. _proprietà heap_ --> ogni nodo ha un padre più grande (se _max-heap_), oppure ogni nodo ha un padre più piccolo (se _min-heap_), o equivalentemente `A[parent(i)] >= A[i]` oppure `A[parent(i)] <= A[i]`.

<u>Nota bene</u>: l'heap è più un [[prototipo-vs-implementazione|prototipo che un'implementazione]].

## Implementazioni
- [[array-heap|Array heap]]
- [[heap-sort|Heap sort]]
- [[coda-con-priorita|Coda con priorità]]

## Referenze