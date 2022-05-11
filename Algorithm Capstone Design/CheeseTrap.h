#ifndef CHEESETRAP_H
#define CHEESETRAP_H

#include <vector>
using std::vector;

#include <algorithm>
using std::max;

//void eatCheeseMaxTrap_print(vector<vector<int>>& path) {
//	int m = path.size(), n = path[0].size();
//	// ��(1), ��(2), �̵�X(0)
//	vector<vector<int>> pathList(n);
//	vector<int> temp(1);
//	pathList[0] = temp;
//	temp.push_back(2);
//
//	for (int i = 0; i < m; i++)
//		for (int j = 0; j < n; j++) {
//			if (path[i][j] == -1)
//				continue;
//			if ((i > 0) && (j > 0)) {
//				path[i][j] = max(path[i - 1][j], path[i][j - 1]) + path[i][j];
//				if (i != 0) {
//					//if (path[i - 1][j] < path[i][j - 1]) {		// ���� ��ġ �������� ���ʰ� �Ʒ����� ���� �� �ִ� ġ���� �ִ밪�� ������ ��� -> �Ʒ����� �ö���� ��θ� ����
//					//	pathList[j] = pathList[j - 1];
//					//	pathList[j].push_back(2);
//					//}
//					//else
//					//	pathList[j].push_back(1);
//					if (path[i - 1][j] > path[i][j - 1])		// ���� ��ġ �������� ���ʰ� �Ʒ����� ���� �� �ִ� ġ���� �ִ밪�� ������ ��� -> ���ʿ��� ���� ��θ� ����
//						pathList[j].push_back(1);
//					else {
//						pathList[j] = pathList[j - 1];
//						pathList[j].push_back(2);
//					}
//				}
//			}
//			else if ((i == 0) && (j > 0)) {
//				path[i][j] = path[i][j - 1] + path[i][j];
//				if (path[i][j] != -1) {
//					pathList[j] = temp;
//					temp.push_back(2);
//				}
//			}
//			else if ((j == 0) && (i > 0)) {
//				path[i][j] = path[i - 1][j] + path[i][j];
//				if (i != 0)
//					pathList[j].push_back(1);
//			}
//		}
//
//	cout << "ġ���� �ִ밪 : " << path[m - 1][n - 1] << '\n';
//	cout << "������ �̵���� : ";
//	for(int i=0;i<pathList[n-1].size();i++)
//		switch (pathList[n - 1][i]) {
//		case 1:
//			cout << "�� ";
//			break;
//		case 2:
//			cout << "�� ";
//			break;
//		}
//}

void eatCheeseMaxTrap_print(const vector<vector<int>>& path) {
	// n(�� ũ��), m(�� ũ��)
	int m = path[0].size(), n = path.size();
	// ������ ��� ������ ���� �� �ִ� ġ���� �ִ밪�� ����
	vector<vector<int>> maxEat(n);
	vector<int> temp(m);
	// ��� ���Ҹ� 0���� �ʱ�ȭ
	for (int i = 0; i < n; i++)
		maxEat[i] = temp;

	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j < m; j++) {
			// �㵣(2)�� ��� 
			if (path[i][j] == 2) {
				maxEat[i][j] = -1;
				continue;
			}
			if ((i < n - 1) && (j > 0))
				maxEat[i][j] = max(maxEat[i + 1][j], maxEat[i][j - 1]) + (path[i][j] == -1 ? 0 : path[i][j]);
			else if ((i == n - 1) && (j > 0))
				maxEat[i][j] = maxEat[i][j - 1] + (path[i][j] == -1 ? 0 : path[i][j]);
			else if ((j == 0) && (i < n - 1))
				maxEat[i][j] = maxEat[i + 1][j] + (path[i][j] == -1 ? 0 : path[i][j]);
		}


	cout << "���� �� �ִ� ġ���� �ִ밪 : " << maxEat[0][n - 1] << '\n';
}

#endif