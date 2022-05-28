#include "LevenshteinDistance.h"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// ����ڷκ��� Source�� Target�� �Է� ����
	string S, T;
	cout << "Source: ";
	cin >> S;
	cout << "Target: ";
	cin >> T;

	// ����ڷκ��� ����, ����, ��ȯ ����� �Է� ����
	vector<double> costList(3);
	cout << "���Ժ��, �������, ��ȯ���((ex) 1 1 1): ";
	for (int i = 0; i < 3; i++)
		cin >> costList[i];

	cout << "Levenshtein Distance = " << LD1(S, T, costList) << '\n';

	return 0;
}