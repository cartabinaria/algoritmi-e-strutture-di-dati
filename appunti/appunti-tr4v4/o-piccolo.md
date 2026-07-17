---
tags:
  - category/note
  - status/finished
  - topic/analisi-I
  - topic/algoritmi-e-strutture-dati
date: 12-11-2023 18:20:10
links:
  - "[[lecture-10112023134301|Lecture 10112023134301]]"
  - "[[lecture-13112023094129|Lecture 13112023094129]]"
  - "[[lecture-21022024111657|Lecture 21022024111657]]"
  - "[[lecture-27032024141122|Lecture 27032024141122]]"
---
# O-piccolo
---
## Introduzione
> Una [[funzione-matematica|funzione]] $g(x)$ si dice essere **o-piccolo** di $f(x)$ per $x \to x_{0}$ se, date le ipotesi
> 1. $f(x) \neq 0$ per $x \neq x_{0}$
> 2. $g(x) \stackrel{x \to x_{0}}{\longrightarrow} 0$
> 
> si ha che
> $$\forall \epsilon > 0, \exists \delta > 0 : \forall x \neq x_{0}, 0 < |x - x_{0}| < \delta \implies \frac{|g(x)|}{|f(x)|} < \epsilon$$
> o, con la notazione di [[limite-finito-al-finito-di-funzione|limite]] che
> $$\lim_{x \to x_{0}} \frac{g(x)}{f(x)} = 0$$
> ovvero, **$g(x)$ è un o-piccolo di $f(x)$ se per $x \to x_{0}$ tende a $0$ più velocemente di $f(x)$, o in altre parole se $g(x)$ è un [[infinitesimi|infinitesimo]] di ordine superiore a $f(x)$**.
> In tal caso si scrive
> $$g(x) = o(f(x))$$
> per cui $g(x)$ è una **generica funzione**[^1] che per $x \to x_{0}$ va a 0 più velocemente di $f(x)$.

### Osservazioni
La notazione
$$g(x) = o(1)$$
sta a indicare che $g(x)$ è una funzione che per $x \to x_{0}$ tende a 0: infatti _la funzione $f(x) = 1$ non tenderà mai a 0 più velocemente di qualunque altra funzione_.

## Utilizzi
Sappiamo che gli _o-piccoli_ si utilizzano per calcolare gli [[sviluppo-in-serie-di-taylor|sviluppi di Taylor]], e nel particolare questo significa che grazie alle loro proprietà _si è in grado di ricreare una qualunque funzione approssimandola con dei polinomi_. Quest'approssimazione prevede un errore da pagare, rappresentato proprio dagli o-piccoli.

> Trovare, di una funzione, l'_o-piccolo migliore_, significa trovare l'o-piccolo che **mantiene più informazione possibile sulla funzione di partenza**. Quello, in parole povere, più vicino alla _"soglia" d'ordine_, che se superata non fa più convergere a 0 il limite.

Se l'errore, e quindi l'o-piccolo, è molto grande (es. $o(\sqrt{x})$), perdiamo la precisione della funzione originaria! Per questo _più l'ordine dell'o-piccolo è alto meglio stiamo approssimando la funzione, perché stiamo considerando un errore infinitesimale_.

### Informatica
Nello studio degli [[algoritmo|algoritmi]] gli $o$-piccoli fanno parte della [[notazione-asintotica|notazione asintotica]], e sono una forma più restrittiva degli [[o-grande|O-grandi]].
> Data una [[funzione-di-costo|funzione di costo]] $g(n)$ definiamo l'[[insieme|insieme]] delle [[funzione-matematica|funzioni]] che sono _dominate asintoticamente_ da $g(n)$ come
> $$o(g(n)) = \{f(n) | \forall c > 0, n_{0} \geq 0 : \forall n \geq n_{0}, f(n) < cg(n)\}$$
> dove $o(g(n))$ è l'**o-piccolo** di $g(n)$.

Vale che
$$f = o(g) \implies f = O(g)$$
ma _non necessariamente il contrario_.

## In $\mathbb{R}^{n}$
Gli o-piccolo nello [[spazio-euclideo|spazio euclideo]] $\mathbb{R}^{n}$ generalizzano la definizione data in precedenza usando la [[norma-euclidea|norma]].
> Sia $A \subseteq \mathbb{R}^{n}$ un [[insieme|insieme]] [[insieme-aperto|aperto]]; assumiamo $x_{0} \in A$, allora una funzione $g: A \to \mathbb{R}$ si dice _o-piccolo_ di $|f(x)|$ se, data l'ipotesi $g(x) \stackrel{x \to x_{0}}{\longrightarrow} 0$, si ha che
> $$\forall \epsilon > 0 \ \exists \delta > 0 : \forall x \neq x_{0}, 0 < ||x - x_{0}|| < \delta \implies \frac{|g(x)|}{|f(x)|} < \epsilon$$
> ovvero, per la notazione di limite, che
> $$\lim_{x \to x_{0}}\frac{|g(x)|}{|f(x)|} = 0$$

### Esempio
Consideriamo una funzione $g: \mathbb{R}^{2} \to \mathbb{R}$ del tipo $g(x, y) = x^{2}+y^{2}$; consideriamo ora $f: \mathbb{R}^{2} \to \mathbb{R}$ del tipo $f(x, y) = \sqrt{x^{2}+y^{2}} = ||(x, y)||$. Vogliamo verificare che $g(x, y) = o(f(x, y))$ per $(x, y) \to (0, 0)$.

Facciamolo prima usando la definizione di limite:
$$\forall \epsilon > 0, \exists \delta > 0: \forall (x, y) \neq (0, 0), 0 < ||(x, y)-(0, 0)|| < \delta \implies \frac{|x^{2}+y^{2}|}{|\sqrt{x^{2}+y^{2}}|} < \epsilon$$
ovvero
$$\forall \epsilon > 0, \exists \delta > 0: \forall (x, y) \neq (0, 0), 0 < ||(x, y)|| < \delta \implies \frac{||(x, y)||^{2}}{||(x, y)||} < \epsilon$$
per cui
$$\forall \epsilon > 0, \exists \delta > 0: \forall (x, y) \neq (0, 0), 0 < ||(x, y)|| < \delta \implies ||(x, y)|| < \epsilon$$
allora scelgo $\delta = \epsilon$ e ottengo una trivialità ($A \implies A$).

Ora usiamo semplicemente la nozione di limite:
$$\lim_{(x, y) \to (0, 0)} \frac{|x^{2}+y^{2}|}{\sqrt{x^{2}+y^{2}}} = 0 \ \iff \ \lim_{(x, y) \to (0, 0)} \frac{||(x, y)||^{2}}{||(x, y)||} = 0 \ \iff \ \lim_{(x, y) \to (0, 0)} ||(x, y)|| = 0$$
il che è banalmente vero.

## Regole
- [[algebra-degli-o-piccoli|Algebra degli o-piccoli]]

## Referenze
[^1]: si dice essere una _[[classe|classe]] di funzioni_