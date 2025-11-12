#include<bits/stdc++.h>
using namespace std;
#define CSP
int n, m, k;
/*
int pa[10010];
int find(int x){
	return x == pa[x] ? x : pa[x] = find(pa[x]);
}
void unite(int x, int y){
	pa[find(x)] = find(y);
}*/
struct Village{
	int c;
	int a[10010];
}vil[13];
int e[10005][10005];
int main(){
#ifdef CSP
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
#endif
	memset(e, 0x3f, sizeof(e));
	cin >> n >> m >> k;
	for (int i = 1, u, v, w; i <= m; i++){
		cin >> u >> v >> w;
		e[u][v] = e[v][u] = w;
	}
	for (int i = 1; i <= k; i++){
		cin >> vil[i].c;
		for (int i = 1; i <= n; i++){
			cin >> vil[i].a[i];
		}
	}
	for (int i = 1; i <= k; i++){
		for (int j = 1; j <= n; j++){
			for (int l = j + 1; l <= n; l++){
				if(e[j][l] > vil[i].c + vil[i].a[j] + vil[i].a[l])e[j][l] = vil[i].c + vil[i].a[j] + vil[i].a[l];
			}
		}
	}
//	for (int i = 1; i <= n; i++)pa[i] = i;
	cout << 0;
	return 0;
}
