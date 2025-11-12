#include<bits/stdc++.h>
using namespace std;
const int nx=1e4;
const int mx=1e6;
int c[20],fth[nx+20];
struct noden
{
	int u,v,w;
	bool friend operator<(const noden &aa,const noden &bb)
	{
		return aa.w<bb.w;
	}
}ee[mx+10],ff[nx*11+10];
int read()
{
	int v=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		v=v*10+(ch-'0');
		ch=getchar();
	}
	return v;
}
int getn(int x)
{
	if(fth[x]==x) return x;
	return fth[x]=getn(fth[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int i,j,n,m,nn,cnt=0;
	long long ans=1e18,sumn;
	n=read();m=read();nn=read();
	for(i=1;i<=m;++i)
	{
		ee[i].u=read();ee[i].v=read();ee[i].w=read();
	}
	sort(ee+1,ee+1+m);
	for(i=1;i<=n;++i) fth[i]=i;
	for(i=1;i<=m;++i)
		if(getn(ee[i].u)!=getn(ee[i].v))
		{
			fth[getn(ee[i].u)]=getn(ee[i].v);
			ff[++cnt]=ee[i];
		}
	for(j=0;j<=nn-1;++j)
	{
		c[j]=read();
		for(i=1;i<=n;++i)
		{
			ff[++cnt].u=i;
			ff[cnt].v=n+j+1;
			ff[cnt].w=read();
		}
	}
	sort(ff+1,ff+1+cnt);
	for(j=0;j<=(1<<nn)-1;++j)
	{
		sumn=0;
		for(i=1;i<=n+nn;++i) fth[i]=i;
		for(i=0;i<=nn-1;++i)
			if(j&(1<<i)) sumn+=c[i];
		for(i=1;i<=cnt;++i)
			if(ff[i].v<=n||j&(1<<(ff[i].v-n-1)))
			{
				if(getn(ff[i].u)!=getn(ff[i].v))
				{
					sumn+=ff[i].w;
					fth[getn(ff[i].u)]=getn(ff[i].v);
				}
			}
		ans=min(ans,sumn);
	}
	printf("%lld\n",ans);
	return 0;
}
