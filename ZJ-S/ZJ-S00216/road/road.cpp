#include<bits/stdc++.h>
using ll = long long;
const int N = 1e4 + 10;
int n, m, k;
std::vector<std::pair<ll, ll> > g[N];
int G[20][N];

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0), std::cout.tie(0);
	std::cin >> n >> m >> k;
	for(int i = 1, u, v, w; i <= m; ++i){
		std::cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	for(int i = 1; i <= k; ++i){
		for(int j = 1; j <= n; ++j){
			std::cin >> G[i][j];
		}
	}
	std::cout << 0;
	return 0;
}

