---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 20-02-2024 18:32:36
links:
  - "[[lecture-20022024111057|Lecture 20022024111057]]"
  - "[[lecture-21022024111657|Lecture 21022024111657]]"
---
# Notazione asintotica
---
## Introduzione
> Per **notazione asintotica** si intende uno strumento matematico usato per confrontare il _tasso di crescita_ (o _growing-rate_) di una [[funzione-matematica|funzione]] rispetto a un'altra.

In particolare viene spesso utilizzata con lo scopo di analizzare il _tempo di calcolo_ e l'_occupazione di memoria_ degli [[algoritmo|algoritmi]] in termini di dimensione dell'input. Infatti il **rate di crescita costituisce a tutti gli effetti il più oggettivo e preciso valore per poter valutare l'efficienza temporale/spaziale di un algoritmo**! Il growing-rate si studia con il nome di _comportamento asintotico_.

### Valore di input vs. dimensione dell'input
La notazione asintotica, nel contesto algoritmico, _dovrebbe essere calcolata sulla dimensione dell'input_ piuttosto che sul valore. Se per esempio l'input è un intero, sarebbe più formalmente corretto andare a rappresentare il suo comportamento asintotico sulla base di quanto occupa in memoria il [[tipi-di-dato|tipo di dato]] "intero": si ha $|n| = \lceil \log_{2}{n} \rceil$, ovvero che la dimensione del valore $n$ è data dal numero di cifre che ha in binario[^1].

## Funzionamento
Per studiare il **comportamento asintotico** di un algoritmo, quindi, è necessario ignorare costanti additive/moltiplicative e in generale termini di ordine inferiore, ed è sufficiente **descrivere quanto velocemente _tempo di calcolo_ e _memoria utilizzata_ crescono rispetto alla dimensione dell'input**.

Per fare ciò si mettono a confronto la [[funzione-di-costo|funzione di costo]] del tempo/memoria con delle [[funzione-di-costo|funzioni di costo]] standard. Le relazioni tra queste due funzioni può essere:
- [[o-grande|O-grande]]
- [[omega-grande|Omega-grande]]
- [[theta|Theta]]
- [[o-piccolo|O-piccolo]]
- [[omega-piccolo|Omega-piccolo]]

<u>Nota bene</u>: la notazione asintotica, in [[analisi-i|analisi]], si concentra su funzioni generali e per valori specifici (come avviene per esempio negli [[sviluppo-in-serie-di-taylor|sviluppi di Taylor]], dove si studia intorno allo 0); _in algoritmi ci riferiamo solo a funzioni positive_ (di costo) _e per valori che tendono a infinito_ (per questo asintotici).

Intuitivamente, le notazioni asintotiche descrivono le relazioni tra i tassi di crescita di due funzioni di costo, e possono quindi essere semplicemente riassunte nella seguente tabella:
![[relazioni-notazione-asintotica.png]]

Al posto di utilizzare le singole definizioni delle notazioni, _si può con maggiore precisione e praticità classificare una funzione di costo usando i seguenti [[limite-di-funzione|limiti]]_:
- $\lim_{n \to +\infty}{\frac{f(n)}{g(n)}} = 0 \implies f(n) = o(g(n)) \implies f(n) = O(g(n))$
- $\lim_{n \to +\infty}{\frac{f(n)}{g(n)}} = \infty \implies f(n) = \omega(g(n)) \implies f(n) = \Omega(g(n))$
- $\lim_{n \to +\infty}{\frac{f(n)}{g(n)}} = k > 0 \implies f(n) = \Theta(g(n))$

<u>Attenzione</u>: _ci sono funzioni cui rate di crescita non sono confrontabili_, come ad esempio $f(n) = n$ e $g(n) = n^{sin(n)+1}$ (in quanto $f(n) \neq O(g(n))$ ma anche $f(n) \neq \Omega(g(n))$).

<u>Nota</u>: _data una funzione positiva posso sempre scrivere un algoritmo che ha quella funzione di costo_.

### Motivazioni
Della funzione di costo a noi interessa, appunto, il tasso di crescita. Supponiamo per esempio di avere due algoritmi con le seguenti funzioni di costo per il tempo di calcolo:
- $f_{A}(n) = 10^{2}n$
- $f_{B}(n) = 10^{-2}n^{2}$

L'algoritmo più veloce, studiandone il comportamento asintotico, risulta essere l'$A$. Lo si capisce guardando le due _rappresentazioni dei comportamenti asintotici_ delle funzioni:
![[confronto-comportamento-asintotico.png]]
La prima sembra suggerire che l'algoritmo $B$ "costi di meno", ma a lungo termine (per l'appunto su _scala asintotica_), l'algoritmo più veloce diventa l'$A$ (si guardi la seconda immagine).

### Ordini di crescita
Ciò che si ricava dalla notazione asintotica è una tabella che riassume, su $O$-grande, l'ordine di crescita delle principali funzioni di costo:
![[ordini-di-crescita.png]]
cui relativi grafici sono
![[confronto-ordini-di-crescita.png]]

## Proprietà
Nel contesto della notazione asintotica valgono le seguenti importanti proprietà:
- $\forall a > 1, \forall b > 1, \log_{a}{n} = \Theta(\log_{b}{n})$
- $\forall a > 0, \forall b > 0, \log^{a}{n} = O(n^{b})$
- $\log{n!} = \Theta(n\log{n})$
- $1 < a < b, a^{n} = O(b^{n})$
- $a > 0, n^{\log{a}} = \Theta(a^{\log{n}})$

Ci sono anche altre proprietà [[algebra-astratta|algebriche]][^2]:
- **transitività**: $f(n) = O(g(n)) \land g(n) = O(h(n)) \implies f(n) = O(h(n))$
- **riflessività**: $f(n) = O(f(n)) \land f(n) = \Omega(f(n)) \land f(n) = \Theta(f(n))$
- **simmetria**: $g(n) = \Theta(f(n)) \iff f(n) = \Theta(g(n))$
- **simmetria trasposta**:
	- $f(n) = O(g(n)) \iff g(n) = \Omega(f(n))$
	- $f(n) = o(g(n)) \iff g(n) = \omega(f(n))$
- **somma** (vale anche per altre relazioni asintotiche): $f_{1}(n) = O(g_{1}(n)) \land f_{2}(n) = O(g_{2}(n)) \implies f_{1}(n) + f_{2}(n) = O(g_{1}(n)) + O(g_{2}(n)) = O(g_{1}(n) + g_{2}(n))$
- **prodotto** (vale anche per altre relazioni asintotiche): $f_{1}(n) = O(g_{1}(n)) \land f_{2}(n) = O(g_{2}(n)) \implies f_{1}(n) \cdot f_{2}(n) = O(g_{1}(n)) \cdot O(g_{2}(n)) = O(g_{1}(n) \cdot g_{2}(n))$
- **moltiplicazione per una costante** (vale anche per altre relazioni asintotiche): $f(n) = O(g(n)) \land a > 0 \implies a \cdot f(n) = O(g(n))$

<u>Attenzione</u>: c'è un motivo ben specifico per cui non esiste la proprietà della "somma per una costante". Presa per esempio una _funzione di costo decrescente_ come $\frac{1}{x}$ (che in algoritmi è introvabile, ma che comunque è una funzione di costo), essa è $O(1)$, ovvero $1$ è il suo limite superiore; se moltiplichiamo $\frac{1}{x}$ otteniamo sempre che è $O(1)$; se invece ci sommiamo un valore ecco che non lo è più: anzi, diventa $\Omega(1)$ o $\Theta(1)$ (se si somma 1).

## Referenze
[^1]: ricordiamo infatti che è questo il modo in cui sono [[codifica-numeri-interi|codificati i numeri positivi in memoria]]
[^2]: che ricorda, non per niente, l'[[algebra-degli-o-piccoli|algebra degli o-piccoli]]