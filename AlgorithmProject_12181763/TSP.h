#ifndef TSP_H
#define TSP_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>

using namespace std;

#include "defines.h"

class TSP {
public:
	TSP(const vector<vector<int>>&);
	// TSP Naive
	int TSP_naive(int = 0);		// Naive 방법으로 최단 경로 계산
	void print_pathNaive();		// Naive로 계산한 최단 경로에 해당하는 정점을 출력
	// TSP DP(Dynamic Programming)
	int TSP_DP(int = 0, int = 0);		// DP 방법으로 최단 경로 계산
	void print_pathDP(int);		// DP로 계산한 최단 경로에 해당하는 정점을 출력
private:
	const vector<vector<int>>& W;		// 유향 가중치 그래프
	const int V_num;		// 정점의 개수
	// TSP Naive
	int min_lenNaive;		// 최단 경로의 길이를 저장
	vector<bool> visitedList;		// 정점의 방문 여부 저장
	vector<int> temp_pathNaive;
	vector<int> pathNaive;		// Naive로 계산한 최단 경로에 해당하는 정점을 저장
	// TSP DP
	vector<vector<int>> D;		// 비트 마스킹 방법으로 방문한 정점의 비용을 저장
	vector<int> pathDP;		// DP로 계산한 최단 경로에 해당하는 정점을 저장
};

#endif