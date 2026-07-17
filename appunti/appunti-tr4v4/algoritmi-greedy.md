---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 13-04-2024 13:16:34
links:
  - "[[lecture-10042024111751|Lecture 10042024111751]]"
  - "[[lecture-15042024091754|Lecture 15042024091754]]"
---
# Algoritmi greedy
---
## Introduzione
> Nell'ambito dei _problemi di ottimizzazione_, per **algoritmi greedy** si intende una [[tecniche-algoritmiche|tecnica algoritmica]] che si applica quando è possibile dimostrare l'esistenza di una _scelta ingorda_, ovvero _che porta sicuramente alla soluzione ottima_. Se dimostrata infatti la _proprietà di scelta greedy_, sappiamo che _la scelta localmente ottima porta sicuramente alla strada globalmente ottima_.
> <u>Nota bene</u>: non tutti i problemi sono dotati di tale scelta.

### Esempi
#### Problema del resto
Si prenda in esame il _problema del resto_, che consiste nel trovare la quantità minima di monete che coincide con il resto, come esempio di applicazione di un algoritmo greedy.

Ci vengono dati i tagli del sistema monetario adottato (es. 50c, 20c, 5c, 2c, 1c), e un resto $R$ da raggiungere con il minor numero possibile di monete. L'approccio greedy in questo caso consiste allora nel **prendere sempre la moneta dal taglio più grande da sottrarre al resto, finché il resto non diventa $0$**.

Ovvero _scegliamo sempre la strada localmente migliore, e questo ci assicura che la soluzione finale sarà la strada globalmente migliore_!

L'algoritmo che implementa questa soluzione è il seguente:
```R
RestoGreedy(integer R, integer T[1..n]) -> integer {
	ordina-decrescente(T);
	integer nm = 0;
	integer i = 1;
	while (R > 0 and i <= n) {
		if (R >= T[i]) {
			R -= T[i]
			nm++;
		} else
			i++;
	}
	if (R > 0)
		# errore: resto non erogabile
		return -1;
	else
		return nm;
}
```

<u>Nota bene</u>: questo algoritmo restituisce solo il numero minimo di monete, senza dirci quali... Per sapere anche questo _basta salvarsi in una struttura ausiliaria `T[i]` ogni volta che si entra nell'`if` del ciclo_.

##### Limiti
L'approccio greedy in questione funziona solo con **sistemi monetari canonici**! Ovvero con _sistemi monetari cui tagli consentono a questo algoritmo di fornire la soluzione ottima_.
Infatti ci sono casi in cui questo algoritmo fallisce:
- $R = 6, \ T = [4, 3, 1]$ ---> greedy: 4+1+1, ottimo: 3+3;
- $R = 6, \ T = [5, 2]$ ---> greedy: 5+errore, ottimo: 2+2+2;

#### Problema dello scheduling
Nei [[sistema-operativo|sistemi operativi]] è piuttosto comune il problema dello _scheduling dei processi_. Un algoritmo possibile per decidere secondo quale criterio far eseguire i processi è lo [[sjf|SJF]]. Questo algoritmo utilizza proprio un'**approccio greedy per poter minimizzare il tempo medio di attesa dei processi**.

#### Problema della compressione
Uno dei problemi più interessanti dell'informatica consiste in quello che studia come codificare i dati _analogici_ in _digitale_, sfruttando il minor numero possibile di _bit_. Abbiamo già studiato come [[rappresentazione-dell-informazione|rappresentare generalmente l'informazione]], e in particolare come [[codifica-dei-caratteri|rappresentare sequenze di caratteri]]. Proprio in quest'ambito esiste una codifica in grado di farlo in modo molto efficiente, usando un approccio greedy: la [[codifica-di-huffman|codifica di Huffman]].

## Resoconto
Gli algoritmi greedy, quindi, hanno vantaggi e svantaggi:
- _vantaggi_
	- semplici da programmare
	- solitamente efficienti
	- in alcuni casi[^1] danno la soluzione ottima
- _svantaggi_
	- non tutti i problemi ammettono soluzione greedy
	- in certi casi non possono essere usati se si vuole la soluzione ottima

## Referenze
[^1]: quando è possibile dimostrare la _proprietà di scelta greedy_