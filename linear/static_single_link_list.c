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
		int p = S; //ָ��A��ĳ���ڵ�ǰ�Ľڵ�
		int k = space[S].cur;//ָ��Aĳ���ڵ��ָ��
		while (k !=space[r].cur&&space[k].data!=b ) //�ж�ʱ��space[r].cur ����Ϊ������Ԫ��
		{
			p = k;
			k = space[k].cur;
		}
		if (k == space[r].cur)//���ڱ��в���r��ָ�ڵ�֮����r���ֲ��䣬��������A����Ԫ��
		{
			int i = Malloc_SL(space);
			space[i].data = b;
			space[i].cur = space[r].cur;
			space[r].cur = i;//����������A��û�е�Ԫ��
		}
		else
		{
			space[p].cur = space[k].cur;
			Free_SL(space, k);
			if (r == k) r = p;//ɾ������r �޸�βָ��
		}
		ListTraverse_SL(space);
	}

	return 0;
}