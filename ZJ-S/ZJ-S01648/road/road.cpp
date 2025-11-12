#include<bits/stdc++.h>
#define int long long
const int N = 1e6 + 10, M = 15;
using namespace std;
int read(){
	int x; scanf("%lld", &x); return x;
}
struct node{
	int v, w;
};
vector<node> g[N];
int c[M][N];
int n, m, k;
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(); m = read(); k = read();
	for(int i = 1; i <= m; i++){
		int u = read(), v = read(), w = read();
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	for(int i = 1; i <= k; i++){
		int res = 0;
		int z = read();
		if(z == 0) res++;
		for(int j = 1; j <= n; j++){
			c[i][j] = read();
			if(c[i][j] == 0) res++;
			g[i].push_back({j, c[i][j] + z});
		}
		if(res == n + 1){
			printf("0");
			return 0;
		}
	}
	
	return 0;
}
