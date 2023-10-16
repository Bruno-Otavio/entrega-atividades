#include <stdio.h>

#define BUFFER_SIZE 1024
#define DATA_FILE_NAME "entrada.csv"

int main() {
	FILE* data, output;
	
	char buffer[BUFFER_SIZE];
	
	int row = 0;
	int column = 0;
	
	data = fopen(DATA_FILE_NAME, "r");
	
	if (data == NULL) {
		printf("Error - Couldn't open %s", DATA_FILE_NAME);
		return 1;
	}
	
	while (fgets(buffer, BUFFER_SIZE, data)) {
		char *token;
		
		token = strtok(buffer, ";");
		
		while (token != NULL) {
			printf("%s ", token);
			token = strtok(NULL, ";");
		}
		printf("\n");
	}	
	
	fclose(data);
	
	return 0;
}
