#include <iostream>
#include <vector>

using namespace std;

class bruteForce {
public:
	int solveKnapsack(const vector<int> &profits, const vector<int> &weights, int capacity) {
	return this->knapsackRecursive(profits, weights, capacity, 0);
	}

private:
	int knapsackRecursive(const vector<int> &profits, const vector<int> &weights, int capacity, int current_idx) {
		if (capacity <= 0 || current_idx >= profits.size()) {
			return 0;
		}
		int profit1 = 0;
		if (weights[current_idx] <= capacity) {
			profit1 = profits[current_idx] + knapsackRecursive(profits, weights, 
															   capacity - weights[current_idx], 
															   current_idx+1);
		}
		int profit2 = knapsackRecursive(profits, weights, capacity, current_idx+1);

		return max(profit1, profit2);
	}
};


class topDown {
public:
	int solveKnapsack(const vector<int> &profits, const vector<int> &weights, int capacity) {
    	vector<vector<int>> dp(profits.size(), vector<int>(capacity+1, -1));
    	return this->knapsackRecursive(dp, profits, weights, capacity, 0);
    }

private:
	int knapsackRecursive(vector<vector<int>> &dp, const vector<int> &profits, const vector<int> &weights,
						  int capacity, int current_idx) {
		// base case
		if (capacity <= 0 || current_idx >= profits.size()) {
			return 0;
		}
		// read table
		if (dp[current_idx][capacity] != -1) {
			return dp[current_idx][capacity];
		}
		int profit1	= 0;
		if (weights[current_idx] <= capacity) {
			profit1 = profits[current_idx] + knapsackRecursive(dp, profits, weights, 
															   capacity - weights[current_idx],
															   current_idx+1);
		}
		int profit2 = knapsackRecursive(dp, profits, weights, capacity, current_idx+1);
		dp[current_idx][capacity] = max(profit1, profit2);
		return dp[current_idx][capacity];
	}
};


class bottomUp {

public:
	int solveKnapsack(const vector<int> &profits, const vector<int> &weights, int capacity) {
		// basic checks
	    if (capacity <= 0 || profits.empty() || weights.size() != profits.size()) {
	    	return 0;
	    }

	    int n = profits.size();
    	vector<vector<int>> dp(n, vector<int>(capacity + 1));

    	// populate the capacity=0 columns, with '0' capacity we have '0' profit
	    for (int i = 0; i < n; i++) {
      		dp[i][0] = 0;
	    }

	    // if we have only one weight, we will take it if it is not more than the capacity
	    for (int c = 0; c <= capacity; c++) {
		    if (weights[0] <= c) {
		      dp[0][c] = profits[0];
		    }
    	}

    	// process all sub-arrays for all the capacities
    	for (int i = 1; i < n; i++) {
        	for (int c = 1; c <= capacity; c++) {
		        int profit1 = 0, profit2 = 0;
		        // include the item, if it is not more than the capacity
		        if (weights[i] <= c) {
		        	profit1 = profits[i] + dp[i - 1][c - weights[i]];
		        }
		        // exclude the item
		        profit2 = dp[i - 1][c];
		        // take maximum
		        dp[i][c] = max(profit1, profit2);
        	}
    	}

    	// maximum profit will be at the bottom-right corner.
    	return dp[n - 1][capacity];
	}
};

int main(int argc, char *argv[]) {
	bruteForce ks1;
	topDown ks2;
	bottomUp ks3;
	vector<int> profits = {1, 6, 10, 16};
	vector<int> weights = {1, 2, 3, 5};
	int maxProfit1 = ks1.solveKnapsack(profits, weights, 7);
	cout << "Total knapsack profit 1:---> " << maxProfit1 << endl;
	maxProfit1 = ks1.solveKnapsack(profits, weights, 6);
	cout << "Total knapsack profit 1:---> " << maxProfit1 << endl;

	int maxProfit2 = ks2.solveKnapsack(profits, weights, 7);
	cout << "Total knapsack profit 2:---> " << maxProfit2 << endl;
	maxProfit2 = ks2.solveKnapsack(profits, weights, 6);
	cout << "Total knapsack profit 2:---> " << maxProfit2 << endl;

	int maxProfit3 = ks3.solveKnapsack(profits, weights, 7);
	cout << "Total knapsack profit 3:---> " << maxProfit3 << endl;
	maxProfit3 = ks2.solveKnapsack(profits, weights, 6);
	cout << "Total knapsack profit 3:---> " << maxProfit3 << endl;
}