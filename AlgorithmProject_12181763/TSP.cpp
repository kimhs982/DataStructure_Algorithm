#include "TSP.h"

// TSP 클래스 생성자(constructor)
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
	// 방문한 정점의 수가 정점의 수와 같을 경우
	if (temp_pathNaive.size() == V_num)
		return len + W[temp_pathNaive.back()][0];		// 현재까지의 비용(len) + 마지막으로 방문한 정점에서 첫번째 정점으로 이동하는데 필요한 비용 반환

	int result = INF, temp;
	for (int next = 1; next < V_num; next++)
		if (!visitedList[next]) {		// 다음 정점이 방문한 정점이 아닌 경우
			int current = temp_pathNaive.back();		// 이전에 방문한 정점들 중에 가장 최근에 방문한 정점
			temp_pathNaive.push_back(next);		// 다음 정점을 저장
			visitedList[next] = true;		// 다음 정점을 방문으로 표시
			if (W[current][next] != INF) {		// 현재 정점에서 다음 정점으로 이동 가능한 경우
				temp = TSP_naive(len + W[current][next]);		// 재귀 호출, 현재까지의 비용(len) + 현재 정점에서 다음 정점으로 이동하는데 필요한 비용 반환
				if (result > temp) {		// 가능한 경로인 경우
					result = temp;
					if ((temp_pathNaive.size() == V_num) && (min_lenNaive > result)) {		// 방문한 정점의 수가 정점의 수와 같고, 최소 비용을 갱신 가능한 경우
						min_lenNaive = result;		// 최소 비용 갱신
						pathNaive = temp_pathNaive;		// 최단 경로 저장
					}
				}
			}
			visitedList[next] = false;		// 다음 정점을 방문하지 않음으로 표시
			temp_pathNaive.pop_back();		// 다음 정점을 빼줌
		}

	return result;
}

// DP TSP, 비트 마스킹
int TSP::TSP_DP(int visited, int cur) {
	visited |= (1 << cur);		// 이제까지 방문한 정점들의 정보에 현재 정점의 정보를 추가

	if (visited == (1 << V_num) - 1)		// 모든 정점을 방문한 경우
		if (W[cur][0] != INF) {		// 현재 정점에서 첫번째 정점으로 이동가능한 경우
			D[visited][cur] = W[cur][0];		// 현재 정점에서 첫번째 정점으로 이동가능한 경우를 저장
			return W[cur][0];		// 현재 정점에서 첫번째 정점으로 이동하는 비용 반환
		}
		else
			return INF;

	int len = D[visited][cur];
	if (len != INF)
		return len;

	int temp;
	for (int i = 0; i < V_num; i++) {
		if ((i != cur) && !(visited & (1 << i)) && (W[cur][i] != INF)) {		// 현재 정점이 아니고, 이제까지 방문한 정점이 아니고, 현재 정점에서 i 정점으로 이동 가능한 경우
			temp = TSP_DP(visited, i) + W[cur][i];		// 재귀 함수, 이제까지 방문한 정점들에서 i 정점으로 이동하는 비용 + 현재 정점에서 i 정점으로 이동하는 비용
			if (len > temp) {		// 최소 비용인 경우
				len = temp;
			}
		}
	}
	D[visited][cur] = len;		// 이제까지 방문한 정점에서 현재 정점으로 이동하는 비용 저장

	return len;
}

// Naive로 계산한 최단 경로에 해당하는 정점을 출력
void TSP::print_pathNaive() {
	for (int i = 0; i < int(pathNaive.size()); i++)
		cout << "V" << pathNaive[i] << " -> ";
	cout << "V0\n";
}

// DP로 계산한 최단 경로에 해당하는 정점을 출력
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