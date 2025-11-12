#include<bits/stdc++.h>
using namespace std;
long long ans,dis[10005];
int n,m,k,pd[15],a[15][1005];
int xuan[10005];
vector <int> b[1005],c[1005];
long long solve(int u,long long sum) {
	int minx=0,t=0,quan;
	xuan[u]=0;
	for (int i=0;i<b[u].size();i++) {
		int v=b[u][i];
		if (v==u||xuan[v]==0) continue;
			if (c[u][i]+dis[u]<dis[v])	dis[v]=c[u][i]+dis[u];
			if (dis[u]>minx) {
			minx=dis[u];
			quan=c[u][i];
			t=u;
		}
	}
	if (t==0) return sum;
	return solve(t,sum+quan);
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ans=INT_MAX;
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		b[u].push_back(v);c[u].push_back(w);
		b[v].push_back(u);c[v].push_back(w);
	}
	for (int j=1;j<=k;j++)	
	for (int i=0;i<=n;i++) 
	scanf("%d",&a[j][i]);
	printf("%lld",solve(1,0));
	return 0;
}
