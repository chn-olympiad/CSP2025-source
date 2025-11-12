#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int, int>
#define fi first
#define se second
using namespace std;

const int N = 1e4 + 10;
const int M = 1e6 + 10;
const int K = 20;

int f[N];

struct aa {
	int u, v, w;
} h[M];

bool cmp(aa a, aa b) {
	return a.w < b.w;
}

int find(int x) {
	if (f[x] == x)
		return x;
	return f[x] = find(f[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	f[x] = y;
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	if (k == 0) {
		for (int i = 1; i <= n; i ++) {
			f[i] = i;
		}
		for (int i = 1; i <= m; i ++) {
			cin >> h[i].u >> h[i].v >> h[i].w;
		}
		sort(h + 1, h + m + 1, cmp);
		int sum = 0;
		for (int i = 1; i <= m; i ++) {
			if (find(h[i].u) != find(h[i].v)) {
				merge(h[i].u, h[i].v);
				sum += h[i].w;
			}
		}
		cout << sum << endl;
	} else {
		cout << 0 << endl;
	}
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();

	return 0;
}
// AKCSP-S2025!!!
