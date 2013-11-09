#include "includes.h"
#define VALUE(n) (*(int *)((n).value))
#define DVALUE(n) (*(double *)((n).value))
char Priority[7] = {0,0,1,1,1,2,2};
Stack_s * Answer,* Opcode;
ITEMSTREAM stream;
int OpcodeTOInt(char op)
{
	switch(op)
	{
	case '+':return 0;
	case '-':return 1;
	case '*':return 2;
	case '/':return 3;
	case '%':return 4;
	case '(':return 5;
	case ')':return 6;
	case '=':return 7;
	default:
		printf("Should not, exit now.\n");
		exit(-1);
		break;
	}
}
ITEM Core_computer(ITEM a,ITEM b,int opcode)
{
	ITEM temp;
	int sum;
	double double_sum;
	int mod_end;
	int counter;
	switch(opcode)
	{
	case ADD:
		if (a.type == INT_TYPE)
		{
			switch(b.type)
			{
			case INT_TYPE:
				sum = VALUE(b) + VALUE(a);
				return MakeNewItem(NULL,INT_TYPE,1,&sum);
				break;
			case DOUBLE_TYPE:
				double_sum =  //DVALUE(a) +(double)(VALUE(b));
                            DVALUE(b) +(double)(VALUE(a));
				return MakeNewItem(NULL,DOUBLE_TYPE,1,&double_sum);
				break;
			case STRING_TYPE:
				printf("Should not int + str, exit now.\n");
				exit(-1);
				break;
			}
		}
		else if (a.type == DOUBLE_TYPE)
		{
			switch(b.type)
			{
			case INT_TYPE:
				double_sum = (double)VALUE(b) + DVALUE(a);
				return MakeNewItem(NULL,DOUBLE_TYPE,1,&double_sum);
				break;
			case DOUBLE_TYPE:
				double_sum =DVALUE(b) +DVALUE(a);
				return MakeNewItem(NULL,DOUBLE_TYPE,1,&double_sum);
				break;
			case STRING_TYPE:
				printf("Should not int + str, exit now.\n");
				exit(-1);
				break;
			}
		}
		else if (a.type == STRING_TYPE)
		{
			switch(b.type)
			{
			case INT_TYPE:
			case DOUBLE_TYPE:
				printf("Should not int + str or double + str, exit now.\n");
				exit(-1);
				break;
			case STRING_TYPE:
				temp.name = NULL;
				temp.size = a.size + b.size;
				temp.type = STRING_TYPE;
				temp.value = (char *)malloc(temp.size);
				if(temp.value == NULL)
                {
                    printf("malloc failed\n");
                    exit(-1);
                }
				strcpy((char *)temp.value,(char *)a.value);
				strcat((char *)temp.value,(char *)b.value);
				return temp;
				break;
			}
		}
		break;
	case SUB:
		if (a.type == INT_TYPE)
		{
			switch(b.type)
			{
			case INT_TYPE:
				sum = ( - VALUE(b) + VALUE(a));
				return MakeNewItem(NULL,INT_TYPE,1,&sum);
				break;
			case DOUBLE_TYPE:
				double_sum = (-DVALUE(b) + (double)(VALUE(a)));
				return MakeNewItem(NULL,DOUBLE_TYPE,1,&double_sum);
				break;
			case STRING_TYPE:
				printf("Should not int - str, exit now.\n");
				exit(-1);
				break;
			}
		}
		else if (a.type == DOUBLE_TYPE)
		{
			switch(b.type)
			{
			case INT_TYPE:
				double_sum = -(double)VALUE(b) + DVALUE(a);
				return MakeNewItem(NULL,DOUBLE_TYPE,1,&double_sum);
				break;
			case DOUBLE_TYPE:
				double_sum = - DVALUE(b) + DVALUE(a);
				return MakeNewItem(NULL,DOUBLE_TYPE,1,&double_sum);
				break;
			case STRING_TYPE:
				printf("Should not int - str, exit now.\n");
				exit(-1);
				break;
			}
		}
		else if (a.type == STRING_TYPE)
		{
			printf("Should not int + str or double + str, exit now.\n");
			exit(-1);
		}
		break;
	case MUL:
		if (a.type == INT_TYPE)
		{
			switch(b.type)
			{
			case INT_TYPE:
				sum = VALUE(b) * VALUE(a);
				return MakeNewItem(NULL,INT_TYPE,1,&sum);
				break;
			case DOUBLE_TYPE:
				double_sum =DVALUE(b) * (double)(VALUE(a));
				return MakeNewItem(NULL,DOUBLE_TYPE,1,&double_sum);
				break;
			case STRING_TYPE:
				temp.name = NULL;
				temp.size = VALUE(a) * b.size;
				temp.type = STRING_TYPE;
				temp.value = (char *)malloc(temp.size);
				if(temp.value == NULL)
                {
                    printf("malloc failed\n");
                    exit(-1);
                }
				strcpy((char *)temp.value,(char *)b.value);
				for (counter = 0; counter < VALUE(a)-1; counter++)
				{
					strcat((char *)temp.value,(char *)b.value);
				}
				return temp;
				break;
			}
		}
		else if (a.type == DOUBLE_TYPE)
		{
			switch(b.type)
			{
			case INT_TYPE:
				double_sum = (double)VALUE(b) * DVALUE(a);
				return MakeNewItem(NULL,DOUBLE_TYPE,1,&double_sum);
				break;
			case DOUBLE_TYPE:
				double_sum =DVALUE(b) * DVALUE(a);
				return MakeNewItem(NULL,DOUBLE_TYPE,1,&double_sum);
				break;
			case STRING_TYPE:
				printf("Should not int + str, exit now.\n");
				exit(-1);
				break;
			}
		}
		else if (a.type == STRING_TYPE)
		{
			switch(b.type)
			{
			case INT_TYPE:
				temp.name = NULL;
				temp.size = a.size * VALUE(b);
				temp.type = STRING_TYPE;
				temp.value = (char *)malloc(temp.size);
				strcpy((char *)temp.value,(char *)a.value);
				for (counter = 0; counter < VALUE(b)-1; counter++)
				{
					strcat((char *)temp.value,(char *)a.value);
				}
				return temp;
			case DOUBLE_TYPE:
			case STRING_TYPE:
				printf("Should not int + str or double + str, exit now.\n");
				exit(-1);
				break;
			}
		}
		break;
	case DIV:
		if (a.type == INT_TYPE)
		{
			switch(b.type)
			{
			case INT_TYPE:
				sum = VALUE(a)/VALUE(b);
				return MakeNewItem(NULL,INT_TYPE,1,&sum);
				break;
			case DOUBLE_TYPE:
				double_sum =(double)(VALUE(a))/DVALUE(b);
				return MakeNewItem(NULL,DOUBLE_TYPE,1,&double_sum);
				break;
			case STRING_TYPE:
				printf("Should not int / str, exit now.\n");
				exit(-1);
				break;
			}
		}
		else if (a.type == DOUBLE_TYPE)
		{
			switch(b.type)
			{
			case INT_TYPE:
				double_sum = DVALUE(a)/(double)VALUE(b) ;
				return MakeNewItem(NULL,DOUBLE_TYPE,1,&double_sum);
				break;
			case DOUBLE_TYPE:
				double_sum = DVALUE(a)/DVALUE(b);
				return MakeNewItem(NULL,DOUBLE_TYPE,1,&double_sum);
				break;
			case STRING_TYPE:
				printf("Should not double / str, exit now.\n");
				exit(-1);
				break;
			}
		}
		else if (a.type == STRING_TYPE)
		{
			printf("Should not str use /. exit now.\n");
			exit(-1);
		}
		break;
	case MOD:
		if ((a.type == INT_TYPE)&&(b.type==INT_TYPE))
		{
			mod_end = (VALUE(a)%VALUE(b));
			return MakeNewItem(NULL,INT_TYPE,1,&mod_end);
		}
		else
		{
			printf("Should not mod not int, exit now.\n");
			exit(-1);
			break;
		}
		break;
	default:
		printf("Should not, exit now.\n");
		exit(-1);
		break;
	}
}
ITEM Evaluation(ITEM * item,size_t N)
{
	size_t i = 0;
	ITEM top;
	ITEM aa,bb;
	for (i = 0; i < N; i++)
	{
		if (item[i].type == OPCODE_TYPE)
		{
			if (VALUE(item[i]) == RBrackets)
			{
				while(VALUE(top = pop(Opcode)) != LBrackets)
				{
				    if(!IsEmpty(Answer))
                         aa = pop(Answer);
                    else
                        printf("syntax Error.\n");
                    if(!IsEmpty(Answer))
                         bb = pop(Answer);
                    else
                        printf("syntax Error.\n");
					push(Answer,Core_computer(aa,bb,VALUE(top)));
					if(aa.name == NULL)free(aa.value);
                    if(bb.name == NULL)free(bb.value);
				}

			}
			else if (VALUE(item[i]) == LBrackets)
			{
				push(Opcode,item[i]);
			}
			else
			{
				while((!IsEmpty(Opcode))
          &&(Priority[VALUE(item[i])] <= Priority[VALUE(top_of(Opcode))])
          &&(VALUE(top_of(Opcode)) != LBrackets))
				{
					top = pop(Opcode);
					push(Answer,Core_computer(pop(Answer),pop(Answer),VALUE(top)));
				}
				push(Opcode,item[i]);
			}
		}
		else
		{
			push(Answer,item[i]);
		}
	}
	while(!IsEmpty(Opcode))
	{
		top = pop(Opcode);
		push(Answer,Core_computer(pop(Answer),pop(Answer),VALUE(top)));
	}
	return pop(Answer);
}
void CreatItemStream(char * lin)
{
	ITEM Anonymous;//匿名
	int item_nums = 0;//item 真正的用量。
	int i = IS_IDLE;
	int state_in = 0;
	int idle_index = 0;
	int length = strlen(lin);
	char * line = (char *)malloc(length+2);
	if(line == NULL)
    {
        printf("Not zugou de gongjian \n");
        exit(-1);
    }
	strcpy(line,lin);
//////////////////////////////////////////////////////////////////////////
//下面三行代码的主要意思是在字符串末尾添加终结符。
	line[length] = ' ';
	line[length+1] = '\0';
	stream.items = (ITEM *)malloc(length*sizeof(ITEM));
	stream.size  = length;
	for (i = 0; line[i] != '\0';)
	{
		switch(state_in)
		{
		case IS_IDLE:
			idle_index = i;
			if (isdigit(line[i]))
			{
				i++;
				state_in = IS_NUM;
			}
			else if (isalpha(line[i])||line[i] == '_')
			{
				i++;
				state_in = IS_NAME_START;
			}
			else if (IsEndSymbol(line[i]))
			{
				if (!isspace(line[i]))
				{
					int op_value = OpcodeTOInt(line[i]);
					stream.items[item_nums++] = MakeNewItem(NULL,OPCODE_TYPE,1,&op_value);
				}
				i++;
			}
			else if (line[i] == '"')
            {
                i++;
				state_in = IS_STRING;
            }
			else
			{
				ErrorStdout("syntax error.Exit now.",line,i);
				exit(SYNTAX_ERROR);
			}
			break;
		case IS_NAME_START:
			if (isalnum(line[i])||line[i] == '_')
			{
				i++;
			}
			else if (IsEndSymbol(line[i]))
			{
				char * name = (char *)malloc(i - idle_index + 1);
				if (name == NULL)
				{
					printf("Sorry,malloc faild.Exit now.\n");
				}
				strncpy(name,line+idle_index,i-idle_index);
				name[i - idle_index] = '\0';
				if (!IsInHashTable(symbol,name))
				{
					Anonymous = MakeNewItem(name,INVAILD_TYPE,0,0);
					InsertHashTable(symbol,Anonymous);
				}
				else
				{
					Anonymous = FindHashTable(symbol,name);
				}
				stream.items[item_nums++] = Anonymous;
				state_in = IS_IDLE;
			}else
			{
				ErrorStdout("Not support opcode.Exit now.\n",line,i);
				exit(NOT_SUPPORT);
			}
			break;
		case IS_NUM:
			if (IsEndSymbol(line[i]))
			{
				char * num = (char *)malloc(i - idle_index);
				if (num == NULL)
				{
					printf("Sorry,malloc faild.Exit now.\n");
				}
				strncpy(num,line+idle_index,i-idle_index);
				int getnum = atoi(num);
				stream.items[item_nums++] = MakeNewItem(NULL,INT_TYPE,1,&getnum);
				state_in = IS_IDLE;
			}
			else if (isdigit(line[i]))
			{
				i++;
			}
			else if (line[i] == '.')
			{
				state_in = IS_DOUBLE;
				i++;
			}
			else
			{
				ErrorStdout("syntax error.Exit now.",line,i);
				exit(SYNTAX_ERROR);
			}
			break;
		case IS_DOUBLE:
			if (IsEndSymbol(line[i]))
			{
				char * doublenum = (char *)malloc(i - idle_index);
				if (doublenum == NULL)
				{
					printf("Sorry,malloc faild.Exit now.\n");
				}
				strncpy(doublenum,line+idle_index,i-idle_index);
				double getdouble = atof(doublenum);
				stream.items[item_nums++] = MakeNewItem(NULL,DOUBLE_TYPE,1,&getdouble);
				state_in = IS_IDLE;
			}
			else if (isdigit(line[i]))
			{
				i++;
			}
			else
			{
				ErrorStdout("syntax error.Exit now.",line,i);
				exit(SYNTAX_ERROR);
			}
			break;
        case IS_STRING:
            while(line[i] != '"')
            {
                i++;
            }
            {
                char * string_v = (char *)malloc(i - idle_index);
				if (string_v == NULL)
				{
					printf("Sorry,malloc faild.Exit now.\n");
				}
				strncpy(string_v,line+idle_index+1,i-idle_index-1);
				string_v[i-idle_index-1] = '\0';
				stream.items[item_nums++] = MakeNewItem(NULL,STRING_TYPE,i - idle_index - 1,string_v);
				i++;
				state_in = IS_IDLE;
            }
		}
	}
	stream.items = (ITEM *)realloc(stream.items,item_nums*sizeof(ITEM));
	stream.size  = item_nums;
}
ITEM line_calc(ITEM * ItemStream,size_t N)
{
	if(N > 1)
    {
        if ((VALUE(ItemStream[1]) ==  ASSIGN)&&(ItemStream[1].type == OPCODE_TYPE))
        {
            char * name_tmp = (char *)malloc(strlen(ItemStream[0].name)+1);
            strcpy(name_tmp,ItemStream[0].name);
            ItemStream[0] = line_calc(ItemStream+2,N-2);//ItemStream[0] show already changed.
            ItemStream[0].name = (char *)malloc(strlen(name_tmp)+1);
            strcpy(ItemStream[0].name,name_tmp);
            free(name_tmp);
            ChangeHashTable(symbol,ItemStream[0]);
            return ItemStream[0];
        }
        else
        {
            ITEM value_t = Evaluation(ItemStream,N);
            PrintItem(value_t);
            return value_t;
        }
    }
    else
    {
        return Evaluation(ItemStream,1);
    }
}
void PrintItem(ITEM value_t)
{
	int i = 0;
	if (value_t.type == INT_TYPE)
	{
		printf("%d\n",*(int *)value_t.value);
	}
	else if (value_t.type == DOUBLE_TYPE)
	{
		printf("%.12f\n",*(double *)value_t.value);
	}
	else if (value_t.type == STRING_TYPE)
	{
		for (i = 0; i < value_t.size; i++)
		{
			putchar(*(char *)(value_t.value + i));
		}
		printf("\n");
	}
	else
	{
		printf("I don't know why,but you are worng.\n");
		printf("name = %s\n \
			type = %d\n \
			size = %d\n \
			value = %p\n ",
			value_t.name,value_t.type,value_t.size,value_t.value);
	}
}
ITEM MakeNewItem(char * name,TYPE type,size_t size,void * value)
{
	size_t i = 0;
	ITEM item;
	if (name == NULL)
	{
		item.name = NULL;
	}
	else
	{
		int length = strlen(name) + 1;
		item.name = (char *)malloc(length);
		strcpy(item.name,name);
	}
	item.type = type;
	item.size = size;

    if ((item.type == INT_TYPE)
        ||(item.type == OPCODE_TYPE))
    {
        item.value = (int *)malloc(size*sizeof(int));
        *(int *)(item.value)  = *(int *)(value + i);
    }
    else if(item.type == DOUBLE_TYPE)
    {
        item.value = (double *)malloc(size*sizeof(double));
        *(double *)item.value = *(double *)(value + i);
    }
    else if (item.type == STRING_TYPE)
    {
        item.value = (char *)malloc(size+1);
        for(i = 0; i < size;i++)
        {
            *(char *)(item.value + i) = *(char *)(value + i);
        }
        *(char *)(item.value + i) = '\0';
    }
    else if(item.type != INVAILD_TYPE)
        printf("There is should not have other type.\n \
               but I will add some maybe.\n");

	return item;

}
void ItemPrint(ITEM item)
{
    if(item.type == 2)
    printf("[%s,%d,%d,%s]",item.name,item.type,item.size,(char *)item.value);
    else if(item.type == 1)
    printf("[%s,%d,%d,%f]",item.name,item.type,item.size,*(double *)item.value);
    else if(item.type == 0)
    printf("[%s,%d,%d,%d]",item.name,item.type,item.size,*(int *)item.value);
}
