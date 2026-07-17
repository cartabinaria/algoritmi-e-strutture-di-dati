---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 24-03-2024 22:11:02
links:
  - "[[lecture-21032024091145|Lecture 21032024091145]]"
  - "[[lecture-25032024091657|Lecture 25032024091657]]"
---
# Collisione hash
---
## Introduzione
> Una **collisione hash** è un _fenomeno inevitabile_ che avviene nel contesto delle [[tabella-hash|tabelle hash]] quando una _[[funzione-hash|funzione hash]] restituisce uno stesso valore di output per due chiavi $k_{1}, k_{2}$ differenti_.

Non si è in grado matematicamente di eliminarle, ma si possono e anzi devono limitare e gestire. Si pensi agli [[attacco-informatico|attacchi informatici]] basati sul cracking delle tabelle hash per provocare [[dos|DoS]].

## Probabilità
La _probabilità_ di una qualsiasi funzione hash di generare una _collisione tra due chiavi è più alta di quanto si possa credere_: assumendo _hashing uniforme semplice_ ($\frac{1}{m}$), il problema delle collisioni è equivalente al [[paradosso-del-compleanno|paradosso del compleanno]].

## Soluzioni
Esistono una serie di provvedimenti e tecniche che si utilizzano per mitigare il problema delle collisioni, tra cui:
- [[concatenamento-separato|Concatenamento separato]]
- [[indirizzamento-aperto|Indirizzamento aperto]]

### Confronti
![[confronti-costi-medi-ispezioni.png]]

Come si può notare dall'immagine non esiste un metodo migliore e uno peggiore per gestire le collisioni: dipende strettamente dai casi. Infatti
- per tabelle hash con _[[fattore-di-carico|fattore di carico]] $\alpha < 0.5$ (riempite fino al 50%) conviene usare l'indirizzamento aperto_;
- per tabelle hash con _fattore di carico $\alpha \geq 0.5$ (riempite oltre il 50%) conviene usate il concatenamento separato_;

## Referenze