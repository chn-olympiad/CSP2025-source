// std T2
#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int M = 2e6 + 20, N = 2e5 + 10, K = 15;
int n, m, k;

struct node{
	int u, v, w;
}E[M], t[M], tmp[M];

pair<int, int> a[K][N];
int c[K], fa[N];

int get(int x) {
	return (fa[x] == x) ? x : (fa[x] = get(fa[x]));
}

bool cmp(node x, node y) {
	return x.w < y.w;
}

signed main() {
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(0); 
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout); 
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++) {
		cin >> E[i].u >> E[i].v >> E[i].w;
	}
	for(int i = 1; i <= k; i++) {
		cin >> c[i];
		for(int j = 1; j <= n; j++) {
			cin >> a[i][j].first;
			a[i][j].second = j;
		}
		sort(a[i] + 1, a[i] + n + 1);
	}
	sort(E + 1, E + m + 1, cmp);
	for(int i = 1; i <= n; i++) fa[i] = i;
	int tot = 0;
	for(int i = 1; i <= m; i++) {
		int u = E[i].u, v = E[i].v, w = E[i].w;
		int fu = get(u), fv = get(v);
		if(fu == fv) continue;
		tmp[++tot] = E[i];
		fa[fu] = fv;
	}
	
	int sum = 0;
	
	int U = (1 << k) - 1, ans = 1e16;
	int len = 0;
	if(n >= 5e3) len = 1000; 
//	cout << sum << "\n";
	// cout << ness / (U * 10) << "\n";
	for(int s = 0; s <= U; s++) {
		int res = 0;
		
		tot = n - 1;
		for(int i = 1; i <= n - 1; i++) t[i] = tmp[i];
		for(int i = 1; i <= k; i++) {
			if((s >> (i - 1)) & 1) {
				res += c[i];
				for(int j = 1; j <= n - len; j++) {
					t[++tot] = {n + i, a[i][j].second, a[i][j].first};
				}
			}
		}
		sort(t + 1, t + tot + 1, cmp);
		for(int i = 1; i <= n + k; i++) fa[i] = i;
		int sze = 0;
		for(int i = 1; i <= tot; i++) {
			int u = t[i].u, v = t[i].v, w = t[i].w;
			int fu = get(u), fv = get(v);
			if(fu == fv) continue;
			fa[fu] = fv;
			res += w;
			sze++;
			if(sze == n + k - 1) break;
		}
		ans = min(ans, res);
	}
	cout << ans;
	
	return 0;
} 