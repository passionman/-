
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



void ShellSort(int arr[], int len)
{
	int i, j, k=0;
	int increatment = len;
	while (increatment > 1)
	{
		increatment = increatment / 3 + 1;
		for (i = 0; i < increatment; i++)
		{
			for (j = i + increatment; j < len; j += increatment)
			{
				int temp = arr[j];
				if (arr[j] < arr[j - increatment])
				{
					for (k = j - increatment; k >= 0 && temp < arr[k]; k -= increatment)
					{
						arr[k + increatment] = arr[k];
					}
				}
				arr[k+increatment] = temp;
			}
			
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
	ShellSort(arr, MAX);
	long t_ended = getSystemTime();
	cout << "Ï£¶ûÅÅÐò£º" << t_ended - t_started << endl;
	//PrintArr(arr, MAX);
	system("pause");
	return 0;
}
