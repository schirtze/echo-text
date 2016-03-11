#include <stdio.h>	//printf, fgets
#include <string.h>	//strcpy, strtok

#define BUFFER_SIZE 300

void parse();
void tokenize(char *str);

int main(int argc, char * argv[])
{
	parse();
	return(0);
}

void parse()
{
	char buffer[BUFFER_SIZE];
	while ( fgets(buffer, BUFFER_SIZE, stdin) != NULL ) {
		tokenize(buffer);
	}
}

void tokenize(char *buffer)
{
	int i;
	for (i = 0; i < BUFFER_SIZE; i++) {
		if ( buffer[i] == '\n' || buffer[i] == '\0' ) {
			buffer[i] = '\0';
			break;
		}
	}

	printf("[%s]\n", buffer);

	char *token = strtok(buffer, " ");
	while ( token != NULL ) {
		printf("\t->[%s]\n", token);
		token = strtok(NULL, " ");
	}
}