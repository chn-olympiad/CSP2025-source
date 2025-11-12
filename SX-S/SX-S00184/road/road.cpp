#include <bits/stdc++.h>
using namespace std;
int cnt;

struct Node {
	int from, to, next, len;
	bool operator <(const Node &n1)const {
		return len > n1.len;
	}
} a[3010000];
int n, m, k, c, pre[10100];
bool b[10100];
long long ans = 0;
priority_queue<Node> q;

void add(int u, int v, int len) {
	c++;
	a[c].from = u;
	a[c].to = v;
	a[c].len = len;
	a[c].next = pre[u];
	pre[u] = c;
	q.push(a[c]);
}


int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v, len;
		scanf("%d%d%d", &u, &v, &len);
		add(u, v, len);
		add(v, u, len);
	}
	for (int i = 1; i <= k; i++) {
		int j;
		scanf("%d", &j);
		for (int l = 1; l <= n; l++) {
			int cost;
			scanf("%d", &cost);
			add(i + n, l, cost);
			add(l, i + n, cost);
		}
	}
	Node top = q.top();
	b[top.from] = true;
	b[top.to] = true;
	ans += top.len;
	q.pop();
	cnt++;
	while (!q.empty()) {
		if (cnt == n - 1)
			break;
		top = q.top();
		if (b[top.from] != b[top.to]) {
			cnt++;
			b[top.from] = true;
			b[top.to] = true;
			ans += top.len;
		}
		q.pop();
	}
	cout << ans << endl;
	return 0;
}