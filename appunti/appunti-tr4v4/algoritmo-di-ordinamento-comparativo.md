---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 10-03-2024 18:59:02
links:
  - "[[lecture-05032024111158|Lecture 05032024111158]]"
---
# Algoritmo di ordinamento comparativo
---
## Introduzione
> Si classificano in **[[algoritmo-di-ordinamento|algoritmi di ordinamento]] comparativi** quegli algoritmi di ordinamento che utilizzano il _confronto per determinare l'ordinamento_.

## Categorie
A loro volta questi algoritmi si suddividono in:
- [[algoritmo-di-ordinamento-incrementale|incrementali]]
- [[algoritmo-di-ordinamento-divide-et-impera|divide et impera]]

## Limite
Guardando alle [[complessita-computazionale|complessità computazionali]] di questi algoritmi _ci si chiede se ne esistano altri con prestazioni migliori di $O(n \log{n})$_. Per rispondere possiamo andare a descrivere il comportamento di un generico algoritmo comparativo attraverso un [[albero-di-decisione|albero di decisione]], ovvero un [[albero-binario|albero binario]] in cui:
- ogni nodo rappresenta un confronto;
- un percorso radice-foglia rappresenta un'esecuzione dell'algoritmo, che termina in un array ordinato;
- l'altezza dell'albero corrisponde al numero di confronti nel caso pessimo, mentre l'altezza media è il numero di confronti nel caso medio;

Il numero di foglie di quest'albero è sempre $\geq n!$ (ovvero il numero possibile di [[permutazione|permutazioni]]) degli indici di un array[^1]: non è $= n!$ perché _alcuni algoritmi potrebbero scegliere percorsi diversi per arrivare alla stessa permutazione_.

Per esempio si osservi il seguente albero decisionale di un'esecuzione dell'[[insertion-sort|insertion sort]]:
![[albero-decisionale-insertion-sort.png]]

### Teorema
Dalle caratteristiche sopra elencate si ricava il seguente teorema:
> Sia $T_{k}$ un albero binario con $k$ foglie in cui ogni nodo interno ha esattamente due figli, e sia $h(T_{k})$ l'altezza di $T_{k}$, allora si ha
> $$h(T_{k}) \geq \log_{2}{k}$$

#### Dimostrazione
Si dimostra per [[induzione-strutturale|induzione]].

##### Caso base
Si ha un albero con la sola radice, per cui $h(T_{1})=0 \geq 0=\log_{2}{1}$.

##### Caso induttivo
Siano $T_{k_{1}}$ e $T_{k_{2}}$ i sottoalberi di $T_{k}$ t.c. $k = k_{1} + k_{2}$, per ipotesi induttiva supponiamo $h(T_{k_{1}}) \geq \log_{2}{k_{1}}$ e che $h(T_{k_{2}}) \geq \log_{2}{k_{2}}$. Sapendo che
$$h(T_{k}) = 1 + \max(h(T_{k_{1}}), h(T_{k_{2}}))$$
posso supporre che l'albero di sinistra $T_{k_{1}}$ sia più alto di quello di destra ($k_{1} \geq k_{2}$), per cui
$$h(T_{k}) = 1 + h(T_{k_{1}})$$
Ora per la 1° ipotesi induttiva posso scrivere
$$h(T_{k}) \geq 1 + \log_{2}{k_{1}} = \log_{2}{2} + \log_{2}{k_{1}} = \log_{2}{2k_{1}}$$
per cui sapendo $\log_{2}{2k_{1}} \geq \log_{2}{k_{1} + k_{2}}$ (perché $k = k_{1} + k_{2}$ e $k_{1} \geq k_{2}$), diventa
$$h(T_{k}) \geq \log_{2}{k}$$

**Qed**.

### Limite asintotico
Ripassiamo gli ingredienti:
- sappiamo che il numero di foglie di un albero decisionale di un algoritmo di ordinamento comparativo è sempre $\geq n!$
- l'altezza dell'albero corrisponde al numero di confronti nel caso pessimo
- sappiamo che l'altezza di un albero binario è sempre $\geq \log_{2}{k}$, dove $k$ è il numero delle sue foglie

Ciò che si evince è che un albero decisionale di un algoritmo di ordinamento comparativo avrà sempre un'altezza:
$$h(T_{k}) \geq \log_{2}{n!}$$

In [[notazione-asintotica|notazione asintotica]], possiamo scrivere questo risultato sottoforma di $\Omega$-[[omega-grande|grande]], ovvero un _lower-bound_:
$$\Omega(n \log{n})$$
Questo è il **minimo numero di confronti di un algoritmo di ordinamento comparativo nel caso pessimo**.

<u>Nota bene</u>: di conseguenza si scopre che il [[merge-sort|merge sort]] è un algoritmo di ordinamento comparativo _asintoticamente ottimo_.

## Referenze
[^1]: fare riferimento al [[calcolo-combinatorio|calcolo combinatorio]]