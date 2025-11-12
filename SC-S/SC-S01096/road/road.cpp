#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int u[N],v[N],w[N];;
struct node{
	int u,v,w;;
}r[N];
int n,m,k,ans=0x3f3f3f3f;
int a[15][10005],c[15],vis[10005];
int fa[10005];
int idx,res;
void ock()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
}
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int find(int x)
{
	if(x==fa[x])
	{
		return x;
	}
	else
	{	
		fa[x]=find(fa[x]);
		return fa[x];
	}
}
void kru()
{
	int cnt=0;
	for(int i=1;i<=n*3;i++)
	{
		fa[i]=i;
		vis[i]=0;
	}
	sort(r+1,r+1+idx,cmp);
	for(int i=1;i<=idx;i++)
	{
		int a=find(r[i].u);
		int b=find(r[i].v);
		if(a!=b)
		{
			fa[a]=b;
			res+=r[i].w;
			if(vis[r[i].v]==0&&r[i].v<=n)
			{
				cnt++;
			}
			if(vis[r[i].u]==0&&r[i].u<=n)
			{
				cnt++;
			}
			vis[r[i].v]=1;
			vis[r[i].u]=1;
			if(cnt==n)
			{
				return;
			}
		}
	}
}
signed main()
{
	ock();
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&u[i],&v[i],&w[i]);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	if(c[0]==0&&c[1]==0&&c[2]==0&&c[3]==0&&c[4]==0&&c[5]==0&&k!=0)
	{
		idx=m;
		for(int j=1;j<=m;j++)
		{
			r[j].u=u[j];
			r[j].v=v[j];
			r[j].w=w[j];
		}
		for(int j=1;j<=k;j++)
		{
			for(int zz=1;zz<=n;zz++)
			{
				idx++;
				r[idx].u=j+n*2;
				r[idx].w=a[j][zz];
				r[idx].v=zz;
			}
		}
		kru();
		ans=min(ans,res);
		printf("%lld",ans);
		return 0;
	}
	for(int i=0;i<(1<<k);i++)
	{
		res=0;
		idx=m+1;
		for(int j=1;j<=m;j++)
		{
			r[j].u=u[j];
			r[j].v=v[j];
			r[j].w=w[j];
		}
		for(int j=1;j<=k;j++)
		{
			if((i|(1<<(j-1)))==i)
			{
				res+=c[j];
				for(int zz=1;zz<=n;zz++)
				{
					idx++;
					r[idx].u=j+n*2;
					r[idx].w=a[j][zz];
					r[idx].v=zz;
				}
			}
		}
		kru();
		ans=min(ans,res);
	}
	printf("%lld",ans);
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