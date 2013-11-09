#ifndef ERROR_H
#define ERROR_H
#define SYNTAX_ERROR    -1
#define NOT_SUPPORT		-2
#define HASH_NOT_FIND   -3
void ErrorStdout(const char * s,char * line,int i);
int IsEndSymbol(char c);
#endif
