#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long LL;
LL read()
{
	char c=getchar();
	LL f=1,x=0;
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^'0');
		c=getchar();
	}
	return x*f;
}
void print(LL x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9) print(x/10);
	putchar(x%10+'0');
}
const LL N=1e4+15,M=1e6+5,K=15;
LL n,m,k,p,ct,c[K],f[1030][N],cnt[1030],sum[1030],ans=1e18;
struct edge
{
	LL u,v,w,id;
}e[M+K*N],ne[M];
struct dsu
{
	LL fa[N];
	void init()
	{
		for(int i=1;i<=n+k;i++) fa[i]=i;
	}
	LL findfa(LL x)
	{
		if(x==fa[x]) return x;
		fa[x]=findfa(fa[x]);
		return fa[x];
	}
}d;
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
LL calc(LL x)
{
	sort(ne+1,ne+1+ct,cmp);
	d.init();
	LL o=0,res=0;
	for(int i=1;i<=ct;i++)
	{
		LL u=ne[i].u,v=ne[i].v,w=ne[i].w;
		u=d.findfa(u),v=d.findfa(v);
		if(u==v) continue;
		o++;
		res+=w;
		d.fa[v]=u;
		f[x][o]=ne[i].id;
		if(o==n+cnt[x]-1) break;
	}
	return res;
}
int main()
{
//	freopen("road1.in","r",stdin);
//	freopen("road.out","w",stdout);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++)
	{
		e[i].u=read();
		e[i].v=read();
		e[i].w=read();
		e[i].id=i;
	}
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++)
		{
			LL o=m+(i-1)*n+j;
			e[o].u=i+n;
			e[o].v=j;
			e[o].w=read();
			e[o].id=o;
		}
	}
	for(int i=0;i<1<<k;i++)
	{
		ct=0;
		if(!i)
		{
			for(int j=1;j<=m;j++) ne[++ct]=e[j];
		}
		else
		{
			LL o=i&(-i);
			LL x=log2(o)+1;
			cnt[i]=cnt[i^o]+1;
			sum[i]=sum[i^o]+c[x];
			for(int j=1;j<=n+cnt[i^o]-1;j++)
			{
				ne[++ct]=e[f[i^o][j]];
			}
			for(int j=1;j<=n;j++)
			{
				LL y=m+(x-1)*n+j;
				ne[++ct]=e[y];
			}
		}
		ans=min(ans,calc(i)+sum[i]);
	}
//	for(int i=0;i<1<<k;i++)
//	{
//		for(int j=1;j<=n)
//	}
	print(ans);
	return 0;
}