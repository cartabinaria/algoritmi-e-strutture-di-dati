---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 22-04-2024 15:51:39
links:
  - "[[lecture-18042024093835|Lecture 18042024093835]]"
---
# Seam carving
---
## Introduzione
Per ridimensionare un'immagine ci sono vari modi:
1. **scaling** --> schiacciare lungo un certo asse l'immagine;
2. **cropping** --> tagliamo i bordi dell'immagine per ottenere la dimensione giusta;
3. **seam carving** --> si ottiene con un algoritmo di [[programmazione-dinamica|programmazione dinamica]];

Nel primo caso il _risultato è stretchato_; nel secondo si _perde dell'informazione_; nel terzo si ha il _risultato fondamentalmente migliore_.

## Definizione
> Il **seam carving** è una _tecnica per ridimensionare le immagini che consiste nell'eliminare delle strisce_ (in gergo "_cuciture_") _contigue di pixel fino a che non si ottiene la grandezza interessata_.

Se per esempio vogliamo ridurre l'immagine di 100 pixel sulla lunghezza ci basta trovare 100 cuciture ed eliminarle.

## Algoritmo
Prima di tutto si deve assegnare un peso, detto _energia_, $E[i, j] \in [0, 1]$ ad ogni pixel salvati in una matrice $E$. Quindi, l'algoritmo segue i seguenti passi:
1. _determiniamo una cucitura verticale di energia complessiva minima_;
2. _rimuoviamo tale cucitura ottenendo un'immagine $M \times (N-1)$_ (se verticale) _o $(M-1) \times N$_ (se orizzontale);
3. _ripetiamo il procedimento fino a ottenere la dimensione desiderata_.

Usiamo quindi una matrice di supporto $W$ per mantenere i pesi complessivi calcolati dall'algoritmo. Il riempimento di $W$ segue allora il seguente criterio induttivo:
- _caso base $i = 1$_ --> ho una sola riga di pixel, quindi il peso complessivo di ogni cella nella riga $1$ è semplicemente il peso di ogni cella nella riga $1$ (ovvio)
	- $W[1, j] = E[1, j]$
- _caso induttivo $i > 1$_ --> alla riga $i$-esima posso ricavare il peso minore del percorso fino alla $j$-esima cella sfruttando le 3 celle superiori (2 se si è ai bordi), di fatto scelgo tra queste quella con peso complessivo minore e la sommo al peso della cella $i, j$
	- $j = 1$ ---> $W[i, j] = E[i, j] + \min(W[i-1, j], W[i-1, j+1])$
	- $1 < j < N$ ---> $W[i, j] = E[i, j] + \min(W[i-1, j-1], W[i-1, j], W[i-1, j+1])$
	- $j = N$ ---> $W[i, j] = E[i, j] + \min(W[i-1, j-1], W[i-1, j])$

Il **peso della cucitura minima sarà il valore minimo dell'ultima riga di $W$**.

Essendo in programmazione dinamica, **non rimane che ricostruire tale cucitura partendo proprio dall'ultima cella e andando a ritroso**. Possiamo farlo in due modi:
- capendo per ogni cella da quale delle 3 proviene togliendo a $W[i, j]$ il valore $E[i, j]$;
- salvandosi, durante la compilazione di $W$, in un'ulteriore struttura ausiliaria per ogni cella la derivazione della cella superiore, ovvero se viene da `NO`, `N`, o `NE`.

## Referenze