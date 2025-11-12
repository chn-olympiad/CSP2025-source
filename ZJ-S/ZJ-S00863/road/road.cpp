#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u,v,b=1,cnt,c[20],sum,ans=LONG_LONG_MAX;
long long fa[10100];
bool vis[10100];
struct node
{
	long long u,v,w;
}e[2000010];
long long read()
{
	long long x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
		ch=getchar();
	while('0'<=ch&&'9'>=ch)
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x;
}
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(fa[x]==x)
		return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;++i)
	{
		e[i].u=read();e[i].v=read();e[i].w=read();
	}
	cnt=m;
	for(int i=1;i<=k;++i)
	{
		b=b*2;
		c[i]=read();
		for(int j=1;j<=n;++j)
		{
			e[++cnt].w=read();e[cnt].u=j;e[cnt].v=n+i;
		}
	}
	sort(e+1,e+1+cnt,cmp);
	for(int l=0;l<b;++l)
	{
		int tmp=1,num=n;
		sum=0;
		for(int i=1;i<=n;++i)
		{
			vis[i]=false;
			fa[i]=i;
		}
		for(int i=1;i<=k;++i)
		{
			if((l&(1<<(i-1)))!=0)
			{
				vis[i+n]=false;++num;
				sum+=c[i];
				fa[n+i]=n+i;
			}else
				vis[i+n]=true;
		}
		for(int i=1;i<=cnt;++i)
		{
			if(vis[e[i].v]||vis[e[i].u])
				continue;
			int x=find(e[i].u);
			int y=find(e[i].v);
			if(x!=y)
			{
				fa[x]=y;
				sum+=e[i].w;
				++tmp;
			}
			if(tmp==num)
				break;
		}
		ans=min(ans,sum);
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