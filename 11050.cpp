#include <iostream>
using namespace std;

int dp[11];

int main() {
	int n, k;

	cin >> n >> k;

	dp[0] = 1;
	for (int i = 1; i <= k; i++) {
		dp[i] = dp[i - 1] * (n + 1 - i) / i;
	}

	cout << dp[k];

	return 0;
}