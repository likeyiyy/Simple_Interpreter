#ifndef CALCULATE_H
#define CALCULATE_H
#define ADD			0
#define SUB			1
#define MUL			2
#define DIV			3
#define MOD         4
#define LBrackets	5
#define RBrackets   6
#define ASSIGN      7

#define IS_IDLE			0
#define IS_NAME_START	1
#define IS_NUM			2
#define IS_DOUBLE		3
#define IS_STRING       4
typedef unsigned char TYPE;
typedef struct ITEM_t ITEM;
struct ITEM_t
{
	char * name;
	int type;
	int size;
	void * value;
};
typedef struct __ItemStream
{
	ITEM * items;
	size_t size;
}ITEMSTREAM;
extern char Priority[7];
extern ITEMSTREAM stream;
ITEM Core_computer(ITEM a,ITEM b,char opcode);
ITEM Evaluation(ITEM * item,size_t N);
void CreatItemStream(char * line);
ITEM line_calc(ITEM * ItemStream,size_t N);
ITEM MakeNewItem(char * name,TYPE type,size_t size,void * value);
void PrintItem(ITEM value_t);
int OpcodeTOInt(char op);
void ItemPrint(ITEM item);
#endif
