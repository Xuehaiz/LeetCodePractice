#include <iostream>
#include <vector>

using namespace std;

class SubsetSum {
public:
	bool canPartition(const vector<int> &num, int sum) {
		int n = num.size();
		vector<vector<bool>> dp(n, vector<bool>(sum+1));
		
		// populate the 0's column to true
		for (int i = 0; i < n; i++) {
			dp[i][0] = true;
		}

		// first row: check if the only number equals to the sum value
		for (int s = 0; s <= sum; s++) {
			dp[0][s] = (num[0] == s ? true : false);
		}

		// fill out the table
		for (int i = 1; i < n; i++) {
			for (int s = 1; s <= sum; s++) {
				if (dp[i-1][s]) {
					dp[i][s] = dp[i-1][s];
				}
				else if (s >= num[i]) {
					dp[i][s] = dp[i-1][s-num[i]];
				}
			}
		}

		return dp[n-1][sum];
	}
};


int main(int argc, char *argv[]) {
	SubsetSum ss;
	vector<int> num = {1, 2, 3, 7};
	cout << ss.canPartition(num, 6) << endl;
	num = vector<int>{1, 2, 7, 1, 5};
	cout << ss.canPartition(num, 10) << endl;
	num = vector<int>{1, 3, 4, 8};
	cout << ss.canPartition(num, 6) << endl;
}