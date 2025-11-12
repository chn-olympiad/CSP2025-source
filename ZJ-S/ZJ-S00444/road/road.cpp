#include <bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,fa[1000005],cnt;
long long c[15],a,ans=1e18;
bool b[11];
char ch;
struct S
{
	int u,v;
	long long w;
}e[1000005];
bool cmp(S a,S b)
{
	return a.w<b.w;
}
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
bool Q(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y)return 0;
	fa[x]=y;
	return 1;
}
long long krs(int p,int q)
{
	for(int i=1;i<=n+k;i++)fa[i]=i;
	long long sum=0;int num=0;
	while(q)
	{
		int u=e[++num].u,v=e[num].v;
		long long w=e[num].w;
		if(v>n&&b[v-n]==0)continue;
		if(Q(u,v))
		{
			q--;
			sum+=w;
		}
	}
	return sum;
}
int read1()
{
	int a=0;
	char c=' ';
	while(c=getchar())
	{
		if('0'<=c&&c<='9')a=a*10+c-'0';
		else break;
	}
	return a;
}
long long read2()
{
	long long a=0;
	while(ch=getchar())
	{
		if('0'<=ch&&ch<='9')a=a*10+ch-'0';
		else break;
	}
	return a;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	ch=getchar();
	for(int i=1;i<=m;i++)
	{
		u=read1();
		v=read1();
		w=read2();
		e[++cnt]=(S){u,v,w};
	}
	for(int i=1;i<=k;i++)
	{
		c[i]=read2();
		for(int j=1;j<=n;j++)
		{
			a=read2();
			e[++cnt]=(S){j,n+i,a};
		}
	}
	sort(e+1,e+cnt+1,cmp);
	for(int i=0;i<(1<<k);i++)
	{
		int t=0;
		long long sum=0;
		for(int j=1;j<=k;j++)
			if(i&(1<<j-1))b[j]=1,t++,sum+=c[j];
			else b[j]=0;
		ans=min(ans,krs(i,t+n-1)+sum);
	}
	printf("%lld",ans);
	return 0;
}
