---
tags:
  - category/note
  - status/finished
  - topic/algoritmi-e-strutture-dati
date: 19-04-2024 12:32:17
links:
  - "[[lecture-15042024091754|Lecture 15042024091754]]"
---
# Codifica di Huffman
---
## Introduzione
Nell'ambito della [[rappresentazione-dell-informazione|rappresentazione dell'informazione]] si vuole cercare una [[codifica-dei-caratteri|codifica dei caratteri]] efficiente, ovvero _in grado di rappresentare una qualunque stringa usando il minor numero possibile di bit_.

Per cui il problema che ci poniamo è il seguente: data una sequenza $c_{1}, \cdots, c_{n}$ di caratteri, definire una [[funzione-matematica|funzione]] $f$ che minimizza la lunghezza della codifica $f(c_{1}), \cdots, f(c_{n})$. In particolare $f$ è una _funzione di codifica_ $f(c) = x$ dove:
- $c$ è un carattere dell'alfabeto $\Sigma$
- $x$ è una rappresentazione binaria del carattere $c$

Inoltre, data una qualsiasi codifica dev'essere <u>sempre</u> possibile decodificarla durantela lettura sequenziale _bit-dopo-bit_.

### Codifiche statiche
Tra le codifiche standard si hanno le codifiche statiche, ovvero che assegnano ad ogni carattere $c$ un numero costante di bit. Tra queste rientra la [[ascii|codifica ASCII]] che per $n$ caratteri usa $8n$ bit, e quella ternaria che ne usa $3n$.

### Codifiche a lunghezza variabile
E se invece assegnassimo un numero variabile di bit per carattere? Per la lettera `a` potremmo usare un codice di un 1 bit; per la `b` di 2 bit, e così via.

Codici di questo tipo rientrano nella categoria di quelli detti "a prefisso", tali per cui vale che **nessun codice è un prefisso di un altro codice**: questa condizione è infatti fondamentale per rispessate il vincolo sulla decodifica sequenziale _bit-dopo-bit_!

La codifica di Huffman consiste proprio nell'implementare una codifica "a prefisso" secondo uno specifico criterio: _euristica sulla frequenza dei caratteri_.

## Codifica
L'idea è di rappresentare i codici "a prefisso" attraverso [[albero-binario|alberi binari]], tali che:
1. **ogni carattere è foglia**, infatti non può essere nodo altrimenti farebbe da prefisso a un altro carattere;
2. **ogni carattere appare nell'albero ad un'altezza inversamente proporzionale alla sua frequenza nell'alfabeto**;

Con questi due vincoli siamo in grado di costruire un albero di Huffman che, _sulla base di una tabella delle frequenze di ogni carattere, minimizza il numero di bit della funzione di codifica $f$_.

Infatti **i caratteri che appaiono più frequentemente saranno più in cima nell'albero**, perciò (si veda dopo perché) **saranno rappresentati da meno bit**.

### Algoritmo
Ci serve anzitutto un [[dizionario|dizionario]] che associ ad ogni carattere la sua frequenza. Per esempio si veda la seguente tabella:
![[codici-di-huffman.png]]

A partire da essa è possibile costruire l'albero di Huffman seguendo questi semplici passaggi:
1. costruisco una lista _ordinata_ di nodi in cui ogni nodo contiene il carattere e la sua frequenza;
2. rimuovo i due nodi con _frequenze minori_;
3. li collego a un nodo padre etichettato con la frequenza combinata (sommata);
4. ripeto gli step 2-4 fino a quando non resta un solo nodo nella lista;

Il nodo ultimo della lista non è che la radice dell'albero di Huffman. Si noti quindi come l'approccio utilizzato dall'algoritmo per generare l'albero è quello tipico degli [[algoritmi-greedy|algoritmi greedy]]: _scegliendo sempre i nodi con frequenza minore, e combinandoli per formare un nodo con le frequenze sommate, otteniamo la soluzione ottimale globale_.

A questo punto il codice è semplice da comporre a partire dalla radice:
- `left` --> `0`;
- `right` --> `1`.

Si veda come esempio il seguente albero, risultato dell'algoritmo a partire dalla tabella delle frequenze sopra riportata:
![[albero-di-huffman.png]]

### Implementazione
Lo step 2 dell'algoritmo richiede, da una lista, di trovare un elemento minore rispetto a una chiave (in questo caso la frequenza). Allora useremo le [[coda-con-priorita|code con priorità]] per farlo! Di fatto vogliamo togliere i minori e aggiungere un nuovo nodo che come chiave ha la somma delle frequenze dei due minori rimossi: il tutto _mantenendo l'ordine decrescente della lista rispetto alla frequenza_.

```R
Huffman(real f[1..n], char c[1..n]) → Tree
	Q ← new MinPriorityQueue();
	integer i;
	for i ← 1 to n do
		z ← new TreeNode(f[i], c[i]);
		Q.insert(f[i], z);
	endfor
	for i ← 1 to n – 1 do
		z1 ← Q.findMin();
		Q.deleteMin();
		z2 ← Q.findMin();
		Q.deleteMin();
		z ← new TreeNode(z1.f + z2.f, '');
		z.left ← z1;
		z.right ← z2;
		Q.insert(z1.f + z2.f, z); 
	endfor
	return Q.findMin();
```

Il [[complessita-computazionale|costo computazionale]] della funzione si concentra per lo più sul primo `for`. Questo richiede infatti di fare per $n$ volte l'operazione di `insert` di una coda con priorità; l'`insert` costa $\log{n}$, per cui il costo complessivo della funzione sarà $O(n\log{n})$[^1].

## Referenze
[^1]: questo assumendo di star lavorando su [[d-heap|d-heap]]