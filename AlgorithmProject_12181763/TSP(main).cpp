#include "TSP.h"

void print_graph(const vector<vector<int>>&);

int main()
{
	vector<int> path;
	vector<vector<int>> graph1 =
	{
		{0, 2, 9, INF},
		{1, 0, 6, 4},
		{INF, 7, 0, 8},
		{6, 3, INF, 0}
	};

	print_graph(graph1);
	cout << '\n';

	cout << "TSP(Naive)\n";
	cout << "최단 경로의 길이: " << TSP_Naive(graph1, path) << '\n';
	cout << "최소 일주경로: ";
	print_pathNaive(path);

	return 0;
}

void print_graph(const vector<vector<int>>& weight) {
	int row = weight.size(), col = weight[0].size();
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << weight[i][j] << ' ';
		cout << '\n';
	}
}