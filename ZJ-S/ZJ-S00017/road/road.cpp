#include<bits/stdc++.h>
using namespace std;
long long n,m,k,minn=INT_MAX,cnt,vis[10015],c[15],a[15][10005];
long long mp[10015][10015];
void dfs(long long id,long long x,long long ans){
	vis[x]=1;
	if(id==n+1){
		minn=min(minn,ans);
	}
	for(int i=1;i<=n+k;i++){
		if(vis[i]) continue;
		if(i<=4){
			dfs(id+1,i,ans+mp[x][i]);
		}else{
			dfs(id,i,ans+mp[x][i]);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		mp[u][v]=mp[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]==0){
			cnt++;
		}
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(cnt==k){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				mp[i+n][j]=mp[j][i+n]=a[i][j];
			}
		}
		dfs(0,1,0);
	}
	cout<<minn;
	return 0;
}
