---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
  - topic/ingegneria-del-software
date: 15-03-2024 15:57:08
links:
  - "[[lecture-12032024111356|Lecture 12032024111356]]"
  - "[[lecture-13032024111045|Lecture 13032024111045]]"
  - "[[lecture-21032025132255|Lecture 21032025132255]]"
---
# Interfaccia
---
## Introduzione
> Un'**interfaccia** in [[java|Java]], funge un po' da [[prototipo-vs-implementazione|prototipo]] da seguire alle classi, [[classe-astratta|astratte]] e concrete, che la implementano. Forniscono appunto solo l'interfaccia, ovvero una serie di [[funzione-informatica-firma|firme di metodi]] che le classi che la implementano (con la keyword `implements`) dovranno implementare.

## Default
I metodi di `default` sono dei metodi implementati all'interno delle stesse interfacce. Questo pone i classici problemi di [[ereditarieta|ereditarieta']] e di [[ereditarieta-multipla|ereditarieta' multipla]]... si puo' benissimo andare a creare il _deadly-diamond-of-death_, e in tal caso:
- _i metodi delle classi sono preferiti a quelli di default delle interfacce_;
- _i metodi gia' sovrascritti da altri supertipi sono ignorati_.

Se chiaramente, pero', due interfacce implementano due metodi di default con la stessa firma (o uno di default e uno astratto), allora il [[compilatore|compilatore]] Java ti obbliga a sovrascrivere il metodo dei supertipi oppure a specificare a quale implementazione si sta facendo riferimento (come avviene in [[c|C++]]), con `super`.

### Motivazioni
Il motivo reale per il quale sono dati i metodi di default e' per permettere l'evoluzione delle interfacce: **se di una gerarchia gia' esistente si aggiungesse un metodo a un'interfaccia, si costringerebbe tutta la gerarchia a implementare tale metodo**. Con un'implementazione di default si rilassa quest'obbligo.

## Utili
### `Comparable`
Un'interfaccia fondamentale _built-in_ di Java che usiamo per implementare [[algoritmo-di-ordinamento|algoritmi di ordinamento]] su oggetto [[generics|generici]] è `Comparable`. Espone unicamente il metodo `public int compareTo(Object o)`, e vale:
- `-1`, se l'oggetto su cui il metodo viene chiamato _precede_ l'oggetto `o` passato come parametro
- `0`, se sono equivalenti rispetto all'ordinamento
- `1`, se l'oggetto su cui il metodo viene chiamato _viene dopo_ l'oggetto `o` passato come parametro

### `Iterator`
Questa interfaccia ci permette di _allocare un iteratore_, ovvero un _cursore che scorre oggetti di una classe che implementano tale interfaccia_. Espone come unico metodo `Iterator<T> iterator();`, che restituisce un oggetto `Iterator`[^1] che a sua volta espone due metodi: `boolean hasNext();` per verificare se c'è un altro elemento e `T next();` per ritornare l'elemento successivo.

Gli oggetti che implementano tale interfaccia, detti _iterabili_, possono essere scansionati da una struttura di controllo chiamata `for-each`[^2].

#### Esempi
Possiamo scansionare gli elementi di un `ArrayList` e di un `LinkedList`.

##### `ArrayList`
```java
ArrayList<Integer> L = new ArrayList<>();
L.add(1); L.add(2); L.add(3);

int sum1 = 0;
Iterator iter = L.iterator();
while(iter.hasNext())
	sum1 = sum1 + iter.next();

int sum2 = 0;
for(Integer n: L)
	sum2 = sum2 + n;

int sum3 = 0;
for(int i = 0; i < L.size(); i++)
	sum3 = sum3 + L.get(i);

System.out.println(sum1 + " " + sum2 + " " + sum3);
```

##### `LinkedList`
```java
LinkedList<Integer> L = new ArrayList<>();
L.add(1); L.add(2); L.add(3);

int sum1 = 0;
Iterator iter = L.iterator();
while(iter.hasNext())
	sum1 = sum1 + iter.next();

int sum2 = 0;
for(Integer n: L)
	sum2 = sum2 + n;

int sum3 = 0;
for(int i = 0; i < L.size(); i++)
	sum3 = sum3 + L.get(i);

System.out.println(sum1 + " " + sum2 + " " + sum3);
```

## Referenze
[^1]: di tipo [[generics|generic]]
[^2]: un [[iterazione-for|ciclo for]]getti