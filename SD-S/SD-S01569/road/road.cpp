#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,K,p,ans=0x3f3f3f3f3f3f3f3f,res,c[12],fa[10020],sz[10020];
struct edge
{
	int u,v,w;
	bool operator<(const edge &x)const{return w<x.w;}
}e[1000006],E[10020],mst[10020],d[10020],a[12][10004];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int merge(int u,int v){if(sz[u]<sz[v])swap(u,v);sz[u]+=sz[v];fa[v]=u;}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();K=read();
	for(int i=1;i<=m;i++){e[i].u=read();e[i].v=read();e[i].w=read();}
	sort(e+1,e+m+1);
	for(int i=1;i<=n;i++){fa[i]=i;sz[i]=1;}
	for(int i=1,u,v;i<=m;i++)
	{
		u=find(e[i].u);
		v=find(e[i].v);
		if(u==v)continue;
		merge(u,v);
		E[++p]=e[i];
		if(p==n-1)break;
	}
	for(int i=0;i<K;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++)a[i][j]=(edge){j,n+i+1,read()};
		sort(a[i]+1,a[i]+n+1);
	}
	for(int i=0,o,x,y,u,v;i<(1<<K);i++)
	{
		o=n-1;res=0;
		for(int j=0;j<n;j++)mst[j]=E[j];
		for(int j=0;j<K;j++)if(i&(1<<j))
		{
			o++;res+=c[j];p=0;x=y=1;
			for(int k=1;k<=n+K;k++){fa[k]=k;sz[k]=1;}
			for(int k=1;k<o;k++)d[k]=mst[k]; 
			for(;;)
			{
				if(x<o&&(y>n||d[x].w<a[j][y].w))
				{
					u=find(d[x].u);
					v=find(d[x].v);
					if(u!=v)
					{
						merge(u,v);
						mst[++p]=d[x];
					}
					x++;
				}
				else
				{
					u=find(a[j][y].u);
					v=find(a[j][y].v);
					if(u!=v)
					{
						merge(u,v);
						mst[++p]=a[j][y];
					}
					y++;
				}
				if(x>=o&&y>n)break;
				if(p==o)break;
			}
		}
		for(int j=1;j<=o;j++)res+=mst[j].w;
		ans=min(ans,res);
	}
	cout<<ans;
}
/*
Ren5Jie4Di4Ling5%
15:00 have an O(mlogm+2^k*k*n*logn) way to solve it,i think it cannot pass.
15:15 ok,ok,i have no idea,i bet O(mlogm+2^k*k*n*alpha(n)) can pass this problem.Anyway,at least 80.
16:05 done,why it gets wrong answer?
16:20 pass all big tests in 0.75s?wtf?
*/
