#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
struct no{
	int v,w,w1;
};
vector <no > g[100005];
int vis[1000005];
no dij1(int p , int h){
	no o;
	o.w = 2147483647;
	o.w1 = 2147483647;
	for(auto j : g[p]){
		if(vis[j.v] + j.w < o.w + o.w1 && j.v != h){
			o.v = j.v;
			o.w = j.w;
			o.w1 = vis[j.v];
		}
	}
	return o;
}
int as = 0;
int cnt = 0;
void dj(int p , int la){
	if(cnt == n){
		return;
	}
	no k = dij1(p , la);
	if(vis[k.v] != 0){
		as += vis[k.v];
		as += k.w;
		vis[k.v] = 0;
	}else{
		as += k.w;
	}
	cnt++;
	dj(k.v , p);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	cin>>n>>m>>k;
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v , w , 0});
		g[v].push_back({u , w , 0});
	}
	for(int i = 1;i <= k;i++){
		int c;
		cin>>c;
		vis[i] = c;
		for(int j = 1;j <= n;j++){
			int a;
			cin>>a;
			g[i].push_back({j , a , c});
			g[j].push_back({i , a , c});
		}
	}
	dj(1 , 0);
	cout<<as;
	return 0;
}
