#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 2e6 + 5;

int n, m, k, c[N], a[15][10005];

int p[N], siz[N], cnt;

struct edge {
	int u, v, w;
	bool operator < (const edge b) const {
		return w < b.w;
	}
};

edge e[N], b[N], tmp[N];

edge E[15][10005];

int find (const int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}

int read() {
	int x = 0;
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x;
}

signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read(), m = read(), k = read();
	for (int i = 1, u, v, w; i <= m; ++ i ) {
		u = read(), v = read(), w = read();
		e[i] = {u, v, w};
	}
	for (int j = 1; j <= k; ++ j ) {
		c[j] = read();
		for (int t = 1; t <= n; ++ t ) {
			a[j][t] = read();
			E[j][t] = {n + j, t, a[j][t]};
		}
		sort(E[j] + 1, E[j] + n + 1);
	}
	for (int i = 1; i <= n; ++ i ) p[i] = i, siz[i] = 1;
	sort(e + 1, e + m + 1);
	for (int i = 1; i <= m; ++ i ) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if (find(u) != find(v)) {
			if (siz[find(u)] < siz[find(v)]) swap(u, v);
			e[ ++ cnt] = {u, v, w};
			siz[find(u)] += siz[find(v)];
			p[find(v)] = find(u);
		}
	}
	m = cnt;
	int ans = 1e18;
	for (int t = 0; t < (1 << k); ++ t ) {
		int now = t << 1;
		int sum = 0;
		for (int j = 1; j <= k; ++ j )
		    if (now >> j & 1)
		        sum += c[j];
		        
		cnt = 0;
		for (int i = 1; i <= m; ++ i ) b[i] = e[i];
		cnt = m;
		for (int j = 1; j <= k; ++ j ) {
			if (now >> j & 1 ^ 1) continue;
		    int ct = 0;
		    int i = 1, at = 1;
		    while (i <= cnt && at <= n) {
		    	if (b[i] < E[j][at]) {
		    		tmp[ ++ ct] = b[i ++ ];
				} else {
					tmp[ ++ ct] = E[j][at ++ ];
				}
			}
			while (i <= cnt) tmp[ ++ ct] = b[i ++ ];
			while (at <= n) tmp[ ++ ct] = E[j][at ++ ];
			for (int i = 1; i <= ct; ++ i ) b[i] = tmp[i];
			cnt = ct; 
		}
		for (int i = 1; i <= n + k; ++ i ) p[i] = i, siz[i] = 1;
        for (int i = 1; i <= cnt; ++ i ) {
        	int u = b[i].u, v = b[i].v, w = b[i].w;
        	if (find(u) != find(v)) {
        		if (siz[find(u)] < siz[find(v)]) swap(u, v);
        		sum += w;
        		siz[find(u)] += siz[find(v)];
        		p[find(v)] = find(u);
			}
		}		
		ans = min(ans, sum);
	}
	printf("%lld\n", ans);
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
