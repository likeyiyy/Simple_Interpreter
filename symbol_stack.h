#ifndef SYMBOL_STACK_H
#define SYMBOL_STACK_H
//extern Stack_s * Opcode;
//�������type��ȷ����һ�����������ô����û�б�Ҫ��value���ڷ��š�
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

