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

	// N=10,000
	start = clock();
	heapSort_min(unsorted_arr1, 10000);
	end = clock();
	result = double(end) - double(start);

	cout << "Minheap sorting complete!\n";
	cout << "Minheap sorting (N=10,000) time cost: " << (result / CLOCKS_PER_SEC) << "段" << endl;
	checkSort_array_descending(unsorted_arr1, 10000);

	// N=50,000
	start = clock();
	heapSort_min(unsorted_arr2, 50000);
	end = clock();
	result = double(end) - double(start);

	cout << "Minheap sorting complete!\n";
	cout << "Minheap sorting (N=50,000) time cost: " << (result / CLOCKS_PER_SEC) << "段" << endl;
	checkSort_array_descending(unsorted_arr2, 10000);

	// N=100,000
	start = clock();
	heapSort_min(unsorted_arr3, 100000);
	end = clock();
	result = double(end) - double(start);

	cout << "Minheap sorting complete!\n";
	cout << "Minheap sorting (N=100,000) time cost: " << (result / CLOCKS_PER_SEC) << "段" << endl;
	checkSort_array_descending(unsorted_arr3, 100000);

	// N=500,000
	start = clock();
	heapSort_min(unsorted_arr4, 500000);
	end = clock();
	result = double(end) - double(start);

	cout << "Minheap sorting complete!\n";
	cout << "Minheap sorting (N=500,000) time cost: " << (result / CLOCKS_PER_SEC) << "段" << endl;
	checkSort_array_descending(unsorted_arr4, 500000);

	// N=1,000,000
	start = clock();
	heapSort_min(unsorted_arr5, 1000000);
	end = clock();
	result = double(end) - double(start);

	cout << "Minheap sorting complete!\n";
	cout << "Minheap sorting (N=1,000,000) time cost: " << (result / CLOCKS_PER_SEC) << "段" << endl;
	checkSort_array_descending(unsorted_arr5, 1000000);

	delete[] unsorted_arr1;
	delete[] unsorted_arr2;
	delete[] unsorted_arr3;
	delete[] unsorted_arr4;
	delete[] unsorted_arr5;

	return 0;
}