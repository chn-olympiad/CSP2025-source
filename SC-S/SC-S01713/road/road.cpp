#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
vector<pair<int,int> >G[100005];
int ans;
//void dfs(int u,int fa){
//	for(int v:G[u]){
//		if(v.first==fa){
//			continue;
//		}
//		ans+=v.second;
//		dfs(v,u);
//	}
//}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
		ans+=w;
	}
	cout<<ans<<endl;
	return 0;
}
