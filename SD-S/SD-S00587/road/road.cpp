#include <bits/stdc++.h>

using namespace std;

const int M = 1e6 + 1e5 + 10;
const int N = 1e4 + 10;
int n, m, k, c[N];
bool vis[N], has[N];
struct Edge {
	int u, v, w, id;
} a[M];

bool cmp(Edge x, Edge y) {
	return x.w < y.w;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	scanf("%d%d%d", &n, &m, &k);
	bool te = true; 
	int idx = 0;
	for (int i = 1; i <= m; i++) {
		idx++;
		scanf("%d%d%d", &a[idx].u, &a[idx].v, &a[idx].w);
		a[idx].id = -1;
	}
	for (int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
		if (c[i] != 0) {
			te = false;
		}
		if (c[i] != 0)
		for (int j = 1; j <= n; j++) {
			int x;
			scanf("%d", &x);
			if (x != 0) {
				te = false;
			}
			idx++;
			a[idx].u = i;
			a[idx].v = j;
			a[idx].w = x;
			a[idx].id = i;
		}
	}
	
	if (te) {
		printf("0\n");
		return 0;
	}
	
	sort(a + 1, a + idx + 1, cmp);
	
	long long ans = a[1].w;
	vis[a[1].u] = vis[a[1].v] = 1;
	for (int i = 2; i < n; i++) {
		if (vis[a[i].u] && !vis[a[i].v]) {
			ans += a[i].w;
			if (a[i].id != -1 && !has[a[i].id]) {
				ans += c[a[i].id];
				has[a[i].id] = true;
			}
			vis[a[i].v] = 1;
		} else if (vis[a[i].v] && !vis[a[i].u]) {
			ans += a[i].w;
			if (a[i].id != -1 && !has[a[i].id]) {
				ans += c[a[i].id];
				has[a[i].id] = true;
			}
			vis[a[i].u] = 1;
		} else {
			i--;
		}
	}
	printf("%d\n", ans);
	return 0;
} 
