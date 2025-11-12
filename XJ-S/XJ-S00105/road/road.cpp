#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M=5000005;
ll n,m,k,c[15],a[15][10005],h[1005][1005],ans;
struct node
{
	ll u,v,w;
}g[M];
bool cmp(struct node x,struct node y)
{
	return x.w<y.w;
}
//void add(int x,int y,int z)
//{
//	idx++;
//	e[idx]=y;
//	w[idx]=z;
//	ne[idx]=h[x];
//	h[x]=idx;
//}
int pd(int x,int y)
{
	int i,j,ok=0;
	for(i=1;i<=n;i++)
	{
		if(i!=x&&h[x][i]==1)
		{
			ok=1;
			if(i==y) return 1;
			else
			{
				if(pd(i,y)==1) return 1;
			}
		}
	}
	return 0;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll i,j,x,y;
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)
	{
		cin>>g[i].u>>g[i].v>>g[i].w;
	}
	for(i=1;i<=k;i++)
	{
		cin>>c[i];
		for(j=1;j<=n;j++)
		{
			cin>>a[i][j];
		} 
		for(x=1;x<=n;x++)
		{
			for(y=x+1;y<=n;y++)
			{
				m++;
				g[m].u=x;g[m].v=y;g[m].w=a[i][x]+a[i][y]+c[i];
			}
		}
	}
	sort(g+1,g+m+1,cmp);
	for(i=1;i<=m;i++)
	{
		if(pd(g[i].u,g[i].v)==0) 
		{
			h[g[i].u][g[i].v]=1;h[g[i].v][g[i].u]=1;
			ans+=g[i].w;
		}
	}
	cout<<ans;
	return 0;
}
