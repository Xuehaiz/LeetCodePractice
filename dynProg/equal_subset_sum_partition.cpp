#include <iostream>
#include <vector>

using namespace std;

class PartitionSet {
public:
  bool canPartition(const vector<int> &num) {
    int sum = 0;
    for (int i = 0; i < num.size(); i++) {
    	sum += num[i];
    }

    // if 'sum' is an odd number, we can't have two subsets with equal sum
    if (sum % 2 != 0) {
    	return false;
    }

  	return this->canPartitionRecursive(num, sum/2, 0);
  }

private:
	bool canPartitionRecursive(const vector<int> &num, int sum, int current_idx) {
		// base check
		if (sum == 0) {
			return true;
		}

		if (num.empty() || current_idx >= num.size()) {
			return false;
		}

		if (num[current_idx] <= sum) {
			if (canPartitionRecursive(num, sum - num[current_idx], current_idx + 1)) {
				return true;
			}
		}

	return canPartitionRecursive(num, sum, current_idx + 1);
	}
};

class topDown {
public:
	bool canPartition(const vector<int> &num) {
	int sum = 0;
	for (int i = 0; i < num.size(); i++) {
		sum += num[i];
	}

	// if 'sum' is an odd number, we can't have two subsets with equal sum
	if (sum % 2 != 0) {
		return false;
	}

	vector<vector<int>> dp(num.size(), vector<int>(sum / 2 + 1, -1));
	return this->canPartitionRecursive(dp, num, sum/2, 0);
	}

private:
	bool canPartitionRecursive(vector<vector<int>> &dp, const vector<int> &num, int sum, int current_idx) {
		// base check
		if (sum == 0) {
			return true;
		}

		if (num.empty() || current_idx >= num.size()) {
			return false;
		}

		if (dp[current_idx][sum] == -1) {
			if (num[current_idx] <= sum) {
				if (canPartitionRecursive(dp, num, sum - num[current_idx], current_idx + 1)) {
					dp[current_idx][sum] = 1;
					return true;
				}
			}

			// recursive call after excluding the number at the current index
			dp[current_idx][sum] = canPartitionRecursive(dp, num, sum, current_idx + 1) ? 1 : 0;
		}

		return dp[current_idx][sum] == 1 ? true : false;
	}
};

class bottomUp {
public:
  	bool canPartition(const vector<int> &num) {
    	int n = num.size();
    	// find total sum
    	int sum = 0;
    	for (int i = 0; i < n; i++) {
    		sum += num[i];
    	}
    	// if 'sum' is an odd number then return false
    	if (sum % 2 != 0) {
    		return false;
    	}
    	// split up sum
    	sum /= 2;

    	// initialize dp table
    	vector<vector<bool>> dp(n, vector<bool>(sum + 1));

    	// populate the 0's collum to be true
    	for (int i = 0; i < n; i++) {
    		dp[i][0] = true;
    	}

    	for (int s = 1; s <= sum; s++) {
    		dp[0][s] = (num[0] == s ? true : false);
    	}
  		
    	// process all subsets for all sums
    	for (int i = 1; i < n; i++) {
    		for (int s = 1; s <= sum; s++) {
    			if (dp[i-1][s]) {
    				dp[i][s] = dp[i-1][s];
    			}
    			else if (s >= num[i]) {
    				dp[i][s] = dp[i-1][s - num[i]];
    			}
    		}
    	}

    	return dp[n-1][sum];
  	}
};

int main(int argc, char *argv[]) {
	PartitionSet ps1;
	topDown ps2;
	bottomUp ps3;
	vector<int> num = {1, 2, 3, 4};
	cout << ps1.canPartition(num) << endl;
	num = vector<int>{1, 1, 3, 4, 7};
	cout << ps1.canPartition(num) << endl;
	num = vector<int>{2, 3, 4, 6};
	cout << ps1.canPartition(num) << endl;

	num = {1, 2, 3, 4};
	cout << ps2.canPartition(num) << endl;
	num = vector<int>{1, 1, 3, 4, 7};
	cout << ps2.canPartition(num) << endl;
	num = vector<int>{2, 3, 4, 6};
	cout << ps2.canPartition(num) << endl;

	num = {1, 2, 3, 4};
	cout << ps3.canPartition(num) << endl;
	num = vector<int>{1, 1, 3, 4, 7};
	cout << ps3.canPartition(num) << endl;
	num = vector<int>{2, 3, 4, 6};
	cout << ps3.canPartition(num) << endl;
}