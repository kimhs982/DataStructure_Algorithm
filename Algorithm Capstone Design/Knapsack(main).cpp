#include <iostream>
using std::cin;
using std::cout;
using std::ios_base;

#include "Knapsack.h"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int W1 = 15, W2 = 30;
	// 보석(무게 / 가치)
	vector<pair<int, int>> input1 = { {0, 0}, {5, 5}, {10, 7}, {7, 10}, {3, 6}, {4, 8}, {11, 20} };
	vector<pair<int, int>> input2 = { {0, 0}, {3, 5}, {7, 7}, {8, 10}, {5, 6}, {6, 8}, {13, 20}, {11, 18}, {2, 5} };

	cout << "입력 1에 대하여 가방에 담은 보석의 최대 가치: " << Knapsack(input1, W1) << '\n';
	cout << "입력 2에 대하여 가방에 담은 보석의 최대 가치: " << Knapsack(input2, W2) << '\n';

	return 0;
}