class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m - 1 == 0 && n - 1 == 0) {
            return 1;
        }
        else if (m - 1 == 0 && !(n - 1 == 0)) {
            return uniquePaths(m, n - 1);
        }
        else if (!(m - 1 == 0) && n - 1 == 0) {
            return uniquePaths(m - 1, n);
        }
        else {
            return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
        }
    }
};