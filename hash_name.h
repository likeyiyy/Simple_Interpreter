#ifndef HASH_NAME_H
#define HASH_NAME_H
#define INT_TYPE	 0
#define DOUBLE_TYPE  1
#define STRING_TYPE  2 //把字符视为string？？？？
#define OPCODE_TYPE  3
#define INVAILD_TYPE 4
//1.你定义了多少种行为？
//答：只有赋值和计算。
//计算就是表达式。
//赋值就是赋值。
//等式右边进行栈运算。
//假如有等于号，则把计算结果赋给左边。
//假如没有等于号，则把计算结果输出到缓冲。
//屏幕输出，我设为变量stdout。
//匿名变量，也就是直接量，命名为直接量。
typedef struct __hashhead HASH_HEAD;
struct __hashhead
{
	ITEM item;
	struct __hashhead * next;
};
typedef struct
{
	HASH_HEAD * hash_s;
	size_t size;
}HASH;
extern HASH symbol;
void CreatHashTable(HASH * symbol_ptr,size_t size);
int IsInHashTable(HASH symbol,char * keyname);
ITEM FindHashTable(HASH symbol,char * keyname);
void InsertHashTable(HASH symbol,ITEM item);
int ChangeHashTable(HASH symbol,ITEM item);
void PrintHashTable(HASH symbol);
#endif
