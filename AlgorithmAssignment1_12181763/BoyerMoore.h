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
	for (int i = 0; i < pattern.size(); i++)		//  pattern에 있는 문자들은 다른 값을 할당
		last[pattern[i]] = i;
	return last;
}

// 보이어-무어 알고리즘의 간단화 버전(불일치 문자, mismatched character만 사용)
// text에서 pattern에 해당하는 문자열을 찾은 경우 해당 문자열 시작 부분의 index를 반환, 찾지 못한 경우 -1을 반환
// prev로 검색을 시작할 위치를 받음
int BMmatch(const string& text, const string& pattern, int prev) {
	vector<int> last = buildLastFunction(pattern);		// 해당 pattern에 대한 last 배열을 만듦
	int n = text.size();		// text의 길이
	int m = pattern.size();		// pattern의 길이

	int i = prev + m - 1;		// text 검색 index
	if (i > n - 1)		// 검색하려는 pattern이 text보다 긴 경우
		return -1;
	int j = m - 1;		// pattern 검색 index
	do {
		if (pattern[j] == text[i])		// text[i]와 pattern[j]가 일치하는 경우
			if (j == 0) return i;		// pattern의 모든 부분이 일치할 경우
			else {		// 패턴을 거꾸로 비교
				i--;
				j--;
			}
		else {
			i = i + m - min(j, 1 + last[text[i]]);		// 이전 위치(i) + pattern의 길이 + j(pattern 검색 index)와 1 + last[text[i]](pattern과 불일치가 일어난 text[i]의 last 배열에 해당하는 값) 중에 최소값
			j = m - 1;		// pattern의 맨 마지막
		}
	} while (i <= n - 1);		// text 길이보다 길어지기 전까지 반복
	return -1;
}

// 문자열이 검색된 위치의 행과 열을 계산
void calculate_rowColumn(const string& text, int foundIndex, int& row, int& column, int prev = 0) {
	if (foundIndex == -1)		// 문자열을 검색하지 못한 경우
		return;

	int temp = 0;

	for (int i = prev; i < foundIndex; i++)		// 이전에 검색된 위치(prev)에서 새롭게 검색된 위치(foundIndex)까지 행을 계산
		if (text[i] == '\n') {
			row++;
			temp = i;
		}
	column = foundIndex - temp;		// 열을 계산
}

#endif