#include<bits/stdc++.h>
using namespace std;
const int MAXN=10010;
int r[MAXN][MAXN],c[20],a[20][MAXN],rc[MAXN][MAXN],vis[MAXN],viscz[20];
int n,m,k,u,v,w,ans=INT_MAX;
void dfs(int cnct,int now,int sum){
	if(cnct==n){
		//cout<<sum<<endl;
		ans=min(ans,sum);
		return;
	}
	vis[now]=1;
	for(int i=1;i<=n;i++){
		if(vis[i])	continue;
		vis[i]=1;
		if(rc[now][i]&&!viscz[rc[now][i]]){
			sum+=c[rc[now][i]];
			viscz[rc[now][i]]=1;
		}
		//cout<<i<<' ';
		dfs(cnct+1,i,sum+r[now][i]);
		vis[i]=0;
		viscz[rc[now][i]]=0;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		r[u][v]=w;
		r[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			for(int cz=1;cz<=k;cz++){
				if(r[i][j]==0){
					r[i][j]=a[cz][i]+a[cz][j];
					rc[i][j]=cz;
				}
				if(a[cz][i]+a[cz][j]+c[cz]<r[i][j]){
					r[i][j]=a[cz][i]+a[cz][j];
					rc[i][j]=cz;
				}
			}
			r[j][i]=r[i][j];
			rc[j][i]=rc[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		dfs(1,i,0);
	}
	cout<<ans;
	return 0;
}
