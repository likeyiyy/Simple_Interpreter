#include "includes.h"
void ErrorStdout(const char * s,char * line,int i)
{
	puts(s);
	printf("%s at %d column\n",line,i);
	int k = 0;
	for (;k < i;k++)
	{
		printf(" ");
	}
	printf("^\n");
}
int IsEndSymbol(char c)
{
	char endsymbol[] = "=+-*/%() ";
	int i = 0;
	for (;endsymbol[i]!='\0';i++)
	{
		if (c == endsymbol[i])
		{
			return 1;
		}
	}
	return 0;
}
