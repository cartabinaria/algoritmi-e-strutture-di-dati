---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 04-05-2024 19:51:11
links:
  - "[[lecture-30042024111642|Lecture 30042024111642]]"
---
# Ordinamento topologico
---
## Introduzione
> Dato un [[dag|DAG]] $G$, un **ordinamento topologico** su $G$ è un ordinamento lineare dei suoi vertici tale per cui:
> 1. $(u, v) \in E$ $\implies$ $u$ compare prima di $v$ nell'ordinamento $\ \ \forall u, v \in V$;
> 2. per transitività, se $v$ è raggiungibile da $u$, allora $u$ compare prima di $v$ nell'ordinamento.
> 
> Fondamentalmente, _ogni nodo deve venire prima di tutti i nodi ad esso adiacenti_.

<u>Nota bene</u>: l'ordinamento topologico _non è totale_, ossia non è unico per un DAG $G$. Possono esistere diversi ordinamenti topologici di uno stesso DAG, _a seconda del tipo di visita applicata_.
![[ordinamento-topologico.png]]

## Algoritmo
Ordinare topologicamente un DAG è facile se si sfruttano le proprietà della [[dfs-su-grafi|visita DFS]]. Questa infatti, per ogni vertice, fornisce il suo _tempo di terminazione_, ovvero dopo quanti "passi" il nodo viene chiuso e si torna alla visita del nodo padre.
Ora, considerati un vertice $u$ e un vertice $v$ e un arco $(u, v)$, si hanno 2 soli casi[^1]:
- $(u, v)$ è un arco _all'avanti_ --> $v$ è discendente di $u$, per cui $v.ft < u.ft$;
- $(u, v)$ è un _attraversamento a sx_ --> per definizione allora $v.ft < u.dt$ e di conseguenza $v.ft < u.ft$.

Questo ci dice che **presi due vertici di un DAG è sempre possibile sapere quale viene prima e quale dopo in un ipotetico ordinamento topologico guardando semplicemente i tempi di terminazione dei due nodi**: se _$v.ft < u.ft$ allora $u$ viene prima di $v$_, perché vuol dire che _per completare $v$ è prima necessario iniziare $u$_.
Ciò significa che il tempo di terminazione rispetta la relazione di ascendenza/discendenza logica dei vertici, e che quindi **per ordinare topologicamente un DAG basta ordinare i suoi vertici in ordine decrescente rispetto al tempo di terminazione**.

### Implementazione
Nella pratica basta modificare leggermente la DFS: una volta calcolato il tempo di terminazione di un vertice, _pusho_ tale vertice in una [[pila|pila]]. Terminato l'algoritmo mi basta _poppare_ la pila finché non è vuota, e _ottengo esattamente i vertici in ordine topologico_.

## Importanza
Se il DAG in questione rappresenta un grafo cui nodi sono delle attività da compiere e gli archi delle dipendenze logiche tra tali attività, allora l'**ordinamento topologico può essere visto come un modo per eseguire le attività rispettando tali dipendenze**.

In particolare l'ordinamento topologico è alla base di tecniche per l'organizzazione delle task da svolgere per ultimare un progetto aziendale come il [[pert|PERT]] e il [[cpm|CPM]].

## Referenze
[^1]: _sono esclusi gli archi all'indietro perché siamo nel dominio dei DAG, che sono aciclici_