#include <iostream>
#include <vector>

using namespace std;

class PartitionSet {
public:
    int canPartition(const vector<int> &num) { 
        return this->canPartitionRecursive(num, 0, 0, 0); 
    }

private:
    int canPartitionRecursive(const vector<int> &num, int current_idx, int sum1, int sum2) {
        // base check
        if (current_idx == num.size()) {
            return abs(sum1 - sum2);
        }
        int diff1 = canPartitionRecursive(num, current_idx + 1, sum1 + num[current_idx], sum2);
        int diff2 = canPartitionRecursive(num, current_idx + 1, sum1, sum2 + num[current_idx]);

        return min(diff1, diff2);
    }
};


class topDown {
public:
    int canPartition(const vector<int> &num) {
        int sum = 0;
        for (int i = 0; i < num.size(); i++) {
            sum += num[i];
        }

        vector<vector<int>> dp(num.size(), vector<int>(sum+1, -1));
        return this->canPartitionRecursive(dp, num, 0, 0, 0);
    }

private:
    int canPartitionRecursive(vector<vector<int>> &dp, const vector<int> &num, int current_idx, int sum1, int sum2) {
        if (current_idx == num.size()) {
            return abs(sum1 - sum2);
        }

        if (dp[current_idx][sum1] == -1) {
            int diff1 = canPartitionRecursive(dp, num, current_idx + 1, sum1 + num[current_idx], sum2);
            int diff2 = canPartitionRecursive(dp, num, current_idx + 1, sum1, sum2 + num[current_idx]);
            dp[current_idx][sum1] = min(diff1, diff2);
        }

        return dp[current_idx][sum1];
    }
};


class bottomUp {
public:
    int canPartition(const vector<int> &num) {
        int sum = 0;
        for (int i = 0; i < num.size(); i++) {
            sum += num[i];
        }

        int n = num.size();
        vector<vector<bool>> dp(n, vector<bool>(sum / 2 + 1, false));

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        for (int s = 1; s <= sum / 2; s++) {
            dp[0][s] = (num[0] == s ? true : false);
        }

        for (int i = 1; i < num.size(); i++) {
            for (int s = 1; s <= sum / 2; s++) {
                if (dp[i - 1][s]) {
                    dp[i][s] = dp[i - 1][s];
                }
                else if (s >= num[i]) {
                    dp[i][s] = dp[i - 1][s - num[i]];
                }
            }
        }

        int sum1 = 0;
        for (int i = sum / 2; i >= 0; i--) {
            if (dp[n - 1][i] == true) {
                sum1 = i;
                break;
            }
        }

        int sum2 = sum - sum1;
        return abs(sum2 - sum1);
    }
};

int main(int argc, char *argv[]) {
    PartitionSet ps1;
    topDown ps2;
    bottomUp ps3;

    vector<int> num = {1, 2, 3, 9};
    cout << ps1.canPartition(num) << endl;
    num = vector<int>{1, 2, 7, 1, 5};
    cout << ps1.canPartition(num) << endl;
    num = vector<int>{1, 3, 100, 4};
    cout << ps1.canPartition(num) << endl;

    num = vector<int>{1, 2, 3, 9};
    cout << ps2.canPartition(num) << endl;
    num = vector<int>{1, 2, 7, 1, 5};
    cout << ps2.canPartition(num) << endl;
    num = vector<int>{1, 3, 100, 4};
    cout << ps2.canPartition(num) << endl;

    num = vector<int>{1, 2, 3, 9};
    cout << ps3.canPartition(num) << endl;
    num = vector<int>{1, 2, 7, 1, 5};
    cout << ps3.canPartition(num) << endl;
    num = vector<int>{1, 3, 100, 4};
    cout << ps3.canPartition(num) << endl;
}