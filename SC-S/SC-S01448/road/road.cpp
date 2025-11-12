#include<bits/stdc++.h>
using namespace std;
int n, m, k;
int e[1005][1005];
int cnt = 0, c[15], x[15][100005], fa[100005];
struct node{
	int u, v, w;
}edge[2000005], edge2[2000005];
bool cmp(node s, node b) {
	return s.w < b.w;
}
int find(int s) {
	if(fa[s] == s) return s;
	return fa[s] = find(fa[s]);
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++) {
		int a, b, c;
		cin >> a >> b >> c;
		e[a][b] = e[b][a] = c;
		edge[++ cnt] = {a, b, c};
	}
	for(int i = 1; i <= k; i ++) {
		cin >> c[i];
		for(int j = 1; j <= n; j ++) {
			cin >> x[i][j];
		}
	}
	int ans = 0x7f7f7f7f;
	for(int i = 0; i < (1 << k); i ++) {
		memset(edge2, 0, sizeof edge2);
		for(int j = 1; j <= cnt; j ++) edge2[j] = edge[j];
		int cnt2 = cnt;
		for(int j = 0; j <= k; j ++) {
			if((i >> j) & 1) {
				for(int p = 1; p <= n; p ++) {
					if(p == (k - j)) continue;
					for(int q = 1; q <= n; q ++) {
						if(q == p) continue;
						edge2[++ cnt2] = {p, q, c[(k - j)] + x[(k - j)][p] + x[(k - j)][q]};
					}
				}
			}
		}
		for(int i = 1; i <= n; i ++) {
			fa[i] = i;
		}
		sort(edge2 + 1, edge2 + 1 + cnt2, cmp);
		int ans2 = 0, fq = 1;
		for(int i = 1; i <= cnt2; i ++) {
			int fx = find(edge2[i].u), fy = find(edge2[i].v);
			if(fx == fy) continue;
			ans2 += edge2[i].w;
			fq ++;
			fa[fx] = fy;
			if(fq == n) break;
		}
		ans = min(ans, ans2);
	}
	cout << ans << endl;
	return 0;
}

