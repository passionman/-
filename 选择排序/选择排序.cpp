
#include<iostream>
#include<string>
#include<time.h>
#include<sys/timeb.h>
#define MAX 10000
using namespace std;
void initArr(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		arr[i] = rand() % 20000;
	}
}
long getSystemTime()
{
	struct timeb tb;
	ftime(&tb);
	return tb.time * 1000 + tb.millitm;
}

void SwapNum(int& a, int& b)
{
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}

void SelectSort(int arr[], int len)
{
	int minIndex = 0;
	for (int i = 0; i < len; i++)
	{
		minIndex = i;
		for (int j = i + 1; j < len ; j++)
		{
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}
		if (i != minIndex)
			SwapNum(arr[i], arr[minIndex]);
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int arr[MAX] = { 0 };
	initArr(arr, MAX);
	long a=getSystemTime();
	SelectSort(arr, MAX);
	long b = getSystemTime();
	cout <<"Ñ¡ÔñÅÅÐò£º"<<	 b - a << endl;
	system("pause");
	return 0;
}
