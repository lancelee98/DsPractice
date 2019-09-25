/**
**  排序算法
**  lichuang
**  2019.09.25
**/

#include <stdio.h>
#include <malloc.h>
// 数组长度
#define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )
#define swap(a,b) do{a=a+b;b=a-b;a=a-b;}while(0) //两个数相同时 会导致结果为0

void show(int a[], int low,int high, char* message)
{
	printf("%s  ", message);
	for (int i = low; i < high; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//一、插入排序

/**
**  插入排序（插入到准确的位置） 
**  时间复杂度：比较和移动和平均时间复杂度为O（n^2）  适合基本有序的序列，此时复杂度接近O（n）
**  空间复杂度：O(1)
**  稳定性：稳定
**/
void InsertSort(int a[], int n)
{
	int i, j;
	for (i = 2; i <=n; i++)//假设第一项已经排好，所以从第二项开始
	{
		if (a[i] < a[i - 1])//若此项小于 前面已经排好的最后一项（已排好的最大项）
		{
			a[0] = a[i];//0号位置为哨兵节点
			for (j = i - 1; a[0] < a[j]; j--)//从后 向前查找待插入位置
			{
				a[j+1] = a[j];//记录后移
			}
			a[j+1] = a[0];//复制到插入的位置 此时a[j]已经是小于a[0]的了
		}
	}
}


/**
**  插入排序（插入到准确的位置）
**  比较复杂度：O（nlogn）
**  移动复杂度：O(n^2) 
**  时间复杂度为:O（n^2） 
**  稳定性：稳定
**/
void BInsertSort(int a[], int n)
{
	int i, j, low, high, mid;
	for (i = 2; i <= n; i++)
	{
		a[0] = a[i];//哨兵元素
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
**  希尔排序 （缩小增量的排序）
**  最坏时间复杂度：O（n^2）
**  平均时间复杂度：O（n^1.3）
**  空间复杂度：O（1）
**  稳定性：不稳定 当相同关键字被划分到不同子表时 可能会造成不稳定
**/
void ShellSort(int a[], int n)
{
	//a[0] 是暂存单元 不是哨兵
	//进行插入排序的步长是dk 而不是1
	int i, j, dk;
	for (dk = n / 2; dk >= 1; dk = dk / 2)//步长变化
	{
		for (i = dk + 1; i <= n; i++)//对已经分好组的进行插入 排序 每一组都交替进行
		{
			if (a[i] < a[i - dk])//若当前项小于本组前一项
			{
				a[0] = a[i];//暂存在a[0]
				for (j = i - dk; j > 0 && a[0] < a[j]; j-=dk)//从本组已经排好序的序列中找到合适的插入位置
					a[j + dk] = a[j];//记录后移
				a[j + dk] = a[0];//插入
			}
		}
	}
	
}


//二、 交换排序

/**
**  冒泡排序（每次交换,将相邻中大的一个放在后面）
**  最坏时间复杂度：O（n^2）
**  平均时间复杂度：O（n^2）
**  最好情况下的复杂度：O(n) 初始序列有序时
**  空间复杂度：O（1）
**  稳定性：稳定
**/
void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < n - 1 - i; j++)//最大的向上浮
		{
			if (a[j] > a[j + 1])//此处若写等号 则变成不稳定的排序
			{
				swap(a[j], a[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0) return;//一整趟都未交换一次 则已排序好 退出
	}
}
void BubbleSort_m(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int flag = 0;
		for (int j = n-1; j >i; j--)//最小的向下浮
		{
			if (a[j-1] > a[j])//此处若写等号 则变成不稳定的排序
			{
				swap(a[j], a[j-1]);
				flag = 1;
			}
		}
		if (flag == 0) return;//一整趟都未交换一次 则已排序好 退出
	}
}

/**
**  快速排序（任取枢轴pivot，将其分为小于pivot，和大于pivot的两部分，此时pivot放在了最终的位置上）
**  最坏空间复杂度O（n）
**  平均空间复杂度O（logn）
**  最坏时间复杂度：O（n^2）
**  平均时间复杂度：O（nlogn）
**  稳定性：不稳定 如若3为枢轴{3，2，2'} 经过一趟排序后 {2',2，3}
**/
int Partition(int a[], int low, int high)//根据枢轴划分两个区间
{
	int pivot = a[low];//将枢轴的值存起来
	while (low < high)
	{
		while (low < high && a[high] >= pivot) --high;//若高位有比枢轴小的 结束循环
		a[low] = a[high];//将高位比枢轴小的值放到低位上 
		while (low < high && a[low] <= pivot) ++low;//若低位有比枢轴大的值 结束循环 
		a[high] = a[low];//将低位比枢轴大的值放在高位上
	}
	a[low] = pivot;//将枢轴的值放到正确的位置上
	return low;//返回枢轴的位置
}
void QuickSort(int a[], int low, int high)
{
	if (low < high)
	{
		int pivotloc = Partition(a, low, high);
		QuickSort(a, low, pivotloc - 1);//依次对两个子表进行递归排序
		QuickSort(a, pivotloc + 1, high);
	}
}

//三、选择排序（每次选最小的）

/**
**  选择排序（每次选最小的）
**  空间复杂度O（1）
**  时间复杂度：O（n^2）
**  稳定性：不稳定 如若{2，2',1} 经过一趟排序后 {1,2',2}
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
**  堆排序（每次选最小的）
**  空间复杂度O（1）
**  时间复杂度：O（nlogn） 建堆时间O（n） 向下平均调整时间O（nlogn）
**  稳定性：不稳定 如若{1,2，2'} 构造初始堆时将2交换到堆顶 {2,1,2'} 最终排序为{1,2',2}
**/

//将堆中小的节点调整至下方
void AdjustDown(int a[], int k, int len)
{
	a[0] = a[k];//用a[0]暂存根节点
	int i;
	for (i = 2 * k; i <= len; i *= 2)
	{
		if (i < len && a[i] < a[i + 1])//找出子数较大的一个
			i++;
		if (a[0] >= a[i])break;//如果根节点本来就大 无须调整
		else//叶子节点比较大
		{
			a[k] = a[i];//将较大的叶子节点调整到根节点
			k = i;//以原先未调整的较大的叶子节点的位置为根再进行调整 
		}
	}//for
	a[k] = a[0];//将最初暂存的根节点的值 放到最后一个做调整的叶子节点上去
}
//建大根堆
void BuildMaxHeap(int a[], int len)
{
	for (int i = len / 2; i > 0; i--)//从i=n/2到1 反复调整堆
		AdjustDown(a, i, len);
}
//堆排序
void HeapSort(int a[], int len)
{
	BuildMaxHeap(a, len);//建立大根堆
	show(a, 1,len, "after_build_max_heap:");
	for (int i = len; i > 1; --i)//将最后一个记录与大根堆的根节点对换
	{
		swap(a[1], a[i]);
		AdjustDown(a, 1, i - 1);//对根节点向下调整，序列长度为i-1 第i项为已经排列好的最大项
	}

}

//已经建成大根堆时 若要再其尾部插入新的元素时 需要向上调整 （将堆中大的元素调整到堆的上方）
void AdjustUp(int a[], int k)
//k为向上调整的结点，也为堆元素的个数
{
	a[0] = a[k];
	for (int i = k / 2; i > 0 && a[i] < a[0]; i /=2) //向上找比插入节点小的节点
	{
		a[k] = a[i];//若双亲比插入的节点小 则插入的节点的值改为双亲//双亲节点下调
		k = i;//继续向上比较
	}
	a[k] = a[0];//最后一个交换的双亲的值为插入的节点的值//复制到最终位置
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
