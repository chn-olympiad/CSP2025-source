#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define FOR(i, l, r, x) for (int i = l; i <= r; i = x)
#define DEFOR(i, l, r, x) for (int i = l; i >= r; i = x)
using namespace std;
struct node {
	int u, v, w;
};
int c[10005], a[15][10005], fa[10055];
vector<node> e;
int n, m, k;
ll ans = 1e17;
bool cmp(node a, node b) {
	return a.w < b.w;
}
int find(int x) {
	if (fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
void minntree(vector<node> e, ll res, int p) {
	sort(e.begin(), e.end(), cmp);
	FOR(i, 1, p, ++i) {
		fa[i] = i;
	}
	for (auto it : e) {
		if (find(it.u) == find(it.v)) {
			continue;
		} else {
			fa[find(it.u)] = find(it.v);
			res += it.w;
		}
	}
	ans = min(ans, res);
}
void dfs(ll res, int cnt, int step, vector<node> e) {
	if (step == k) {
		minntree(e, res, cnt + n);
		return ;
	} 
	dfs(res, cnt, step + 1, e);
	++cnt;
	FOR(i, 1, n, ++i) {
		e.push_back((node) {n + cnt, i, a[step + 1][i]});
	}
	dfs(res + c[step + 1], cnt, step + 1, e);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	FOR(i, 1, m, ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		e.push_back((node) {u, v, w});
	}
	FOR(i, 1, k, ++i) {
		cin >> c[i];
		FOR(j, 1, n, ++j) {
			cin >> a[i][j];
		}
	}
	dfs(0, 0, 0, e);
	cout << ans << endl;
	return 0;
}