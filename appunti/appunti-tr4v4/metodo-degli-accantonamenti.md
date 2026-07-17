---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 28-02-2024 11:58:53
links:
  - "[[lecture-26022024091150|Lecture 26022024091150]]"
---
# Metodo degli accantonamenti
---
## Introduzione
> Il **metodo degli accantonamenti** è una tecnica usata nell'[[analisi-ammortizzata|analisi ammortizzata]] _basato sulla contabilità_. Ha un [[algoritmo|algoritmo]] specifico che consente di calcolare il _costo ammortizzato_ di un algoritmo preso in analisi.

## Algoritmo
L'algoritmo del metodo degli accantonamenti prevede:
1. assegnamento di un costo ammortizzato ad ogni operazione
2. ogni operazione viene addebitata con il suo costo ammortizzato
3. dopo ogni operazione salviamo come credito la differenza tra il suo costo ammortizzato e il costo reale
4. accumuliamo il credito collezionato durante l'esecuzione
5. se il costo reale è più alto del costo ammortizzato usiamo il credito
6. _il costo ammortizzato è corretto se il credito non è mai negativo_

<u>Nota bene</u>: il metodo degli accantonamenti è ottimo ma _è necessario specificare il costo ammortizzato di partenza_; ci si può impiegare del tempo prima di arrivare al costo ammortizzato ottimale.

## Referenze