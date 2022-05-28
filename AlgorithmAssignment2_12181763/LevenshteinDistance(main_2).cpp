#include "LevenshteinDistance.h"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<double> costList = { 0.7,0.5,0.3 };

	string S[3] = { "Levenshtein", "TACTG", "����Ÿ���̴�" };		// Data 1, 2, 3�� Source
	string T[3] = { "Meilenstein", "CATGACTG", "�����ͺ��̽�����" };		// Data 1, 2, 3,�� Target

	// Data 1) Source = Levenshtein, Target = Meilenstein
	cout << "Source = Levenshtein, Target = Meilenstein\n";
	auto LevDis = LD2(S[0], T[0], costList);
	cout << " : Levenshtein Distance = " << LevDis << "\n\n";

	// Data 2) Source = TACTG, Target = CATGACTG
	cout << "Source = TACTG, Target = CATGACTG\n";
	LevDis = LD2(S[1], T[1], costList);
	cout << " : Levenshtein Distance = " << LevDis << "\n\n";

	// Data 3) Source = ����Ÿ���̴�, Target = �����ͺ��̽�����
	cout << "Source = ����Ÿ���̴�, Target = �����ͺ��̽�����\n";
	LevDis = LD3(S[2], T[2], costList);
	cout << " : Levenshtein Distance = " << LevDis << '\n';

	return 0;
}