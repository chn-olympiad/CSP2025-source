#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int v,w;
};
int vis[10005];
vector<node> ve[10005];
long long ans=INT_MAX;
void dfs(int s,long long len,int q){
	if(len>ans){
		return ;
	}
	if(s==n){
		ans=min(ans,len);
		return ;
	}
	for(int i=0;i<ve[q].size();i++){
		if(vis[ve[q][i].v]==0){
			vis[ve[q][i].v]=1;
			dfs(s+1,len+=ve[q][i].w,ve[q][i].v);
			vis[ve[q][i].v]=0;
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
		ve[u].push_back({v,w});
		ve[v].push_back({u,w});
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		dfs(1,0,i);
	}
	cout<<ans;
	return 0;
}
