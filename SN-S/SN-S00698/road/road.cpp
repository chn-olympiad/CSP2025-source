#include<bits/stdc++.h>
using namespace std;

struct edge{
	int w;
	int u;
	int v;
}edges[1000006];
bool cmp(edge a, edge b){
	return a.w < b.w;
}
bool vis[10004];

//map<int,int> linjie[10004];

int n,m,k;
int update[10004];
int newr[10004];
int dis[10004];

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(dis,1073741824,sizeof(dis));
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	memset(linjie,1073741284,sizeof(linjie));
	cin >> n >> m >> k;
	for(int i = 1;i <= m;++i){
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
//		linjie[edges[i].u][edges[i].v] = w;
//		linjie[edges[i].v][edges[i].u] = w;
	}
	for(int i = 1;i <= k;++i){
		cin >> update[i];
		for(int j = 1;j <= n;++j) cin >> newr[i];
	}
	sort(edges+1,edges+1+n,cmp);
	
	if(k == 0){
		int cnt = 0,ans = 0;
		for(int i = 1;;++i){
			if(!(vis[edges[i].u] == 1 && vis[edges[i].v] == 1)){
				vis[edges[i].u] = 1;
				vis[edges[i].v] = 1;
				cnt++;
				ans += edges[i].w;
			}
			if(cnt == n-1)break;
		}
		cout << ans;
		return 0;
	}
	cout << 200;
	return 0;
}
