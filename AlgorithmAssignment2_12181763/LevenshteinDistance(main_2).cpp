#include "LevenshteinDistance.h"

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<double> costList = { 0.7,0.5,0.3 };

	string S[3] = { "Levenshtein", "TACTG", "데이타마이닝" };		// Data 1, 2, 3의 Source
	string T[3] = { "Meilenstein", "CATGACTG", "데이터베이스설계" };		// Data 1, 2, 3,의 Target

	// Data 1) Source = Levenshtein, Target = Meilenstein
	cout << "Source = Levenshtein, Target = Meilenstein\n";
	auto LevDis = LD2(S[0], T[0], costList);
	cout << " : Levenshtein Distance = " << LevDis << "\n\n";

	// Data 2) Source = TACTG, Target = CATGACTG
	cout << "Source = TACTG, Target = CATGACTG\n";
	LevDis = LD2(S[1], T[1], costList);
	cout << " : Levenshtein Distance = " << LevDis << "\n\n";

	// Data 3) Source = 데이타마이닝, Target = 데이터베이스설계
	cout << "Source = 데이타마이닝, Target = 데이터베이스설계\n";
	LevDis = LD3(S[2], T[2], costList);
	cout << " : Levenshtein Distance = " << LevDis << '\n';

	return 0;
}