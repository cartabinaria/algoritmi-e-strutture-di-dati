---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 22-02-2024 20:09:47
links:
  - "[[lecture-21022024111657|Lecture 21022024111657]]"
  - "[[lecture-22022024091903|Lecture 22022024091903]]"
  - "[[lecture-26022024091150|Lecture 26022024091150]]"
  - "[[lecture-27022024111544|Lecture 27022024111544]]"
---
# Complessità computazionale
---
## Introduzione
> La **complessità computazionale** per un [[algoritmo|algoritmo]] $A$ è (in [[notazione-asintotica|notazione asintotica]]) [[o-grande|O-grande]] di $f$, ovvero $O(f(n))$, rispetto a una _certa risorsa di calcolo_ se _la quantità di risorse necessaria (tempo/spazio) per eseguire $A$ su un qualsiasi input di dimensione $n$ è $O(f(n))$_.
> Invece, la **complessità computazionale** per un **problema** $P$ è $O(f(n))$ rispetto a una certa risorsa di calcolo se esiste un algoritmo che risolve $P$ con costo compiutazionale $O(f(n))$ rispetto a tale risorsa di calcolo.

## Funzionamento
Quando si analizza un algoritmo, gli si assegna una complessità compiutazionale, in notazione asintotica, su 3 casi: _caso ottimo_, _caso pessimo_, _caso medio_. Per ognuno di questi si cerca di trovare, ovviamente, $\Theta(g(n))$... essendo molto complesso, spesso ci si riconduce sempre a _lower_ e _upper bounds_, ovvero a $\Omega(g(n))$ e soprattutto a $O(g(n))$.

I casi quindi sono:
- **caso ottimo**: si studia il comportamento dell'algoritmo quando l'input è ottimale --> _poco interessante_;
- **caso pessimo**: si studia il comportamento dell'algoritmo quando l'input è pessimo --> _quasi unicamente si fa riferimento ad esso_;
- **caso medio**: si studia il comportamento dell'algoritmo nella media --> complicato da analizzare, ci vogliono grosse _manipolazioni [[algebra-astratta|algebriche]]_;

<u>Ricorda</u>: solitamente _si privilegia la notazione $O$-grande_, scartando $\Omega$ e $\Theta$.

<u>Attenzione</u>: spesso si fa confusione nella condizione del caso ottimo. Se per esempio la _dimensione dell'input $n$ è pari a 0 si può pensare che questo sia il caso ottimo e che quindi il tale algoritmo in questione abbia costo costante ($O(1)$), ma così non è_! Di fatto il caso ottimo non è formulato sulla dimensione dell'input ma su una condizione di un input generico $n$: in poche parole **il caso ottimo deve valere per ogni dimensione $n$, e non deve dipendere dalla suddetta**.

### Esempi
#### Ricerca sequenziale
![[ricerca-lineare.png]]

##### Caso ottimo
$$O(1)$$
Il valore ricercato è nella prima posizione dell'[[array|array]] (il numero di operazioni è 3, quindi costante).

##### Caso pessimo
$$\Theta(n)$$
Il valore ricercato è nell'ultima posizione o non è presente nell'array (in entrambi i casi $2n + 1$ operazioni, quindi proporzionale linearmente ad $n$);

##### Caso medio
Questo è più complesso da calcolare. Sappiamo che per ogni cella, _compresa una in più per il caso in cui il valore ricercato non c'è_, la probabilità che essa sia quella giusta è $$\frac{1}{n+1}$$
detta **probabilità uniforme**.
Ora, il **costo compiutazionale** per arrivare a ogni cella è lineare: 1 passi per la prima; 2 passi per la seconda; 3 passi per la terza, e così via. Quindi _facciamo la somma di ogni numeri di passi per la probabilità che avvenga_, in questo modo:
$$\frac{1}{n+1} + \frac{2}{n+1} + \frac{3}{n+1} + ... + \frac{n+1}{n+1}$$
ovvero la [[formula-di-gauss|formula di Gauss]] dei numeri da $1$ a $n+1$ diviso $n+1$. Otteniamo così
$$\frac{n+2}{2}$$
ergo una complessità compiutazionale di $\Theta(n)$, che indichiamo però più generalmente con
$$O(n)$$

#### Ricerca binaria
Proviamo ora ad analizzare la complessità compiutazionale della [[ricerca-dicotomica|ricerca binaria]], ricordando che _l'array in input dev'essere ordinato_.
![[ricerca-binaria.png]]

##### Caso ottimo
Nel caso ottimale l'elemento ricercato si trova esattamente in mezzo all'array, ed è quindi quello prima visitato dall'algoritmo. Il tempo, a prescindere dalla dimensione di $n$, è costante, perciò
$$O(1)$$

##### Caso pessimo
Nel caso pessimo l'elemento ricercato si può trovare agli estremi dell'array o addirittura non esserci. In quest'ultimo, pessimissimo, caso, l'algoritmo si ferma perché eventualmente $i > j$: gli indici si "superano". Questo avviene solo se il numero di divisioni in cui è stato suddiviso l'array lungo $n$ ha superato $n$ stesso. Se sappiamo che l'algoritmo ad ogni iterazione va a dividere $n$ a metà, allora il limite oltre il quale non è più possibile dividere $n$ è quando
$$\frac{n}{2^{i-1}} < 1$$
ovvero, appunto, quando il numero di divisioni dell'array ha superato il numero di elementi dello stesso.
Risolvendo per $i$ si ha
$$i > \log_{2}{n} + 1$$
Sappiamo allora, matematicamente, che l'algoritmo si ferma, nel caso pessimo, quando il numero di iterazioni ha superato $\log_{2}{n} + 1$: _il costo è allora logaritmico_, e sarebbe $\Theta(\log{n})$ ma noi lo indichiamo con
$$O(\log{n})$$

##### Caso medio
Il caso medio è, ancora una volta, il più complesso da analizzare. Guardiamo allora la seguente immagine per ricavare una formula utile:
![[passi-ricerca-binaria.png]]
Abbiamo: 1 cella $\cdot$ 1 passo; 2 celle $\cdot$ 2 passi; 4 celle $\cdot$ 3 passi; 8 celle $\cdot$ 4 passi. Il tutto diviso per il numero di celle effettive. La formula che si ricava è allora
$$\frac{1}{n} \sum\limits_{i=1}^{\log_{2}{n}}2^{i-1} \cdot i$$

E' una notazione pesante, non facilmente sviluppabile per conoscere il comportamento asintotico esatto dell'algoritmo. Ma, attraverso la seguente approssimazione, possiamo trovare un _upper-bound_:
$$\frac{1}{n} \sum\limits_{i=1}^{\log_{2}{n}}2^{i-1} \cdot i \leq \frac{1}{n} \sum\limits_{i=1}^{\log_{2}{n}} 2^{i} \cdot \log_{2}{n} = \frac{\log_{2}{n}}{n} \sum\limits_{i=1}^{\log_{2}{n}}2^{i} = \frac{\log_{2}{n}}{n} \cdot \frac{2^{\log_{2}{n}+1} - 2}{2-1} = O(\log{n})$$

Troviamo insomma che la complessità compiutazionale della ricerca binaria nel caso medio è
$$O(\log{n})$$

#### Ricerca valore minimo
Infine analizziamo la complessità compiutazionale dell'algoritmo che trova l'indice dell'elemento più piccolo all'interno di un array di $n$ elementi:
![[ricerca-valore-minimo.png]]

##### Caso ottimo
Nel caso ottimo abbiamo un'array crescente, il numero più piccolo è il primo elemento, e non si entra mai nell'`if`. L'algoritmo compie ad ogni modo $n$ operazioni, ottenendo una complessità di $\Theta(n)$, scritta comunque come
$$O(n)$$

##### Caso pessimo
Nel caso pessimo l'array è invece decrescente, il numero più piccolo è in fondo, e così si entra sempre nell'`if`. L'algoritmo compie così $2n$ operazioni (una in più per l'`if`), ottenendo una complessità sempre di $\Theta(n)$ scritta come
$$O(n)$$

##### Caso medio
Il caso medio è la via di mezzo tra il caso ottimo e quello pessimo, che combaciando "schiacciano"[^1] il caso medio in
$$O(n)$$

##### Riflessione
Non c'è distinzione tra caso ottimo, pessimo e medio, perché ad ogni modo _il ciclo `for` dipende linearmente da $n$_. Ricordiamo infatti che analizzando il comportamento asintotico non ci importa se si entra nell'`if` o meno.

In definitiva diremo che l'algoritmo ha in generale un **costo lineare** (che potremmo indicare con $\Theta(n)$).

## Casi di studio
Per analizzare la complessità computazionale di un algoritmo [[ricorsione|ricorsivo]], le tecniche finora studiate non sono sufficienti. Quello che si fa è di studiare, attraverso specifiche tecniche, le [[equazione-di-ricorrenza|equazioni di ricorrenza]] associate a tali algoritmi.

## Referenze
- [[analisi-ammortizzata|Analisi ammortizzata]]

[^1]: un po' come il [[teorema-del-confronto|teorema del confronto]]