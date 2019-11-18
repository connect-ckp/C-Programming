#include <stdio.h>
#include <string.h>

int main(void) {
	char stringA[250], stringB[250];
	
	printf("Enter Sting A\n");
	scanf("%s", stringA);
	printf("Enter Sting B\n");
	scanf("%s", stringB);
	
	/****************************************************************
	 * String Functions
	 ****************************************************************/	
	//strlen
	printf("The length of stringA is: %d\n", strlen(stringA));
	
	//Length of string without strlen
	int count = 0;
	while (stringA[count] != '\0')
		++count;
	
	/* strcpy() & strncpy()
	************************/
	/*  strcpy() does not check to see whether the source string actually fits in the destination string or not.
		Hence safer way to copy strings is to use strncpy(), which takes a third argument - the no. of chars to copy.
	*/
	char destString[50];
	
	strncpy(destString, stringA, sizeof(destString) - 1);
	printf("strncpy destString is: %s\n", destString);
	
	/* strcat() & strncat()
	************************/
	char sourceString[250];
	
	/* strcmp() & strncmp()
	************************/
	
	
	//Searching a string character or a substring 
	/* For character: strchr()
	 * For substring: strstr()
	************************/
	
	
	
	//Tokenizing a string - Breaking a sentence into words is called Tokenizing.
	/* strtok()
	************************/
	
	
	//Analyzing a string
	/* islower(), isupper(), isalpha(), isdigit(), isalnum(), iscntrl(), isprint(), isgraph(), isxdigit(), isblank(), isspace(), ispunct()
	**************************************************************************************************************************************/
	
	
	//Converting Strings - Upper Case, Lower Case
	/* toupper(), tolower() - return int (ACII)
	*******************************************/
	
	
	//Converting Strings to Numbers
	/* atof(), atoi(), atol(), atoll(), itoa(), strtod(), strtof(), strtold()
	*******************************************/
	return 0;
}