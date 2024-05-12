#include"SqList.h"


void PrintElem(ElemType e) {
	printf("%d\t", e);
}

// 判断data>e是否成立
Status CmpGreater(ElemType data, ElemType e) {
	return data > e ? TRUE : FALSE;
}

int main() {
	int priorElem=40;
	int nextElem=30;
	int locateElem = 50;
	SqList L;
	InitList(&L);
	//DestroyList(&L);
	for (int i = 1; i < 10; i++)
	{
		InsertList(&L, i, i*10);
	}

	ListTraverse(L, PrintElem);
	ElemType elem = 2;
	
	for (int i = 1; i <= L.length; i++)
	{
		if (PriorElem(&L, i*10, &elem) == TRUE) {
			printf("%d的前驱是%d\t\n", i*10, elem);
		}
		else {
			printf("%d没有前驱\n", i);
		}
	}
	printf("\n");
	for (int i = 1; i <= L.length; i++)
	{
		if (NextElem(&L, i*10, &elem) == TRUE) {
			printf("%d的后继是%d\t\n", i*10, elem);
		}
		else {
			printf("%d没有后继\n", i*10);
		}
	}

	if (DeleteElem(&L, 2, &elem) == TRUE) {
		printf("成功删除第%d个元素%d\n", 2, elem);
	}
	else {
		printf("删除第%d个元素失败!\n", 2);
	}
	ListTraverse(L, PrintElem);

	if (GetElem(&L, 3, &elem) == TRUE) {
		printf("表中位序3的元素是%d\n", elem);
	}
	else
	{
		printf("表中不存在位序为3的元素\n");
	}

	int order = LocateList(L, locateElem, CmpGreater);
	if (order > 0) {
		printf("表中比%d大位序是%d\n", locateElem,order);
	}
	else {
		printf("表中不存在%d", locateElem);
	}

	ListTraverse(L, PrintElem);
	printf("Length of List:%d\n", L.length);
	printf("InitSize of List:%d\n", L.listSize);



}