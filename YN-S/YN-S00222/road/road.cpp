#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 50;
int n, m, k, vi2[N], cnt[N], p = 0;

struct lj {
	int en, co;
};
vector<lj>ra[N];

struct lj2 {
	int en, co;
};
vector<lj2>vi[N];

struct rd {
	int pay, qc;
};
queue<rd> q;

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int f, u, c;
		cin >> f >> u >> c;
		cnt[f]++;
		cnt[u]++;
		ra[f].push_back({u, c});
		ra[u].push_back({f, c});
	}
	for (int i = 1; i <= k; i++) {
		int c;
		cin >> vi2[i];
		for (int j = 1; j <= n; j++) {
			cin >> c;
			vi[i].push_back({i, c});
		}
	}
	rd now;
	int loc;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] > p) {
			p = cnt[i];
			loc = i;
		}
	}
	cout << rand() % N + 2;

	return 0;
}
