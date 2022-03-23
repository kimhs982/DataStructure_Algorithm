#ifndef SHELLSORT_H
#define SHELLSORT_H

#include <iostream>
using namespace std;

void ShellSort1(int a[], int n)		// 증가식 h = 3 * h + 1, 감소식 h = h / 3
{
	int h;
	for (h = 1; h < n; h = h * 3 + 1) {}
	for (; h > 0; h /= 3)
	{
		int i, j;
		int key;
		for (i = h; i < n; i++)
		{
			key = a[i];
			j = i;
			while ((j >= h) && (a[j - h] > key))
			{
				a[j] = a[j - h];
				j = j - h;
			}
			a[j] = key;
		}
	}
}

void ShellSort2(int a[], int n)		// 증가식 h = 4 * h, 감소식 h = h / 4
{
	int h;
	for (h = 1; h < n; h = h * 4) {}
	for (; h > 0; h /= 4)
	{
		int i, j;
		int key;
		for (i = h; i < n; i++)
		{
			key = a[i];
			j = i;
			while ((j >= h) && (a[j - h] > key))
			{
				a[j] = a[j - h];
				j = j - h;
			}
			a[j] = key;
		}
	}
}

void ShellSort3(int a[], int n)		// 증가식 h = 5 * h + 1, 감소식 h = h / 5
{
	int h;
	for (h = 1; h < n; h = h * 5 + 1) {}
	for (; h > 0; h /= 5)
	{
		int i, j;
		int key;
		for (i = h; i < n; i++)
		{
			key = a[i];
			j = i;
			while ((j >= h) && (a[j - h] > key))
			{
				a[j] = a[j - h];
				j = j - h;
			}
			a[j] = key;
		}
	}
}

void checkSort(const int a[], int n)
{
	bool sorted = true;
	for (int i = 0; i < n - 1; i++)
		if (a[i] > a[i + 1])
		{
			sorted = false;
			break;
		}
	if (sorted)
		cout << "정렬 완료." << endl;
	else
		cout << "정렬 오류!!" << endl;
}

#endif