---
tags:
  - category/note
  - status/finished
  - topic/programmazione
  - topic/algoritmi-e-strutture-dati
date: 25-10-2023 14:09:17
links:
  - "[[lecture-24102023100626|Lecture 24102023100626]]"
  - "[[lecture-22112023092107|Lecture 22112023092107]]"
  - "[[lecture-04032024091423|Lecture 04032024091423]]"
---
# Algoritmo di ordinamento
---
## Introduzione
Un problema tipico della programmazione consiste nel trovare una [[permutazione|permutazione]] di un [[array|array]] in modo che i numeri siano ordinati in ordine crescente (o decrescente).
In matematica cerchiamo una permutazione
$$p: \{1, \cdots, n\} \to \{1, \cdots, n\}$$
degli _indici_
$$[a_{p(1)}, \cdots, a_{p(n)}]$$
t.c.
$$a_{p(1)} \leq a_{p(2)} \leq ... \leq a_{p(n)}$$

Questo processo, chiamato _ordinamento_, viene in fatto in funzione di altri algoritmi che beneficiano di ciò[^1]

Esistono moltissimi [[algoritmo|algoritmi]] (più di una cinquantina) che risolvono questo problema che si differenziano per efficienza e velocità: in poche parole in [[complessita-computazionale|complessità compiutazionale]].

<u>Nota bene</u>: il motivo per cui si studiano una varietà di algoritmi e non ci si concentra su quello migliore è perché _l'algoritmo migliore non esiste_. Di fatto non è possibile individuare a priori un algoritmo che avrà sempre le performance migliori: dipende dai singoli casi in cui capita l'array in input.

## Caratteristiche
Prima di addentrarci nel mondo degli algoritmi di ordinamento è bene conoscere alcune nozioni preliminari.

### Chiave e valore
Nonostante nella maggior parte dei casi ciò che si ordina è un array di interi, quindi di numeri che valgono per se stessi, _esistono casi in cui conviene dividere ciò che si ordina in una coppia chiave-valore_. Si ordinano le chiavi, che essendo associate a dei valori comportano l'ordinamento degli stessi.

<u>Attenzione</u>: _chiave $\neq$ indice_. Quello che si ordina, di solito, o quando comunque si fa riferimento a un algoritmo di ordinamento, è un _array di sole chiavi_ (interi, double, ecc...). Potremmo invece avere un _array di chiavi associate a delle stringhe_, per cui ordinando le chiavi si ordinano le stringhe sotto un certo criterio.

### In-place e stabilità
> Un algoritmo di ordinamento si dice **in-place** quando _riordina gli elementi direttamente nell'array di input, senza l'ausilio di un array aggiuntivo per il calcolo_.

> Un algoritmo di ordinamento si dice **stabile** quando dato in input un array di chiave-valore, _valori con la stessa chiave appaiono nell'array ordinato nello stesso ordine in cui appaiono nell'array in input_[^1].

Fondamentalmente un algoritmo stabile, nel caso due o più elementi dell'array siano uguali (abbiano le stesse chiavi), _mantiene il loro ordine di apparizione nell'array in input anche dopo l'ordinamento_. Questa è una _proprietà fondamentale_ degli algoritmi di ordinamento.

#### Osservazione
E' sempre possibile trasformare un algoritmo non stabile in uno stabile, usando come chiave la coppia (_key_, _index_) dove:
- _key_ è la chiave primaria di ordinamento e corrisponde all'effettivo valore della cella;
- _index_ è la chiave secondaria di ordinamento e corrisponde alla posizione del valore nell'array in input;

Per esempio $(10, 2) < (10, 6)$.

## Categorie
Questi algoritmi si dividono in 3 principali categorie, a _seconda del modo in cui attuano l'operazione di ordinamento_:
- [[algoritmo-di-ordinamento-comparativo|comparativi]]
	- **[[algoritmo-di-ordinamento-incrementale|incrementali]]**
	- **[[algoritmo-di-ordinamento-divide-et-impera|divide et impera]]**
- **[[algoritmo-di-ordinamento-non-comparativo|non-comparativi]]**

## Tabelle riassuntive

|                    | Caso ottimo         | Caso medio          | Caso pessimo        |
| ------------------ | ------------------- | ------------------- | ------------------- |
| [[selection-sort|Selection sort]] | $\Theta(n^{2})$     | $\Theta(n^{2})$     | $\Theta(n^{2})$     |
| [[insertion-sort|Insertion sort]] | $\Theta(n)$         | $\Theta(n^{2})$     | $\Theta(n^{2})$     |
| [[merge-sort|Merge sort]]     | $\Theta(n \log{n})$ | $\Theta(n \log{n})$ | $\Theta(n \log{n})$ |
| [[quick-sort|Quick sort]]     | $\Theta(n \log{n})$ | $\Theta(n \log{n})$ | $\Theta(n^{2})$     |
| [[counting-sort|Counting sort]]  | $\Theta(n + k)$     | $\Theta(n + k)$     | $\Theta(n + k)$     |
| [[radix-sort|Radix sort]]     | $\Theta(d(n + k))$  | $\Theta(d(n + k))$  | $\Theta(d(n + k))$  |

con:
- $n =$ numeri di elementi da ordinare;
- $d =$ numero massime di cifre in una chiave;
- $k =$ ampiezza del range di valori chiave;

|                | In-place | Stabile |
| -------------- | -------- | ------- |
| Selection sort | Sì       | No      |
| Insertion sort | Sì       | Sì      |
| Merge sort     | No       | Sì      |
| Quick sort     | Sì       | No      |
| Counting sort  | No       | Sì      |
| Radix sort     | No       | Sì      |

## Referenze
[^1]: si veda la [[ricerca-dicotomica|ricerca binaria]]
[^2]: è una definizione che ha più senso nel caso degli [[tabella-hash|hashmap]]