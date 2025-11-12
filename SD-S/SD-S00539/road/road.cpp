#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010, M = 2000010;
typedef long long LL;
struct Edge {
	int a, b; LL c;
	bool operator<(const Edge& W) const {
		return c < W.c;
	}
}edges[M], tr[N], q[N * 10], a[11][N], b[N * 10]; int cnt, num; 
int p[N<<1];
int find(int x) {
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}
int n, m, K;
LL w[N];

void merge(int u) {
	int tta = 0, ttb = 0, num = 0;
	for (int i = 1; i <= cnt + n; i ++ ) {
		LL v = 1e18;
		if (tta <= cnt) v = min(v, q[tta].c);
		if (ttb <= n) v = min(v, a[u][ttb].c);
		if (v == q[tta].c) b[ ++ num] = q[tta], tta ++ ;
		else b[ ++ num] = a[u][ttb], ttb ++ ;
	}
	for (int i = 1; i <= num; i ++ ) q[i] = b[i]; cnt = num;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &K);
	for (int i = 1; i <= m; i ++ )
		scanf("%d%d%lld", &edges[i].a, &edges[i].b, &edges[i].c);
	sort(edges + 1, edges + m + 1);
	for (int i = 1; i <= n; i ++ ) p[i] = i;
	for (int i = 1; i <= m; i ++ ) {
		int a = edges[i].a, b = edges[i].b; LL c = edges[i].c;
		int pa = find(a), pb = find(b);
		if (pa == pb) continue;
		tr[ ++ cnt] = {a, b, c};
		p[pa] = pb;		
	}
	cnt = 0;
	for (int i = 0; i < K; i ++ ) {
		scanf("%lld", &w[i]);
		for (int j = 1; j <= n; j ++ )
			scanf("%lld", &a[i][j].c), a[i][j].a = n+i+1, a[i][j].b = j;
		sort(a[i] + 1, a[i] + n + 1);
	}
	LL res = 1e18;
	for (int s = 0; s < (1 << K); s ++ ) {
		LL ans = 0;
		cnt = 0;
		for (int i = 1; i <= n - 1; i ++ ) q[ ++ cnt] = tr[i];
		for (int j = 0; j < K; j ++ )
			if (s >> j & 1) {
				ans += w[j];
				merge(j);
				//for (int u = 1; u <= n; u ++ )
				//	q[ ++ cnt] = a[j][u];
			}
		for (int i = 1; i <= n + K; i ++ ) p[i] = i; 
		for (int i = 0; i <= n - 1 + cnt; i ++ ) {
			int a = q[i].a, b = q[i].b; LL c = q[i].c;
			int pa = find(a), pb = find(b);
			if (pa == pb) continue;
			ans += q[i].c;
			p[pa] = pb;
		}
		res = min(res, ans);
	}
	printf("%lld\n", res);
	return 0;
}
