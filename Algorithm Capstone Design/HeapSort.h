#ifndef HEAPSORT_H
#define HEAPSORT_H

void heapify_max(int arr[], int h, int m)
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

void heapSort_max(int arr[], int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify_max(arr, i, size);
	for (int i = size - 2; i >= 0; i--)
	{
		int temp = arr[0];
		arr[0] = arr[i + 1];
		arr[i + 1] = temp;
		heapify_max(arr, 0, i + 1);
	}
}

void heapify_min(int arr[], int h, int m)
{
	int v = arr[h], i;

	for (i = 2 * h + 1; i < m; i = i * 2 + 1)
	{
		if ((i < m - 1) && (arr[i] > arr[i + 1]))
			i++;
		if (v <= arr[i])
			break;
		else
			arr[(i - 1) / 2] = arr[i];
	}
	arr[(i - 1) / 2] = v;
}

void heapSort_min(int arr[], int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify_min(arr, i, size);
	for (int i = size - 2; i >= 0; i--)
	{
		int temp = arr[0];
		arr[0] = arr[i + 1];
		arr[i + 1] = temp;
		heapify_min(arr, 0, i + 1);
	}
}

void checkSort_array_ascending(const int arr[], int n)
{
	bool sorted = true;
	for (int i = 0; i < n - 1; i++)
		if (arr[i] > arr[i + 1])
		{
			sorted = false;
			break;
		}
	if (sorted)
		cout << "정렬 완료." << endl;
	else
		cout << "정렬 오류!!" << endl;
}

void checkSort_array_descending(const int arr[], int n)
{
	bool sorted = true;
	for (int i = 0; i < n - 1; i++)
		if (arr[i] < arr[i + 1])
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