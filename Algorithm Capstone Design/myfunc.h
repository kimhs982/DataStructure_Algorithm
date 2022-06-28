#ifndef MYFUNC_H
#define MYFUNC_H

#include <vector>
#include <algorithm>

using namespace std;

// ��ȯ(exchange)
template <typename T>
void exchange(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

// ���� ����(Bubble Sort, ��ȯ ����(Exchange Sort))
template <typename T>
void BubbleSort(vector<T>& arr, bool ascending = true) {
	for (int i = 0; i < arr.size() - 1; i++)
		for (int j = i + 1; j < arr.size(); j++)
			if (ascending) {
				if (arr[i] > arr[j])
					swap(arr[i], arr[j]);
			}
			else {
				if (arr[i] < arr[j])
					swap(arr[i], arr[j]);
			}
}

// ���� ����(Insertion Sort)
template <typename T>
void InsertionSort(vector<T>& arr, bool ascending = true) {
	for (int i = 1; i < arr.size(); i++) {
		int j = i - 1;
		T temp = arr[i];
		while (j >= 0 && (ascending ? arr[j] > temp : arr[j] < temp)) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
}

// ���� ����(Selection Sort)
template <typename T>
void SelectionSort(vector<T>& arr, bool ascending = true) {
	for (int i = 0; i < arr.size() - 1; i++) {
		int temp = i;
		for (int j = i + 1; j < arr.size(); j++)
			if ((ascending ? arr[temp] > arr[j] : arr[temp] < arr[j]))
				temp = j;
		swap(arr[i], arr[temp]);
	}
}

//// ���(node) ����ü
//template <typename T>
//struct node {
//	T key;
//	node* left;
//	node* right;
//};
//
//// ���� Ž�� Ʈ��(Binary Search Tree) - Ʈ��, tree
//class BST {
//public:
//
//private:
//};

// ���� Ž��(Binary Search) - ����, vector
// left ~ right ���� Ž��(index)
template <typename T>
int BS(const vector<T>& arr, T key, int left, int right) {
	if (left <= right) {
		int mid = (left + right) / 2;
		if (key < arr[mid])
			return BS(arr, key, left, mid - 1);
		else if (key > arr[mid])
			return BS(arr, key, mid + 1, right);
		else
			return mid;
	}
	else
		return -1;
}

// ���� ���(Binomial Coefficient) - ���� ��ȹ��, DP
// N_C_K
int BinomialCoefficient(int N, int K) {
	int result;
	int** BC = new int* [N + 1];
	for (int i = 0; i < N + 1; i++)
		*(BC + i) = new int[K + 1];

	for (int n = 1; n <= N; n++)
		for (int k = 0; k <= min(n, K); k++)
			if ((k == 0) || (k == n))
				BC[n][k] = 1;
			else
				BC[n][k] = BC[n - 1][k - 1] + BC[n - 1][k];

	result = BC[N][K];

	for (int i = 0; i < N + 1; i++)
		delete[] BC[i];
	delete[] BC;

	return result;
}

#endif