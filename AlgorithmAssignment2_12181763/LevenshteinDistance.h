#ifndef LEVENSHTEINDISTANCE_H
#define LEVENSHTEINDISTANCE_H

#include <iostream>
using std::cout;
using std::cin;
using std::ios_base;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::min;

enum class COST { INS = 1, DEL, EXC1, EXC2 };

// 원래 스트링(S), 목표 스티링(T), costList는 [삽입 연산, 삭제 연산, 교환 연산]비용
template <typename cost_type>		// 비용이 정수 또는 실수가 될 수 있으므로 template 사용
cost_type LD1(const string& S, const string& T, const vector<cost_type>& costList) {
	int S_len = S.size(), T_len = T.size();		// Source와 Target의 문자열의 길이를 저장
	vector<cost_type> temp(S_len + 1);
	vector<vector<cost_type>> D(T_len + 1, temp);		// 편집 거리의 최소 비용을 저정할 2차원 배열 D, 크기 T_len + 1 * S_len + 1

	// 첫 번째 열에서는 삽입 연산만 일어남
	for (int i = 1; i <= T_len; i++)
		D[i][0] = D[i - 1][0] + costList[0];
	// 첫 번째 행에서는 삭제 연산만 일어남
	for (int i = 1; i <= S_len; i++)
		D[0][i] = D[0][i - 1] + costList[1];

	cost_type exchange_cost;		// 교환 비용
	for (int i = 1; i <= T_len; i++)
		for (int j = 1; j <= S_len; j++) {
			// 특정 index에서 Source와 Target의 문자가 동일할 경우
			if (S[j - 1] == T[i - 1])
				exchange_cost = 0;
			else
				exchange_cost = costList[2];
			D[i][j] = min(min(D[i][j - 1] + costList[1], D[i - 1][j] + costList[0]), D[i - 1][j - 1] + exchange_cost);		// 이전 상태에서 삽입, 삭제, 교환 비용을 더한 값들 중 최소값 선택
		}

	return D[T_len][S_len];
}

// 연산 순서 출력
template <typename cost_type>
void path(const vector<vector<COST>>& P, int q, int r, const vector<cost_type>& costList) {
	if (P[q][r] == INS) {		// 삽입 연산인 경우
		path(P, q - 1, r, costList);		// 재귀호출, 윗 행의 동일한 열로 이동
		cout << "삽입연산 = " << costList[0] << ' ';
	}
	else if (P[q][r] == DEL) {		// 삭제 연산인 경우
		path(P, q, r - 1, costList);		// 재귀호출, 동일한 행의 앞 열로 이동
		cout << "삭제연산 = " << costList[1] << ' ';
	}
	else if (P[q][r] == EXC2) {		// 교환 연산인 경우
		path(P, q - 1, r - 1, costList);		// 재귀호출, 윗 행의 앞 열로 이동
		cout << "교환연산 = " << costList[2] << ' ';
	}
	else if (P[q][r] == EXC1)		// 교환 연산인 경우, 특정 index의 Source와 Target의 문자가 동일함->출력X
		path(P, q - 1, r - 1, costList);
}

// 원래 스트링(S), 목표 스티링(T), costList는 [삽입 연산, 삭제 연산, 교환 연산]비용, 연산 순서 출력(영어만)
template <typename cost_type>
cost_type LD2(const string& S, const string& T, const vector<cost_type>& costList) {
	int S_len = S.size(), T_len = T.size();
	vector<cost_type> temp1(S_len + 1);
	vector<vector<cost_type>> D(T_len + 1, temp1);
	vector<COST> temp2(S_len + 1);
	vector<vector<COST>> P(T_len + 1, temp2);		// 편집 순서를 저정할 2차원 배열,  크기 T_len + 1 * S_len + 1

	for (int i = 1; i <= T_len; i++) {
		D[i][0] = D[i - 1][0] + costList[0];
		P[i][0] = INS;
	}
	for (int i = 1; i <= S_len; i++) {
		D[0][i] = D[i - 1][0] + costList[1];
		P[0][i] = DEL;
	}

	cost_type insert_cost = costList[0];		// 삽입 비용
	cost_type delete_cost = costList[1];		// 삭제 비용
	cost_type exchange_cost;		// 교환 비용
	for (int i = 1; i <= T_len; i++)
		for (int j = 1; j <= S_len; j++) {
			if (S[j - 1] == T[i - 1])
				exchange_cost = 0;
			else
				exchange_cost = costList[2];

			// 이전 상태에서 삽입, 삭제, 교환 비용을 더한 값들 중 최소값 선택 & 삽입, 삭제, 교환 연산 중에 어떤 연산이 일어났는지 저장
			cost_type cost_compare = D[i - 1][j - 1] + exchange_cost;		// 교환 연산이 최소일 경우
			COST type_decision;
			if (exchange_cost != 0)
				type_decision = EXC2;
			else
				type_decision = EXC1;
			if (cost_compare > D[i - 1][j] + insert_cost) {		// 삽입 연산이 최소일 경우
				cost_compare = D[i - 1][j] + insert_cost;
				type_decision = INS;
			}
			if (cost_compare > D[i][j - 1] + delete_cost) {		// 삭제 연산이 최소일 경우
				cost_compare = D[i][j - 1] + delete_cost;
				type_decision = DEL;
			}
			D[i][j] = cost_compare;
			P[i][j] = type_decision;
		}

	path(P, T_len, S_len, costList);		// 편집 순서를 출력

	return D[T_len][S_len];
}

// 원래 스트링(S), 목표 스티링(T), costList는 [삽입 연산, 삭제 연산, 교환 연산]비용, 연산 순서 출력(한글만)
template <typename cost_type>
cost_type LD3(const string& S, const string& T, const vector<cost_type>& costList) {
	int S_len = S.size() / 2, T_len = T.size() / 2;		// visual studio에서 한글은 한 글자당 2 byte
	vector<cost_type> temp1(S_len + 1);
	vector<vector<cost_type>> D(T_len + 1, temp1);
	vector<COST> temp2(S_len + 1);
	vector<vector<COST>> P(T_len + 1, temp2);

	for (int i = 1; i <= T_len; i++) {
		D[i][0] = D[i - 1][0] + costList[0];
		P[i][0] = INS;
	}
	for (int i = 1; i <= S_len; i++) {
		D[0][i] = D[i - 1][0] + costList[1];
		P[0][i] = DEL;
	}

	cost_type insert_cost = costList[0];		// 삽입 비용
	cost_type delete_cost = costList[1];		// 삭제 비용
	cost_type exchange_cost;		// 교환 비용
	int T_gap = 0;		// 한 글자당 2 byte씩 저장되는 한글을 따로 읽기 위한 index, 대상 : Target
	for (int i = 1; i <= T_len; i++) {
		int S_gap = 0;		// 한 글자당 2 byte씩 저장되는 한글을 따로 읽기 위한 index, 대상 : Source
		for (int j = 1; j <= S_len; j++) {
			if (S.substr(S_gap, 2) == T.substr(T_gap, 2))
				exchange_cost = 0;
			else
				exchange_cost = costList[2];

			cost_type cost_compare = D[i - 1][j - 1] + exchange_cost;
			COST type_decision;
			if (exchange_cost != 0)
				type_decision = EXC2;
			else
				type_decision = EXC1;
			if (cost_compare > D[i - 1][j] + insert_cost) {
				cost_compare = D[i - 1][j] + insert_cost;
				type_decision = INS;
			}
			if (cost_compare > D[i][j - 1] + delete_cost) {
				cost_compare = D[i][j - 1] + delete_cost;
				type_decision = DEL;
			}
			D[i][j] = cost_compare;
			P[i][j] = type_decision;
			S_gap += 2;
		}
		T_gap += 2;
	}

	path(P, T_len, S_len, costList);

	return D[T_len][S_len];
}

#endif