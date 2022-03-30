#include "Odd_even_transposition.h"

int main() {
	vector<int> sorting_arr;
	int key_num, key;
	cout << "key의 개수를 입력하세요 : ";
	cin >> key_num;

	cout << "key : ";
	for (int i = 0; i < key_num; i++) {
		cin >> key;
		sorting_arr.push_back(key);
	}
	cout << "\nunsorted : ";
	print<int>(sorting_arr);
	cout << endl;

	odd_even_transpositionSort_print<int>(sorting_arr);

	return 0;
}