#include <iostream>
using namespace std;

int n, maxx; 
int dp[2][17];

void DFS(int k, int result) {
	if (k > n) 
		maxx = (maxx < result ? result : maxx);

	if (k + dp[0][k] <= n) // �ش糯�� ��� O
		DFS(k + dp[0][k], result + dp[1][k]);
	if (k <= n) // �ش糯�� ��� X
		DFS(k + 1, result);
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) 
		cin >> dp[0][i] >> dp[1][i];
	dp[0][n] = 1;

	DFS(0, 0);

	cout << maxx;

	return 0;
}