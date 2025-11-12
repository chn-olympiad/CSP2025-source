#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M = 1e6 + 10;
const int N = 1e4 + 10;
int n, m, k, fa[N];
int find(int x) {
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
struct info{
	int u, v, w;
}a[N];
bool cmp(info x, info y) {
	return x.w < y.w;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++) {
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	for(int i = 1; i <= n; i ++) fa[i] = i;
	for(int i = 1; i <= k; i ++) {
		int c;
		cin >> c;
		for(int j = 1; j <= n; j ++) {
			int t;
			cin >> t;
		}
	}
	sort(a + 1, a + 1 + m, cmp);
	int ans = 0;
	for(int i = 1; i <= m; i ++) {
		int fx = find(a[i].u);
		int fy = find(a[i].v);
		if(fx != fy) {
			fa[fx] = fy;
			ans += a[i].w;
		}
	}
	cout << ans;
	return 0;
}


