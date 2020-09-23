#include <stdio.h>

int main()
{
  int i = 2;
  char ch;

  FILE *inputFile, *outputFile;
  inputFile = fopen("fileInput.file","r");
  outputFile=fopen("fileInput.file.crypt", "w");

  while(1)
  {
	ch = fgetc(inputFile);
	if(ch==EOF)
	    break;
	else
	{
	    if(i % 2 == 0 && i % 5 != 0)
                ch += 35 - i;
	    if(i % 5 == 0 && i % 2 != 0)
                ch += 31 + i;
            else
                ch += i;
  	    fputc(ch, outputFile);
	}
	i++;
  }
  fclose(inputFile);
  fclose(outputFile);
  remove("fileInput.file");
  return 0;
}
