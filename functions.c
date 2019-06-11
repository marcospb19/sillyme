#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


char* getNameOfUser()
{
	FILE* stream = popen("echo $USER" , "r");
	char* user = malloc(sizeof(char) * 128);
	fscanf(stream , "%[^\n]\n" , user);

	void* status = realloc(user , strlen(user));
	if (!status)
	{
		printf("Error reallocing user stream\n");
		exit(2);
	}

	pclose(stream);
	return user;
}


char* getHomePath()
{
	FILE* stream = popen("echo $HOME" , "r");
	char* home = malloc(sizeof(char) * 128);
	fscanf(stream , "%[^\n]\n" , home);

	void* status = realloc(home , strlen(home));
	if (!status)
	{
		printf("Error reallocing home stream\n");
		exit(2);
	}

	pclose(stream);
	return home;
}

