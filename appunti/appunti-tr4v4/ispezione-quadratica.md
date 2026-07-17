---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 28-03-2024 16:47:12
links:
  - "[[lecture-25032024091657|Lecture 25032024091657]]"
---
# Ispezione quadratica
---
## Introduzione
> L'**ispezione quadratica** è una [[funzione-informatica|funzione]] d'ispezione adottata dalla tecnica di mitigazione delle [[collisione-hash|collisioni hash]] dell'[[indirizzamento-aperto|indirizzamento aperto]], nel contesto delle [[tabella-hash|tabelle hash]], e si formulizza in
> $$h(k, i) = (h'(k)+c_{1}i+c_{2}i^{2}) \mod{m}$$
> dove:
> - $k$ è la chiave di $U$;
> - $i$ è il passo d'ispezione;
> - $h'(k)$ è la [[funzione-hash|funzione hash]] adottata;
> 
> e con $c_{1} \neq c_{2}$.

Anche in questo caso, come per l'[[ispezione-lineare|ispezione lineare]], il primo indice $h'(k)$ determina l'intera sequenza $(i = 0)$.

<u>Nota bene</u>: è importante _scegliere dei valori di $c_{1}, c_{2}$ che garantiscano che tale ispezione fornisca una [[permutazione|permutazione]] degli indici $0, \cdots, m-1$ della tabella_.

## Problema
L'ispezione quadratica genera **clustering secondario**, provocato dal fatto che _se due chiavi hanno la stessa ispezione iniziale allora le loro sequenze sono identiche_. Quindi è _come se si ricalcassero gli stessi passi per ogni chiave con la stessa $h(k)$_, una grande perdita di tempo. Inoltre per l'appunto, se $c_{1}, c_{2}$ non sono scelti bene potrebbero non garantire una permutazione degli indici della tabella, _provocando in alcuni casi dei loop da cui è impossibile uscire_: non vengono allora visitate tutte le $m$ celle, e l'algoritmo restituirà erroneamente un eccezione di `overflow`.

### Esempio
Si considerino, su $h(k, i) = (h'(k) + c_{1}i + c_{2}i^{2}) \mod{10}$ con $h'(k) = k \mod{10}$ ([[metodo-della-divisione|metodo della divisione]]) e $c_{1}=0$ e $c_{2} = 1$, i seguenti inserimenti:
![[ispezione-quadratica.png]]

Se a seguito di ciò volessimo eseguire `insert 6`, _i passi di ispezione per raggiungere le celle 8 e 9 libere superano la decina_! E molto probabilmente (sarebbe da verificare) _non sono raggiungibili perché si finisce in un loop_...

## Referenze