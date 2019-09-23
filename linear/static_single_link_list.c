#include <stdio.h>
#define MAXSIZE 100

typedef struct
{
	char data;
	int cur;
}component, SLinkList[MAXSIZE];

static void InitSpaceSL(SLinkList space)
{
	for (int i = 0; i < MAXSIZE - 1; i++)space[i].cur = i + 1;
	space[MAXSIZE - 1].cur = 0;
}
int Malloc_SL(SLinkList space)
{
	int i = space[0].cur;
	if (space[0].cur) space[0].cur=space[i].cur;
	return i;
}
int Free_SL(SLinkList space, int k)
{
	space[k].cur = space[0].cur;
	space[0].cur = k;
}
void ListTraverse_SL(SLinkList space)
{
	int i = space[1].cur;
	while (i)
	{
		printf(" %d %c %d ",i, space[i].data,space[i].cur);
		i = space[i].cur;
	}
	printf("\n");
}
int _2main()
{
	//char A[6] = { 'c','b','e','g','f','d' };
	//char B[4] = { 'a','b','n','f'};

	char A[6] = { 'g','b','e','p','r','d' };
	char B[4] = { 'a','d','n','e'};
	SLinkList space;
	InitSpaceSL(space);
	int m = 6;
	int n = 4;
	int S = Malloc_SL(space);
	int r = S;
	for (int j = 0; j < m; j++)
	{
		int i = Malloc_SL(space);
		space[i].data = A[j];
		space[r].cur = i;
		r = i;
	}
	space[r].cur = 0;
	ListTraverse_SL(space);
	
	for (int j = 0; j < n; j++)
	{
		int b = B[j];
		int p = S; //指向A的某个节点前的节点
		int k = space[S].cur;//指向A某个节点的指针
		while (k !=space[r].cur&&space[k].data!=b ) //判断时用space[r].cur 是因为会新增元素
		{
			p = k;
			k = space[k].cur;
		}
		if (k == space[r].cur)//不在表中插入r所指节点之后，且r保持不变，用于区分A集合元素
		{
			int i = Malloc_SL(space);
			space[i].data = b;
			space[i].cur = space[r].cur;
			space[r].cur = i;//这里新增了A中没有的元素
		}
		else
		{
			space[p].cur = space[k].cur;
			Free_SL(space, k);
			if (r == k) r = p;//删除的是r 修改尾指针
		}
		ListTraverse_SL(space);
	}

	return 0;
}