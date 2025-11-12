#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e4+5, M = 1e6+5;
int n, m, c[15][N], cnt, k, u, v, w;
ll ans;
bool flag = 0;

struct T {
	int u, v, w;
	operator< (T const &other)const & {
		return w > other.w;
	}
};

priority_queue<T>q;

struct Q {
	int to, s;
} f[N];

int find(int x) {
	if (f[x].to == x)
		return x;
	f[x].to = find(f[x].to);
	return f[x].to;
}

void add(int x, int y) {
	int u = find(x);
	int v = find(y);
	f[u].to = v;
	f[v].s += f[u].s;
}

void ss() {
	while (!q.empty()) {
		T t = q.top();
		q.pop();
		int u = t.u, v = t.v, w = t.w;
		int r = find(u);
		if ( r != find(v)) {
			ans += w;
			add(u, v);
		}
		if (f[r].s == n) {
			return;
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		q.push({u, v, w});
	}
	cnt = m;
	for (int i = 1; i <= n; i++) {
		f[i].to = i;
		f[i].s = 1;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i][0];
		if (c[i] != 0) {
			flag = 1;
		}
		for (int j = 1; j <= n; j++) {
			cin >> c[i][j];
		}
	}
	if (flag == 0 && n <= 1e3) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int t = 0x3f3f3f3f;
				for (int d = 1; d <= k; d++) {
					t = min(t, c[d][i] + c[d][j]);
				}
				q.push({i, j, t});
			}
		}
		ss();
		cout << ans;
		return 0;
	}
	if (k == 0) {
		ss();
		cout << ans;
		return 0;
	}
	if (n <= 1e3+5) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int t = 0x3f3f3f3f;
				for (int d = 1; d <= k; d++) {
					t = min(t, c[d][i] + c[d][j]);
				}
				q.push({i, j, t});
			}
		}
		ss();
		cout << ans;
		return 0;
	}
	ss();
	cout << ans;
	return 0;
}
