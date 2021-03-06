#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, k, visited[100001];
queue<pair<int, int>> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> n >> k;

	q.push(make_pair(n, 0));
	visited[n] = 1;
	while (!q.empty()) {
		int f = q.front().first;
		int s = q.front().second;

		if (f == k) {
			cout << s;
			break;
		}
		else q.pop();

		if (f > 0 && !visited[f - 1]) {
			q.push(make_pair(f - 1, s + 1));
			visited[f - 1] = 1;
		}
		if (f < 100000 && !visited[f + 1]) {
			q.push(make_pair(f + 1, s + 1));
			visited[f + 1] = 1;
		}
		if (f <= 50000 && !visited[f * 2]) {
			q.push(make_pair(f * 2, s + 1));
			visited[f * 2] = 1;
		}
	}

	return 0;
}