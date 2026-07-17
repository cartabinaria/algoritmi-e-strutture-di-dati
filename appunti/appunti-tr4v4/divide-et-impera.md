---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 12-04-2024 14:45:37
links:
  - "[[lecture-09042024125218|Lecture 09042024125218]]"
  - "[[lecture-10042024111751|Lecture 10042024111751]]"
---
# Divide et impera
---
## Introduzione
> Per **divide et impera** si intende una [[tecniche-algoritmiche|tecnica algoritmica]] usata per risolvere in modo semplice problemi computazionali complessi, che consiste nel seguire le 3 seguenti fasi:
> 1. _divide_: dividi il problema in sotto-problemi indipendenti, di dimensioni "minori";
> 2. _impera_: risolvi i sotto-problemi ricorsivamente;
> 3. _combina_: unisci le soluzioni dei sottoproblemi per costruire la soluzione del problema di partenza;
> 
> <u>Nota bene</u>: non esiste un'unica ricetta per implementare [[algoritmo|algoritmi]] di questo tipo;

### Esempi
#### Torri di Hanoi
![[torri-di-hanoi.jpeg]]
Vogliamo spostare la pila di dischi dal 1° piolo al 3°, spostando un solo disco alla volta senza mai impilarne uno più grande sopra uno più piccolo, e utilizzando il 2° piolo come supporto.

Sembra un problema complesso, a prima vista, ma analizzato con un approccio _divide et impera_ l'algoritmo risolutivo viene lungo 6 righe!

Scomponiamo il problema per [[induzione-strutturale|induzione]]:
- _caso base_, $n=1$: abbiamo un solo disco nel 1° piolo --> lo spostiamo sul 3°;
- _caso induttivo_, $n > 1$:
	1. come ipotesi induttiva immaginiamo di aver spostato i primi $n-1$ dischi (partendo dall'alto), dal 1° piolo al 2°;
	2. prendiamo ora l'elemento rimasto del 1° piolo e lo mettiamo nel 3°;
	3. quindi reinseriamo gli $n-1$ dischi del 2° piolo sul 3°;

L'algoritmo che risolve quindi il problema delle torri di Hanoi è il seguente:
```cpp
void hanoi(Stack p1, Stack p2, Stack p3, int n) {
	if (n == 1)
		p3.push(p1.pop())
	else {
		hanoi(p1, p3, p2, n-1)
		p3.push(p1.pop())
		hanoi(p2, p1, p3, n-1)
	}
}
```

Analizziamo il [[complessita-computazionale|costo computazionale]] dell'algoritmo attraverso la sua [[equazione-di-ricorrenza|equazione di ricorrenza]]:
$$T(n) = \begin{cases} 1 & n = 1 \\ 2T(n-1) + 1 & n > 1 \end{cases}$$

Non possiamo applicare il [[master-theorem|master theorem]], per cui usiamo il [[metodo-dell-iterazione|metodo dell'iterazione]]:
$$\begin{align} T(n) & = 2T(n-1)+1 \\ & = 2(2T(n-1)+1)+1 = 4T(n-1)+3 \\ & = \cdots \\ & = 2^{i}T(n-i) + 2i-1 \end{align}$$
il che significa che l'algoritmo termina quando $n-i = 1 \iff i=n-1$, da cui otteniamo che alla fine il costo è
$$T(n) = 2^{n-1}+2(n-1)-1 = O(2^{n})$$
esponenziale.

<u>Attenzione</u>: si dimostra che non è possibile applicare un numero di mosse minori di questo.

#### Moltiplicazione di interi
Non solo l'approccio _divide et impera_ aiuta a risolvere problemi complessi con semplicità, ma **a volte consente di ridurre il costo computazionale di algoritmi standard**. Per esempio, la moltiplicazione in colonna tra due interi richiederebbe di norma $n^{2}$ operazioni[^1]:
![[moltiplicazione-in-colonna.png]]

L'idea allora è di provare a risolvere il problema mediante una divisione dei numeri da moltiplicare. Per farlo consideriamo due generici interi $X$ e $Y$ in questo modo:
$$\begin{align} X = \sum\limits_{i=0}^{n-1} x_{i} \cdot 10^{i} \\ Y = \sum\limits_{i=0}^{n-1} y_{i} \cdot 10^{i} \end{align}$$
e considerando $X_{1}, Y_{1}$ come la prima metà rispettivamente di $X, Y$, e $X_{0}, Y_{0}$ come la loro seconda metà, possiamo riscrivere i due interi come
$$\begin{align} X = X_{1} \cdot 10^{\frac{n}{2}} + X_{0} \\ Y = Y_{1} \cdot 10^{\frac{n}{2}} + Y_{0} \end{align}$$

tale per cui il loro prodotto risulta essere
$$X \cdot Y = \left(X_{1} \cdot 10^{\frac{n}{2}} + X_{0}\right) \cdot \left(Y_{1} \cdot 10^{\frac{n}{2}} + Y_{0}\right) = (X_{1} \cdot Y_{1}) \cdot 10^{n} + (X_{1} \cdot Y_{0} + X_{0} \cdot Y_{1}) \cdot 10^{\frac{n}{2}} + X_{0} \cdot Y_{0}$$

Questo modello di moltiplicazione si basa proprio su un approccio divide et impera: infatti $X \cdot Y$ richiede di calcolare $X_{1} \cdot Y_{1}$, $X_{1} \cdot Y_{0}$, $X_{0} \cdot Y_{1}$ e $X_{0} \cdot Y_{0}$, ovvero delle sotto-moltiplicazioni di interi.

Analizzando il costo mediante la seguente equazione di ricorrenza, però, ci accorgiamo che il costo è proprio $O(n^{2})$:
$$T(n) = \begin{cases} c_{1} & n \leq 1 \\ 4T\left(\frac{n}{2}\right) + c_{2}n & n > 1 \end{cases}$$

In breve _non abbiamo migliorato in alcun modo le prestazioni dell'algoritmo_.

Per ottenere un miglioramento possiamo pensare di riscrivere
$$(X_{1} \cdot Y_{1}) \cdot 10^{n} + (X_{1} \cdot Y_{0} + X_{0} \cdot Y_{1}) \cdot 10^{\frac{n}{2}} + X_{0} \cdot Y_{0}$$
in modo tale da dover svolgere solo 3 moltiplicazioni al posto di 4. E' possibile farlo considerando le 3 seguenti moltiplicazioni:
$$\begin{align} P_{1} = (X_{1}+X_{0}) \cdot (Y_{1}+Y_{0}) \\ P_{2}=X_{1}\cdot Y_{1} \\ P_{3}=X_{0} \cdot Y_{0} \end{align}$$
e riscrivendo il prodotto $X \cdot Y$ come
$$X \cdot Y = P_{2} \cdot 10^{n} + (P_{1}-P_{2}-P_{3}) \cdot 10^{\frac{n}{2}} + P_{3}$$

Così facendo l'equazione di ricorrenza diviene
$$T(n) = \begin{cases} c_{1} & n \leq 1 \\ 3T\left(\frac{n}{2}\right) + c_{2}n & n > 1 \end{cases}$$
producendo così un costo di
$$O(n^{\log_{2}{3}}) \approx O(n^{1.59})$$

## Implementazioni
Algoritmi che usano questo approccio sono per esempio:
- [[ricerca-dicotomica|ricerca binaria]]
- [[quick-sort|quick sort]]
- [[merge-sort|merge sort]]

<u>Nota bene</u>: [[ricorsione-strutturale|ricorsione strutturale]] e in generale [[ricorsione|ricorsione]] sono alla base dell'implementazione di algoritmi di questo tipo.

## Referenze
[^1]: assumendo che i due interi abbiano entrambi $n$ cifre