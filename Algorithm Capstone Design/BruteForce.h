#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H
#include <string>
using namespace std;

int BruteForce(string& p, string& t)
{
	int M = p.length(), N = t.length(), i, j;

	for (i = 0, j = 0; j < M && i < N; i++, j++)
		if (t[i] != p[j])
		{
			i -= j;
			j = -1;
		}

	if (j == M)
		return i - M;
	else
		return i;
}

#endif