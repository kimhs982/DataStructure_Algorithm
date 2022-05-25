#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <vector>
using std::vector;

#include <utility>
using std::pair;

#include <algorithm>
using std::max;

// jewelList의 첫 번째 index는 사용하지 않음, 보석(무게 / 가치)
int Knapsack(vector<pair<int, int>>& jewelList, int W) {
	int jewel_num = jewelList.size();
	vector<int> weight(W + 1);		// W + 1 -> W까지 index로 사용
	vector<vector<int>> P(jewel_num, weight);

	for (int i = 1; i < jewel_num; i++)
		// 최대 무게를 1씩 증가시키면서 계산
		for (int j = 0; j <= W; j++)
			if (jewelList[i].first <= j)
				P[i][j] = max(P[i - 1][j], jewelList[i].second + P[i - 1][j - jewelList[i].first]);
			else
				P[i][j] = P[i - 1][j];

	return P[jewel_num - 1][W];
}

// Knapsack 개량 알고리즘, index번째 & 배낭의 최대 용량 weight
int Knapsack_improve(vector<pair<int, int>>& jewelList, int index, int weight) {
	if ((index == 1) || (weight <= 0)) {
		if (weight <= 0)
			return 0;
		else if (jewelList[index].first <= weight)
			return jewelList[index].second;
		else
			return 0;
	}
	else {
		if (jewelList[index].first <= weight)
			return max(Knapsack_improve(jewelList, index - 1, weight), jewelList[index].second + Knapsack_improve(jewelList, index - 1, weight - jewelList[index].first));
		else
			return Knapsack_improve(jewelList, index - 1, weight);
	}
}

#endif