#include <iostream>
#include <vector>

using namespace std;

class topDown {

public:
	virtual int CalculateFibonacci (int n) {
		vector<int> memoize(n + 1, 0);
		return CalculateFibonacciRecursive(memoize, n);
	}

	virtual int CalculateFibonacciRecursive(vector<int> &memoize, int n) {
		if (n < 2) {
			return n;
		}
		if (memoize[n] != 0) {
			return memoize[n];
		}
		memoize[n] = CalculateFibonacciRecursive(memoize, n - 1) + CalculateFibonacciRecursive(memoize, n - 2);
		return memoize[n];
	}
};

class bottomUp {

public:
	virtual int CalculateFibonacci(int n) {
		if (n == 0) return 0;
		vector<int> dp(n + 1);
		dp[0] = 0;
		dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];
	}
};

int main(int argc, char *argv[]) {
	topDown *fib1 = new topDown();
	bottomUp *fib2 = new bottomUp();
	cout << "5th topDown is ---> " << fib1->CalculateFibonacci(5) << endl;
  	cout << "6th topDown is ---> " << fib1->CalculateFibonacci(6) << endl;
  	cout << "7th topDown is ---> " << fib1->CalculateFibonacci(7) << endl;
  	cout << "5th bottomUp is ---> " << fib2->CalculateFibonacci(5) << endl;
  	cout << "6th bottomUp is ---> " << fib2->CalculateFibonacci(6) << endl;
  	cout << "7th bottomUp is ---> " << fib2->CalculateFibonacci(7) << endl;
}

