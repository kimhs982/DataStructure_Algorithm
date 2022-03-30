#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "Odd_even_transposition.h"

int main() {
	int* sorting_arr1 = new int[10000];
	int* sorting_arr2 = new int[50000];
	int* sorting_arr3 = new int[100000];
	int rand_key;

	srand(unsigned int(time(0)));

	for (int i = 0; i < 10000; i++)
		sorting_arr1[i] = rand() % 1001;

	for (int i = 0; i < 50000; i++)
		sorting_arr2[i] = rand() % 1001;

	for (int i = 0; i < 100000; i++)
		sorting_arr3[i] = rand() % 1001;

	clock_t start, end;
	double result;

	start = clock();
	odd_even_transpositionSort_array<int>(sorting_arr1, 10000);
	end = clock();
	result = double(end) - double(start);
	cout << "Odd-Even 정렬 실행 시간 (N=10000): " << (result / CLOCKS_PER_SEC) << "초" << endl;
	checkSort_array<int>(sorting_arr1, 10000);

	start = clock();
	odd_even_transpositionSort_array<int>(sorting_arr2, 50000);
	end = clock();
	result = double(end) - double(start);
	cout << "Odd-Even 정렬 실행 시간 (N=50000): " << (result / CLOCKS_PER_SEC) << "초" << endl;
	checkSort_array<int>(sorting_arr2, 50000);

	start = clock();
	odd_even_transpositionSort_array<int>(sorting_arr3, 100000);
	end = clock();
	result = double(end) - double(start);
	cout << "Odd-Even 정렬 실행 시간 (N=100000): " << (result / CLOCKS_PER_SEC) << "초" << endl;
	checkSort_array<int>(sorting_arr3, 100000);


	return 0;
}