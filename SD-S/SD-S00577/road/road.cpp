#include<bits/stdc++.h>
#define int long long
#define mk make_pair
using namespace std;
int n,m,k,mo,ans=1e13+1;
vector<pair<int,pair<int,int>>>g[100005];
bool vis[100005],vv[100005];
int u[100005],v[100005],w[100005];
bool dfs(int x,int cnt){
	if(cnt==n)return 1;
	for(auto i:g[x]){
		if(i.second.second==-1||vis[i.first])continue;
		vis[i.first]=1;
		dfs(i.first,cnt+1);
	}
	return 0;
}
void dfs1(int k){
	if(k==n+1){
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			if(vv[i]){
				g[u[i]][v[i]].second.second=-1;
			}
			else{
				g[u[i]][v[i]].second.second=0;
			}
		} 
		if(dfs(1,1)){
			int mm=mo;
			for(int i=1;i<=n;i++){
				if(vv[i])mo-=g[u[i]][v[i]].second.first;
			}
			ans=min(ans,mo);
			mo=mm;
		}
		return;
	}
	vv[k]=1;
	dfs1(k+1);
	vv[k]=0;
	dfs1(k+1);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		g[u[i]].push_back(make_pair(v[i],make_pair(w[i],0)));
		g[v[i]].push_back(make_pair(u[i],make_pair(w[i],0)));
		mo+=w[i];
	}
	dfs1(1);
	cout<<ans;
	return 0;
}
