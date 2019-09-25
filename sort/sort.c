/**
**  �����㷨
**  lichuang
**  2019.09.25
**/

#include <stdio.h>
#include <malloc.h>
// ���鳤��
#define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )
#define swap(a,b) do{a=a+b;b=a-b;a=a-b;}while(0) //��������ͬʱ �ᵼ�½��Ϊ0

void show(int a[], int low,int high, char* message)
{
	printf("%s  ", message);
	for (int i = low; i < high; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//һ����������

/**
**  �������򣨲��뵽׼ȷ��λ�ã� 
**  ʱ�临�Ӷȣ��ȽϺ��ƶ���ƽ��ʱ�临�Ӷ�ΪO��n^2��  �ʺϻ�����������У���ʱ���ӶȽӽ�O��n��
**  �ռ临�Ӷȣ�O(1)
**  �ȶ��ԣ��ȶ�
**/
void InsertSort(int a[], int n)
{
	int i, j;
	for (i = 2; i <=n; i++)//�����һ���Ѿ��źã����Դӵڶ��ʼ
	{
		if (a[i] < a[i - 1])//������С�� ǰ���Ѿ��źõ����һ����źõ�����
		{
			a[0] = a[i];//0��λ��Ϊ�ڱ��ڵ�
			for (j = i - 1; a[0] < a[j]; j--)//�Ӻ� ��ǰ���Ҵ�����λ��
			{
				a[j+1] = a[j];//��¼����
			}
			a[j+1] = a[0];//���Ƶ������λ�� ��ʱa[j]�Ѿ���С��a[0]����
		}
	}
}


/**
**  �������򣨲��뵽׼ȷ��λ�ã�
**  �Ƚϸ��Ӷȣ�O��nlogn��
**  �ƶ����Ӷȣ�O(n^2) 
**  ʱ�临�Ӷ�Ϊ:O��n^2�� 
**  �ȶ��ԣ��ȶ�
**/
void BInsertSort(int a[], int n)
{
	int i, j, low, high, mid;
	for (i = 2; i <= n; i++)
	{
		a[0] = a[i];//�ڱ�Ԫ��
		low = 1; high = i - 1;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (a[mid] > a[0])
				high = mid - 1;
			else
				low = mid + 1;
		}
		for (j = i - 1; j >=high+1; j--)
			a[j + 1] = a[j];
		a[high + 1] = a[0];
	}
}

/**
**  ϣ������ ����С����������
**  �ʱ�临�Ӷȣ�O��n^2��
**  ƽ��ʱ�临�Ӷȣ�O��n^1.3��
**  �ռ临�Ӷȣ�O��1��
**  �ȶ��ԣ����ȶ� ����ͬ�ؼ��ֱ����ֵ���ͬ�ӱ�ʱ ���ܻ���ɲ��ȶ�
**/
void ShellSort(int a[], int n)
{
	//a[0] ���ݴ浥Ԫ �����ڱ�
	//���в�������Ĳ�����dk ������1
	int i, j, dk;
	for (dk = n / 2; dk >= 1; dk = dk / 2)//�����仯
	{
		for (i = dk + 1; i <= n; i++)//���Ѿ��ֺ���Ľ��в��� ���� ÿһ�鶼�������
		{
			if (a[i] < a[i - dk])//����ǰ��С�ڱ���ǰһ��
			{
				a[0] = a[i];//�ݴ���a[0]
				for (j = i - dk; j > 0 && a[0] < a[j]; j-=dk)//�ӱ����Ѿ��ź�����������ҵ����ʵĲ���λ��
					a[j + dk] = a[j];//��¼����
				a[j + dk] = a[0];//����
			}
		}
	}
	
}


//���� ��������

/**
**  ð������ÿ�ν���,�������д��һ�����ں��棩
**  �ʱ�临�Ӷȣ�O��n^2��
**  ƽ��ʱ�临�Ӷȣ�O��n^2��
**  �������µĸ��Ӷȣ�O(n) ��ʼ��������ʱ
**  �ռ临�Ӷȣ�O��1��
**  �ȶ��ԣ��ȶ�
**/
void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < n - 1 - i; j++)//�������ϸ�
		{
			if (a[j] > a[j + 1])//�˴���д�Ⱥ� ���ɲ��ȶ�������
			{
				swap(a[j], a[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0) return;//һ���˶�δ����һ�� ��������� �˳�
	}
}
void BubbleSort_m(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int flag = 0;
		for (int j = n-1; j >i; j--)//��С�����¸�
		{
			if (a[j-1] > a[j])//�˴���д�Ⱥ� ���ɲ��ȶ�������
			{
				swap(a[j], a[j-1]);
				flag = 1;
			}
		}
		if (flag == 0) return;//һ���˶�δ����һ�� ��������� �˳�
	}
}

/**
**  ����������ȡ����pivot�������ΪС��pivot���ʹ���pivot�������֣���ʱpivot���������յ�λ���ϣ�
**  ��ռ临�Ӷ�O��n��
**  ƽ���ռ临�Ӷ�O��logn��
**  �ʱ�临�Ӷȣ�O��n^2��
**  ƽ��ʱ�临�Ӷȣ�O��nlogn��
**  �ȶ��ԣ����ȶ� ����3Ϊ����{3��2��2'} ����һ������� {2',2��3}
**/
int Partition(int a[], int low, int high)//�������Ữ����������
{
	int pivot = a[low];//�������ֵ������
	while (low < high)
	{
		while (low < high && a[high] >= pivot) --high;//����λ�б�����С�� ����ѭ��
		a[low] = a[high];//����λ������С��ֵ�ŵ���λ�� 
		while (low < high && a[low] <= pivot) ++low;//����λ�б�������ֵ ����ѭ�� 
		a[high] = a[low];//����λ��������ֵ���ڸ�λ��
	}
	a[low] = pivot;//�������ֵ�ŵ���ȷ��λ����
	return low;//���������λ��
}
void QuickSort(int a[], int low, int high)
{
	if (low < high)
	{
		int pivotloc = Partition(a, low, high);
		QuickSort(a, low, pivotloc - 1);//���ζ������ӱ���еݹ�����
		QuickSort(a, pivotloc + 1, high);
	}
}

//����ѡ������ÿ��ѡ��С�ģ�

/**
**  ѡ������ÿ��ѡ��С�ģ�
**  �ռ临�Ӷ�O��1��
**  ʱ�临�Ӷȣ�O��n^2��
**  �ȶ��ԣ����ȶ� ����{2��2',1} ����һ������� {1,2',2}
**/
void SelectSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
				if (a[j] < a[min])
					min = j;
		}
		if(min!=i)
			swap(a[i], a[min]);
	}
}
/**
**  ������ÿ��ѡ��С�ģ�
**  �ռ临�Ӷ�O��1��
**  ʱ�临�Ӷȣ�O��nlogn�� ����ʱ��O��n�� ����ƽ������ʱ��O��nlogn��
**  �ȶ��ԣ����ȶ� ����{1,2��2'} �����ʼ��ʱ��2�������Ѷ� {2,1,2'} ��������Ϊ{1,2',2}
**/

//������С�Ľڵ�������·�
void AdjustDown(int a[], int k, int len)
{
	a[0] = a[k];//��a[0]�ݴ���ڵ�
	int i;
	for (i = 2 * k; i <= len; i *= 2)
	{
		if (i < len && a[i] < a[i + 1])//�ҳ������ϴ��һ��
			i++;
		if (a[0] >= a[i])break;//������ڵ㱾���ʹ� �������
		else//Ҷ�ӽڵ�Ƚϴ�
		{
			a[k] = a[i];//���ϴ��Ҷ�ӽڵ���������ڵ�
			k = i;//��ԭ��δ�����Ľϴ��Ҷ�ӽڵ��λ��Ϊ���ٽ��е��� 
		}
	}//for
	a[k] = a[0];//������ݴ�ĸ��ڵ��ֵ �ŵ����һ����������Ҷ�ӽڵ���ȥ
}
//�������
void BuildMaxHeap(int a[], int len)
{
	for (int i = len / 2; i > 0; i--)//��i=n/2��1 ����������
		AdjustDown(a, i, len);
}
//������
void HeapSort(int a[], int len)
{
	BuildMaxHeap(a, len);//���������
	show(a, 1,len, "after_build_max_heap:");
	for (int i = len; i > 1; --i)//�����һ����¼�����ѵĸ��ڵ�Ի�
	{
		swap(a[1], a[i]);
		AdjustDown(a, 1, i - 1);//�Ը��ڵ����µ��������г���Ϊi-1 ��i��Ϊ�Ѿ����кõ������
	}

}

//�Ѿ����ɴ����ʱ ��Ҫ����β�������µ�Ԫ��ʱ ��Ҫ���ϵ��� �������д��Ԫ�ص������ѵ��Ϸ���
void AdjustUp(int a[], int k)
//kΪ���ϵ����Ľ�㣬ҲΪ��Ԫ�صĸ���
{
	a[0] = a[k];
	for (int i = k / 2; i > 0 && a[i] < a[0]; i /=2) //�����ұȲ���ڵ�С�Ľڵ�
	{
		a[k] = a[i];//��˫�ױȲ���Ľڵ�С �����Ľڵ��ֵ��Ϊ˫��//˫�׽ڵ��µ�
		k = i;//�������ϱȽ�
	}
	a[k] = a[0];//���һ��������˫�׵�ֵΪ����Ľڵ��ֵ//���Ƶ�����λ��
}


void main()
{
	int i;
	int a[] = { 20,40,30,10,60,50 };
	int ilen = LENGTH(a);

	//show(a, 0, ilen, "before sort:");

	//InsertSort(a, ilen-1);
	//BInsertSort(a, ilen - 1);
	//ShellSort(a, ilen - 1);

	//BubbleSort(a, ilen);
	//BubbleSort_m(a, ilen);
	//QuickSort(a, 0, ilen-1);

	//SelectSort(a, ilen);
	//show(a, 0, ilen, "after  sort:");

	int heapArray[] = { 0,53,17,78,9,45,65,87,32 };
	int heaplen = LENGTH(heapArray);
	show(heapArray, 1, heaplen, "before sort:");
	HeapSort(heapArray, heaplen-1);
	show(heapArray, 1, heaplen, "after  sort:");
}
