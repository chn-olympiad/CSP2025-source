#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, k, f[10210], ans, a[20][10210];
struct EDGE {
	int u, v, w;
} edge[11000010];

int read() {
	int x = 0, fl = 1;
	char c = getchar();
	while(c > '9' || c < '0') {
		if(c == '-') fl = -1;
		c = getchar();
	}
	while(c <= '9' && c >= '0')
		x = x*10+c-'0', c = getchar();
	return x*fl;
}
int find(int x) {
	if(f[x] != x) return f[x] = find(f[x]);
	return x;
}
void merge(int u, int v) {
	f[u] = v;
}
bool cmp(EDGE x, EDGE y) {
	return x.w < y.w;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int i = 1; i <= m; i++)
		edge[i].u = read(), edge[i].v = read(), edge[i].w = read();
	for(int i = 1; i <= k; i++) {
		int c = read(), flg = 0;
		for(int j = 1; j <= n; j++) {
			a[i][j] = read();
			if(a[i][j] == 0) flg = j;
		}
		if(!flg) {
			for(int j = 1; j <= n; j++)
				for(int l = 1; l < j; l++)
					edge[++m] = {l, j, a[i][j]+a[i][l]+c};
		}
		else {
			for(int j = 1; j <= n; j++)
				if(j != flg) edge[++m] = {flg, j, a[i][j]+c};
		}
	}
	sort(edge+1, edge+m+1, cmp);
	for(int i = 1; i <= m; i++) {
		int fx = find(edge[i].u), fy = find(edge[i].v);
		if(fx != fy) merge(fx, fy), ans += edge[i].w;
	}
	printf("%lld", ans);
	
	return 0;
}
