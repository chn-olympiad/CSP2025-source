//SN-S00388
#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
int minn=1e7,ans=1e7;
vector<pair<int,int> > mm[1000005];
void dfs(int f,int d,int end,int sum){
	if(d==end){
		ans=min(ans,sum);
		return;
	}
	for(auto v:mm[d]){
		if(v==f){
			continue;
		}
		sum+=v.second;
		dfs(d,v.first,end,sum);
	}
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		mm[u].push_back({v,w});
		mm[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		int u;
		cin>>u;
		for(int j=1;j<=n;j++){
			int v;
			cin>>v;
			mm[m+i].push_back({j,0});
			mm[j].push_back({m+i,0});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans=0;
			dfs(0,i,j,0);
			minn+=ans;
		}
	}
	cout<<ans;
	return 0;
}
