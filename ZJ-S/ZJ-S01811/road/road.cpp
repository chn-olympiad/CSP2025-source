#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>

namespace noip {
typedef long long ll;
constexpr ll MAX_M = 2000000;
constexpr ll MAX_N = 10000;
constexpr ll MAX_K = 10;
struct Edge {
	ll u, v, len;
};
std::vector<Edge> outgoings[1+MAX_N];
ll a[1+MAX_K][1+MAX_N];
bool v[1+MAX_N] {};
ll juli[1+MAX_N];
ll n, m, k;
ll ans = 0;
void prim() {
	for (ll i = 1; i <= n; i++)
		juli[i] = LLONG_MAX;
	
	for (Edge e: outgoings[1]) {
		ll v = e.v, len = e.len;
		juli[v] = std::min(juli[v], len);
	}
	v[1] = true;
	
	
	for (ll i = 2; i <= n; i++) {
		ll min = LLONG_MAX, nofmin;
		
		for (ll j = 1; j <= n; j++) {
			if (!v[j] && juli[j] < min)
				min = juli[j], nofmin = j;
		}
		
		v[nofmin] = true;
		ans += min;
	
		for (Edge e: outgoings[nofmin]) {
			ll v = e.v, len = e.len;
			juli[v] = std::min(juli[v], len);
		}
		
		
	}
}
void main() {
	std::freopen("road.in", "r", stdin);
	std::freopen("road.out", "w", stdout);
	std::cin >> n >> m >> k;
	for (ll i = 1; i <= m; i++) {
		ll u, v, w; 
		std::cin >> u >> v >> w;
		
		outgoings[u].push_back(Edge {u, v, w});
		outgoings[v].push_back(Edge {v, u, w});
	}
	
	for (ll i = 1; i <= k; i++) {
		ll c; std::cin >> c;
		for (ll j = 1; j <= n; j++)
			std::cin >> a[i][j];
		
		for (ll j = 1; j <= n; j++)
			for (ll k = j+1; k <= n; k++) {
				outgoings[j].push_back(Edge {j, k, a[i][j]+a[i][k]+c});
				outgoings[k].push_back(Edge {k, j, a[i][j]+a[i][k]+c});
			}
	}
	
	noip::prim();
	
	std::cout << ans;
	
}
}

int main() {
	noip::main();
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


5 4 1
1 3 5
2 4 6
2 5 114514
3 5 114514
0 4 114514 5201314 8 7

*/
