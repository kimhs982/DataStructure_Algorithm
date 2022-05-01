#ifndef BOYERMOORE_H
#define BOYERMOORE_H

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Data Structures and Algorithms in C++

// last 배열을 만드는 함수
vector<int> buildLastFunction(const string& pattern) {
	const int ASCII_N = 128;		// 총 128개의 ASCII 코드값
	vector<int> last(ASCII_N, -1);		// 128개의 공간을 -1로 초기화
	for (int i = 0; i < pattern.size(); i++)
		last[pattern[i]] = i;
	return last;
}

int BMmatch(const string& text, const string& pattern, int prev) {
	vector<int> last = buildLastFunction(pattern);
	int n = text.size();
	int m = pattern.size();
	int i = prev + m - 1;
	if (i > n - 1)
		return -1;
	int j = m - 1;
	do {
		if (pattern[j] == text[i])
			if (j == 0) return i;
			else {
				i--;
				j--;
			}
		else {
			i = i + m - min(j, 1 + last[text[i]]);
			j = m - 1;
		}
	} while (i <= n - 1);
	return -1;
}

#endif