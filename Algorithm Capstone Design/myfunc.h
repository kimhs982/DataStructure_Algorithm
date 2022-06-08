#ifndef MYFUNC_H
#define MYFUNC_H

#include <algorithm>

using namespace std;

// 이항 계수(동적 계획법, DP)
int BinomialCoefficient2(int N, int K) {
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