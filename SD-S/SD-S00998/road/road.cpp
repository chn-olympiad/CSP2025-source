#include<bits/stdc++.h>
using namespace std;
#define int long long
int f[10010],siz[10010];
int n,m,k;
int a[10010];
struct edge{
	int u,v,w;
	bool operator < (const edge & x)const
	{
		return this->w<x.w;
	}
}e[10000100];
inline int read()
{
	int num=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		num=(num<<3)+(num<<1)+(ch^48);
		ch=getchar();
	}
	return num;
}
int find(int x)
{
	return x==f[x]?x:f[x]=find(f[x]);
}
void unionn(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y)return ;
	if(siz[x]>siz[y])swap(x,y);
	f[x]=y;
	siz[y]+=siz[x];
}
inline void work()
{
	long long ans=0,cnt=0;
	for(int i=1;i<=m;i++)
	{
		e[i].u=read();e[i].v=read();e[i].w==read();
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++)
	{
		if(find(e[i].u)==find(e[i].v))continue;
		ans+=e[i].w;
		unionn(e[i].u,e[i].v);
		cnt++;
		if(cnt==n-1)break;
	}
	cout<<ans;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
		siz[i]=1;
	}
	if(k==0)
	{
		work();
		return 0;
	}
	long long cnt=0,ans=0,num=0;
	for(int i=1;i<=m;i++)
	{
		cnt++;
		e[cnt].u=read();e[cnt].v=read();e[cnt].w=read();
	}
	for(int i=1;i<=k;i++)
	{
		int c;
		cin>>c;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				cnt++;
				e[cnt]={i,j,c+a[i]+a[j]};
			}
		}
	}
	sort(e+1,e+cnt+1);
	for(int i=1;i<=cnt;i++)
	{
		if(find(e[i].u)==find(e[i].v))continue;
		ans+=e[i].w;
		unionn(e[i].u,e[i].v);
		num++;
		if(num==n-1)break;
	}
	cout<<ans;
}
