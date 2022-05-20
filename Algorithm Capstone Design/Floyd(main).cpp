#include "Floyd.h"
#define infinity 100000000		// ∞를 표현

int main() {
	// weight 행렬
	vector<vector<int>> W =
	{
		{0,0,0,0,0,0},
		{0,0,1,infinity,1,5},
		{0,9,0,3,2,infinity},
		{0,infinity,infinity,0,4,infinity},
		{0,infinity,infinity,2,0,3},
		{0,3,infinity,infinity,infinity,0}
	};

	floyd_path(W);

	return 0;
}