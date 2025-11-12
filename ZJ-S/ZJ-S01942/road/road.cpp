#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k, c[15], a[15][10005];
bool vis[10005];
struct edge{
	int u, v, w;
}es[1000005];

bool cmp(struct edge a, struct edge b){
	return a.w < b.w;
}

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++){
		cin >> es[i].u >> es[i].v >> es[i].w;
	}
	sort(es+1, es+1+m, cmp);
//	for(int i = 1;i <= k;i++){
//		cin >> c[i];
//		for(int j = 1;j <= n;j++){
//			cin >> a[i][j];
//		}
//	}
	return 0;
}
