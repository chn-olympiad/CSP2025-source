#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define fi first
#define se second
#define F(i, l, r) for(int i = l; i <= r; i++)
const int N = 10004;

int n, m, k, c[11], a[11][N];
struct edge{
	int u, v;
	ll w;
}g[2000006];
//bcj
int s[N];
int fnd(int x) {
	if(s[x] != x) s[x] = fnd(s[x]);
	return s[x];
}
void mrg(int x, int y) {
	x = fnd(x);
	y = fnd(y);
	if(x != y)
		s[x] = y;
}

bool cmp(edge x, edge y) {
	return x.w < y.w;
}
ll kru() {
	sort(g+1, g+1+m, cmp);
	int tot = 0;
	ll ans = 0;
	for(int i = 1; i <= m; i++) {
		if(tot == n - 1) break;
		if(fnd(g[i].u) == fnd(g[i].v)) break;
		ans += g[i].w;
		mrg(g[i].u, g[i].v);
	}
	return ans;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
		s[i] = i;
	for(int i = 1; i <= m; i++)
		cin >> g[i].u >> g[i].v >> g[i].w;
	for(int i = 1; i <= k; i++) {
		cin >> c[i];
		for(int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			ll minn = 1e18;
			for(int kk = 1; kk <= k; kk++) {
				ll tmp = a[kk][i] + c[kk] + a[kk][j];
				minn = min(minn, tmp);
			}
			g[++m].u = i;
			g[m].v = j;
			g[m].w = minn;
		}
	}
//	for(int i = 1; i <= m; i++) 
//		cout << g[i].u << ' ' << g[i].v << ' ' << g[i].w << endl;
		ll ans = kru();
		cout << ans;
		return 0;
	return 0;
} 
/*
4 4 3
1 2 10000
1 3 10000
2 4 10000
3 4 10000
0 1 1 1 1
0 1 1 1 1
0 1 1 1 1

*/
