#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans=1e9+5,xiu[10500];
bool vis[10500];
struct node{
	int u,w;
};
vector<node> q[10500];
void dfs(int x,int s,int y){
	if(s>=ans) return ;
	if(y>=n){
		ans=min(ans,s);
		return ;
	}
	int l=q[x].size();
	for(int i=0;i<l;i++){
		int u=q[x][i].u;
		int w=q[x][i].w;
		if(!vis[u]){
			vis[u]=1;
			if(xiu[u]!=0){
				int t=xiu[u];
				xiu[u]=0;
				dfs(u,s+w+t,y);
				xiu[u]=t;
			}
			else dfs(u,s+w,y+1);
			vis[u]=0;
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		q[u].push_back({v,w});
		q[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		int w,x;
		cin>>x;
		xiu[n+i]=x;
		for(int j=1;j<=n;j++){
			cin>>w;
			int u=n+i;
			q[u].push_back({j,w});
			q[j].push_back({u,w});
		}
	}
	vis[1]=1;
	dfs(1,0,1);
	cout<<ans;
	return 0;
}
//
