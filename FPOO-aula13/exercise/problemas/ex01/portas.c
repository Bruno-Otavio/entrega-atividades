#include <stdio.h>
#include <locale.h>

#define BUFFER 100

FILE *data, *output;

char dataFileName[] = "portas.in.txt";
char outputFileName[] = "portas.out.txt";

void closeDoors(int *array) {
	int i;
	for (i = 0; i < BUFFER; i++)
		array[i] = 0;
}

int main() {
	setlocale(LC_ALL, "");
	
	int doorState[BUFFER];
	int number, position;
	int i;
	
	closeDoors(doorState);
	
	data = fopen(dataFileName, "r");
	
	if (data == NULL) {
		printf("Error - Couldn't open '%s'", dataFileName);
		return 1;
	}
	
	while (fscanf(data, "%d", &number) == 1) {
		for (i = 1; i <= BUFFER; i++) {
			position = number * i;
			
			if (doorState[position-1] == 1 && position <= BUFFER) {
				doorState[position-1] == 0;
				printf("Fechou %d %d\n", number, position);
			}
			else if (doorState[position-1] == 0 && position <= BUFFER) {
				doorState[position-1] == 1;
				printf("Abriu %d %d\n", number, position);
			}
		}
	}
	
	fclose(data);
	
	output = fopen(outputFileName, "w");
	
	if (output == NULL) {
		printf("Error - Couldn't open '%s'", outputFileName);
		return 1;
	}
	
	
	
	fclose(output);
	
	printf("Estado das portas: ");
	for (i = 0; i < BUFFER; i++) {
		printf("%d", doorState[i]);
	}
	
//  Gera os valores de input do programa
//	FILE *input;
//	input = fopen("portas.in.txt", "w");
//	
//	if (input == NULL) {
//		printf("Error - Couldn't opoen the file");
//		return 1;
//	}
//	
//	int i;
//	for (i = 1; i <= 100; i++) {
//		fprintf(input, "%d\n", i);
//	}
//	
//	fclose(input);
	
	return 0;
}
