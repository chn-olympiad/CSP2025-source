#include<bits/stdc++.h>
using namespace std;
long long n,m,k,bcj[10010],a[20][10010],ans,ex[20],jl2[10010][20],jsq,jl[20];
struct node
{
	int u,v,sf;
	long long w;
	bool operator<(node x)const
	{
		return w+ex[sf]<x.w+ex[x.sf];
	}
}edge[60000000];
long long fd(long long x)
{
	return x==bcj[x]?x:x=fd(bcj[x]);
}
long long kru(long long sx)
{
	long long ans2=0,tot=0;
	for(int i=1;i<=sx;++i)
	{
		long long u=fd(edge[i].u),b=fd(edge[i].v);
		if(u!=b)
		{
			++tot;
			bcj[b]=u;
			ans2+=edge[i].w;
			jl[edge[i].sf]=1;
			if(jl2[u][edge[i].sf])
			{
				ans2-=a[edge[i].sf][u];
			}
			if(jl2[b][edge[i].sf])
			{
				ans2-=a[edge[i].sf][b];
			}
			jl2[u][edge[i].sf]=jl2[b][edge[i].sf]=edge[i].sf;
		}
		if(tot==n-1)
		{
			break;
		}
	}
	for(int i=1;i<=k;++i)
	{
		if(jl[i])
		{
			ans2+=ex[i];
		}
	}
	return ans2;
}
long long read()
{
	char ch=getchar();
	long long x=0;
	while(ch<'0'||'9'<ch)
	{
		ch=getchar();
	}
	while('0'<=ch&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=n;++i)
	{
		bcj[i]=i;
	}
	for(int i=1;i<=m;++i)
	{
		edge[i].u=read();
		edge[i].v=read();
		edge[i].w=read();
	}
	sort(edge+1,edge+m+1);
	ans=kru(m);
	for(int i=1;i<=k;++i)
	{
		ex[i]=read();
		for(int j=1;j<=n;++j)
		{
			a[i][j]=read();
		}
	}
	jsq=m;
	if(k)
	{
		for(int j=1;j<n;++j)
		{
			for(int sp=j+1;sp<=n;++sp)
			{
				++jsq;
				edge[jsq].w=a[1][j]+a[1][sp];
				edge[jsq].u=j;
				edge[jsq].v=sp;
				edge[jsq].sf=1;
				for(int i=2;i<=k;++i)
				{
					if(a[i][j]+a[i][sp]<edge[jsq].w)
					{
						edge[jsq].w=a[i][j]+a[i][sp];
						edge[jsq].sf=i;
					}
				}
			}
		}
		for(int i=1;i<=n;++i)
		{
			bcj[i]=i;
		}
		sort(edge+1,edge+jsq+1);
		ans=min(ans,kru(jsq));
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}