#ifndef TSP_H
#define TSP_H

#define INF 999

#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

class TSP {
public:
	TSP(const vector<vector<int>>&);
	// TSP Naive
	int TSP_naive(int = 0);
	void print_pathNaive();
	// TSP DP(Dynamic Programming)
	int TSP_DP(int = 0, int = 0);
	void print_pathDP(int);
private:
	const vector<vector<int>>& W;
	const int V_num;
	// TSP Naive
	int min_lenNaive;
	vector<bool> visitedList;
	vector<int> temp_pathNaive;
	vector<int> pathNaive;
	// TSP DP
	vector<vector<int>> D;
	vector<int> pathDP;
};

#endif