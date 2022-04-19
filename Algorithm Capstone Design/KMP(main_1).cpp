#include <iostream>
using namespace std;

#include "KMP.h"

int main()
{
	string Text = "ababababcababababcaabbabababcaab";
	string Pattern = "abababca";

	int pos, previous = 0, temp = 0;
	int M = Pattern.length(), N = Text.length();
	while (1)
	{
		pos = KMP(Pattern, Text, previous);		// Text�� previous ��ġ���� Pattern�� ã��. �߰��� Pattern�� index�� pos�� ����
		temp = pos + M;
		if (temp <= N)		// Text ���ڿ��� �� �κп� �����ߴ��� Ȯ��
			cout << "������ �߻��� ��ġ : " << pos << '\n';
		else
			break;
		previous = temp;
	}

	cout << "Ž�� ����\n";

	return 0;
}