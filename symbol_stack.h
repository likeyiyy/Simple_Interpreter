#ifndef SYMBOL_STACK_H
#define SYMBOL_STACK_H
//extern Stack_s * Opcode;
//假如根据type能确定是一个运算符，那么根本没有必要让value等于符号。
typedef struct __stack
{
	int sp;
	int size;
	ITEM * a;
}Stack_s;
extern Stack_s * Answer,*Opcode;
Stack_s * init(int size);
void empty(Stack_s * sptr);
int IsEmpty(Stack_s * s);
int IsFull(Stack_s * s);
void push(Stack_s * s,ITEM item);
ITEM pop(Stack_s * s);
ITEM top_of(Stack_s * s);

#endif

