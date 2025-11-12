#include<bits/stdc++.h>
using namespace std;

const int N = 1e4+5, N2 = 1e3+5;
signed n, m, k;
signed u, v, w;
signed c[N], a[15][N];
signed fa[N];

struct EDGE {
	signed from, to, cost, tag;
};

vector<EDGE> e;

int getfa(int x) {
	return fa[x] = (fa[x] != x ? getfa(fa[x]) : x);
}
int cmp(EDGE A, EDGE B) {
	return A.cost < B.cost;
}

//Part 1: k = 0
long long mintree() {
	long long ans = 0;
	for (int i = 1; i <= n; i++)	fa[i] = i;
	sort(e.begin(), e.end(), cmp);

	for (int i = 0, cnt = 0; cnt < n - 1; i++) {
		EDGE t = e[i];
		if (getfa(t.from) != getfa(t.to)) {
			fa[getfa(t.to)] = getfa(t.from);
			ans += t.cost;
			cnt++;
		}
	}
	return ans;
}

long long solve() {
	if (k == 0)	return mintree();
	return 0;
}


signed main() {
	cin.tie(0), cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		e.push_back((EDGE) {
			u, v, w
		});
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++)	cin >> a[i][j];
	}
	cout << solve() << "\n";
	return 0;
}