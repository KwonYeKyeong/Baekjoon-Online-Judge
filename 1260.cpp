#include <iostream>
#include <queue>
using namespace std;

bool graph[1001][1001] = {};
queue<int> q;

void dfs(int s, bool check[]) {
	cout << s << ' ';
	check[s] = true;
	for (int i = 1; i < 1001; i++) {
		if (graph[s][i] == 0) continue;
		else {
			if (check[i] == true) continue;
			else dfs(i, check);
		}
	}
}
void bfs(int s, bool check[]) {
	q.push(s);
	check[s] = true;

	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		cout << tmp << ' ';
		for (int i = 1; i < 1001; i++) {
			if (graph[tmp][i] == 0) continue;
			else {
				if (check[i] == false) {
					q.push(i);
					check[i] = true;
				}
			}
		}
	}
}

int main() {
	bool check[1001] = {};
	int n, m, k, u, v;
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		graph[u][v] = true;
		graph[v][u] = true;
	}

	dfs(k, check);
	cout << '\n';
	for (int i = 1; i < 1001; i++)
		check[i] = false;
	bfs(k, check);

	return 0;
}