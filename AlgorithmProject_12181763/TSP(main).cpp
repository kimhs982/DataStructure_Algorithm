#include <ctime>
#include "TSP.h"

void print_graph(const vector<vector<int>>&);

int main()
{
	int min_lenNaive, min_lenDP;
	clock_t start, end;

	vector<vector<int>> graph1 =
	{
		{0, 2, 9, INF},
		{1, 0, 6, 4},
		{INF, 7, 0, 8},
		{6, 3, INF, 0}
	};

	vector<vector<int>> graph2 =
	{
		{0, 10, 10, 30, 25},
		{10, 0, 14, 21, 10},
		{10, 18, 0, 7, 9},
		{8, 11, 7, 0, 3},
		{14, 10, 10, 3, 0}
	};

	vector<vector<int>> graph3 =
	{
		{0, 13, 41, 20, 19, 18, 44, 82, 33, 16},
		{28, 0, 50, 60, 26, 59, 35, 45, 71, 25},
		{39, 32, 0, 29, 38, 41, 10, 37, 81, 15},
		{20, 27, 39, 0, 44, 36, 24, 48, 45, 23},
		{20, 41, 16, 28, 0, 68, 18, 13, 71, 67},
		{28, 45, 34, 37, 51, 0, 25, 30, 36, 18},
		{78, 27, 44, 15, 60, 11, 0, 29, 31, 12},
		{21, 19, 25, 40, 16, 45, 33, 0, 20, 35},
		{47, 17, 22, 53, 38, 23, 19, 16, 0, 49},
		{67, 38, 72, 26, 13, 12, 48, 55, 10, 0}
	};

	TSP G1(graph1);
	TSP G2(graph2);
	TSP G3(graph3);

	cout << "그래프 1(정점 4개)\n";
	print_graph(graph1);
	cout << '\n';

	start = clock();
	min_lenNaive = G1.TSP_naive();
	end = clock();
	cout << "TSP(Naive)\n";
	cout << "최단 경로의 길이: " << min_lenNaive << '\n';
	cout << "최소 일주경로: ";
	G1.print_pathNaive();
	cout << "수행시간 : " << end - start << "ms\n";

	start = clock();
	min_lenDP = G1.TSP_DP();
	end = clock();
	cout << "\nTSP(DP)\n";
	cout << "최단 경로의 길이: " << min_lenDP << '\n';
	cout << "최소 일주경로: ";
	G1.print_pathDP(min_lenDP);
	cout << "수행시간 : " << end - start << "ms\n";

	cout << "\n그래프 2(정점 5개)\n";
	print_graph(graph2);
	cout << '\n';

	start = clock();
	min_lenNaive = G2.TSP_naive();
	end = clock();
	cout << "TSP(Naive)\n";
	cout << "최단 경로의 길이: " << min_lenNaive << '\n';
	cout << "최소 일주경로: ";
	G2.print_pathNaive();
	cout << "수행시간 : " << end - start << "ms\n";

	start = clock();
	min_lenDP = G2.TSP_DP();
	end = clock();
	cout << "\nTSP(DP)\n";
	cout << "최단 경로의 길이: " << min_lenDP << '\n';
	cout << "최소 일주경로: ";
	G2.print_pathDP(min_lenDP);
	cout << "수행시간 : " << end - start << "ms\n";

	cout << "\n그래프 3(정점 10개)\n";
	print_graph(graph3);
	cout << '\n';

	start = clock();
	min_lenNaive = G3.TSP_naive();
	end = clock();
	cout << "TSP(Naive)\n";
	cout << "최단 경로의 길이: " << min_lenNaive << '\n';
	cout << "최소 일주경로: ";
	G3.print_pathNaive();
	cout << "수행시간 : " << end - start << "ms\n";

	start = clock();
	min_lenDP = G3.TSP_DP();
	end = clock();
	cout << "\nTSP(DP)\n";
	cout << "최단 경로의 길이: " << min_lenDP << '\n';
	cout << "최소 일주경로: ";
	G3.print_pathDP(min_lenDP);
	cout << "수행시간 : " << end - start << "ms\n";

	return 0;
}

void print_graph(const vector<vector<int>>& weight) {
	int row = weight.size(), col = weight[0].size();
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << setw(3) << weight[i][j] << ' ';
		cout << '\n';
	}
}