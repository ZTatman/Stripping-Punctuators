#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

// All punctuation marks in C programming are: 
// ! " # $ % & ' ( ) * + , - . / : ; < = > ? @ [ \ ] ^ _ ` { | } ~	


void stripPuncuators(char *str) // :(
{
	int i, j = 0;
	int len = strlen(str);

	//printf("Old: %s\n", str);
	// Loop through every char in the string.
	for(i = 0; i < len; i++)
	{	
		if (isalpha(str[i]))
			str[j++] = tolower(str[i]);
	}
	str[j] = '\0';
	//printf("New: %s\n", str);
}

int noPuncuators(char *str)
{	
	int i;
	int len = strlen(str);

	for (i = 0; i < len; i++) 
		if (!isalpha(str[i]))
			return 0;

	return 1;
}
int findDigits(char *str)
{
	int i, j = 0;
	int len = strlen(str);
	int n;
	//printf("Old: %s\n", str);
	// Loop through every char in the string.
	for(i = 0; i < len; i++)
	{	
		if (isdigit(str[i]))
		{
			str[j++] = str[i];
		}
	}
	str[j] = '\0';
	n = atoi(str);

	return n;
}

int readFile(char *fileName)
{
	
	char digitsBuffer[1023 + 1];
	char buffer[1023 + 1];
	FILE *fp;
	int n;

	// Open The Corpus Input File
	if ((fp = fopen(fileName, "r")) == NULL)
	{
		printf("Error: %s could not be opened in readFile().\n", fileName);
		return 1;
	}

	// Start scanning in all the words into the buffer
	while (fscanf(fp, "%[^\n]\n", buffer) != EOF)
	{
		printf("reading string......%s\n", buffer);

		strcpy(digitsBuffer, buffer);
		n = findDigits(digitsBuffer);
		printf("n: %d\n", n);

		stripPuncuators(buffer);
		printf("stripped......%s\n", buffer);
	}

	fclose(fp);
	return 0;
}

int main(int argc, char **argv) 
{
 

  char buffer[50];
  char fileName[1023];


  if (argc < 2)
	{
		printf("Error: 2 arguments required \n");
	}

	strcpy(fileName, argv[1]);
	

	if ( readFile(fileName) == 0)
	{
		// printf("> Enter a string: ");
	 //  	scanf("%s", buffer);

	 //  if (!noPuncuators(buffer))
	 //  {
	 //  	stripPuncuators(buffer);
	 //  	printf("String in main(): %s\n", buffer);
	 //  }
	 //  else
	 //  {
	 //  	printf("(%s) has no puncuators. \n", buffer);
	 //  }
	}

	  



 
  

  return 0;
}