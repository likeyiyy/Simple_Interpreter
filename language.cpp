#include "includes.h"
int main()
{
	Answer = init(255);
	Opcode = init(255);
	CreatHashTable(&symbol,257);
	char line[1000] = "********(5+6)*(7+4) ";
	while(1)
    {
        printf(">>>");
        gets(line);
        if(line[0] == '\0')
            continue;
        if(strcmp(line,"exit")==0)
            break;
        CreatItemStream(line);
        line_calc(stream.items,stream.size);
        PrintHashTable(symbol);
    }
	return 0;
}
