#include <stdio.h>

int main()
{
    char ch;
    char *key = "key";
    FILE *inputFile, *outputFile;
    inputFile = fopen("inputFile.file", "r");
    outputFile= fopen("inputFile.file.crypt", "w");

    while(1)
    {
	ch = fgetc(inputFile);
	if(ch==EOF)
	   break;
	else
	   ch ^= (int)key;
	fputc(ch, outputFile);
    }
    fclose(inputFile);
    fclose(outputFile);
    remove("inputFile.file");
    return 0;
}
