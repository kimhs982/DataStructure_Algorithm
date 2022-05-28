#include "LevenshteinDistance.h"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 사용자로부터 Source와 Target을 입력 받음
	string S, T;
	cout << "Source: ";
	cin >> S;
	cout << "Target: ";
	cin >> T;

	// 사용자로부터 삽입, 삭제, 교환 비용을 입력 받음
	vector<double> costList(3);
	cout << "삽입비용, 삭제비용, 교환비용((ex) 1 1 1): ";
	for (int i = 0; i < 3; i++)
		cin >> costList[i];

	cout << "Levenshtein Distance = " << LD1(S, T, costList) << '\n';

	return 0;
}