#include <stdio.h>	//printf, fgets
#include <string.h>	//strcpy, strtok

#define BUFFER_SIZE 300

void parse();
void tokenize(char *str, int entryId);

int main(int argc, char * argv[])
{
	parse();
	return(0);
}

void parse()
{
	char buffer[BUFFER_SIZE];
	int entryId = 1;
	while ( fgets(buffer, BUFFER_SIZE, stdin) != NULL ) {
		tokenize(buffer, entryId);

		if ( entryId == 8) {
			entryId = 2;
		} else {
			entryId++;
		}
	}
}

void tokenize(char *buffer, int entryId)
{
	int i;
	for (i = 0; i < BUFFER_SIZE; i++) {
		if ( buffer[i] == '\n' || buffer[i] == '\0' ) {
			buffer[i] = '\0';
			break;
		}
	}

	printf("%i:[%s]\n", entryId, buffer);

	char *token = strtok(buffer, " ");
	while ( token != NULL ) {
		printf("\t->[%s]\n", token);
		token = strtok(NULL, " ");
	}
}