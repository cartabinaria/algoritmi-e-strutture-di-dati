---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 23-04-2024 16:43:09
links:
  - "[[lecture-18042024093835|Lecture 18042024093835]]"
  - "[[lecture-22042024091936|Lecture 22042024091936]]"
---
# Distanza di Levenshtein
---
## Introduzione
> La **distanza di Levenshtein** è il _numero minimo di operazioni elementari_ (nulla, inserimento, rimozione, sostituzione) _necessarie per trasformare una stringa in un'altra_.

Serve in un certo senso a capire quanto simili sono due stringhe, _a quantificare la loro distanza_. Viene infatti usata dai correttori ortografici per suggerire la parola più "vicina" a quella digitata.

## Principio di funzionamento
E' basata sul concetto di _edit distance_, ovvero al numero di operazioni di editing necessarie alla trasformazione della stringa. In particolare le operazioni ammesse sono:
1. `NOPE` - lasciare immutato il carattere corrente --> costo 0
2. `DEL` - cancellare un carattere --> costo 1
3. `INS` - inserire un carattere --> costo 1
4. `SUB` - sostituire il carattere con uno diverso --> costo 1

Il punto sta nel **trovare la quantità minima di trasformazioni che trasformano una parola in un'altra**.

<u>Nota bene</u>: _posso sempre trasformare una parola in un'altra, cancellando e riscrivendo tutto_.

### Esempio
Vogliamo passare da `ALBERO` a `LIBRO`, per cui scorro ogni lettera di `ALBERO` e per ognuna di esse applico una trasformazione:
- cancello `A` -> +1
- mantengo `L` -> +0
- inserisco `I` -> +1
- mantengo `B` -> +0
- rimuovo `E` -> +1

Per cui la distanza tra `ALBERO` e `LIBRO`, con queste trasformazioni, ha costo 3.

## Algoritmo
L'algoritmo che consente di trovare la distanza di Levenshtein di due stringhe $S$ e $T$ è basato sulla [[programmazione-dinamica|programmazione dinamica]]. Quindi definiamo anzitutto il sottoproblema.

Il sottoproblema $P(i, j)$ vuole trasformare un prefisso di $S[1, \cdots, i]$ in un prefisso di $T[1, \cdots, j]$. Ci salviamo in una [[matrice|matrice]] d'appoggio $L[i, j]$ ogni costo della trasformazione del prefisso per $i \in \{0, \cdots, n\}$ e $j \in \{0, \cdots, m\}$.

Risolviamo ora $P(i, j)$ induttivamente:
- _caso base $i = 0 \lor j = 0$_: si vuole trasformare una stringa vuota in una stringa non vuota, quindi ci vorranno rispettivamente $j$ inserimenti (per $i = 0$) e $i$ rimozioni (per $j = 0$)
	- $P(0, j) = j$
	- $P(i, 0) = i$
- _caso induttivo $i > 0 \land j > 0$_: ci sono 3 vie per trasformare $S[1, \cdots, i]$ in $T[1, \cdots, j]$
	1. supponendo di aver trasformato $S[1, \cdots, i-1]$ in $T[1, \cdots, j]$, allora il nuovo $i$-esimo carattere di $S$ dev'essere cancellato;
	2. supponendo di aver trasformato $S[1, \cdots, i]$ in $T[1, \cdots, j-1]$, allora devo aggiungere il $j$-esimo carattere di $T$ in $S$;
	3. supponendo di aver trasformato $S[1, \cdots, i-1]$ in $T[1, \cdots, j-1]$, allora ci sono due casi
		1. se $S[i] = T[j]$ allora non faccio nulla;
		2. se $S[i] \neq T[j]$ sostituisco $S[i]$ con $T[j]$.

L'idea è di _scegliere tra queste 3 vie sempre quella che ha complessivamente costo minore_.

In matematichese la formula generale viene:
$$L[i, j] = \begin{cases}
\max(i, j) & i = 0 \lor j = 0 \\
\min(L[i-1, j] + 1, L[i, j-1]+1, L[i-1, j-1]) & i > 0 \land j > 0 \land S[i] = T[j] \\
\min(L[i-1, j] + 1, L[i, j-1]+1, L[i-1, j-1]+1) & i > 0 \land j > 0 \land S[i] \neq T[j]
\end{cases}$$

A questo punto **la soluzione finale sarà nella cella $L[n, m]$** (in basso a destra).

Non ci rimane, una volta trovata la distanza, capire quali sono eventualmente le trasformazioni che producono questa distanza: l'idea è di andare a ritroso partendo dall'ultima cella scegliendo ad ogni iterazione la cella, tra le 3 adiacenti, con numero minore.

<u>Nota bene</u>: _ci sono più strade che si possono intraprendere_.

## Referenze