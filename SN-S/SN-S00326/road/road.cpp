#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,c[15];
vector<pair<int,int> > vec[10014];
int dis[10014],vis[10014],viss[15];
void prim(int x){
	vis[x]=1;
	int cnt=1,ans;
	while(cnt!=n){
		int j,nx=LONG_LONG_MAX;
		for(pair<int,int> to:vec[x]){
			if(!vis[to.first]&&to.second<nx){
				nx=to.second;
				j=to.first;
			}
		}
		if(j<=n){
			cnt++;
		}
			vis[j]=1;
		x=j;
		ans+=nx;
	}
	for(int i=1;i<=k;i++)
		if(vis[n+i]) ans+=c[i];
	cout<<ans<<"\n";
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		vec[u].push_back({v,w});
		vec[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1,a;j<=n;j++){
			cin>>a;
			vec[n+i].push_back({j,a});
			vec[j].push_back({n+i,a});
		}
	}
	prim(1);
	return 0;
}
