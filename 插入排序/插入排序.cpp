
#include<iostream>
#include<string>
#include<time.h>
#include<sys/timeb.h>
#define MAX 10000
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
void InsertSort(int arr[], int len)
{
	int i, j;
	for (i = 1; i < len; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			int temp = arr[i];
			for (j = i - 1; j >= 0 && temp < arr[j]; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j] = temp;
		}
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[MAX] = { 0 };
	InitArr(arr, MAX);
	//PrintArr(arr, MAX);
	long t_started = getSystemTime();
	InsertSort(arr, MAX);
	long t_ended = getSystemTime();
	cout << "²åÈëÅÅÐò£º" << t_ended - t_started << endl;
	//PrintArr(arr, MAX);
	system("pause");
	return 0;
}
