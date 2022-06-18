#include "TSP.h"

// TSP Ŭ���� ������(constructor)
TSP::TSP(const vector<vector<int>>& weight) : W(weight), V_num(W.size()) {
	// TSP Naive
	min_lenNaive = INF;
	visitedList.assign(V_num, 0);
	visitedList[0] = true;
	temp_pathNaive.reserve(V_num);
	temp_pathNaive.push_back(0);
	// TSP DP
	D.resize(1 << V_num);
	for (int i = 0; i < (1 << V_num); i++)
		D[i].assign(V_num, INF);
	pathDP.reserve(V_num);
	pathDP.push_back(0);
}

// Naive TSP
int TSP::TSP_naive(int len) {
	// �湮�� ������ ���� ������ ���� ���� ���
	if (temp_pathNaive.size() == V_num)
		return len + W[temp_pathNaive.back()][0];		// ��������� ���(len) + ���������� �湮�� �������� ù��° �������� �̵��ϴµ� �ʿ��� ��� ��ȯ

	int result = INF, temp;
	for (int next = 1; next < V_num; next++)
		if (!visitedList[next]) {		// ���� ������ �湮�� ������ �ƴ� ���
			int current = temp_pathNaive.back();		// ������ �湮�� ������ �߿� ���� �ֱٿ� �湮�� ����
			temp_pathNaive.push_back(next);		// ���� ������ ����
			visitedList[next] = true;		// ���� ������ �湮���� ǥ��
			if (W[current][next] != INF) {		// ���� �������� ���� �������� �̵� ������ ���
				temp = TSP_naive(len + W[current][next]);		// ��� ȣ��, ��������� ���(len) + ���� �������� ���� �������� �̵��ϴµ� �ʿ��� ��� ��ȯ
				if (result > temp) {		// ������ ����� ���
					result = temp;
					if ((temp_pathNaive.size() == V_num) && (min_lenNaive > result)) {		// �湮�� ������ ���� ������ ���� ����, �ּ� ����� ���� ������ ���
						min_lenNaive = result;		// �ּ� ��� ����
						pathNaive = temp_pathNaive;		// �ִ� ��� ����
					}
				}
			}
			visitedList[next] = false;		// ���� ������ �湮���� �������� ǥ��
			temp_pathNaive.pop_back();		// ���� ������ ����
		}

	return result;
}

// DP TSP, ��Ʈ ����ŷ
int TSP::TSP_DP(int visited, int cur) {
	visited |= (1 << cur);		// �������� �湮�� �������� ������ ���� ������ ������ �߰�

	if (visited == (1 << V_num) - 1)		// ��� ������ �湮�� ���
		if (W[cur][0] != INF) {		// ���� �������� ù��° �������� �̵������� ���
			D[visited][cur] = W[cur][0];		// ���� �������� ù��° �������� �̵������� ��츦 ����
			return W[cur][0];		// ���� �������� ù��° �������� �̵��ϴ� ��� ��ȯ
		}
		else
			return INF;

	int len = D[visited][cur];
	if (len != INF)
		return len;

	int temp;
	for (int i = 0; i < V_num; i++) {
		if ((i != cur) && !(visited & (1 << i)) && (W[cur][i] != INF)) {		// ���� ������ �ƴϰ�, �������� �湮�� ������ �ƴϰ�, ���� �������� i �������� �̵� ������ ���
			temp = TSP_DP(visited, i) + W[cur][i];		// ��� �Լ�, �������� �湮�� �����鿡�� i �������� �̵��ϴ� ��� + ���� �������� i �������� �̵��ϴ� ���
			if (len > temp) {		// �ּ� ����� ���
				len = temp;
			}
		}
	}
	D[visited][cur] = len;		// �������� �湮�� �������� ���� �������� �̵��ϴ� ��� ����

	return len;
}

// Naive�� ����� �ִ� ��ο� �ش��ϴ� ������ ���
void TSP::print_pathNaive() {
	for (int i = 0; i < int(pathNaive.size()); i++)
		cout << "V" << pathNaive[i] << " -> ";
	cout << "V0\n";
}

// DP�� ����� �ִ� ��ο� �ش��ϴ� ������ ���
void TSP::print_pathDP(int distance) {
	int temp = 0, mask = 1;

	for (int i = 0; i < V_num; i++)
		for (int j = 0; j < V_num; j++)
			if (!(mask & (1 << j)) && (distance - W[temp][j] == D[mask + (1 << j)][j])) {
				pathDP.push_back(j);
				distance = D[mask + (1 << j)][j];
				temp = j;
				mask += (1 << j);
			}

	for (int i = 0; i < pathDP.size(); i++)
		cout << "V" << pathDP[i] << " -> ";
	cout << "V0\n";
}