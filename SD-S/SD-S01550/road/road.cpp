#include<bits/stdc++.h>
using namespace std;

const int N = 5e6 + 7;
struct edge {
	int u, v, w;
}e[N];
int a[N][11], c[N];
int n, m, k;
int fa[N];
int cnt;
int findfa(int u) {
	if(fa[u] == u) return u;
	return fa[u] = findfa(fa[u]);
}
bool cmp(edge a1, edge a2) {
	return a1.w < a2.w;
} 
void solve1() {
	for(int i = 1; i <= n; i ++) fa[i] = i;
	sort(e + 1, e + m + 1, cmp);
	int ans = 0;
	for(int i = 1; i <= m; i ++) {
		int u = e[i].u, v = e[i].v;
		if(findfa(u) != findfa(v)) {
			fa[u] = v;
			ans += e[i].w;
		}
	}
	cout << ans << endl;
}

void solve2() {
	
}
int o[1003][1003];
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[++ cnt] .u = u, e[cnt].v = v, e[cnt].w = w;
		o[u][v] = o[v][u] = w;
	}
	int flaga = 1;
	for(int i = 1; i <= k; i ++) {
		cin >> c[i];
		if(c[i] != 0) flaga = 0;
		for(int j = 1; j <= n; j ++) cin >> a[j][i];
	}
	if(k == 0) {
		solve1();
	}
	else if(flaga) {
		solve2();
	}
}


// // // // // // // //  
