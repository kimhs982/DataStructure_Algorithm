#ifndef NUMBERBOARDPLAY_H
#define NUMBERBOARDPLAY_H

#include <vector>
using std::vector;

#include <algorithm>
using std::max;

void printMaxSum(vector<vector<int>>& numberBoard) {
	// ������ ��� ������ ���� ������ 2���� �迭
	int** sumList = new int* [numberBoard.size()]();
	for (int i = 0; i < int(numberBoard.size()); i++)
		*(sumList + i) = new int[numberBoard[0].size()]();

	// �� �࿡�� ������ ���� ������ vector �����̳�
	vector<vector<int>> followIndex(numberBoard[0].size());

	// A[i, j] = max(A[i - 1, j - 1], A[i - 1, j], A[i - 1, j + 1]) + A[i, j]
	for (int i = 0; i < int(numberBoard.size()); i++)
		for (int j = 0; j < int(numberBoard[0].size()); j++)
			if (i == 0)
				sumList[i][j] = numberBoard[i][j];
			else if (j == 0) {
				sumList[i][j] = max(sumList[i - 1][j], sumList[i - 1][j + 1]) + numberBoard[i][j];
				followIndex[j].push_back(max(numberBoard[i - 1][j], numberBoard[i - 1][j + 1]));
			}
			else if (j == numberBoard[0].size() - 1) {
				sumList[i][j] = max(sumList[i - 1][j - 1], sumList[i - 1][j]) + numberBoard[i][j];
				followIndex[j].push_back(max(numberBoard[i - 1][j - 1], numberBoard[i - 1][j]));
			}
			else {
				sumList[i][j] = max(max(sumList[i - 1][j - 1], sumList[i - 1][j]), sumList[i - 1][j + 1]) + numberBoard[i][j];
				followIndex[j].push_back(max(max(numberBoard[i - 1][j - 1], numberBoard[i - 1][j]), numberBoard[i - 1][j + 1]));
			}
	// ������ �࿡�� ������ ���� ����
	for (int i = 0; i < int(numberBoard[0].size()); i++)
		if (i == 0)
			followIndex[i].push_back(max(numberBoard[numberBoard.size() - 1][i], numberBoard[numberBoard.size() - 1][i + 1]));
		else if (i == numberBoard[0].size() - 1)
			followIndex[i].push_back(max(numberBoard[numberBoard.size() - 1][i - 1], numberBoard[numberBoard.size() - 1][i]));
		else
			followIndex[i].push_back(max(max(numberBoard[numberBoard.size() - 1][i - 1], numberBoard[numberBoard.size() - 1][i]), numberBoard[numberBoard.size() - 1][i + 1]));

	// 2���� �迭 sumList�� ������ �࿡�� �ִ밪�� ã��
	int maxNum_index = 0;;
	for (int i = 1; i < int(numberBoard[0].size()); i++)
		if (sumList[numberBoard.size() - 1][maxNum_index] < sumList[numberBoard.size() - 1][i])
			maxNum_index = i;

	cout << "�ִ밪 : " << sumList[int(numberBoard.size()) - 1][maxNum_index] << '\n';
	cout << "�� �࿡�� ������ �� : ";
	for (int i = 0; i < int(followIndex[maxNum_index].size()); i++)
		cout << followIndex[maxNum_index][i] << ' ';
	cout << '\n';

	for (int i = 0; i < int(numberBoard.size()); i++)
		delete[] sumList[i];
	delete[] sumList;
}

#endif