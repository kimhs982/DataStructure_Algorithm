#include <iostream>
using std::cin;
using std::cout;

#include "NumberBoardPlay.h"

int main() {
	/*
	// ���������� ��� ���� ���� �Է� ���� �� ����
	int row, column;
	cout << "[�� ����] : ";
	cin >> row;
	cout << "[�� ����] : ";
	cin >> column;

	vector<vector<int>> numberBoardList(row);
	vector<int> rowList(column);

	for (int i = 0; i < int(numberBoardList.size()); i++) {
		cout << i + 1 << "�� : ";
		for (int j = 0; j < int(rowList.size()); j++)
			cin >> rowList[j];
		numberBoardList[i] = rowList;
	}
	*/

	vector<vector<int>> numberBoardList = {
		{3, 4, 9, -2, 2, 51, -23, 2, -1},
		{223, 7, 8, -11, 5, -99, 2, 3, -4},
		{2, 51, -23, -23, 6, 3, 2, 4, 5},
		{5, -99, 2, -1, 32, 2, 5, -99, 2},
		{6, 3, 3, -4, 2, -1, 6, 3, 3},
		{32, 2, 4, 5, 3, -4, 2, -1, 4},
		{4, 4, 23, 6, 2, -1, 3, -4, 34},
		{78, 32, 1, 7, 3, -4, -23, -23, 6}
	};

	printMaxSum(numberBoardList);

	return 0;
}