
#include<iostream>
#include<string>
#include<time.h>
#include<sys/timeb.h>


#define MAX 100000
using namespace std;

long getSystemTime()
{
	struct timeb tb;
	ftime(&tb);
	return tb.time * 1000 + tb.millitm;
}
void Merge(int arr[],int start,int end,int mid,int* temp)
{
	int i_start = start;
	int i_end = mid;
	int j_start = mid + 1;
	int j_end = end;
	int lenght = 0;
	while (i_start<=i_end&&j_start<=j_end)
	{
		if (arr[i_start] < arr[j_start])
		{
			temp[lenght] = arr[i_start];
			lenght++;
			i_start++;
		}
		else
		{
			temp[lenght] = arr[j_start];
			j_start++;
			lenght++;
		}
	}
	while (i_start<=i_end)
	{
		temp[lenght] = arr[i_start];
		lenght++;
		i_start++;
	}
	while (j_start<=j_end)
	{
		temp[lenght] = arr[j_start];
		lenght++;
		j_start++;
	}
	//覆盖原来的序列
	for (int i = 0; i < lenght; i++)
	{
		arr[i + start] = temp[i];
	}
}
void MergeSort(int arr[], int start, int end, int* temp)
{
	if (start>=end)
	{
		return;
	}
	int mid = (start + end) / 2;
	MergeSort(arr, start, mid, temp);
	MergeSort(arr, mid + 1, end, temp);
	Merge(arr,start,end,mid,temp);
}

int* CreatArr()
{
	srand((unsigned)time(NULL));
	int* arr = new int[MAX];
	for (int i = 0; i < MAX; i++)
	{
		arr[i] = rand() % MAX;
	}
	return arr;
}

int main()
{
	int* arr = CreatArr();
	int* temp = new int[MAX];
	long begin = getSystemTime();
	MergeSort(arr, 0, MAX-1, temp);
	long end = getSystemTime();
	cout << "归并排序； " << end - begin << endl;
	system("pause");
	return 0;
}
