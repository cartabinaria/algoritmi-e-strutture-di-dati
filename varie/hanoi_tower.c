#include <stdio.h>
#include <stdlib.h>
#include <math.h> //compile using -lm library: $ gcc hanoi_torre.c -o hanoi.o -lm

#define DIM 10

#define push(sp, n) (*((sp)++) = (n))
#define pop(sp) (*--(sp))

//Hanoi(Stack p1, Stack p2, Stack p3, integer n)
void hanoi (int *p1, int *p2, int *p3, int n, int nome1, int nome2, int nome3, int *mossa) {
//	if (n = 1) then
	if (n == 1) {
//		p3.push(p1.pop())
		push(p3, pop(p1));

		*mossa = *mossa +1;
		printf("\t\t\t\t(%d)\tpiolo %d --> piolo %d\t( n = 1\t).\n", *mossa, nome1, nome3);
//	else
	} else {
//		hanoi(p1, p3, p2, n-1)
		printf("hanoi(p%d, p%d, p%d, n = %d)\n", nome1, nome3, nome2, n-1);
		hanoi(p1, p3, p2, n-1, nome1, nome3, nome2, mossa);
		
//		p3.push(p1.pop())
		push(p3,pop(p1));
		
		*mossa = *mossa +1;
		printf("\t\t\t\t(%d)\tpiolo %d --> piolo %d\t( n = %d\t).\n", *mossa, nome1, nome3, n);

//		hanoi(p2, p1, p3, n-1)
		printf("hanoi(p%d, p%d, p%d, n = %d)\n", nome2, nome1, nome3, n-1);
		hanoi(p2, p1, p3, n-1, nome2, nome1, nome3, mossa);
//	endif
	}
}
int main(int argc, char* argv[]) {
	//declaration
	int stack1[DIM], stack2[DIM], stack3[DIM];
	//initialize
	int *piolo1 = & stack1[0];
	int *piolo2 = & stack2[0];
	int *piolo3 = & stack3[0];

	//numero di mossa
	int mossa = 0;
	
	//numero di dischi da impilare
	int n = atoi( argv[1] );
	if(n > DIM) {
		printf("I let remember you hanoi is an algorithm in O(2^n)\n");
		printf("and u want to execute one in O(2^%d) = %d.\n", n, (int) pow(2, n) );
		printf("That means I will probably END AFTER YOU DIE BY OLD AGE... ( mission aborted! )\n");
		return -1;
	}
	
	//chiamata di funzione
	printf("\t\t\t\thanoi(p1, p2, p3, n = %d)\n", n);
	hanoi(piolo1, piolo2, piolo3, n, 1, 2, 3, & mossa);
}

