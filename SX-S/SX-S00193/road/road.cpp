#include <bits/stdc++.h>
using namespace std;

struct node {
	long long u, v, w;
};

bool operator<(node a, node b) {
	return a.w > b.w;
}
priority_queue<node> qf, qt, q;
int fa[10005];

int find(int x) {
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	fa[find(x)] = find(y);
}
int n, m, k;
long long c[15], a[15][10005];
long long ans = 0;

void work(int opt) {
	q = qt;
	long long cost = 0, cnt = 0;
	for (int i = 1; i <= k; i++) {
		if (opt % 2 == 1) {
			cost += c[i];
			cnt--;
			for (int j = 1; j <= n; j++)
				q.push(node{n + i, j, a[i][j]});
		}
		opt /= 2;
	}
	for (int i = 1; i <= n + k; i++)
		fa[i] = i;
	while (!q.empty() && cnt < n - 1) {
		node tmp = q.top();
		q.pop();
		if (find(tmp.u) != find(tmp.v)) {
			merge(tmp.u, tmp.v);
			cnt++;
			cost += tmp.w;
		}
	}
	ans = min(ans, cost);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v;
		long long w;
		cin >> u >> v >> w;
		qf.push(node{u, v, w});
	}
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	long long cost = 0, cnt = 0;
	while (!qf.empty() && cnt < n - 1) {
		node tmp = qf.top();
		qf.pop();
		if (find(tmp.u) != find(tmp.v)) {
			merge(tmp.u, tmp.v);
			cnt++;
			cost += tmp.w;
			qt.push(tmp);
			//cout << tmp.u << " " << tmp.v << endl;
		}
	}
	ans = cost;
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	}
	for (int i = 1; i < (1 << k); i++)
		work(i);
	cout << ans;
	return 0;
}
