#include"SqList.h"


void PrintElem(ElemType e) {
	printf("%d\t", e);
}

// �ж�data>e�Ƿ����
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
			printf("%d��ǰ����%d\t\n", i*10, elem);
		}
		else {
			printf("%dû��ǰ��\n", i);
		}
	}
	printf("\n");
	for (int i = 1; i <= L.length; i++)
	{
		if (NextElem(&L, i*10, &elem) == TRUE) {
			printf("%d�ĺ����%d\t\n", i*10, elem);
		}
		else {
			printf("%dû�к��\n", i*10);
		}
	}

	if (DeleteElem(&L, 2, &elem) == TRUE) {
		printf("�ɹ�ɾ����%d��Ԫ��%d\n", 2, elem);
	}
	else {
		printf("ɾ����%d��Ԫ��ʧ��!\n", 2);
	}
	ListTraverse(L, PrintElem);

	if (GetElem(&L, 3, &elem) == TRUE) {
		printf("����λ��3��Ԫ����%d\n", elem);
	}
	else
	{
		printf("���в�����λ��Ϊ3��Ԫ��\n");
	}

	int order = LocateList(L, locateElem, CmpGreater);
	if (order > 0) {
		printf("���б�%d��λ����%d\n", locateElem,order);
	}
	else {
		printf("���в�����%d", locateElem);
	}

	ListTraverse(L, PrintElem);
	printf("Length of List:%d\n", L.length);
	printf("InitSize of List:%d\n", L.listSize);



}