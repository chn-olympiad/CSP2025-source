#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define N 20005
#define M 1000006
using namespace std;
int read()
{
	int fl=1,x=0;
	char c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')fl=-1,c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*fl;
}
int n,m,K;
struct po{
	int x,y,v;
}E[M],num[15][N],tmp[N],e[M],tmpe[M];
int len=0,fa[N];
bool cmp(po a,po b)
{
	return a.v<b.v;
}
int getfa(int x)
{
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
void merge(int x)
{
	int A=1,B=1,cnt=0;
	while(A<=len&&B<=n)
	{
		if(e[A].v<=num[x][B].v)
		{
			tmpe[++cnt]=e[A];
			A++;
		}
		else
		{
			tmpe[++cnt]=num[x][B];
			B++;
		}
	}
	while(A<=len)
	{
		tmpe[++cnt]=e[A];
		A++;
	}
	while(B<=n)
	{
		tmpe[++cnt]=num[x][B];
		B++;
	}
	len=cnt;
	for(int i=1;i<=len;i++)e[i]=tmpe[i];
	return ;
}
int getans()
{
	for(int i=1;i<=n+K;i++)fa[i]=i;
	int S=0;
	for(int i=1;i<=len;i++)
	{
		int x=getfa(e[i].x),y=getfa(e[i].y);
		if(x==y)continue;
		fa[x]=y;
		S+=e[i].v;
	}
	return S;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();K=read();
	for(int i=1;i<=m;i++)
	{
		E[i].x=read();
		E[i].y=read();
		E[i].v=read();
	}
	for(int i=1;i<=K;i++)
	{
		for(int j=0;j<=n;j++)
		{
			num[i][j].x=n+i;num[i][j].y=j;
			num[i][j].v=read();
		}
		sort(num[i]+1,num[i]+1+n,cmp);
	}
	sort(E+1,E+1+m,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		int x=getfa(E[i].x),y=getfa(E[i].y);
		if(x==y)continue;
		fa[x]=y;
		tmp[++cnt]=E[i];
	}
	int minn=inf;
	for(int i=0;i<(1<<K);i++)
	{
		len=0;
		for(int j=1;j<n;j++)e[++len]=tmp[j];
		for(int j=1;j<=K;j++)
			if((i>>(j-1))&1)
				merge(j);
		int val=getans();
//		cout<<i<<' '<<val<<'\n';
//		for(int j=1;j<=len;j++)cout<<e[j].x<<' '<<e[j].y<<' '<<e[j].v<<'\n';
//		cout<<'\n';
		for(int j=1;j<=K;j++)
			if((i>>(j-1))&1)
				val+=num[j][0].v;
		minn=min(minn,val);
	}
	cout<<minn<<'\n';
	return 0;
}
