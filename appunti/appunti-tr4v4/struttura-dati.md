---
tags:
  - category/note
  - status/finished
  - topic/programmazione
  - topic/algoritmi-e-strutture-dati
date: 05-11-2023 13:40:42
links:
  - "[[lecture-31102023091528|Lecture 31102023091528]]"
  - "[[lecture-07032024091439|Lecture 07032024091439]]"
---
# Struttura dati
---
## Introduzione
> Una **struttura dati** definisce come i _dati sono logicamente organizzati_, e le _operazioni per accedere e modificarli_.

<u>Nota bene</u>: _non definisce quali [[tipi-di-dato|tipi di dati]] sono memorizzati, ma piuttosto come sono memorizzati_. Ad esempio una liste di interi o di stringhe sono la stessa struttura dati, solo di tipo diverso.

In [[c|C]]/[[c|C++]] è possibile definirli come un tipo di dati composto da _elementi eterogenei_ raggruppati sotto un unico nome.

Le strutture inizializzate sono chiamate **record**, mentre i nomi degli elementi al loro interno sono detti **campi**.

### Differenze con [[array|array]]
La differenze fondamentali con gli array, a loro volta un tipo di [[strutture-dati-statiche|struttura dati statico]], consistono in:
- differente _composizione_ --> gli array contengono elementi dello stesso tipo, le strutture invece no;
- differente _modalità di accesso_ --> mentre con gli array è possibile usare la semplice [[array-esempio|formula di accesso a indice]], con le strutture si deve usare la **dot-notation**;

#### Accesso per dot-notation
Il motivo di questa differenza nell'accesso agli elementi di una struttura sta nella sua stessa composizione. Essendo composta da elementi eterogenei _ogni campo ha grandezze diverse_, o meglio l'**offset non è costante per ogni campo, perché dipende dal tipo**.

## Operazioni
### Dichiarazione
In [[c|C++]] la dichiarazione di strutture dati avviene attraverso il costrutto `struct`, come segue:
```cpp
struct id {
	type1 id1;
	type2 id2;
	type3 id3;
	...
};
```

### Inizializzazione
Per inizializzare una struttura si può utilizzare la stessa notazione degli array:
```cpp
studente studente1 = {"Nicola", "Travaglini"}
```

### Accesso
Come già anticipato si utilizza la _dot-notation_, che in C++ si concretizza come:
```cpp
studente studente1;
studente1.nome = "Nicola";
studente1.cognome = "Travaglini";
```

### Assegnamento
E' possibile assegnare valori di campi da una struttura a un'altra, _facendo attenzione al tipo_ (dev'essere lo stesso):
```cpp
struttura.campo1 = struttura.campo2;
```

E' possibile, inoltre, a differenza degli array, **copiare e assegnare intere strutture**: tutti i campi della struttura sorgente vengono copiati nei corrispondenti campi della struttura destinazione (ovviamente la struttura dev'essere la stessa).

### Confronto
Non è possibile, e neanche sensato, confrontare la grandezza per esempio di due strutture.

### Passaggio a funzione
Le strutture possono essere passate come argomenti di [[funzione-informatica|funzione]] e restituite come valori, ma attenzione: a differenza di quanto avviene per gli array, le strutture sono passate di default [[passaggio-per-valore|per parametro]], e non [[passaggio-per-riferimento|per riferimento]].

## Tipologie
- [[strutture-dati-statiche|Strutture dati statiche]]
- [[strutture-dati-dinamiche|Strutture dati dinamiche]]

## Referenze