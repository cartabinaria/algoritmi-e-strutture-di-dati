---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 04-05-2024 17:45:06
links:
  - "[[lecture-30042024111642|Lecture 30042024111642]]"
  - "[[lecture-02052024091854|Lecture 02052024091854]]"
---
# DFS su grafi
---
## Introduzione
> La **visita in profondità su [[grafo|grafi]]** (o [[dfs|DFS]] su grafi) è un [[algoritmo|algoritmo]] di [[algoritmi-di-visita-su-grafi|visita]] che consente di esplorare l'intero grafo $G$, e non solo i nodi raggiungibili da una sorgente $s$ come avviene per la [[bfs-su-grafi|visita BFS]]. In particolare _a partire da un vertice $v$ si esplora immediatamente il primo vertice adiacente ad esso, e così via fino ad arrivare a un "vicolo cieco"; quindi a ritroso si esplorano gli altri vertici adiacenti a $v$, fino a terminare il sottografo_. L'algoritmo _genera una [[foresta|foresta]] DF (depth-first) $G_{\pi} = (V, E_{\pi})$_ e fornisce informazioni addizionali sul _tempo di visita di ogni nodo_.

## Algoritmo
Come per la visita BFS è _necessario marcare i vertici già visitati per evitare di incorrere in loop_.

In questo caso, però, _per motivi che saranno chiariti in seguito_, dividiamo i vertici non in due categorie (`true` o `false`) ma bensì in 3:
- `white` --> inesplorato;
- `gray` --> aperto;
- `black` --> chiuso.

### Implementazione
```R
global time := 0; //var.globale

function DFS(Grafo G) {
	for each u in V {
		u.mark := white;
		u.parent := nil;
	}
	for each u in V {
		if (u.mark == white) {
			DFS-visit(u);
		}
	}
}

function DFS-visit(vertice u) {
	u.mark := gray;
	time := time+1;
	u.dt := time;
	for each v adiacente a u {
		if (v.mark = white) {
			v.parent := u;
			DFS-visit(v);
		}
	}
	“visita il vertice u”
	time := time+1;
	u.ft := time;
	u.mark := black;
}
```

L'algoritmo si divide in due funzioni: `DFS`, ossia il _main_ che per ogni vertice `white` (inesplorato) invoca la visita ricorsiva `DFS-visit`; e proprio `DFS-visit`, che richiama ricorsivamente se stessa per ogni vertice adiacente al vertice `v` in input.

Quindi, una volta impostata una variabile globale `time` a `0`, procediamo con l'algoritmo.

`DFS`:
1. per ogni vertice $v \in V$:
	1. marchiamo $v$ a `white`, perché all'inizio ogni vertice è inesplorato;
	2. settiamo il padre di $v$ a `nil`, perché dobbiamo ancora fare l'esplorazione;
2. per ogni vertice $v \in V$:
	1. se il vertice è inesplorato (`white`), invochiamo la visita ricorsiva `DFS-visit`.

`DFS-visit`:
1. marchiamo il vertice $u$ da visitare a `gray`, perché è aperto e non più inesplorato;
2. incrementiamo `time` di 1;
3. quindi settiamo il tempo di scoperta di $u$ a `time` (`u.dt = time`);
4. per ogni vertice $v$ adiacente a $u$:
	1. se $v$ è inesplorato (`white`):
		1. settiamo al padre di $v$ il vertice $u$ (`v.parent = u`);
		2. richiamiamo `DFS-visit` su $v$ --> da qui la visita in profondità;
5. una volta terminata la visita di tutti i vertici adiacenti a $u$, visitiamo effettivamente $u$;
6. incrementiamo `time` di 1;
7. quindi settiamo il tempo di terminazione di $u$ a `time` (`u.ft = time`);
8. marchiamo il vertice $u$ a `black`, perché abbiamo visitato ogni vertice adiacente, quindi da aperto diventa chiuso.

<u>Nota bene</u>: la funzione _`DFS` esterna è proprio quella che ci consente di ottenere una foresta di alberi liberi_. Infatti, **terminata una visita ricorsiva di un vertice $v \in V$ che a sua volta esplorerà un intero sottografo di $G$, passerà a un vertice ancora inesplorato (`white`), e quindi a un altro sottografo di $G$**. Nessun vertice, fondamentalmente, verrà escluso dalla visita.

<u>Nota bene</u>: trattandosi di una visita basata sull'approccio DFS, non è necessario usare una [[struttura-dati|struttura dati]] ausiliaria, e in particolare una [[pila|pila]], perché _sfruttiamo lo [[stack|stack]] delle chiamate ricorsive per ottenere lo stesso risultato_.

### Costo computazionale
Il [[complessita-computazionale|costo computazionale]] della DFS è assolutamente identico alla BFS:
- per le [[lista-di-adiacenza|liste di adiacenza]] dobbiamo scorrere $n$ vertici in `DFS` ($O(n)$), e poi per ognuno di essi dobbiamo scorrere la sua lista di adiacenza, quindi in totale tutti i suoi archi ($O(m)$) --> in totale si avrà $O(n) + O(m) = O(n + m)$;
- per le [[matrice-di-adiacenza|matrici di adiacenza]] dobbiamo scorrere per ogni vertice $n$ i suoi archi e i suoi non archi, per cui $n$ vertici --> in totale avremo $O(n) + O(n^{2}) = O(n^{2})$.

## Importanza
Ciò che la visita DFS consente di conoscere di un grafo consiste nei 2/3 attributi che compila per ogni vertice, ovvero:
- `v.mark` - `white` se inesplorato, `gray` se aperto, `black` se chiuso;
- `v.dt` - "discovery time", tempo di scoperta del vertice `v`;
- `v.ft` - "finish time", tempo di terminazione del vertice `v`.

In particolare, grazie a queste informazioni si riesce a:
- _scovare i cicli in grafi non orientati_;
- _ordinare topologicamente un grafo_;
- _individuare le componenti connesse di un grafo non orientato_, e le _componenti fortemente connesse di un grafo orientato_.

### Proprietà
#### Teorema delle parentesi
Per poter capire quanto importanti siano le informazioni raccolte dalla visita partiamo dal notare un fatto importante:
> Visitando in profondità un grafo $G = (V, E)$, per ogni [[coppia-ordinata|coppia]] di vertici $u, v$, si ha che una e una sola delle seguenti condizioni è vera:
> - $[u.dt, u.ft] \cap [v.dt, v.ft] = \varnothing$ (gli intervalli sono disgiunti) $\implies$ $u, v$ non sono in una relazione di ascendenza/discendenza;
> - $[u.dt, u.ft] \subset [v.dt, v.ft]$ $\implies$ $u$ discendente di $v$ in un albero DF;
> - $[v.dt, v.ft] \subset [u.dt, u.ft]$ $\implies$ $v$ discendente di $u$ in un albero DF.

Alternativamente posso affermare che prendendo due vertici del grafo e analizzando i loro intervalli ho che:
- _se un intervallo è completamente incluso nell'altro allora c'è una relazione di ascendenza/discendenza tra di essi_;
- _se gli intervalli sono completamente disgiunti allora non c'è alcuna relazione di ascendenza/discendenza_.

Come corollario, allora, ho che **$v$ è un discendente del vertice $u$ nella foresta DF per un grafo $G$ $\iff$ $u.dt < v.dt < v.ft < u.ft$**.

Questo criterio di appartenenza o meno a una discendenza a seconda degli intervalli è _paragonabile al criterio delle parentesi ben formate in un'espressione matematica_, anche detto **teorema delle parentesi**.

#### Grafi orientati
Se si applica la DFS su grafi orientati si possono ottenere tante altre proprietà, in particolare per ogni coppia di vertici $(u, v)$ si possono avere 3 casi:
1. se $[u.dt, u.ft] \subset [v.dt, v.ft]$ $\implies$ l'arco $(u, v)$ è **all'indietro**, infatti $u$ è discendente di $v$ per il teorema delle parentesi;
2. se $[v.dt, v.ft] \subset [u.dt, u.ft]$ $\implies$ l'arco $(u, v)$ è **in avanti**, infatti $u$ è ascendente di $v$ per il teorema delle parentesi;
3. $v.ft < u.dt$ $\implies$ l'arco $(u, v)$ è **di attraversamento a sx**.

![[dfs-grafo-orientato.png]]

<u>Nota bene</u>: _non è possibile avere archi $(u, v)$ di attraversamento a dx_. Questo perché se $(u, v)$ fosse un arco di attraversamento a dx vorrebbe dire che $u.ft < v.dt$; allora $u$ sarebbe visitato prima di $v$, ed esistendo $(u, v)$ allora $v$ si raggiungerebbe da $u$ come vertice adiacente inesplorato, per cui ne sarebbe discendente, il che contraddice l'ipotesi $u.ft < v.dt$ per il teorema delle parentesi.

<u>Nota bene</u>: di fatto, un arco di attraversamento a sx collega un nodo "nuovo" con uno vecchio, già esplorato (`black`), ossia il presente con il passato; invece, un ipotetico arco di attraversamento a dx collegherebbe un nodo vecchio a uno nuovo, ossia il passato con il presente, il che è quindi impossibile perché allora il nodo vecchio dovrebbe essere un ascendente del nuovo.

<u>Osservazione</u>: un arco all'indietro porta un discendente verso un suo ascendente, creando per definizione un _ciclo_.

Come corollario di questa osservazione si ha che **in un grafo orientato esiste un ciclo $\iff$ esiste un arco all'indietro nel grafo prodotto da una visita DFS**.

### Applicazioni
Viste le proprietà di questa visita ci concentriamo sulle applicazioni reali.
- [[dag-verifica|verifica dei DAG]]
- [[ordinamento-topologico|ordinamento topologico]]
- [[componenti-connesse|componenti connesse]]

## Referenze
- appunti scientificamente accurati [qui](https://disi.unitn.it/~montreso/asd/appunti/argomenti/09-grafi.pdf)