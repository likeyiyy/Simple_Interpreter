#ifndef HASH_NAME_H
#define HASH_NAME_H
#define INT_TYPE	 0
#define DOUBLE_TYPE  1
#define STRING_TYPE  2 //���ַ���Ϊstring��������
#define OPCODE_TYPE  3
#define INVAILD_TYPE 4
//1.�㶨���˶�������Ϊ��
//��ֻ�и�ֵ�ͼ��㡣
//������Ǳ��ʽ��
//��ֵ���Ǹ�ֵ��
//��ʽ�ұ߽���ջ���㡣
//�����е��ںţ���Ѽ�����������ߡ�
//����û�е��ںţ���Ѽ�������������塣
//��Ļ���������Ϊ����stdout��
//����������Ҳ����ֱ����������Ϊֱ������
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
