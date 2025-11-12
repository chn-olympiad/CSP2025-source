#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+10,inf=1e18;
int n,m,k,f[N][N],a[N][N],minn,dis[N],flag[N],v[N][N],sum;
inline void dfs(int now){
	queue<int> q;
	q.push(now);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=1;i<=n;i++){
			if(f[u][i]&&dis[u]+a[u][i]<dis[i]){
				q.push(i);
				dis[i]=a[u][i];
				if(f[u][i]!=1) flag[f[u][i]]=1;
			}
		}
	}
	return ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		f[u][v]=f[v][u]=1;
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=1;i<=n;i++) dis[i]=inf;
	dis[1]=0;
	dfs(1);
	for(int i=1;i<=n;i++) minn+=dis[i];
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++) cin>>v[i][j];
	for(int p=1;p<=k;p++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(f[i][j]==0||v[p][i]+v[p][j]+v[p][0]<=a[i][j]) a[i][j]=v[p][i]+v[p][j],f[i][j]=p;
	for(int i=1;i<=n;i++) sum+=dis[i];
	for(int p=1;p<=k;p++) if(flag[p]) sum+=v[p][0];
	cout<<min(minn,sum);
}
