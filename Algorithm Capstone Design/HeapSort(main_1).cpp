#include <iostream>
using namespace std;

#include "HeapSort.h"

int main()
{
	int unsorted_arr1[] = { 6,2,8,1,3,9,4,5,10,7 };
	int unsorted_arr2[] = { 6,2,8,1,3,9,4,5,10,7 };

	heapSort_max(unsorted_arr1, 10);

	cout << "MaxHeap 정렬 결과\n";
	for (int i = 0; i < 10; i++)
		cout << unsorted_arr1[i] << " ";
	cout << endl;

	heapSort_min(unsorted_arr2, 10);

	cout << "MinHeap 정렬 결과" << '\n';
	for (int i = 0; i < 10; i++)
		cout << unsorted_arr2[i] << " ";
	cout << endl;

	return 0;
}