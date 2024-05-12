#include "SqList.h"
#include<stdlib.h>
Status InitList(SqList* L)
{
	L->elem = (ElemType*)malloc(INIT_LIST_SIZE * sizeof(ElemType));
	if (L->elem == NULL)
	{
		exit(OVERFLOW);
	}

	L->length = 0;
	L->listSize = INIT_LIST_SIZE;

	return OK;
}

Status DestroyList(SqList* L)
{
	if (L->elem == NULL)
	{
		return ERROR;
	}

	free(L->elem);
	L->elem = NULL;

	L->length = 0;
	L->listSize = 0;

	return OK;
}

Status ClearList(SqList* L)
{
	L->length = 0;
	return OK;
}

int ListLength(SqList L)
{
	return L.length;
}

Status ListEmpty(SqList L)
{
	return L.length == 0 ? TRUE : FALSE;
}

Status InsertList(SqList* L, int i, ElemType e)
{
	ElemType* lastP;//最后一个元素地址
	ElemType* insertP;//插入位置元素地址
	if (i<1 || i>L->length + 1)
	{
		return ERROR;
	}
	//先不考虑扩容的情况
	insertP = &(L->elem[i - 1]);

	//从插入位置开始，元素后移
	for (lastP = &(L->elem[L->length - 1]); lastP >= insertP; lastP--)
	{
		*(lastP + 1) = *lastP;
	}

	*insertP = e;
	L->length++;

	return OK;
}

int LocateList(SqList L, ElemType e, Status(Compare(ElemType, ElemType))) {
	int i = 1;
	ElemType* p;

	if (L.elem == NULL || L.length < 1) {
		return ERROR;
	}

	p = L.elem;
	while (i <= L.length && !Compare(*p++, e)) {
		++i;
	}
	if (i < L.length) {
		return i;
	}
	else {
		return -1;
	}
}

Status GetElem(SqList* L, int i, ElemType* e) {

	if (L->elem == NULL || i < 1 || i> L->length)
	{
		return ERROR;
	}
	*e = L->elem[i - 1];
	return OK;
}


Status PriorElem(SqList* L, ElemType cur_e, ElemType* e)
{
	if (L == NULL || L->elem == NULL) {
		return ERROR;
	}

	int i;
	for (i = 0; i < L->length; i++) {
		if (L->elem[i] == cur_e)
		{
			break;
		}
	}

	if (i == 0 || i >= L->length) {
		return ERROR;
	}

	*e = L->elem[i - 1];

	return OK;
}

Status NextElem(SqList* L, ElemType cur_e, ElemType* next_e)
{
	if (L->elem == NULL || L->length < 2)
	{
		return ERROR;
	}

	int i;
	for (i = 0; i < L->length - 1; i++)
	{
		if (L->elem[i] == cur_e)
		{
			break;
		}
	}
	if (i >= L->length - 1)
	{
		return ERROR;
	}

	*next_e = L->elem[i + 1];

	return OK;
}

Status DeleteElem(SqList* L, int i, ElemType* e)
{
	ElemType* deleteP;
	ElemType* lastP;

	if (L == NULL || L->elem == NULL)
	{
		return ERROR;
	}

	if (i<1 || i>L->length)
	{
		return ERROR;
	}

	deleteP = &(L->elem[i - 1]);
	*e = *deleteP;

	lastP = &(L->elem[L->length - 1]);
	for (++deleteP; deleteP <= lastP; ++deleteP)
	{
		*(deleteP - 1) = *deleteP;
	}

	L->length--;

	return OK;
}

void ListTraverse(SqList L, ElemType(Visit)(ElemType e))
{
	for (int i = 0; i < L.length; i++)
	{
		Visit(L.elem[i]);
	}
	printf("\n");
}

