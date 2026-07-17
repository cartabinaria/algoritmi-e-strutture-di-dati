---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
  - topic/ingegneria-del-software
  - topic/linguaggi-di-programmazione
date: 15-03-2024 16:03:33
links:
  - "[[lecture-12032024111356|Lecture 12032024111356]]"
  - "[[lecture-22092025100902|Lecture 22092025100902]]"
  - "[[lecture-23042025111218|Lecture 23042025111218]]"
  - "[[lecture-14052025105842|Lecture 14052025105842]]"
---
# Generics
---
## Introduzione
> Un **generic** in [[java|Java]] è un _[[tipi-di-dato|tipo di dato]] per l'appunto generico_, _utile per definire classi che operano su tipi di dati differenti_. Questo ci permette di [[astrazione|astrarre]] ancora di più delle classi e dei metodi.

La sintassi per definire una classe generic è `NomeDellaClasse<T>`. Alcune [[interfaccia|interfacce]] possono essere generic, come `Comparable<T>`.

## Funzionamento
Il [[tipi-di-dato|tipo di dato]] `Set` e' parametrico: _le operazioni di unione, intersezione, inclusione, sono parametriche agli elementi dell'insieme_. Solo quando si istanzia un `Set` con un certo tipo allora il tipo e' il parametro attuale dell'insieme.
Un [[sistema-di-tipi|sistema di tipi]] allora si dice parametrico se introduce la possibilita' del [[polimorfismo|polimorfismo]] parametrico/universale.

### Theorems for free
Con questo polimorfismo si ottengono prove di correttezza di programmi "gratuitamente"! Soprattutto, consente di fare ottimizzazione.

## Imposizione di vincoli
E' anche possibile imporre delle restrizioni sul tipo di dato generic della classe. Per esempio _su una classe che implementa [[algoritmo-di-ordinamento|algoritmi di ordinamento]], è inutile prendere in input array di oggetti non confrontabili e quindi non ordinabili secondo un certo criterio_. Si può allora imporre una restrizione con la seguente sintassi: `public class NomeDellaClasse<T extends Comparable<T>>`. In questo modo la classe `NomeDellaClasse` prenderà dei generici tipi `T` che siano di tipo `Comparable`, e che quindi possono essere confrontati (con il metodo `compareTo`).

## Limiti
**Non è possibile allocare un array di generics**. Questo perché il tipo degli array è verificato a runtime, mentre i generici sono sostituiti durante la compilazione (dove c'è `T` viene tutto sostituito con il tipo istanziato). Questo conflitto può essere risolto con due metodi che ci permettono alla fine di ottenere array di generici.

### 1° metodo
```java
T[] array;
@SuppressWarnings("unchecked")
T[] tmp = (T[]) new Object[size];
array = tmp;
```

O se si vuole imporre un vincolo sul tipo dei generici, come `T extends Comparable<T>`, allora si dovrà dichiarare non un `Object` ma un `Comparable`:
```java
T[] array;
@SuppressWarnings("unchecked")
T[] tmp = (T[]) new Comparable[size];
array = tmp;
```

### 2° metodo
```java
Object[] array;
@SuppressWarnings("unchecked")
T data = (T) array[i];
return data;
```

## Metodi statici
I tipi generics non possono essere referenziati in un contesto statico, per cui bisogna usare una speciale keyword nella firma del metodo per rendere possibile ciò: `public static <T extends Comparable<T>> void sort(T[] A);`.

## Altri linguaggi
### C
In [[c|C]] non ci sono nativamente i generics, ma è possibile implementare il [[polimorfismo|polimorfismo]] generico attraverso:
- _macro_ (esempio con funzione `swap` su tipi generici);
- _puntatori void_ (`void *`).

### C++
In [[c|C++]] i generics si fanno attraverso la keyword `template`. Nella fattispecie, a compile-time (di preciso prima del binding), i template _generano per quella classe o funzione tutti i codici per ogni tipo possibile_, andando di fatto a far "esplodere" la dimensione del codice sorgente.

<u>Nota bene</u>: con la _template specialization_ si possono addirittura creare gerarchie di template.

Questo processo si chiama **monomorfizzazione**.

### Java
In Java il meccanismo dei generics è gestito mediante [[type-erasure|type erasure]].

In Java c'e' il **polimorfismo parametrico ibrido**: viene fornito l'_operatore di introspezione `instanceof` per verificare se un valore appartiene a un determinato tipo_.

Altre volte e' utile esprimere dei vincoli sul quantificatore universale $T$. Si fa mescolando polimorfismo parametrico con il [[sottotipaggio|sottotipaggio]]. Per esempio
```rust
∀T, T <: Comparable, max: T -> T -> T
```

Sia in Java che in Rust si puo' scrivere `Set<T>` come tipo polimorfico che accetta un parametro di tipo (formale), qui catturato con la variabile di tipo $T$.
```Java
<T extends Comparable> T max (T x, T y){…}
```

#### Sottotipaggio di tipi parametrici
Ma se `Dog` $<:$ `Animal`, allora `Set<Dog>` $<:$ `Set<Animal>`? Stesso discorso del sottotipaggio di profondita' per i record: [[covarianza-e-controvarianza|covarianza e controvarianza]], la prima per la lettura la seconda per la scrittura.

Lo stesso vale per il sottotipaggio in larghezza dei tipi parametrici:
```rust
type Set<T>: {add:T->(),remove:T->(),includes:T->Bool}
type List<T>:{add:T->(),remove:T->(),includes:T->Bool,get:int->T}
```
in questo caso a prescindere da $T$ ed $S$ si avra' sempre `List<T>` $<:$ `Set<S>` (perche' `List<T>` conterra' sempre dei campi in piu').

## Referenze