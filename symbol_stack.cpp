#include "includes.h"

Stack_s * init(int size)
{
	Stack_s * s = (Stack_s *)malloc(sizeof *s);
	s->sp = -1;
	s->a = (ITEM *)malloc(size*sizeof(int));
	s->size = size;
	return s;
}
void empty(Stack_s * sptr)
{
	free(sptr->a);
	sptr->sp = -1;
	sptr->size = 0;
}
int IsEmpty(Stack_s * s)
{
	if (s->sp == -1)
	{
		return 1;
	}
	return 0;
}
int IsFull(Stack_s * s)
{
	if (s->sp == s->size)
	{
		return 1;
	}
	return 0;
}
void push(Stack_s * s,ITEM item)
{
	if (!IsFull(s))
	{
		s->a[++s->sp] = item;
		return;
	}
	printf("FULL\n");
	while(1);
}
ITEM pop(Stack_s * s)
{
	if (!IsEmpty(s))
	{
		return s->a[s->sp--];
	}
	printf("stack is Empty.");
	while (1);
}
ITEM top_of(Stack_s * s)
{
	if (!IsEmpty(s))
	{
		return s->a[s->sp];
	}
	printf("Empty.");
	while (1);
}
