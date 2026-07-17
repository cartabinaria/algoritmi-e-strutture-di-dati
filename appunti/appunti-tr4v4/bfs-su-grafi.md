---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 04-05-2024 16:24:29
links:
  - "[[lecture-29042024091854|Lecture 29042024091854]]"
  - "[[lecture-30042024111642|Lecture 30042024111642]]"
---
# BFS su grafi
---
## Introduzione
> La **visita in ampiezza su [[grafo|grafi]]** (o [[bfs|BFS]] su grafi) è un [[algoritmo|algoritmo]] di [[algoritmi-di-visita-su-grafi|visita]] che a partire da un vertice sorgente $s$ _esplora il grafo $G$ visitando prima i nodi adiacenti ad $s$, poi i nodi adiacenti ai nodi adiacenti ad $s$, e così via, fino a terminare i vertici del sottografo._ L'algoritmo _genera un albero BF (breadth-first)_ e fornisce informazioni addizionali sulla _distanza di ogni vertice dalla sorgente_.

## Algoritmo
Partiamo col dire che la _BFS standard non può funzionare_: non basta utilizzare una [[coda|coda]] e aggiungere in fondo i nodi adiacenti a un vertice `v`, perché _potremmo incorrere i nodi già visitati e provocare un loop_[^1].
```R
function non-visita(grafo G, nodo s) {
	coda := {s}
	while (coda ≠ ∅) {
		u = coda.dequeue()
		“visita u”
		for each “nodo v adiacente a u” {
			coda.enqueue(v)
		}
	}
}
```

### Aggiustamento
Per aggiustare la BFS allora è necessario intanto _classificare i vertici_ in:
- _inesplorati_, il vertice non è ancora stato incontrato;
- _aperti_, il vertice è in lista per l'esplorazione, è stato incontrato per la prima volta;
- _chiusi_, il vertice è stato visitato completamente, ovvero abbiamo messo in coda anche gli archi incidenti.

Quindi l'algoritmo dovrà mantenere l'_[[insieme|insieme]] di tutti i vertici aperti e chiusi $T$ e un suo [[definizione-di-essere-sottoinsieme|sottoinsieme]] $F \subseteq T$ coda di tutti i vertici aperti_: l'_esplorazione terminerà quando $F$ sarà vuota_ ($F = \varnothing$), ovvero quando tutti i vertici saranno stati chiusi.

La **struttura $T$**, ovvero l'insieme di tutti i vertici esplorati, **sarà ciò che verrà restituito dall'algoritmo**: bisogna notare molto bene che **$T \subseteq V$**! Questo perché _non è detto che il grafo $G$ sia connesso, per cui partendo dalla sorgente $s$ potremmo non arrivare a tutti i vertici_.

### Implementazione
```R
function BFS(Grafo G, vertice s) → albero {
	for each v in V {
		v.mark := false
	}
	T := s
	F := new Queue()
	F.enqueue(s)
	s.mark := true
	s.dist := 0
	while (F ≠ ∅) {
		u := F.dequeue()
		“visita il vertice u”
		for each v adiacente a u {
			if (not v.mark) {
				v.mark := true
				T := T ∪ v
				F.enqueue(v)
				v.parent := u
				v.dist := u.dist+1
			}
		}
	}
	return T
}
```

Quindi:
1. prima di tutto inizializziamo tutti i `v.mark` a `false`, perché tutti i vertici all'inizio sono inesplorati;
2. quindi inseriamo in $T$ la sorgente $s$;
3. creiamo la coda $F$ e ci inseriamo $s$;
4. settiamo `s.mark` a `true`, questo perché già inserita in $F$ (è un vertice aperto, non più inesplorato);
5. settiamo `s.dist` a `0`, perché la distanza di $s$ da se stesso è 0;
6. finché $F$ non è vuota:
	1. estraiamo dalla coda il vertice $u$ (che all'inizio sarà proprio $s$)
	2. per ogni nodo $v$ adiacente a $u$:
		1. se $v$ è inesplorato (`v.mark = false`):
			1. settiamo `v.mark` a `true`, perché è aperto, non più inesplorato;
			2. uniamo a $T$ il vertice $v$;
			3. inseriamo in coda $F$ il vertice aperto $v$;
			4. settiamo il padre di $v$ come $u$ (`v.parent = u`);
			5. settiamo la distanza di $v$ dalla sorgente come la distanza del padre $u$ + 1 (`v.dist = u.dist + 1`)
7. restituisci $T$.

Seguendo questo procedimento otteniamo in $T$ il **grafo dell'esplorazione**, che è di fatto un albero libero, detto **albero di copertura**. In $T$ infatti ci sarà l'insieme di vettori raggiungibili da $s$ e di cui conosciamo:
- il _vincolo di parentela padre-figlio_;
- la _distanza da $s$_.

Per questo $T$ non è altro che un [[albero-radicato|albero radicato]] (e libero) in $s$.

<u>Nota bene</u>: i campi `v.mark` e `v.dist` sono _attributi dei vertici che DEVONO essere supportati per poter implementare questa visita_. Di fatto si utilizza una struttura ben precisa per implementare l'[[array|array]] di vertici $V$ per la BFS, detta **parent vector**, che _ad ogni nodo associa l'indice del padre_.

### Costo computazionale
Il [[complessita-computazionale|costo]] complessivo dell'algoritmo deriva fondamentalmente da:
- il primo `for` che marca tutti i vertici a `false`;
- il `while` e il `for` dentro di esso.

Il primo `for` sappiamo avere costo computazionale $\Theta(n)$, dove $n = |V|$.

Il `while` estrae i vertici, e ogni vertice può essere estratto una sola volta, per cui ha costo $O(n)$ (non $\Theta(n)$ perché $G$ potrebbe non essere connesso). Il `for` dentro di esso scorre tutti gli archi di un vertice, per cui al massimo farà $n-1$ cicli, ovvero ancora $O(n)$: **un'analisi naive allora concluderebbe che il costo complessivo dell'algoritmo è $\Theta(n) + O(n) \cdot O(n) = O(n^{2})$**, il che non è scorretto, ma sicuramente _impreciso_.

Per avere un costo più preciso dobbiamo studiare meglio il comportamento del `while` e del `for` al suo interno. In effetti quel `while` complessivamente scorre per ogni vertice le sue adiacenze, ovvero gli archi di ogni vertice: in totale il `while` (con il `for` annesso) avrà un costo massimo pari al numero di archi del grafo, ossia $O(m)$. Quindi considerando anche il primo `for` si ottiene $O(n) + O(m) = O(n + m)$.

Ma attenzione: _abbiamo assunto che le adiacenze di un vertice fossero esclusivamente gli archi a cui esso è connesso_, ma questo **dipende da come è implementata la funzione del grafo `archiIncidenti`**, e quindi in generale da come è implementato il grafo.

Infatti:
- con un grafo implementato con _[[lista-di-adiacenza|liste di adiacenza]] si ha costo $O(n) + O(m) = O(n + m)$_;
- con un grafo implementato con _[[matrice-di-adiacenza|matrici di adiacenza]] si ha invece un costo $O(n^{2})$_, perché la funzione `archiIncidenti` restituisce anche i "non-archi", quindi $n$ archi per ogni vertice.

In breve: il costo dipende dall'implementazione.

## Importanza
La BFS sui grafi consente principalmente di _trovare i cammini di lunghezza minima da un nodo $v$ alla sorgente $s$_.
Infatti la combinazione delle due proprietà raccolte dall'albero risultante $T$ ci consentono, per ogni nodo, di **poter risalire di padre in padre fino ad arrivare alla radice/sorgente nel cammino minore possibile**.

### Proprietà
Le proprietà della visita BFS si riassumono in:
- _visita i nodi a distanze crescenti dalla sorgente_ --> prima visita i nodi a distanza $k$, poi i nodi a distanza $k+1$;
- _genera un albero BF_ (breadth-first);
- _calcola la distanza minima da $s$ a tutti i vertici raggiungibili da esso_.

### Sub-algoritmi
Proprio per queste caratteristiche la visita BFS consente ad altri algoritmi di implementarsi con facilità.

#### `print-path`
L'algoritmo [[ricorsione|ricorsivo]] `print-path`, a seguito di una visita BFS, _scorre i padri di un vertice $v$ fino ad arrivare alla sorgente $s$_.
```R
function print-path(G, s, v) {
	if (v = s) {
		print s
	} else if (v.parent = nil) {
		print “no path from s to v”
	} else {
		print-path(G, s, v.parent)
		print v
	}
}
```
[^2]

Un'applicazione reale di un simile algoritmo consiste per esempio nel _trovare la strada con meno corridoi possibili per uscire da un labirinto_: una volta "tradotto" il labirinto in un grafo e applicata la visita BFS possiamo usare _`print-path` sul vertice che rappresenta l'uscita e ottenere il percorso ottimale dalla sorgente_.

## Referenze
[^1]: l'algoritmo basico funzionerebbe solo su [[albero-libero|alberi liberi]], su cui infatti non sono presenti cicli
[^2]: notare la [[ricorsione-in-coda|ricorsione in coda]] per facilitare il lavoro al compilatore