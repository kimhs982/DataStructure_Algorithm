#ifndef CHEESETRAP_H
#define CHEESETRAP_H

#include <vector>
using std::vector;

#include <algorithm>
using std::max;

//void eatCheeseMaxTrap_print(vector<vector<int>>& path) {
//	int m = path.size(), n = path[0].size();
//	// ↑(1), →(2), 이동X(0)
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
//					//if (path[i - 1][j] < path[i][j - 1]) {		// 현재 위치 기준으로 왼쪽과 아래에서 먹을 수 있는 치즈의 최대값이 동일한 경우 -> 아래에서 올라오는 경로를 선택
//					//	pathList[j] = pathList[j - 1];
//					//	pathList[j].push_back(2);
//					//}
//					//else
//					//	pathList[j].push_back(1);
//					if (path[i - 1][j] > path[i][j - 1])		// 현재 위치 기준으로 왼쪽과 아래에서 먹을 수 있는 치즈의 최대값이 동일한 경우 -> 왼쪽에서 오는 경로를 선택
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
//	cout << "치즈의 최대값 : " << path[m - 1][n - 1] << '\n';
//	cout << "선택한 이동경로 : ";
//	for(int i=0;i<pathList[n-1].size();i++)
//		switch (pathList[n - 1][i]) {
//		case 1:
//			cout << "↑ ";
//			break;
//		case 2:
//			cout << "→ ";
//			break;
//		}
//}

void eatCheeseMaxTrap_print(const vector<vector<int>>& path) {
	// n(행 크기), m(열 크기)
	int m = path[0].size(), n = path.size();
	// 각각의 행과 열에서 먹을 수 있는 치즈의 최대값을 저장
	vector<vector<int>> maxEat(n);
	vector<int> temp(m);
	// 모든 원소를 0으로 초기화
	for (int i = 0; i < n; i++)
		maxEat[i] = temp;

	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j < m; j++) {
			// 쥐덫(2)인 경우 
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


	cout << "먹을 수 있는 치즈의 최대값 : " << maxEat[0][n - 1] << '\n';
}

#endif