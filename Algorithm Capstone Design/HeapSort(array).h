#ifndef PRACTICE_H
#define PRACTICE_H

#include <vector>

template <typename key>
void heapify(vector<key>& arr, int h, int m)
{
	int v = arr[h], i;

	for (i = 2 * h + 1; i < m; i = i * 2 + 1)
	{
		if ((i < m - 1) && (arr[i] < arr[i + 1]))
			i++;
		if (v >= arr[i])
			break;
		else
			arr[(i - 1) / 2] = arr[i];
	}
	arr[(i - 1) / 2] = v;
}

template <typename key>
void heapSort(vector<key>& arr)
{
	int n = arr.size();

	for (int i = n / 2 - 1; i >= 0; i--)
		heapify<key>(arr, i, n);
	for (int i = n - 2; i >= 0; i--)
	{
		int temp = arr[0];
		arr[0] = arr[i + 1];
		arr[i + 1] = temp;
		heapify<key>(arr, 0, i + 1);
	}
}

#endif