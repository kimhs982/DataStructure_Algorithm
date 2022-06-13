#include "TSP.h"

int TSP_Naive(const vector<vector<int>>& weight, vector<int>& path, int len) {
	const int V_num = weight.size();
	static int min_len = INF;
	static vector<bool> visited(V_num, false);
	visited[0] = true;
	static vector<int> temp_path(1, 0);

	if (temp_path.size() == V_num)
		return len + weight[temp_path.back()][0];
	
	int result = INF, temp;
	for (int next = 1; next < V_num; next++)
		if (!visited[next]) {
			int current = temp_path.back();
			temp_path.push_back(next);
			visited[next] = true;
			if (weight[current][next] != INF) {
				temp = TSP_Naive(weight, path, len + weight[current][next]);
				if (result > temp) {
					result = temp;
					if ((temp_path.size() == V_num) && (min_len > result)) {
						min_len = result;
						path = temp_path;
					}
				}
			}
			visited[next] = false;
			temp_path.pop_back();
		}

	return result;
}

void print_pathNaive(const vector<int>& path) {
	for (int i = 0; i < int(path.size()); i++)
		cout << "V" << path[i] << " -> ";
	cout << "V0\n";
}