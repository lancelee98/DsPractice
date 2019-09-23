
#include <stdio.h>
#include <malloc.h>

/**
 * C 语言: 单向链表
 */

 // 单向链表的“节点”
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode,*LinkList;



static void ListTraverse(LNode* head)
{
	int e = 0;
	LNode* p = head->next;
	while (p)
	{
		e = p->data;
		p = p->next;
		printf("e=%d  ", e);
	}
		printf("\n");
}

//获取链表第i个位置的元素的值到e
static int GetElem(LNode* L, int i, int* e)
{
	LNode* p = L->next; int j = 1;
	while (p && j < i)
	{
		p = p->next; ++j;
	}
	if (!p || j > i) return 0;
	*e = p->data;
	return 1;
}

static LNode* CreateList(int n)
{
	LNode* head = (LNode*)malloc(sizeof(LNode));
	head->next = NULL;
	for (int i = 20+n; i >0; i-=2)
	{
		LNode* p = (LNode*)malloc(sizeof(LNode));
		p->data = i;
		p->next = head->next; head->next = p;
	}
	return head;
}

int ListInsert(LNode* head, int i, int e)
{ 
	LNode* p = head; int j = 0;
	while (p && j < i - 1)
	{
		p = p->next; j++;
	}
	if (!p || j > i - 1)
		return 0;
	else
	{
		LNode* t = (LNode*)malloc(sizeof(LNode));
		t->next = p->next;
		t->data = e;
		p-> next=t;
	}
	return 1;
}

int ListDelete(LNode* head, int i, int* e)
{
	LNode* p = head; int j = 0;
	while (p->next && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || j > i - 1)
		return 0;
	else
	{
		LNode *t = p->next;
		*e = t->data;
		p->next = t->next;
		free(t);
		return 1;
	}
}
LNode* MergeList(LNode* La, LNode* Lb)
{
	LNode* pa = La->next;
	LNode* pb = Lb->next;
	LNode* pc = La;
	LNode* Lc = pc;
	while (pa && pb)
	{
		if (pa->data <= pb->data)
		{
			pc->next = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;	
			pb = pb->next;
		}
		pc = pc->next;
	}
	pc->next = pa ? pa : pb;
	return Lc;
}


void _1main()
{
	// 单向链表的“表头”
	LNode* phead = NULL;
	int e = 0;
	phead=CreateList(0);
	ListTraverse(phead);
	GetElem(phead, 3, &e);
	ListInsert(phead, 11, 23);
	ListDelete(phead, 14, &e);
	ListTraverse(phead);

	LNode* ListA = CreateList(1);
	LNode* ListB = CreateList(2);
	LNode* ListC = NULL;
	ListTraverse(ListA);
	ListTraverse(ListB);

	ListC=MergeList(ListA, ListB);
	ListTraverse(ListC);
	printf("tmp=%d\n", e);
	
}
