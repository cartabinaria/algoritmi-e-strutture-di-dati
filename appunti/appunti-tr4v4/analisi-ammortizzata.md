---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 28-02-2024 11:23:43
links:
  - "[[lecture-26022024091150|Lecture 26022024091150]]"
---
# Analisi ammortizzata
---
## Introduzione
> Per **analisi ammortizzata**, nello studio della [[complessita-computazionale|complessità compiutazionale]] di un [[algoritmo|algoritmo]], è un _metodo per valutare il costo medio di una sequenza di operazioni_.

Il motivo per cui si utilizza questo metodo piuttosto che il classico previsto per lo studio della complessità (divisione in caso ottimo, pessimo e medio), è perché _per alcuni algoritmi le tecniche standard non sono sufficienti_. Ci sono algoritmi che si comportano in modo molto strano: l'_analisi ammortizzata è un approccio differente in grado di catturare tale stranezza_.

Di fatto per alcuni algoritmi l'_analisi del costo pessimo può essere troppo pessimistica_, e l'_analisi del costo medio necessità di assunzioni probabilistiche difficili da formulare_[^1].

## Costo medio vs. Costo ammortizzato
- il **costo medio** è il valore medio di _una singola operazione_;
- il **costo ammortizzato** è il costo medio di una _sequenza di operazioni_;

Il costo ammortizzato funziona bene con [[struttura-dati|strutture dati]].

## Metodi
- [[metodo-dell-aggregazione|Metodo dell'aggregazione]]
- [[metodo-degli-accantonamenti|Metodo degli accantonamenti]]

### Esempio
Guardiamo l'algoritmo che implementa un contatore binario, definito come segue:
![[algoritmo-contatore-binario.png]]

Si tratta di un algoritmo singolare, perché nei singoli casi ha un comportamento poco prevedibile, o che comunque dipende dal numero salvato in $A$:
- se si vuole passare da 6 ($110$) a 7 ($111$) il costo è 1;
- se si vuole passare da 7 ($111$) a 8 ($1000$) il costo diventa 4, ovvero la lunghezza dell'array;

Se analizziamo infatti i singoli casi (come nell'analisi standard), otteniamo:
- _caso ottimo_: $O(1)$, ovvero quando non si entra nel ciclo perché l'ultima cifra del numero da incrementare è 0 ($A[i] == 0$);
- _caso pessimo_: $O(k)$, ovvero quando il numero è composto da tutti 1, e bisogna quindi scorrere il ciclo $k$ volte;

Entrambi non ci aiutano a capire il vero comportamento dell'algoritmo sul lungo termine, ovvero su una serie di applicazioni in sequenza. Allora utilizziamo l'analisi ammortizzata, entrambe le tecniche.

#### Metodo dell'aggregazione
Questo metodo prevede di notare un pattern all'interno della successione dell'algoritmo, e quindi di aggregare questo comportamento di $n$ operazioni e di dividerlo per $n$. In particolare, ci conviene analizzare il comportamento di ogni bit per una sequenza di $n$ operazioni:
![[incremento-bit.png]]

L'idea è allora di sommare tutte le modifiche dei bit per $n$ operazioni. In questo caso notiamo che:
- il $k$-esimo bit è cambiato ad ogni incremento $\implies$ su $n$ operazioni ci saranno $n$ modifiche
- il $k-1$-esimo bit è cambiato ogni 2 incrementi $\implies$ su $n$ operazioni ci saranno $\frac{n}{2}$ modifiche
- il $k-2$-esimo bit è cambiato ogni 4 incrementi $\implies$ su $n$ operazioni ci saranno $\frac{n}{4}$ modifiche
- ...

Otteniamo insomma una sommatoria del tipo
$$n + \frac{n}{2} + \frac{n}{4} + \frac{n}{8} + \cdots + \frac{n}{2^{k-1}}$$
che è trascrivibile in
$$\sum\limits_{i=0}^{k-1} \frac{n}{2^{i}} \leq n \cdot \sum\limits_{i=0}^{\infty} \frac{1}{2^{i}} = n \cdot \frac{1}{1-\frac{1}{2}} = 2n = O(n)$$

Se ora dividiamo per $n$ otteniamo il costo ammortizzato su una sequenza di operazioni, per l'appunto una sorta di media:
$$\frac{O(n)}{n} = O(1)$$

ovvero che _il costo ammortizzato è costante_.

#### Metodo degli accantonamenti
Con il metodo degli accantonamenti è necessario in primis tentare di stabilire il costo ammortizzato stesso, che settiamo a 2€[^2]. Vuol dire che ad ogni operazione otterremo 2€ per fare un eventuale cambio di bit (da 0 a 1 e viceversa). Ogni cambio costa 1€.
Quindi, per esempio, partendo con 0€ la sequenza sarà:

| Numero | Credito |
| ------ | ------- |
| -      | 0€      |
| 0001   | +2-1=1€ |
| 0010   | +2-2=1€ |
| 0011   | +2-1=2€ |
| 0100   | +2-3=1€ |
e così via.

Si capisce che in ogni momento, ogni 1 nell'array ha 1€ di credito che si va ad aggiungere al totale, e questo significa che il credito non potrà mai essere negativo. Già questo ci basta per capire che 2€ sono sufficienti. Se volessimo approfondire, però, otterremo che per $n$ operazioni ci sarà bisogno di $2n$€, questo perché ogni cambio da 0 ad 1 costa 2€, e se quindi si devono fare $n$ incrementi si arriva a $2n$€ "spesi". Per cui
$$\frac{2n}{n} = 2 = O(1)$$

Anche con il metodo degli accantonamenti abbiamo ottenuto lo stesso risultato: _il costo ammortizzato è costante_.

## Referenze
[^1]: esempio con [[strutture-union-find|strutture union-find]]
[^2]: la valuta ovviamente non è importante