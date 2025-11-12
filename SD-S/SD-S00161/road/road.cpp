#include<bits/stdc++.h>
#define int long long
using namespace std;
int next[2000005],end[2000005],w[2000005],top,cnt,fa[2000005],n,m,k,c[200005],ans=0x3f3f3f3f3f3f3f3f,o;
//void add(int u,int v,int c)
//{
//	if (end[u])
//	{
//		next[end[u]]=++top;
//		end[u]=top;
//	}
//	else
//	{
//		top[u]=++top;
//		end[u]=top;
//	}
//	w[top]=c;
//}
struct node{
	int u,v,c;
	bool operator <(const node x)const
	{
		return c<x.c;
	}
}a[2000005];node b[15][200005];
int find(int u)
{
	if (u==fa[u])
	{
		return u;
	}
	else
	{
		return fa[u]=find(fa[u]);
	}
}
int d[6];
int zxscs(int x)
{
	int z=0;
	d[0]=d[1]=d[2]=d[3]=d[4]=d[5]=1;
	for (int i=1;i<=m+n*k;i++)
	{
		int minid=0,minx=a[d[0]].c;
		for (int j=1;j<=k;j++)
		{
			if (o&(1<<(j-1)))
			{
				if (b[j][d[j]].c>minx)
				{
					minid=j;
				}
			}
		}
		node xx;
		if (minid==0)
		{
			xx=a[d[minid]++];
		}
		else
		{
			xx=b[minid][d[minid]++];
		}
		if (find(xx.u)!=find(xx.v))
		{
			x--;
			z+=xx.c;
			if (x==1)
			{
				return z;
			}
			fa[find(xx.u)]=find(xx.v);
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for (int i=1,u,v,w;i<=m;i++)
	{
		cin>>u>>v>>w;
		a[++cnt]=(node){u,v,w};
	}
	sort(a+1,a+m+1);
	for (int i=1;i<=k;i++)
	{
		cin>>c[i];
		for (int j=1;j<=n;j++)
		{
			cin>>b[i][j].c;
			b[i][j].u=n+i;
			b[i][j].v=j;
		}
		sort(b[i]+1,b[i]+n+1);
	}
	int cnt_;
	cnt_=cnt;
	for (int i=0;i<(1<<k);i++)
	{
		o=i;
		cnt=cnt_;
		int x=i,cc=0,anss=0;
		for (int i=1;i<=n+10;i++)
		{
			fa[i]=i;
		}
		ans=min(anss+zxscs(n+cc),ans);
	}
	cout<<ans;
	return 0;
}

