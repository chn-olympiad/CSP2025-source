#include <bits/stdc++.h>
using namespace std;
struct node {
	int v, w;
};
int n, m, k, c[15], a[15][10005];
int Start = 1, Max, End = 1, Max2;
vector<node> vec[10005];
int fg[10005];

void BFS(int st, int op) {
	queue<int> q;
	q.push(st);
	fg[st] = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for (node it : vec[u]) {
			if (fg[it.v]) continue;
			fg[it.v] = fg[u] + 1;
			if (op == 1) if (fg[it.v] > Max) Max = fg[it.v], Start = it.v;
			if (op == 2) if (fg[it.v] > Max2) Max2 = fg[it.v], End = it.v;
			q.push(it.v);
		}
	}
}

void DFS(int u) {
	for (node it : vec[u]) {
		if (fg[it.v] > fg[u] + it.w) {
			fg[it.v] = fg[u] + it.w;
			DFS(it.v);
		}
	} 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	bool flag = false;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		vec[u].push_back({v, w}), vec[v].push_back({u, w});
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		flag = c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			flag = c[i];
		}
	}
	if (k == 0) {
		BFS(1, 1);
		memset(fg, 0, sizeof(fg));
		BFS(Start, 2);
		memset(fg, 0x3f, sizeof(fg));
		fg[Start] = 0;
		DFS(Start);
		cout << fg[End];
	} else if (!flag) cout << 0;
	return 0;
}
