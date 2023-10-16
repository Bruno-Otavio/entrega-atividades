#include <stdio.h>
#include <locale.h>

FILE *data, *output;

char dataFileName[] = "suco.in.txt";
char outputFileName[] = "suco.out.txt";

int main() {
	setlocale(LC_ALL, "");
	
	char text[8];
	
	int friends, fruits;
	int mlFruit = 50;
	float juiceFriends;
		
	data = fopen(dataFileName, "r");
	output = fopen(outputFileName, "w");
	
	if (data == NULL) {
		printf("Error - Couldn't open '%s'", dataFileName);
		return 1;
	}
	
	while (fgets(text, sizeof(text) / sizeof(text[0]), data) != NULL) {
		friends = atoi(strtok(text, " "));
		fruits = atoi(strtok(NULL, " "));
		
		if (fruits == 0 || friends == 0)
			break;
		
		juiceFriends = fruits * mlFruit / (float)(friends * 1000);
		
		fprintf(output, "%.2f\n", juiceFriends);
	}
	
	
	fclose(data);
	fclose(output);
	
	return 0;
}
