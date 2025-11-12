#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[10005][10005],u[1000005],v[100005],vis[10005],nn;
long long c[15],w[1000005],ww[15][1000005];
int minn=0x3f3f3f3f;
void dfs(int fang,int nn,int cnt){
	vis[fang]=1;
	if(nn==n){
		minn=min(minn,cnt-1);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(a[fang][i]>0){
			if(vis[i]==0){
				dfs(i,nn+1,cnt+a[fang][i]);
				vis[i]=0;
			}
		}
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		a[u[i]][v[i]]=w[i];
		a[v[i]][u[i]]=w[i];
	}
	int f=1;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>ww[i][j];
		}
		if(c[i]!=0) f=0;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			a[u[i]][v[i]]=max(a[u[i]][v[i]],ww[i][v[n]]+ww[i][u[n]]);
			a[v[i]][u[i]]=max(a[v[i]][u[i]],ww[i][u[n]]+ww[i][v[n]]);
		}
	}
	dfs(1,1,0);
	cout<<minn;
	return 0;
}
