#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10, M = 20;

int n, m, k, a[M][N], c[M], f[N], ans;
struct G{
	int u, v, w;
}g[N]; 
bool cmp(G a, G b){
	return a.w < b.w;
}
int find(int x){
	if(f[x] != x){
		return find(f[x]);
	}
	return x;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		f[i] = i;
	}
	for(int i = 1; i <= m; i++){
		cin >> g[i].u >> g[i].v >> g[i].w;
	}
	sort(g + 1, g + 1 + m, cmp);
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= m; i++){
		int f1 = find(g[i].u), f2 = find(g[i].v);
		if(f1 != f2){
			f[f1] = f2;
			ans += g[i].w;
		}
	}
	cout << ans;
	return 0;
}
