#ifndef KMP_H
#define KMP_H

#include <string>
using namespace std;

void InitNext(const string& p, int* next)
{
	int M = p.length();

	for (int i = 0, j = -1; i < M; i++, j++)
	{
		next[i] = j;
		while ((j >= 0) && (p[i] != p[j]))
			j = next[j];
	}
}

void InitNext_improve(const string& p, int* next)	// 개선된 InitNext 알고리즘
{
	int M = p.length();

	next[0] = -1;		// 개선된 InitNext 알고리즘에서는 필요
	for (int i = 1, j = 0; i < M; i++, j++)		// i = 0, j = -1 -> i = 1, j = 0 으로 변경
	{
		next[i] = (p[i] == p[j] ? next[j] : j);		// string과 배열의 index는 0부터 시작
		while ((j >= 0) && (p[i] != p[j]))
			j = next[j];
	}
}

// prev : Text에서 Pattern 검색을 시작할 위치
int KMP(const string& p, const string& t, int prev = 0)
{
	int M = p.length(), N = t.length();
	int* next = new int[M];

	InitNext_improve(p, next);

	int i, j;
	for (i = prev, j = 0; i < N && j < M; i++, j++)
		while ((j >= 0) && (t[i] != p[j]))
			j = next[j];

	delete[] next;

	if (j == M)
		return i - M;
	else
		return i;
}

#endif