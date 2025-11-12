#include<bits/stdc++.h>
#define min(x, y) (x < y ? x : y)

struct Edge {
	int u, v, w;
}edge[5000005];

int N, M, K;
int u, v, w;
int c[10005], a[10005][10005],b[10005];
int f[10005];
int cnt;
long long Ans;

inline bool cmp(Edge x, Edge y) {
	return x.w < y.w;
}

inline int fnd(int x) {
	return f[x] = (x == f[x] ? x : fnd(f[x]));
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin >> N >> M >> K;
	for(int i = 1; i <= N; i ++) 
		for(int j = 1; j <= N; j ++) 
			a[i][j] = 2e9;
	for(int i = 1; i <= M; i ++) std::cin >> u >> v >> w, a[u][v] = min(a[u][v], w);
	for(int i = 1; i <= K; i ++) {
		std::cin >> c[i];
		for(int j = 1; j <= N; j ++) 
			std::cin >> b[j];
		for(int j = 1; j <= N; j ++) a[i][j] = min(a[i][j], b[j] + b[i]);
	}
	M = 0;
	for(int i = 1; i <= N; i ++) 
		for(int j = 1; j <= N; j ++) 
			if(a[i][j] != 2e9) 
				edge[++ M] = {i, j, a[i][j]};
	
	std::sort(edge + 1, edge + 1 + M, cmp);
	for(int i = 1; i <= N; i ++) f[i] = i;
	for(int i = 1; i <= M; i ++) {
		if(cnt >= N - 1) break;
		if(fnd(f[edge[i].u]) == fnd(f[edge[i].v])) continue;
		f[edge[i].v] = f[edge[i].u];
		Ans += (long long)edge[i].w, ++ cnt;
	}
	
	std::cout << Ans;
	return 0;
}
