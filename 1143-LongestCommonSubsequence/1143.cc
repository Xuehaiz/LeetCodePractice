#include "stdc++.h"
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <string>
using namespace std;
using std::string;

class LCS {
public:
    string text1;
    string text2;
    
    int max(int a, int b) {
        return (a > b) ? a : b;
    }
    
    void setText1(string text) {
        text1 = text;
        // strcpy(text1, text);
    }
    
    void setText2(string text) {
        text2 = text;
        // strcpy(text2, text);
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n,m;
        n = text1.length();
        m = text2.length();

        int memo[n+1][m+1];
        int i,j;

        // for (i = 0; i <= n; i++) {
        //     for (j = 0; j <= m; j++) {
        //         memo[i][j] = 0;
        //     }
        // }
        
        for (i = 0; i <= n; i++) {
            for (j = 0; j <= m; j++) {
                if (i == 0 || j == 0) {
                    memo[i][j] = 0;
                }
                else if (text1[i-1] == text2[j-1]) {
                    // cout << text1[i] << "," << text2[j] << endl;
                    memo[i][j] = 1 + memo[i - 1][j - 1];
                }
                else {
                    memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
                }
            }
        }
        // for (i = 0; i <= n; i++) {
        //     cout << endl;
        //     for (j = 0; j <= m; j++) {
        //         cout << memo[i][j] << endl;
        //     }
        // }
        return memo[n][m];
    }
};


int main() {
    LCS lcs;
    int answer;
    
    lcs.setText1("abc");
    lcs.setText2("def");
    // int n = strlen(lcs.text1);
    // int m = strlen(lcs.text2);
    answer = lcs.longestCommonSubsequence(lcs.text1, lcs.text2);

    // cout << answer << endl;
    
}