#pragma once
#include <vector>
#include <algorithm>

int dratewka(int N, int W, std::vector<int>& prices, std::vector<int>& weights)
{
	if (N == 0 || W == 0)
		return 0;

	if (weights[N - 1] > W)
		return dratewka(N - 1, W, prices, weights);

	return std::max(dratewka(N - 1, W, prices, weights), prices[N - 1] + dratewka(N - 1, W - weights[N - 1], prices, weights));
}
