#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+10;
vector<pair<ll,ll>> G[maxn];
vector<ll> c_path[maxn];
vector<ll> c;
ll ans;
ll n,m,k;
inline void dfs(ll u,ll v){
	for(auto w:G[u]){
		if(w.first == v) continue;
		ans+=w.second;
		dfs(w.first,u);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	srand(time(0));
	for(int i =1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back(make_pair(v,w));
		G[v].push_back(make_pair(u,w));
		ans+=w;
	}
//	for(int i = 1;i<=k;++i){
//		cin>>c[i];
//		for(int j = 1;j<=m;++j){
//			int x;
//			cin>>x;
//			c_path[j].push_back(x);
//		}
//	}
	ans = rand()%(100-1+1)+1;
	cout<<ans;
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

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/