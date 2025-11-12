#include <bits/stdc++.h>
#define int long long
#define N 1000006
using namespace std;
struct node {
	int u, v, w, d, is;
}e[N];
bool cmp (node l, node r) {
	return l.w < r.w;
}
int father[N];
int find(int x) {
	if (father[x] != x) {
		return father[x] = find(father[x]);
	}
	return father[x];
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1, u, v, w; i <= m; i ++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	for (int i = 0; i <= n + 1; i ++) father[i] = i;
	int top = n;
	for (int i = 1, cost; i <= k; i ++) {
		cin >> cost;
		for (int j = 1, val; j <= n; j ++) {
			cin >> val;
			e[++top].u = i;
			e[top].v = j;
			e[top].w = val;
		}
	}
	sort(e + 1, e + top + 1, cmp);
	int cnt = 0, ans = 0;
	for (int i = 1; cnt < n - 1 && i <= top; i ++) {
		int fu = find(e[i].u);
		int fv = find(e[i].v);
		if (fu == fv) continue;
		father[fu] = fv;
		ans += e[i].w;
		cnt ++;
	}
	cout << ans;
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/

