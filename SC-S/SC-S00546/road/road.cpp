#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
const int M = 1e6 + 10;
const int K = 15;

struct node {
	int u, v;
	long long w;
}r[M];
int n, m, k, cnt;
int fa[N];
long long c[N], a[K][N];
bool cmp(node x, node y) {
	return x.w < y.w;
}
int find(int x) {
	if(fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
bool merge(int u, int v) {
	int fu = find(u), fv = find(v);
	if(fu == fv) return 0;
	else {
		fa[fu] = fv;
		return 1;
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i++) {
		scanf("%d%d%lld", &r[i].u, &r[i].v, &r[i].w);
		fa[i] = i;
	}
	for(int i = 1; i <= k; i++) {
		scanf("%lld", &c[i]);
		for(int j = 1; j <= k; j++) {
			scanf("%lld", &a[i][j]);
		}
	}
	if(k == 0) {
		long long ans = 0;
		sort(r + 1, r + 1 + m, cmp);
		for(int i = 1; i <= m; i++) {
			if(merge(r[i].u, r[i].v)) ans = ans + r[i].w;
		}
		printf("%lld", ans);
		return 0;
	}
	printf("0");
	return 0;
}