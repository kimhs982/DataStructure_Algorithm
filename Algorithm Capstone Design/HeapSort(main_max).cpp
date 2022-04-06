#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "HeapSort.h"

int main()
{
	srand(unsigned int(time(NULL)));
	clock_t start, end;
	double result;

	int* unsorted_arr1 = new int[10000];
	int* unsorted_arr2 = new int[50000];
	int* unsorted_arr3 = new int[100000];
	int* unsorted_arr4 = new int[500000];
	int* unsorted_arr5 = new int[1000000];

	for (int i = 0; i < 10000; i++)
		unsorted_arr1[i] = rand() % 1001;
	for (int i = 0; i < 50000; i++)
		unsorted_arr2[i] = rand() % 1001;
	for (int i = 0; i < 100000; i++)
		unsorted_arr3[i] = rand() % 1001;
	for (int i = 0; i < 500000; i++)
		unsorted_arr4[i] = rand() % 1001;
	for (int i = 0; i < 1000000; i++)
		unsorted_arr5[i] = rand() % 1001;

	start = clock();
	heapSort_max(unsorted_arr1, 10000);
	end = clock();
	result = double(end) - double(start);

	cout << "Maxheap sorting complete!\n";
	cout << "Maxheap sorting (N=10,000) time cost: " << (result / CLOCKS_PER_SEC) << "段" << endl;
	checkSort_array_ascending(unsorted_arr1, 10000);

	start = clock();
	heapSort_max(unsorted_arr2, 50000);
	end = clock();
	result = double(end) - double(start);

	cout << "Maxheap sorting complete!\n";
	cout << "Maxheap sorting (N=50,000) time cost: " << (result / CLOCKS_PER_SEC) << "段" << endl;
	checkSort_array_ascending(unsorted_arr2, 10000);

	start = clock();
	heapSort_max(unsorted_arr3, 100000);
	end = clock();
	result = double(end) - double(start);

	cout << "Maxheap sorting complete!\n";
	cout << "Maxheap sorting (N=100,000) time cost: " << (result / CLOCKS_PER_SEC) << "段" << endl;
	checkSort_array_ascending(unsorted_arr3, 100000);

	start = clock();
	heapSort_max(unsorted_arr4, 500000);
	end = clock();
	result = double(end) - double(start);

	cout << "Maxheap sorting complete!\n";
	cout << "Maxheap sorting (N=500,000) time cost: " << (result / CLOCKS_PER_SEC) << "段" << endl;
	checkSort_array_ascending(unsorted_arr4, 500000);

	start = clock();
	heapSort_max(unsorted_arr5, 1000000);
	end = clock();
	result = double(end) - double(start);

	cout << "Maxheap sorting complete!\n";
	cout << "Maxheap sorting (N=1,000,000) time cost: " << (result / CLOCKS_PER_SEC) << "段" << endl;
	checkSort_array_ascending(unsorted_arr5, 1000000);

	delete[] unsorted_arr1;
	delete[] unsorted_arr2;
	delete[] unsorted_arr3;
	delete[] unsorted_arr4;
	delete[] unsorted_arr5;

	return 0;
}