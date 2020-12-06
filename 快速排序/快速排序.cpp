
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
void PrintArr(int arr[], int len)
{
	cout << endl;
	for (int i = 0; i < len; i++)
		cout << arr[i] << ' ';
	cout << endl << "-----------------------" << endl;
}
void SwapNum(int& a, int& b)
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}

void InitArr(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		arr[i] = rand() % 20000;
	}
}




void QuickSort(int arr[],int low,int height)
{
	int left = low;
	int right = height;
	//取出基准数
	int target = arr[left];
	if (left < right)
	{
		while (left<right)
		{
			//在左边挖坑，从右边开始，找比基准数小的；
			while (left<right&&arr[right]>target)
			{
				right--;
			}
			if (left < right)
			{
				arr[left] = arr[right];
				left++;
			}
			//从左边向右边找比基准数大的
			while (left<right&&arr[left]<target)
			{
				left++;
			}
			if (left < right)
			{
				arr[right] = arr[left];
				right--;
			}
		}
		arr[left] = target;
		QuickSort(arr, low, left - 1);
		QuickSort(arr, left + 1, height);

	}
}


int main()
{
	srand((unsigned)time(NULL));
	int arr[MAX] = { 0 };
	InitArr(arr, MAX);
	//PrintArr(arr, MAX);
	long t_started = getSystemTime();
	QuickSort(arr,0,MAX-1);
	long t_ended = getSystemTime();
	cout << "快速排序：" << t_ended - t_started << endl;
	//PrintArr(arr, MAX);
	system("pause");
	return 0;
}
