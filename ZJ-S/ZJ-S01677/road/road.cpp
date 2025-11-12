#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 100;
int n, m, k, ans, fa[N], c[N];
struct segyid {
	int u, v, w;
	bool operator < (segyid t) const {
		return w < t.w;
	}
} fu[N];
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
struct node {
	int c, sum, b[10100];
} a[20];
bool cmp(node x, node y) {
	return x.c < y.c;
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		fu[i] = {u, v, w};
	}
	for(int i = 1; i <= k; i ++) {
		cin >> a[i].c;
		a[i].sum = a[i].c;
		for(int j = 1; j <= n; j ++) cin >> a[i].b[j], a[i].sum += a[i].b[j];
	}
	sort(a + 1, a + 1 + k, cmp);
	sort(fu + 1, fu + 1 + m);
	for(int i = 1; i <= n; i ++) fa[i] = i;
	for(int i = 1; i <= m; i ++) {
		int x = find(fu[i].u), y = find(fu[i].v);
		if(x != y) {
			fa[x] = y;
			ans += fu[i].w;
		}
	}
	int tot = m;
	int ans1 = 0;
	for(int i = 1; i <= k; i ++) {
		if(a[i].sum < ans || a[i].c - (ans - (a[i].sum - a[i].c)) <= ans) {
			ans1 += a[i].c;
			for(int j = 1; j <= n; j ++) fu[++ tot] = {i + n, j, a[i].b[j]}; 
			
		}
		else break;
	}
	sort(fu + 1, fu + 1 + tot);
	for(int i = 1; i <= tot; i ++) fa[i] = i;
	
	
//	cout << ans1 << "\n";
	for(int i = 1; i <= tot; i ++) {
		int x = find(fu[i].u), y = find(fu[i].v);
		if(x != y) {
			fa[x] = y;
			ans1 += fu[i].w;
		}
	}
	cout << ans1;
	return 0;
}
