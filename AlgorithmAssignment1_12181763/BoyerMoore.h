#ifndef BOYERMOORE_H
#define BOYERMOORE_H

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Data Structures and Algorithms in C++

// last �迭�� ����� �Լ�
vector<int> buildLastFunction(const string& pattern) {
	const int ASCII_N = 128;		// �� 128���� ASCII �ڵ尪
	vector<int> last(ASCII_N, -1);		// 128���� ������ -1�� �ʱ�ȭ
	for (int i = 0; i < pattern.size(); i++)		//  pattern�� �ִ� ���ڵ��� �ٸ� ���� �Ҵ�
		last[pattern[i]] = i;
	return last;
}

// ���̾�-���� �˰����� ����ȭ ����(����ġ ����, mismatched character�� ���)
// text���� pattern�� �ش��ϴ� ���ڿ��� ã�� ��� �ش� ���ڿ� ���� �κ��� index�� ��ȯ, ã�� ���� ��� -1�� ��ȯ
// prev�� �˻��� ������ ��ġ�� ����
int BMmatch(const string& text, const string& pattern, int prev) {
	vector<int> last = buildLastFunction(pattern);		// �ش� pattern�� ���� last �迭�� ����
	int n = text.size();		// text�� ����
	int m = pattern.size();		// pattern�� ����

	int i = prev + m - 1;		// text �˻� index
	if (i > n - 1)		// �˻��Ϸ��� pattern�� text���� �� ���
		return -1;
	int j = m - 1;		// pattern �˻� index
	do {
		if (pattern[j] == text[i])		// text[i]�� pattern[j]�� ��ġ�ϴ� ���
			if (j == 0) return i;		// pattern�� ��� �κ��� ��ġ�� ���
			else {		// ������ �Ųٷ� ��
				i--;
				j--;
			}
		else {
			i = i + m - min(j, 1 + last[text[i]]);		// ���� ��ġ(i) + pattern�� ���� + j(pattern �˻� index)�� 1 + last[text[i]](pattern�� ����ġ�� �Ͼ text[i]�� last �迭�� �ش��ϴ� ��) �߿� �ּҰ�
			j = m - 1;		// pattern�� �� ������
		}
	} while (i <= n - 1);		// text ���̺��� ������� ������ �ݺ�
	return -1;
}

// ���ڿ��� �˻��� ��ġ�� ��� ���� ���
void calculate_rowColumn(const string& text, int foundIndex, int& row, int& column, int prev = 0) {
	if (foundIndex == -1)		// ���ڿ��� �˻����� ���� ���
		return;

	int temp = 0;

	for (int i = prev; i < foundIndex; i++)		// ������ �˻��� ��ġ(prev)���� ���Ӱ� �˻��� ��ġ(foundIndex)���� ���� ���
		if (text[i] == '\n') {
			row++;
			temp = i;
		}
	column = foundIndex - temp;		// ���� ���
}

#endif