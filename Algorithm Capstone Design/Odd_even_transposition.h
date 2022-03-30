#ifndef ODD_EVEN_TRANSPOSITION_H
#define ODD_EVEN_TRANSPOSITION_H

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


template <typename key>
void print(const vector<key>& arr) {
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}

template <typename key>
void odd_even_transpositionSort(vector<key>& arr) {
	bool isSorted = false;

	while (!isSorted) {
		isSorted = true;

		for (int i = 0; i <= arr.size() - 2; i += 2) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				isSorted = false;
			}
		}

		for (int i = 1; i <= arr.size() - 2; i += 2)
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				isSorted = false;
			}
	}
}

template <typename key>
void odd_even_transpositionSort_print(vector<key>& arr) {
	bool isSorted = false;

	while (!isSorted) {
		isSorted = true;

		for (int i = 0; i <= arr.size() - 2; i += 2) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				isSorted = false;
			}
		}
		cout << "odd index" << endl;
		print<key>(arr);

		for (int i = 1; i <= arr.size() - 2; i += 2)
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				isSorted = false;
			}
		cout << "even index" << endl;
		print<key>(arr);
	}
	cout << "\n최종 정렬 결과" << endl;
	print<key>(arr);
}

template <typename key>
void checkSort(const vector<key> arr)
{
	bool sorted = true;
	for (int i = 0; i < arr.size() - 1; i++)
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

template <typename key>
void odd_even_transpositionSort_array(key arr[], int n) {
	bool isSorted = false;

	while (!isSorted) {
		isSorted = true;

		for (int i = 0; i <= n - 2; i += 2) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				isSorted = false;
			}
		}

		for (int i = 1; i <= n - 2; i += 2)
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				isSorted = false;
			};
	}
}

template <typename key>
void checkSort_array(const key arr[], int n)
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

#endif