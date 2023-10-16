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

		return 1;
	} else return 0;
}

int main() {
	int continueD, decision;
	int newElement;
	
	do {
		mostraPilha();
		
		printf("\nDeseja adicionar/retirar numeros a pilha? Sim: 1, Nao: 0 - ");
		scanf("%d", &continueD);
		
		if (continueD) {
			printf("Remover ou Adicionar um numero? Adicionar: 1, Remover: 0 - ");
			scanf("%d", &decision);
			if (decision) {
				printf("Digite o numero a ser adicionado a seguir: ");
				scanf("%d", &newElement);
				push(newElement);
			} else 
				pop();
		}
	
	} while (continueD);
	
	return 0;
}
