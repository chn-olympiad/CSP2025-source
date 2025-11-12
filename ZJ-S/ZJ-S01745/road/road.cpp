#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0, f=1;
	char ch=getchar();
	while(ch<'0' || '9'<ch)
		ch=getchar();
	while('0'<=ch && ch<='9')
		x=(x<<1)+(x<<3)+ch-'0', ch=getchar();
	return x;
}
const int N=1e4+10, M=2e6+10;

struct edge
{
	int u;
	int v;
	int w;
}Edge[M];

int Fa[N];
int Find(int x)
{
	return Fa[x]==x ? x : Fa[x]=Find(Fa[x]);
}

bool cmp(edge x, edge y)
{
	return x.w<y.w;
}
int Val[20];
int n, m, K;
long long GetMin(short Exist)
{
	long long Res=0;
	for(int i=1;i<=n+K;i++) Fa[i]=i;
	for(register int i=1;i<=m;i++)
	{
		int fu=Find(Edge[i].u), fv=Find(Edge[i].v);
		if(fu==fv || Edge[i].u>n && ((Exist>>(Edge[i].u-n-1))&1)==0)
			continue;
		Res+=Edge[i].w;
		Fa[fu]=fv;
	}
	for(int i=1;i<=K;i++)
	{
		if(Exist&1)
			Res+=Val[i];
		Exist>>=1;
	}
	return Res;
}
long long ans=0x7f7f7f7f7f7f7f7f;
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &K);
	bool flag=true;
	for(register int i=1;i<=m;i++)
		Edge[i].u=read(), Edge[i].v=read(), Edge[i].w=read();
	for(int i=1;i<=K;i++)
	{
		Val[i]=read(), flag&=Val[i]==0;
		for(int j=1, x;j<=n;j++)
		{
			x=read();
			Edge[++m]={n+i, j, x};
		}
	}
	sort(Edge+1, Edge+m+1, cmp);
	if(flag)
		ans=GetMin((1<<K)-1);
	else
	{
		for(short s=0;s<=(1<<K)-1;s++)
			ans=min(ans, GetMin(s));
	}
	printf("%lld", ans);
	return 0;
}
/*
求含有特殊点权图的最小生成树 
50%
k<=10 枚举每个特殊点是否存在，每次进行一次最小生成树计算O(2^k * m) 

加快读加longlong 

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
