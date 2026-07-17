---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 24-03-2024 22:20:14
links:
  - "[[lecture-21032024091145|Lecture 21032024091145]]"
---
# Concatenamento separato
---
## Introduzione
> Per **concatenamento separato** si intende una tecnica di mitigazione delle [[collisione-hash|collisioni hash]] nel contesto delle [[tabella-hash|tabelle hash]], che _consiste nel memorizzare le chiavi $k$ con lo stesso valore $h(k) = i$ in una [[lista|lista]] concatenata_, chiamata _lista di trabocco_.

![[concatenamento-separato.png]]

## Pseudocodice
![[pseudo-concatenamento-separato.png]]

### Costi
I [[complessita-computazionale|costi]] delle 3 operazioni risultano allora essere:
- _caso ottimo_: $O(1)$;
- _caso pessimo_: $\Theta(T[h(k)].\text{length})$, perché dipendono dalla ricerca lineare sulla lista di trabocco $T[h(k)]$ (e non da $m$, la dimensione della tabella);
- _caso medio_: difficile da calcolare;

## Analisi caso medio
Il caso medio, per essere analizzato, ha bisogno di introdurre il [[fattore-di-carico|fattore di carico]]. Ricordiamo infatti che sotto l'ipotesi di [[uniformita-semplice|hashing uniforme semplice]], **ogni slot della tabella hash ha mediamente $\alpha$ chiavi**, e da ciò ne conseguono due teoremi.

### Ricerca senza successo
> Una _ricerca senza successo_ in una tabella hash con concatenamento ha costo medio
> $$\Theta(1 + \alpha)$$

#### Dimostrazione
Dalle ipotesi sappiamo che ogni slot ha mediamente $\alpha$ chiavi, ovvero $\frac{n}{m}$ chiavi. Una ricerca senza successo su uno slot di $\frac{n}{m}$ chiavi scorre allora $\frac{n}{m}$ nodi della lista di trabocco. Allora se $\frac{n}{m} < 1$ il costo è lineare $O(1)$; se invece $\frac{n}{m} \geq 1$ il costo è invece $\Theta\left(\frac{n}{m}\right)= \Theta(\alpha)$. Unendo i risultati otteniamo quindi che in media si ha un costo
$$O(1) + \Theta(\alpha) = \Theta(1 + \alpha)$$

**Qed**.

### Ricerca con successo
> Una _ricerca con successo_ in una tabella hash con concatenamento ha costo medio
> $$\Theta(1 + \alpha)$$

#### Dimostrazione
Anche in questo caso dalle ipotesi ogni slot ha mediamente $\alpha$ chiavi, ovvero $\frac{n}{m}$ elementi. Una ricerca con successo su uno slot di $\alpha$ chiavi, in media scorrerà $\frac{\alpha}{2}$ nodi della lista di trabocco. Allora se $\alpha < 1$ il costo è lineare $O(1)$; se invece $\alpha \geq 1$ il costo è $\Theta(\frac{\alpha}{2})$. Unendo i risultati otteniamo che in media si ha un costo
$$O(1) + \Theta\left(\frac{\alpha}{2}\right)= \Theta\left(1 + \frac{\alpha}{2}\right)= \Theta(1 + \alpha)$$

### Caso medio
Otteniamo quindi che in entrambi i casi, la ricerca lineare su una tabella hash con concatenamento ha costo medio $\Theta(1 + \alpha)$, per cui essendo ogni operazione, `search`, `insert` e `delete`, direttamente dipendente da tale ricerca, si ha che il caso medio di ogni operazione è proprio
$$\Theta(1 + \alpha)$$
il che apre una serie di casistiche:
- $n = O(m) \implies \alpha = O(1) \implies$ costo medio costante $O(1)$
- $n = O(m^{2}) \implies \alpha = \Theta(n) \implies$ costo medio lineare $\Theta(n)$

<u>Nota bene</u>: il primo caso è ovvio perché se $n = O(m)$, sotto l'ipotesi di hashing uniforme non si va a generare alcuna lista di trabocco! Per cui la ricerca di ogni chiave è sempre costante.

#### Conseguenze
Questo significa che con concatenamento separato **man mano che la tabella si riempie le prestazioni tendono a peggiorare**. Di fatto il costo nel caso medio è
- _direttamente proporzionale_ al numero di elementi inseriti, $n$;
- _inversamente proporzionale_ agli slot della tabella, $m$.

In breve: più la si fa grande meglio è; più la si tiene vuota meglio è.

## Referenze