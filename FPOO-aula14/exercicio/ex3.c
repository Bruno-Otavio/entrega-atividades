#include <stdio.h>
#include <stdlib.h>

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

int push(int dado) {
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

int pop() {
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

int main() {
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
                push(element);
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
        pop();
    }

    return 0;
}
