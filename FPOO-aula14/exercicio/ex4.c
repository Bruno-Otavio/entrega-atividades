#include <stdio.h>

#define SIZE 6

int pilha[SIZE];
int ponteiro = 0;

// Pilha Functions

void mostraPilha() {
	printf("Pilha: \n");
	int i;
	for (i = 0; i < ponteiro; i++)
		printf("%d ", pilha[i]);
}

int pushPilha(int dado) {
	if (ponteiro < SIZE) {
		pilha[ponteiro] = dado;
		ponteiro++;

		return 0;
	} else return 1;
}

int popPilha() {
	int i;
	if (ponteiro >= 0) {
		ponteiro--;

		return 1;
	} else return 0;
}

// Fila Functions

void mostraFila() {
	printf("Fila: \n");
	int i;
	for (i = 0; i < ponteiro; i++)
		printf("%d ", pilha[i]);
}

int pushFila(int dado) {
	if (ponteiro < SIZE) {
		pilha[ponteiro] = dado;
		ponteiro++;

		return 0;
	} else return 1;
}

int popFila() {
	int i;
	if (ponteiro >= 0) {
		ponteiro--;
		for (i = 0; i < ponteiro; i++)
			pilha[i] = pilha[i+1];
		return 1;
	} else return 0;
}

// Lista Functions

struct Lista {
    int dado;
    struct Lista *prox;
};

struct Lista *inicio = NULL;
struct Lista *fim = NULL;
struct Lista *aux = NULL;

void mostraLista() {
    aux = inicio;
    printf("Lista:\n");
    while (aux != NULL) {
        printf("%d\n", aux->dado);
        aux = aux->prox;
    }
}

int pushLista(int dado) {
    aux = (struct Lista*)malloc(sizeof(struct Lista));
    if (aux == NULL)
        return 0;
    aux->dado = dado;
    aux->prox = NULL;
    if (inicio == NULL) {
        inicio = aux;
        fim = aux;
    } else {
        fim->prox = aux;
        fim = aux;
    }
    return 1;
}

int popLista() {
    if (inicio != NULL) {
        aux = inicio;
        inicio = inicio->prox;
        free(aux);
        return 1;
    } else
        return 0;
}

int slice(int index) {
    int i;
    aux = inicio;
    if (index == 0) {
        inicio = inicio->prox;
        free(aux);
        return 1;
    } else {
        for (i = 0; i < index - 1; i++) {
            aux = aux->prox;
        }
        struct Lista *aux2 = aux->prox;
        aux->prox = aux2->prox;
        free(aux2);
        return 1;
    }
    return 0;
}

// Normal Functions

void changePilha() {
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
				pushPilha(newElement);
			} else
				popPilha();
		}

	} while (continueD);
}

void changeFila() {
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
				pushFila(newElement);
			} else
				popFila();
		}

	} while (continueD);
}

void changeLista() {
    int continueD, decision, element, position;

    do {
        mostraLista();

        printf("\nDeseja adicionar/retirar elementos da lista? Sim: 1, Não: 0 - ");
        scanf("%d", &continueD);

        if (continueD) {
            printf("Adicionar ou remover um elemento? Adicionar: 1, Remover: 0 - ");
            scanf("%d", &decision);

            if (decision) {
                printf("Digite o elemento a ser adicionado: ");
                scanf("%d", &element);
                pushLista(element);
            } else {
                if (inicio == NULL) {
                    printf("A lista está vazia. Não é possível remover.\n");
                } else {
                    mostraLista();
                    printf("Digite a posição (0 para o primeiro elemento, 1 para o segundo, etc.) do elemento a ser removido: ");
                    scanf("%d", &position);
                    if (slice(position)) {
                        printf("Elemento removido com sucesso.\n");
                    } else {
                        printf("Falha ao remover o elemento. Verifique a posição.\n");
                    }
                }
            }
        }

    } while (continueD);

    while (inicio != NULL) {
        popLista();
    }
}

int main() {
    int storageType;
    printf("Qual tipo de armazenamento deseja usar? Pilha(0), Fila(1), Lista(2): ");
    scanf("%d", &storageType);

    if (storageType == 0)
        changePilha();
    else if (storageType == 1)
        changeFila();
    else if (storageType == 2)
        changeLista();

    return 0;
}
