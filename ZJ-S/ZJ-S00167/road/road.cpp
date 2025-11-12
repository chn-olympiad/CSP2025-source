#include<bits/stdc++.h>
#define PLLI pair<long long,int>
using namespace std;
//struct edge
//{
//	int u,v,w;
//}w[1000005];
int n,m,k,c[15],a[15][10005];//f[10005];
long long ans=LONG_LONG_MAX,res,V[10015];//d[10015];
bool vis[10015];
vector<pair<int,int> > w[10005];
priority_queue<PLLI,vector<PLLI >,greater<PLLI > > p;
//bool cmp(edge x,edge y)
//{
//	return x.w<y.w;
//}
//int find(int x)
//{
//	return f[x]==x?x:f[x]=find(f[x]);
//}
int main()
{
	freopen("road.in","r",stdin);
//	freopen("road3.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(register int i=1,u,v,W;i<=m;i++)
//		scanf("%d%d%d",&w[i].u,&w[i].v,&w[i].w);
		scanf("%d%d%d",&u,&v,&W),
		w[u].push_back({W,v}),w[v].push_back({W,u});
	for(register int i=1,j;i<=k;i++)
		for(scanf("%d",c+i),j=1;j<=n;j++)
			scanf("%d",&a[i][j]);//printf("a[i][j]=%d%c",a[i][j],"\n "[j<n]);
//	sort(w+1,w+m+1,cmp);
	for(register int dp=0,u,f;dp<1<<k;f?0ll:ans=min(ans,res),dp++)
	{
		res=0;f=0;
		for(register int i=0;i<k;i++)
		{
			res+=!!(dp&1<<i)*c[i+1];
			if(!(dp&1<<i) && !c[i+1])
			{
				f=1;break;
			}
		}
		if(f) continue;
//		for(int i=1;i<=n;i++)
//			f[i]=i;
//		int u;
//		memset(d,0x3f,sizeof d);d[1]=0;
		memset(vis,0,sizeof vis);
		memset(V,0x3f,sizeof V);V[1]=0;
		for(p.push({0,1});!p.empty();)
		{
			u=p.top().second;p.pop();
			if(vis[u]) continue;
			vis[u]=1;
			res+=V[u];
//			printf("%d %d\n",u,V[u]);
			if(u<=n)
				for(register PLLI v:w[u])
					!vis[v.second] && /*d[u]+v.first<d[v.second]*/v.first<V[v.second]?
						p.push(make_pair(/*d[v.second]=d[u]+v.first*/V[v.second]=v.first,v.second)),0:0;
			if(u>n && u<=n+k)
				for(register int i=1;i<=n;i++)
					!vis[i] && /*d[u]+a[u-n][i]<d[i]*/a[u-n][i]<V[i]?
						p.push(make_pair(/*d[i]=d[u]+a[u-n][i]*/V[i]=a[u-n][i],i)),0:0;
			else
				for(register int i=n+1;i<=n+k;i++)
					(dp&1<<i-n-1) && !vis[i] && /*d[u]+a[i-n][u]<d[i]*/a[i-n][u]<V[i]?
						p.push(make_pair(/*d[i]=d[u]+a[i-n][u]*/V[i]=a[i-n][u],i)),0:0;
		}
//		printf("res=%lld\n",res);
	}
	printf("%lld",ans);
	return 0;
}
