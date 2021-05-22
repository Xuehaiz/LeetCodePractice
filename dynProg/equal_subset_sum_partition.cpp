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
				}
			}
		}

		return canPartitionRecursive(num, sum, current_idx + 1);
	}
};

int main(int argc, char *argv[]) {
	PartitionSet ps;
	vector<int> num = {1, 2, 3, 4};
	cout << ps.canPartition(num) << endl;
	num = vector<int>{1, 1, 3, 4, 7};
	cout << ps.canPartition(num) << endl;
	num = vector<int>{2, 3, 4, 6};
	cout << ps.canPartition(num) << endl;
}