#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "Odd_even_transposition.h"

int main() {
	vector<int> sorting_arr1;
	vector<int> sorting_arr2;
	vector<int> sorting_arr3;
	int rand_key;

	srand(unsigned int(time(0)));

	for (int i = 0; i < 10000; i++)
		sorting_arr1.push_back(rand() % 1001);

	for (int i = 0; i < 50000; i++)
		sorting_arr2.push_back(rand() % 1001);

	for (int i = 0; i < 100000; i++)
		sorting_arr3.push_back(rand() % 1001);

	clock_t start, end;
	double result;

	start = clock();
	odd_even_transpositionSort<int>(sorting_arr1);
	end = clock();
	result = double(end) - double(start);
	cout << "Odd-Even 정렬 실행 시간 (N=10000): " << (result / CLOCKS_PER_SEC) << "초" << endl;
	checkSort<int>(sorting_arr1);

	start = clock();
	odd_even_transpositionSort<int>(sorting_arr2);
	end = clock();
	result = double(end) - double(start);
	cout << "Odd-Even 정렬 실행 시간 (N=50000): " << (result / CLOCKS_PER_SEC) << "초" << endl;
	checkSort<int>(sorting_arr2);

	start = clock();
	odd_even_transpositionSort<int>(sorting_arr3);
	end = clock();
	result = double(end) - double(start);
	cout << "Odd-Even 정렬 실행 시간 (N=100000): " << (result / CLOCKS_PER_SEC) << "초" << endl;
	checkSort<int>(sorting_arr3);


	return 0;
}