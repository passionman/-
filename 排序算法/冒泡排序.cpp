
#include<iostream>
#include<string>
#include<time.h>
#include<sys/timeb.h>
using namespace std;
#define MAX 10000
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
	cout << endl<< "-----------------------" << endl;
}
void SwapNum(int &a,int &b)
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}
void BubbleSort(int arr[],int len)
{
	int flag = 1;
	for (int i = len; i >1&&flag==1; i--)
	{
		flag = 0;
		for (int j = 0; j < i-1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				flag = 1;
				SwapNum(arr[j], arr[j + 1]);
			}
			
		}
	}
}
void InitArr(int arr[],int len)
{
	for (int i = 0; i < len; i++)
	{
		arr[i] = rand() % 20000;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[MAX] = { 0 };
	InitArr(arr, MAX);
	//PrintArr(arr, MAX);
	long t_started = getSystemTime();
	BubbleSort(arr, MAX);
	long t_ended = getSystemTime();
	cout << "Ã°ÅÝÅÅÐò£º"<<t_ended - t_started << endl;
	//PrintArr(arr, MAX);

	system("pause");
	return 0;
}
