#include <stdio.h>

#define SIZE 6

int pilha[SIZE];
int ponteiro = 0;

void mostraPilha() {
	printf("Pilha: \n");
	int i;
	for (i = 0; i < ponteiro; i++)
		printf("%d ", pilha[i]);
}

int push(int dado) {
	if (ponteiro < SIZE) {
		pilha[ponteiro] = dado;
		ponteiro++;
		
		return 0;
	} else return 1;
}

int pop() {
	int i;
	if (ponteiro >= 0) {
		ponteiro--;
		for (i = 0; i < ponteiro; i++)
			pilha[i] = pilha[i+1];
		return 1;
	} else return 0;
}

int main() {
	int i;
	for (i = 0; i < SIZE; i++)
		push(8+i*2);
	
	pop();
	
	mostraPilha();
	
	return 0;
}
