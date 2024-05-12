#ifndef _SQLIST_H_
#define _SQLIST_H_

#include<stdio.h>

#include"../../Status/src/Status.h"

#define INIT_LIST_SIZE 100
#define INCREMENT 10

typedef struct {
	ElemType* elem;
	int length;
	int listSize;
}SqList;

Status InitList(SqList* L);

Status DestroyList(SqList* L);

Status ClearList(SqList* L);

int ListLength(SqList L);

Status ListEmpty(SqList L);

Status InsertList(SqList* L, int i, ElemType e);

int LocateList(SqList L, ElemType e,Status(Compare(ElemType,ElemType)));

Status GetElem(SqList* L, int i, ElemType* e);

Status PriorElem(SqList* L, ElemType cur_e, ElemType* e);

Status NextElem(SqList* L, ElemType next_e, ElemType* e);

Status DeleteElem(SqList* L,int i, ElemType* e);

void ListTraverse(SqList L, ElemType(Visit)(ElemType e));


#endif // !_SQLIST_H_
