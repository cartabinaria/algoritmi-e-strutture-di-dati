---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 29-02-2024 16:35:16
links:
  - "[[lecture-28022024111804|Lecture 28022024111804]]"
  - "[[lecture-29022024091237|Lecture 29022024091237]]"
  - "[[lecture-04032024091423|Lecture 04032024091423]]"
  - "[[lecture-07032024091439|Lecture 07032024091439]]"
  - "[[lecture-12032024111356|Lecture 12032024111356]]"
---
# Java
---
## Introduzione
> **Java** è un [[linguaggio-di-programmazione|linguaggio di programmazione]] [[oop|object-oriented]] sviluppato negli anni '90.

Il suo punto di forza sta nella [[compilazione-a-2-livelli|compilazione a 2 livelli]] attuata dalla [[jvm|Java Virtual Machine]] (_JVM_), che lo rende _indipendente dalla piattaforma e portabile_ ([[wora|WORA]]).

## Tipi di dati
Java divide i [[tipi-di-dato|dati]] in due principali categorie:
- _primitivi_
	- `int`, `boolean`, `char`, `short`, `long`, `float`, `double`
	- per ognuno dei quali esiste una _rispettiva classe wrapper_, con operazioni di _boxing_ e _unboxing_ automatiche
- _classi_
	- definite dall'utente o incluse in librerie

### Classi utili
In particolare si ricordano classi di fondamentale importanza tra cui:
- `String`, per la manipolazione di stringhe;
- `Arrays` (_statica_) per la manipolazione di [[array|array]] (come l'[[algoritmo-di-ordinamento|ordinamento]])
	- in particolare il metodo `sort` è la combinazione tra [[insertion-sort|insertion sort]], [[merge-sort|merge sort]] e [[quick-sort|quick sort]];
	- il quick sort implementato usa due pivot, per diminuire la probabilità di beccarne uno pessimo (_DualPivot QuickSort_)
	- l'insertion sort è usato su istanze piccole, $\leq 47$
		- ed è usato nei `merge` e nei `partition` di merge sort e quick sort
	- il merge sort è preferito al quick sort su istanze grandi, $\geq 286$

## Caratteristiche
Java basa la sua struttura sull'[[ereditarieta|ereditarietà]] e sul [[polimorfismo|polimorfismo]]. In particolare ricordarsi che:
- in caso di _overwriting_ bisogna specificare l'annotazione `@Override`;
	- di solito si fa l'override di metodi base come `toString()` e `equals()`;
		- in particolare per `equals()` un metodo potrebbe essere
		```java
		  if (obj == null || !(obj isinstanceof NomeClasse))
			  return false;
			else
				return ... // confronta tutti gli attributi
		```
		- ma attenzione, fare il _typecasting_ su `obj` per poter confrontare gli attributi di `NomeClasse`
- `super` è la _key-word_ per accedere a metodi e attributi della superclasse;
- la classe `Object` è la superclasse di tutte le classi in Java;
- le _eccezioni_ sono tutti oggetti, solitamente sottoclassi della classe `Exception`
	- c'è una gerarchia di eccezioni ![[java-exceptions.png]]
	- per il lancio delle eccezioni ci sono `throws` (nella firma del metodo) e `throw` (all'interno del metodo);
	- per la presa delle eccezioin c'è il costrutto `try & catch`;
	- si possono definire eccezioni estendendo `Exception` o qualunque altra classe che implementi l'[[interfaccia|interfaccia]] `throwable`;

## Comandi
- `javac NomeFile.java` per la _[[compilatore|compilazione]]_ di primo livello;
- `java NomeFile` per l'_[[interprete|interpretazione]]_ di secondo livello;
- `javadoc NomeFile.java` per la generazione della documentazione automatica Java (_JavaDoc_)

## Referenze
- [[garbage-collector|Garbage collector]]
- [[classe-astratta|Classe astratta]]
- [[interfaccia|Interfaccia]]
- [[generics|Generics]]