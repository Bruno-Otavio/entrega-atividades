#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "");
	FILE *entrada, *saida;
	
	char text[256];
	char *nome;
	int n1, n2, n3;
	float media;
	
	entrada = fopen("nomes.txt", "r");
	if (entrada == NULL)
		printf("Erro, não foi possível abrir o entrada.\n");
	else {
		fopen("resultado.txt", "w");
		
		while (fgets(text, 256, entrada) != NULL) {
			nome = strtok(text, " ");
			
			n1 = atoi(strtok(NULL, " "));
			n2 = atoi(strtok(NULL, " "));
			n3 = atoi(strtok(NULL, " "));
			
			media = (n1 + n2 + n3) / 3.0f;
			
			if (media >= 5)
				fprintf(saida, "%s %s\n", nome, "Aprovado");
			else
				fprintf(saida, "%s %s\n", nome, "Reprovado");
		}
	}

	fclose(entrada);
	fclose(saida);
	
	return 0;
}
