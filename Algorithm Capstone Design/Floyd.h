#ifndef FLOYD_H
#define FLOYD_H

#include <iostream>
using std::cout;
using std::cin;

#include <iomanip>
using std::setw;

#include <vector>
using std::vector;

// path 알고리즘
void path(const vector<vector<int>>& P, int q, int r) {
	if (P[q][r] != 0) {
		path(P, q, P[q][r]);
		cout << " V" << P[q][r];
		cout << " ->";
		path(P, P[q][r], r);
	}
}

// Floyed 알고리즘
void floyd_path(const vector<vector<int>>& W) {
	int n = int(W.size());
	vector<vector<int>> D(W);
	vector<vector<int>> P(n);
	vector<int> temp(n);
	for (int i = 0; i < n; i++)
		P[i] = temp;

	for (int k = 1; k < n; k++)
		for (int i = 1; i < n; i++)
			for (int j = 1; j < n; j++)
				if (D[i][k] + D[k][j] < D[i][j]) {
					P[i][j] = k;
					D[i][j] = D[i][k] + D[k][j];
				}

	cout << "D[i][j] is\n";
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++)
			cout << setw(3) << D[i][j];
		cout << '\n';
	}
	cout << '\n';

	cout << "P[i][j] is\n";
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++)
			cout << setw(3) << P[i][j];
		cout << '\n';
	}
	cout << '\n';

	int loop, start, end;
	cout << "최단 경로를 출력할 횟수 : ";
	cin >> loop;
	for (int i = 0; i < loop; i++) {
		cout << "입력[(예: 5 3) -> path(5, 3)] : ";
		cin >> start >> end;

		cout << "The shortest path(" << start << ", " << end << ") is ";
		cout << "V" << start << " ->";
		path(P, start, end);
		cout << " V" << end << "\n\n";
	}
}
#endif