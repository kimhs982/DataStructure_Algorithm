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

// ���� ��Ʈ��(S), ��ǥ ��Ƽ��(T), costList�� [���� ����, ���� ����, ��ȯ ����]���
template <typename cost_type>		// ����� ���� �Ǵ� �Ǽ��� �� �� �����Ƿ� template ���
cost_type LD1(const string& S, const string& T, const vector<cost_type>& costList) {
	int S_len = S.size(), T_len = T.size();		// Source�� Target�� ���ڿ��� ���̸� ����
	vector<cost_type> temp(S_len + 1);
	vector<vector<cost_type>> D(T_len + 1, temp);		// ���� �Ÿ��� �ּ� ����� ������ 2���� �迭 D, ũ�� T_len + 1 * S_len + 1

	// ù ��° �������� ���� ���길 �Ͼ
	for (int i = 1; i <= T_len; i++)
		D[i][0] = D[i - 1][0] + costList[0];
	// ù ��° �࿡���� ���� ���길 �Ͼ
	for (int i = 1; i <= S_len; i++)
		D[0][i] = D[0][i - 1] + costList[1];

	cost_type exchange_cost;		// ��ȯ ���
	for (int i = 1; i <= T_len; i++)
		for (int j = 1; j <= S_len; j++) {
			// Ư�� index���� Source�� Target�� ���ڰ� ������ ���
			if (S[j - 1] == T[i - 1])
				exchange_cost = 0;
			else
				exchange_cost = costList[2];
			D[i][j] = min(min(D[i][j - 1] + costList[1], D[i - 1][j] + costList[0]), D[i - 1][j - 1] + exchange_cost);		// ���� ���¿��� ����, ����, ��ȯ ����� ���� ���� �� �ּҰ� ����
		}

	return D[T_len][S_len];
}

// ���� ���� ���
template <typename cost_type>
void path(const vector<vector<COST>>& P, int q, int r, const vector<cost_type>& costList) {
	if (P[q][r] == INS) {		// ���� ������ ���
		path(P, q - 1, r, costList);		// ���ȣ��, �� ���� ������ ���� �̵�
		cout << "���Կ��� = " << costList[0] << ' ';
	}
	else if (P[q][r] == DEL) {		// ���� ������ ���
		path(P, q, r - 1, costList);		// ���ȣ��, ������ ���� �� ���� �̵�
		cout << "�������� = " << costList[1] << ' ';
	}
	else if (P[q][r] == EXC2) {		// ��ȯ ������ ���
		path(P, q - 1, r - 1, costList);		// ���ȣ��, �� ���� �� ���� �̵�
		cout << "��ȯ���� = " << costList[2] << ' ';
	}
	else if (P[q][r] == EXC1)		// ��ȯ ������ ���, Ư�� index�� Source�� Target�� ���ڰ� ������->���X
		path(P, q - 1, r - 1, costList);
}

// ���� ��Ʈ��(S), ��ǥ ��Ƽ��(T), costList�� [���� ����, ���� ����, ��ȯ ����]���, ���� ���� ���(���)
template <typename cost_type>
cost_type LD2(const string& S, const string& T, const vector<cost_type>& costList) {
	int S_len = S.size(), T_len = T.size();
	vector<cost_type> temp1(S_len + 1);
	vector<vector<cost_type>> D(T_len + 1, temp1);
	vector<COST> temp2(S_len + 1);
	vector<vector<COST>> P(T_len + 1, temp2);		// ���� ������ ������ 2���� �迭,  ũ�� T_len + 1 * S_len + 1

	for (int i = 1; i <= T_len; i++) {
		D[i][0] = D[i - 1][0] + costList[0];
		P[i][0] = INS;
	}
	for (int i = 1; i <= S_len; i++) {
		D[0][i] = D[i - 1][0] + costList[1];
		P[0][i] = DEL;
	}

	cost_type insert_cost = costList[0];		// ���� ���
	cost_type delete_cost = costList[1];		// ���� ���
	cost_type exchange_cost;		// ��ȯ ���
	for (int i = 1; i <= T_len; i++)
		for (int j = 1; j <= S_len; j++) {
			if (S[j - 1] == T[i - 1])
				exchange_cost = 0;
			else
				exchange_cost = costList[2];

			// ���� ���¿��� ����, ����, ��ȯ ����� ���� ���� �� �ּҰ� ���� & ����, ����, ��ȯ ���� �߿� � ������ �Ͼ���� ����
			cost_type cost_compare = D[i - 1][j - 1] + exchange_cost;		// ��ȯ ������ �ּ��� ���
			COST type_decision;
			if (exchange_cost != 0)
				type_decision = EXC2;
			else
				type_decision = EXC1;
			if (cost_compare > D[i - 1][j] + insert_cost) {		// ���� ������ �ּ��� ���
				cost_compare = D[i - 1][j] + insert_cost;
				type_decision = INS;
			}
			if (cost_compare > D[i][j - 1] + delete_cost) {		// ���� ������ �ּ��� ���
				cost_compare = D[i][j - 1] + delete_cost;
				type_decision = DEL;
			}
			D[i][j] = cost_compare;
			P[i][j] = type_decision;
		}

	path(P, T_len, S_len, costList);		// ���� ������ ���

	return D[T_len][S_len];
}

// ���� ��Ʈ��(S), ��ǥ ��Ƽ��(T), costList�� [���� ����, ���� ����, ��ȯ ����]���, ���� ���� ���(�ѱ۸�)
template <typename cost_type>
cost_type LD3(const string& S, const string& T, const vector<cost_type>& costList) {
	int S_len = S.size() / 2, T_len = T.size() / 2;		// visual studio���� �ѱ��� �� ���ڴ� 2 byte
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

	cost_type insert_cost = costList[0];		// ���� ���
	cost_type delete_cost = costList[1];		// ���� ���
	cost_type exchange_cost;		// ��ȯ ���
	int T_gap = 0;		// �� ���ڴ� 2 byte�� ����Ǵ� �ѱ��� ���� �б� ���� index, ��� : Target
	for (int i = 1; i <= T_len; i++) {
		int S_gap = 0;		// �� ���ڴ� 2 byte�� ����Ǵ� �ѱ��� ���� �б� ���� index, ��� : Source
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