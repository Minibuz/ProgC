#include <stdio.h>

int main(int argc, char* argv[]){
	FILE * file_to_read;
	int current_character=0;

	argc--;

	file_to_read = fopen("./exercice_5.c", "r");
	if(file_to_read == NULL)
	{
		printf("Error : Cannot open %s\n",argv[0]);
	}
	printf("Error : Cannot open %s\n",argv[0]);
	while(!feof(file_to_read))
	{
		current_character = fgetc(file_to_read);
		putchar(current_character);
	}
	printf("\n");
	fclose(file_to_read);

	return 0;
}