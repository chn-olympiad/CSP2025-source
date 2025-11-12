#include <bits/stdc++.h>
using namespace std;

//struct node {
//	long long to, w, nxt;
//} edge[4000005];
//long long cnt, head[4000005];
//
//void add(int u, int v, long long w) {
//	cnt++;
//	edge[cnt].to = v;
//	edge[cnt].w = w;
//	edge[cnt].nxt = head[u];
//	head[u] = cnt;
//}
long long dp[10005][10005];
long long c[10005], a[10005][10005];
bool f[15];
int n, m, k;

//尝试解决购买问题（失败）
long long change(long long x, int i, int j) {
	if (i > k) {
		return x;
	}
	long long num = 0;
	if (f[i] == 0) {
		num += c[i];
		f[i] = 1;
	}
	num += a[i][j];
	if (dp[i][j] == 0x3f3f3f3f) {
		return num;
	}
	return min(dp[i][j], num);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				dp[i][j] = 0x3f3f3f3f;
				dp[j][i] = 0x3f3f3f3f;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		long long w;
		scanf("%d%d%lld", &u, &v, &w);
		dp[u][v] = w;
		dp[v][u] = w;
//		add(u, v, w);
//		add(v, u, w);
	}
	for (int i = 1; i <= k; i++) {
		scanf("%lld", &c[i]);
		for (int j = 1; j <= n; j++) {
			scanf("%lld", &a[i][j]);
//			dp[i][j] = a + c[i];
//			dp[j][i] = a + c[i];
//			add(i, j, a + c);
//			add(j, i, a + c);
		}
	}
	for (int o = 1; o <= n; o++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j] = min(change(dp[i][j], i, j), change(dp[i][o], i, o) + change(dp[o][j], o, j));
			}
		}
	}
	long long maxn = INT_MIN;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			maxn = max(maxn, dp[i][j]);
		}
	}
	printf("%lld", maxn);
	return 0;
}
//我尽力了，于我而言，没有遗憾
//有缘再见，信奥