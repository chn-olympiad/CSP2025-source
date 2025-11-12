#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<pair<int,int> > G[11005];
vector<pair<int,int> > F[12][11005];
bool vis[11005];
int n,m,k;
bool ok[12];
int c[11005];
ll ans2=0x3f3f3f3f3f3f3f,ans=0x3f3f3f3f3f3f3f3f;
void dfs(int now,ll anss,int awa){
	if(anss>=ans) return;
	vis[now]=1;
	if(awa+1==n){
		ans=min(ans,anss);
		vis[now]=0;
		return;
	}
	for(int i=0;i<G[now].size();i++){
		if(!vis[G[now][i].first]){
			dfs(G[now][i].first,anss+G[now][i].second,awa+1);
		}
	}
	for(int i=1; i<=k; i++){
		if(ok[i]){
			for(int k=0;k<F[i][now].size();k++){
				if(!vis[F[i][now][k].first]){
					dfs(F[i][now][k].first,anss+F[i][now][k].second,awa+(now>n));
				}
			}
		}
	}
	vis[now]=0;
}
void dfs2(int pos,int cc){
	if(pos==k+1){
		ans=0x3f3f3f3f3f3f3f3f;
		dfs(1,0,0);
		ans2=min(ans2,ans+cc);
		return;
	}
	dfs2(pos+1,cc);
	ok[pos]=1;
	dfs2(pos+1,cc+c[pos]);
	ok[pos]=0;
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	int cnt=0;
	for(int i=1; i<=k; i++){
		cin>>c[i];
		for(int j=1; j<=n; j++){
			int a;
			cin>>a;
			F[i][i+n].push_back({j,a});
			F[i][j].push_back({i+n,a});
		}
		if(c[i]==0) cnt++;
	}
	if(cnt==k){
		for(int i=1; i<=k; i++) ok[i]=1;
		dfs(1,0,0);
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	ans2=min(ans2,ans);
	dfs2(1,0);
	cout<<ans2;
	return 0;
}

