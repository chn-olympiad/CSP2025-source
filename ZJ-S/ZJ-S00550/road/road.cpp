#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+7;
int n,m,k,ans=INT_MAX;
int g2[N];
vector<pair<int,int> >g[N],g1[N];
int w1[20],w2[20][N];
int vis1[20],vis2[N];
int f(){
	int s=0;
	vis2[1]=1;
	for(int i=1;i<=n;i++){
		if(vis2[i])continue;
		vis2[i]=1;
		int minn=INT_MAX;
		for(int j=0;j<g1[i].size();j++){
			pair<int,int> pii=g1[i][j];
			minn=min(minn,pii.second);
		}
		s+=minn;
	}return s;
}
void dfs(int dp){
	if(dp+1==k){
		int s=0;
		for(int i=1;i<=n;i++)g1[i]=g[i];
		for(int i=1;i<=k;i++){
			if(vis1[i]==1){
				s+=w1[i];
				for(int j=1;j<=n;j++){
					if(i!=j){
						g1[i].push_back({j,w2[i][j]});
						g1[j].push_back({i,w2[i][j]}); 
					}
				}
			}
		}
		for(int i=1;i<=n;i++)vis2[i]=0;
		ans=min(f()+s,ans);
		return;
	}
	vis1[dp]=1;
	dfs(dp+1);
	vis1[dp]=0;
	return;
}
signed main(){

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({u,w});
		g[v].push_back({v,w});
	}for(int i=1;i<=k;i++){
		cin>>w1[i];
		for(int j=1;j<=n;j++){
			cin>>w2[i][j];
			if(i==j)w2[i][j]=0;
		}
	}
	dfs(1); 
	cout<<ans;
	return 0;
}
