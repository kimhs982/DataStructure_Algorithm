#ifndef TSP_H
#define TSP_H

#define INF 999

#include <iostream>
#include <vector>

using namespace std;

int TSP_Naive(const vector<vector<int>>&, vector<int>&, int = 0);
int TSP_DP(const vector<vector<int>>&, vector<int>&);

void print_graph(const vector<vector<int>>&);
void print_pathNaive(const vector<int>&);
void print_pathDP(const vector<vector<int>>&);

#endif