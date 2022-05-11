#ifndef CHEESE_H
#define CHEESE_H

#include <vector>
using std::vector;

#include <algorithm>
using std::max;

int eatCheeseMax(vector<vector<int>>& path) {
	int m = path.size(), n = path[0].size();

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if ((i > 0) && (j > 0))
				path[i][j] = max(path[i - 1][j], path[i][j - 1]) + path[i][j];
			else if ((i == 0) && (j > 0))
				path[i][j] = path[i][j - 1] + path[i][j];
			else if ((j == 0) && (i > 0))
				path[i][j] = path[i - 1][j] + path[i][j];

	return path[m - 1][n - 1];
}

#endif