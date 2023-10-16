#include <stdio.h>
#include <locale.h>

#define BUFFER 256

int main() {
	setlocale(LC_ALL, "");
	
	FILE *data;
	char text[BUFFER];
	
	int number;

	int sum, size = 0;
	float average;
	
	data = fopen("dados.txt", "r");
	
	if (data == NULL) 
		printf("Error - Couldn't open the file\n");
	else {
		while (fscanf(data, "%d", &number) == 1) {
			sum += number;
			size++;
		}
	}
	average = sum / (float)size;
	
	fclose(data);
	
	data = fopen("dados.txt", "r");
	
	FILE *result;
	
	result = fopen("resultado.txt", "w");
	
	while ((fgets(text, BUFFER, data)) != NULL){
		fprintf(result, "Dados: %s\n", text);
	}
	fprintf(result, "Soma: %d\n", sum);
	fprintf(result, "Média: %.1f\n", average);
	
	fclose(data);
	fclose(result);
	
	return 0;
}
