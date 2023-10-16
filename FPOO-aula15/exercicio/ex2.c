#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define DATA_FILE_NAME "entrada.csv"

/*
int countLines(char *filename) {
	FILE *file = fopen(filename, "r");

	char c;
	int lines = 0;

	if (file == NULL) {
		printf("Error - Couldn't open %s", filename);
		return -1;
	}

	lines++;
	while ((c=fgetc(file)) != EOF) {
		if (c == '\n')
			lines++;
	}

	fclose(file);

	return lines-1;
}
*/
struct Person {
	int id;
	char name[32];
	char birthday[64];
	int age;
};

int main() {
	FILE *data, *output;

	char buffer[BUFFER_SIZE];

	int row = 0;
	// int column = 0;

	// int dataLines = countLines(DATA_FILE_NAME);

	// struct Person people[dataLines];
	struct Person p1;

	data = fopen(DATA_FILE_NAME, "r");
	output = fopen("saida.csv", "w");

	if (data == NULL) {
		printf("Error - Couldn't open %s", DATA_FILE_NAME);
		return 1;
	}

    const int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int curDay, curMonth, curYear;

	time_t now = time(NULL);

	struct tm local = *localtime(&now);
	curDay = local.tm_mday;
	curMonth = local.tm_mon + 1;
	curYear = local.tm_year + 1900;

	int birthYear, birthMonth, birthDay;

	fprintf(output, "id;nome;nascimento;idade\n");

	int i = 0;
	while (fgets(buffer, sizeof(buffer), data) != NULL) {
        row++;
        if (row == 1)
            continue;

		char *token = strtok(buffer, ";");

        p1.id = atoi(token);
        token = strtok(NULL, ";");

        strcpy(p1.name, token);
        token = strtok(NULL, ";");

        strcpy(p1.birthday, token);

        int birthYear = atoi(strtok(p1.birthday, "-"));
		int birthMonth = atoi(strtok(NULL, "-"));
		int birthDay = atoi(strtok(NULL, "-"));


        if (birthDay > curDay) {
			curDay += months[birthMonth-1];
			curMonth--;
		}

		if (birthMonth > curMonth) {
			curYear--;
			curMonth += 12;
		}

		p1.age = curYear - birthYear;

		fprintf(output, "%d;%s;%s;%d\n", p1.id, p1.name, p1.birthday, p1.age);
		/*
		while (token != NULL) {
			if (column == 0)
				people[i].id = atoi(token);

			if (column == 1)
				strcpy(people[i].name, token);

			if (column == 2)
                strcpy(people[i].birthday, token);

			token = strtok(NULL, ";");
			column++;
			i++;
		}
		*/
	}

	fclose(data);
	fclose(output);
/*
    i = 0;
	for (i = 0; i < dataLines; i++) {
		birthYear = atoi(strtok(people[i].birthday, "-"));
		birthMonth = atoi(strtok(NULL, "-"));
		birthDay = atoi(strtok(NULL, "-"));

		if (birthDay > curDay) {
			curDay += months[birthMonth-1];
			curMonth--;
		}

		if (birthMonth > curMonth) {
			curYear--;
			curMonth += 12;
		}

		people[i].age = curYear - birthYear;
		printf("%s: %d", people[i].name, people[i].age);
	}
*/
	return 0;
}
