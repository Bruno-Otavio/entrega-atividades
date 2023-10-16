#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define BUFFER 256

FILE *data, *output;

char dataFileName[] = "esquerda.in.txt";
char outputFileName[] = "esquerda.out.txt";

int main() {
    setlocale(LC_ALL, "");

    char text[BUFFER];

    data = fopen(dataFileName, "r");
	output = fopen(outputFileName, "w");


    if (data == NULL) {
        printf("Error - Couldn't open '%s'", dataFileName);
        return 1;
    }

    if (output == NULL) {
        printf("Error - Couldn't open '%s'", outputFileName);
        return 1;
    }
    
	char positions[] = {'N', 'L', 'S', 'O'};
    char personDirection = 0; // 0 por ser a posição inicial do array positions

    int numDirections = 1;
	char directions[numDirections];
	
	int i;
	do {
		fscanf(data, "%d", &numDirections);
		fscanf(data, "%s", &directions);
		
		if (numDirections == 0)
			break;

		personDirection = 0;
		
		for (i = 0; i < numDirections; i++) {
			if (directions[i] == 'E') {
				if (personDirection == 0) // Se a pessoa estiver virada para o norte e virar para a esquerda
					personDirection = 3; // Ultima posição do array positions 
				else
					personDirection--;
			} else {
				if (personDirection == 3) // Se a pessoa estiver virada para o Oeste e virar para a direita
					personDirection = 0; // Posição inicial do array
				else
					personDirection++;
			}
   		}
   		
   		fprintf(output, "%c\n", positions[personDirection]);
	} while (numDirections != 0);

    fclose(data);
    fclose(output);

    return 0;
}
