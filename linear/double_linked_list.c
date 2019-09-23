#include<stdio.h>
#include<malloc.h>
typedef struct DuLNode
{
	int data;
	struct DuLNode* prior;
	struct DuLNode* next;
}DuLNode,* DuLinkList;

static DuLinkList InitDuList(int n)
{
	DuLinkList head = (DuLinkList)malloc(sizeof(DuLNode));
	DuLinkList tail = head;
	head->next = head;
	head->prior = head;
	for (int i = n; i > 0; i--)
	{
		DuLinkList p= (DuLinkList)malloc(sizeof(DuLNode));
		p->data = i;
		p->next = tail->next;
		p->prior = tail;
		tail->next = p;
		tail = p;
		head->prior = tail;
	}
	return head;
}
static void ListTraverse_DuL(DuLinkList list)
{
	DuLinkList p = list;
	while (p->next != list)
	{
		printf(" %d %d %d \n", p->prior->data, p->data, p->next->data);
		p = p->next;
	}
	printf("\n");
}

static DuLinkList GetElem_DuL(DuLinkList list, int i)
{
	DuLinkList p = list;
	int j = 0;
	while (!(p->next == list) && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (p->next == list || j > i - 1)
		return NULL;
	else
		return p->next;

}
int static ListInsert_DuL(DuLinkList list, int i, int e)
{
	DuLinkList p = GetElem_DuL(list, i);
	if (!p)
		return 0;
	DuLinkList s = (DuLinkList)malloc(sizeof(DuLNode));
	if (!s) return 0;
	s->data = e;

	//在第i个节点后插入
	//s->next = p->next;
	//p->next = s;
	//s->prior = p;
	//s->next->prior = s;

	//在第i个节点前插入
	s->next = p;
	p->prior->next = s;
	s->prior = p->prior;
	p->prior = s;
	return 1;
}

int ListDelete_DuL(DuLinkList list, int i, int* e)
{
	DuLinkList p = GetElem_DuL(list, i);
	if (!p)return 0;
	else
	{
		*e = p->data;
		p->prior->next = p->next;
		p->next->prior = p->prior;
		free(p);
		return 1;
	}
}
int _3main()
{
	DuLinkList duList = NULL;
	duList=InitDuList(10);
	ListTraverse_DuL(duList);
	DuLinkList p = GetElem_DuL(duList, 3);
	ListInsert_DuL(duList, 3, 23);
	ListTraverse_DuL(duList);
	int e;
	ListDelete_DuL(duList, 5, &e);
	printf("%d \n", e);
	ListTraverse_DuL(duList);
	return 0;
}