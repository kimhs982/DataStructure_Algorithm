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
	int TSP_naive(int = 0);		// Naive ������� �ִ� ��� ���
	void print_pathNaive();		// Naive�� ����� �ִ� ��ο� �ش��ϴ� ������ ���
	// TSP DP(Dynamic Programming)
	int TSP_DP(int = 0, int = 0);		// DP ������� �ִ� ��� ���
	void print_pathDP(int);		// DP�� ����� �ִ� ��ο� �ش��ϴ� ������ ���
private:
	const vector<vector<int>>& W;		// ���� ����ġ �׷���
	const int V_num;		// ������ ����
	// TSP Naive
	int min_lenNaive;		// �ִ� ����� ���̸� ����
	vector<bool> visitedList;		// ������ �湮 ���� ����
	vector<int> temp_pathNaive;
	vector<int> pathNaive;		// Naive�� ����� �ִ� ��ο� �ش��ϴ� ������ ����
	// TSP DP
	vector<vector<int>> D;		// ��Ʈ ����ŷ ������� �湮�� ������ ����� ����
	vector<int> pathDP;		// DP�� ����� �ִ� ��ο� �ش��ϴ� ������ ����
};

#endif