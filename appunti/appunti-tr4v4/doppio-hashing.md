---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 28-03-2024 17:17:05
links:
  - "[[lecture-25032024091657|Lecture 25032024091657]]"
---
# Doppio hashing
---
## Introduzione
> Il **doppio hashing** è una [[funzione-informatica|funzione]] d'ispezione adottata dalla tecnica di mitigazione delle [[collisione-hash|collisioni hash]] dell'[[indirizzamento-aperto|indirizzamento aperto]], nel contesto delle [[tabella-hash|tabelle hash]], e si formulizza in
> $$h(k, i) = (h_{1}(k) + ih_{2}(k)) \mod{m}$$
> dove:
> - $k$ è la chiave di $U$;
> - $i$ è il passo d'ispezione;
> - $h_{1}(k)$ è la [[funzione-hash|funzione hash]] primaria;
> - $h_{2}(k)$ è la funzione hash secondaria.
> 
> In breve, in caso di collisione, ovvero per $i > 0$, _si utilizza un secondo hashing di $k$ moltiplicato per $i$ per determinare il successivo slot da ispezionare_.

### Vincoli
La funzione hash $h_{2}$ deve rispettare i seguenti vincoli:
- _non deve mai restituire 0_ (altrimenti crea un loop);
- _deve permettere l'iterazione su tutti gli indici della tabella_;

## Vantaggi
Al contrario dell'[[ispezione-lineare|ispezione lineare]] e [[ispezione-quadratica|quadratica]], il doppio hashing **evita il clustering primario e il clustering secondario**. Di fatto, se $h_{1} \neq h_{2}$ è meno probabile che per una coppia di chiavi $a \neq b$ si abbia una collisione sia su $h_{1}$ che su $h_{2}$, ovvero è quasi impossibile che
$$h_{1}(a) = h_{1}(b) \ \land \ h_{2}(a) = h_{2}(b)$$

Questo rende possibile più di $m$ sequenze distinte di ispezioni, garantendo la [[permutazione|permutazione]] sugli indici $0, \cdots, m-1$ della tabella.

### Esempio
Si considerino, su $h(k, i) = (h_{1}(k) + ih_{2}(k)) \mod{m}$ con $h_{1}(k) = k \mod{10}$ ([[metodo-della-divisione|metodo della divisione]]) e $h_{2}(k) = (k \mod{9})+1$, i seguenti inserimenti:
![[doppio-hashing.png]]

## Referenze