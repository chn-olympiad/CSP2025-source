#include <bits/stdc++.h>
using namespace std;
constexpr int N = 10010, M = 1000010;

struct edge {
	int u, v, w;
	inline bool operator<(const edge &a)const {
		return w < a.w;
	}
} e[M];
int n, m, k, fa[N];
int c[15], a[15][N];

long long res;

inline int find(int x) {
	if (x == fa[x])
		return x;
	return fa[x] = find(fa[x]);
}

inline void kruskal() {
	sort(e + 1, e + m + 1);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++) {
		int p = find(e[i].u), q = find(e[i].v);
		if (p != q)
			fa[p] = q, res += e[i].w;
	}
}

int main() {
	// yidingyaoqudiaozhushi!!!!!!!!!!
	//freopen("road.in", "r", stdin);
	//freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1, a, b, c; i <= m; i++)
		scanf("%d%d%d", &a, &b, &c), e[i] = {a, b, c};
	for (int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
		for (int j = 1; j <= n; i++)
			scanf("%d", &a[i][j]);
	}
	/*
	for(int i=1;i<=k;i++)
		if(c[i]==0)
			for(int j=1;j<=n;j++)
				if(a[i][j]==0)
					for(int k=1;k<=n;k++)
						e[]
	*/
	kruskal();
	printf("%lld\n", res);
	return 0;
}
