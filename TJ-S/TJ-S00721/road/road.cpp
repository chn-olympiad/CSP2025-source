#include<bits/stdc++.h> 
using namespace std;
int a[1005][1005];
bool b[15],vis[1005];
int c[10][1005],d[15];
int ans=1e9;
int n,m,k;
void dfs(int x,int dj,int ljs){
	if(dj>ans) return ;
	if(ljs>=n){
		ans=min(ans,dj);
		return ;
	}	
	for(int i=1;i<=1005;i++){
		if(a[x][i]!=0&&vis[i]==false){
			vis[i]=true;
			dfs(i,dj+a[x][i],ljs+1);
			vis[i]=false;
		}
	}
	for(int i=0;i<=1005;i++){
		if(b[i]==false) dfs(i,dj+c[x][i],ljs+1);
		if(b[i]==true) dfs(i,dj+c[x][i]+d[i],ljs+1);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>d[i];
		for(int j=1;j<=m;j++){
			cin>>c[i][j];
		}
	}
	dfs(1,0,0);
	return 0;
}
