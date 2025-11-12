#include<bits/stdc++.h>
#define int long long
using namespace std;
int fa[1018617];
int getfa(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=getfa(fa[x]);
}
void merge(int x,int y)
{
	fa[getfa(x)]=y;
}
struct edges
{
	int u,v,w;
}g[1018617];
bool cmp(edges a,edges b)
{
	return a.w<b.w;
}
int n,m,k;
int dian[1018617],d[1018617],b[1018617];
bool used[1018617];
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)scanf("%lld%lld%lld",&g[i].u,&g[i].v,&g[i].w);    int nowm=m;
	for(int i=1;i<=k;i++)
    {
    	cin>>dian[n+i];
    	for(int j=1;j<=n;j++)
    	{
    		g[++nowm].v=n+i;
    		g[nowm].u=j;
    		scanf("%lld",&g[nowm].w);
    		g[nowm].w+=dian[n+i];
		}
	}
	sort(g+1,g+1+nowm,cmp);
    for(int i=1;i<=n+k;i++)fa[i]=i;
    int ans=0;
    int res=0;
    for(int i=1;i<=nowm;i++)
    {    	
    	int fau=getfa(g[i].u),fav=getfa(g[i].v);
		if(fau!=fav)
    	{
    		merge(g[i].u,g[i].v);
    		ans+=g[i].w;
			res++;
    		d[g[i].u]++,b[g[i].u]+=g[i].w,d[g[i].v]++,b[g[i].v]+=g[i].w;
		}
	}
	for(int i=n+1;i<=n+k;i++)
	{
		if(d[i]==1ll)ans-=b[i];
		else ans-=(d[i]-1ll)*dian[i]*2ll;
	}
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/