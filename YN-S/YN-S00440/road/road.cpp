/*********************************************************************
    程序名:
    版权:
    作者:
    日期: 2025-11-01 18:15
    说明:
*********************************************************************/
#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;

struct e {
	int u, v, w;
};
e a[1000010];
int fa[1000010];
e b[15][1000010];
e c[1000010];

bool cmd(e x, e y) {
	return x.w < y.w;
}

int find (int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int ans = inf;
int n, m, k;

void dfs(int u, int ret) {
	memcpy(c, a, sizeof(c));
	//cout << u << endl;
	if (u > k) {
		ans = min(ans, ret);
		return ;
	}
	dfs(u + 1, ret);
	ret = 0;

	for (int i = 1; i <= n; i++)
		a[++m] = b[u][i];
	//for (int i = 1; i <= m; i++) {
	//	cout << a[i].u << " " << a[i].v << " " << a[i].w << endl;
	//}
	puts("_");
	n++;
	sort(a + 1, a + 1 + m, cmd);
	for (int i = 1; i <= n + 10; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++) {
		int tx = find(a[i].u);
		int ty = find(a[i].v);
		if (tx != ty) {
			ret += a[i].w;
			fa[tx] = ty;
			//	cout << a[i].u << " " << a[i].v << endl;
		}
	}
	dfs(u + 1, ret);
	n--;
	m -= n;
	memcpy(a, c, sizeof(a));
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	for (int i = 1; i < 1000010; i++)
		fa[i] = i;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].w);
	}
	int n_ = n;
	for (int i = 1; i <= k; i++) {
		int c;
		scanf("%d", &c);
		n_++;
		for (int j = 1; j <= n; j++) {
			int x;
			scanf("%d", &x);
			x += c;
			b[i][j].u = n_;
			b[i][j].v = j;
			b[i][j].w = x;
		}
	}
	sort(a + 1, a + 1 + m, cmd);
	ans = 0;
	for (int i = 1; i <= m; i++) {
		int tx = find(a[i].u);
		int ty = find(a[i].v);
		if (tx != ty) {
			ans += a[i].w;
			fa[tx] = ty;
			//cout << a[i].u << " " << a[i].v << endl;
		}
	}
	dfs(1, ans);
	printf("%d\n", ans);
	return 0;
}
