#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m, k, u, v, mci[15];
ll w, d[15], c[15][10005], mc[15], ans, f[10005], ans2;
bool b[15], bb = 1;

struct W {
	int u, v;
	ll w;
	bool operator<(const W k)const {
		return k.w < w;
	}
};
priority_queue<W>q;
vector<W>a;

int ff(int x) {
	return (x == f[x]) ? x : f[x] = ff(f[x]);
}

void dfs(int pos) {
	if (pos > k) {
		ans2 = 0;
		for (int j = 1; j <= k; j++) {
			if (!b[j])
				continue;
			ans2 += d[j];
			for (int x = 1; x <= n; x++)
				q.push({x, mci[j], c[j][x] + mc[j]});
		}
		for (int x = 1; x <= n; x++)
			f[x] = x;
		for (auto [u, v, w] : a)
			q.push({u, v, w});
		while (q.size()) {
			auto [u, v, w] = q.top();
			q.pop();
			int x = ff(u), y = ff(v);
			if (x == y)
				continue;
			f[x] = y;
			ans2 += w;
		}
		if (ans2 < ans)
			ans = ans2;
		return ;
	}
	dfs(pos + 1);
	b[pos] = 1;
	dfs(pos + 1);
	b[pos] = 0;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%lld", &u, &v, &w);
		q.push({u, v, w});
	}
	for (int i = 1; i <= n; i++)
		f[i] = i;
	for (int i = 1; i <= k; i++) {
		scanf("%lld", &d[i]);
		mc[i] = 1e15;
		for (int j = 1; j <= n; j++) {
			scanf("%lld", &c[i][j]);
			if (c[i][j] < mc[i])
				mc[i] = c[i][j], mci[i] = j;
		}
		if (d[i] != 0)
			bb = 0;
	}
	if (bb or k == 0) {
		for (int i = 1; i <= k; i++)
			for (int j = 1; j <= n; j++)
				q.push({j, mci[i], c[i][j] + mc[i]});
		while (q.size()) {
			auto [u, v, w] = q.top();
			q.pop();
			int x = ff(u), y = ff(v);
			if (x == y)
				continue;
			f[x] = y;
			ans += w;
		}
		printf("%lld", ans);
		return 0;
	}
	while (q.size()) {
		auto [u, v, w] = q.top();
		q.pop();
		int x = ff(u), y = ff(v);
		if (x == y)
			continue;
		f[x] = y;
		a.push_back({u, v, w});
		ans += w;
	}
	dfs(1);
	printf("%lld", ans);
	return 0;
}