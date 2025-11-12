#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,ans=INT_MAX;
int a[1010][1010];
int b[20][1010];
bool vis[1010];
void dfs(int id,int cnt){
	if(id==n){
		if(cnt<ans){
			ans=cnt;
		}
		return ;
	}
	for(int i=2;i<=n-1;i++){
		if(a[id][i]==-1){
			continue;
		}
		vis[id]=false;
		dfs(i,cnt+a[id][i]);
		vis[id]=true;
	} 
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	memset(a,-1,sizeof(a));
	for(int i=1;i<=m;i++){
		int q,u,x;
		cin>>q>>u>>x;
		a[q][u]=x;
		a[u][q]=x;
	}
	for(int i=1;i<=k;i++){
		cin>>a[i][0];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	dfs(1,0);
	cout<<ans;
	return 0;
} 