/*
1.得到树边m log m
2.状态压缩枚举加入哪些城市化乡镇 2^k=1024
3.加入剩下的边 nk 100000
4.跑kruscal n+(n*k)log(n*k) 1e5 log 1e5

e,e I finished it?

将边持久化了，应该会更快吧 

检查了程序边界 
*/
#include<bits/stdc++.h>
using namespace std;
const int N=10100;
struct edge
{
	int u,v,w,id;
}e[1000010];
int fa[N],cnt,n,m,k;
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
int findfa(int u)
{
	return (fa[u]==u)?(fa[u]):(fa[u]=findfa(fa[u]));
}
int add[N];
int lk[11][N];
bool can[11];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
		e[i].id=0;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>add[i];
		for(int j=1;j<=n;j++)
		{
			cin>>lk[i][j];
		}
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	long long sum=0;
	for(int i=1;i<=m;i++)
	{
		int fx=findfa(e[i].u);
		int fy=findfa(e[i].v);
		if(fx==fy)
		{
			continue;
		}
		fa[fx]=fy;
		e[++cnt]=e[i];
		sum+=e[i].w;
		if(cnt==n-1)
		{
			break;
		}
	}
	m=n-1;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			e[++m]={j,n+i,lk[i][j],i};
		}
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<(1<<k);i++)
	{
		int st=n-1;
		long long num=0;
		for(int j=1;j<=n+k;j++)
		{
			fa[j]=j;
		}
		memset(can,0,sizeof can);
		can[0]=1;
		for(int j=0;j<k;j++)
		{
			if((i>>j)&1)
			{
				num+=add[j+1];
				can[j+1]=1;
				st++;
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(!can[e[j].id])
			{
				continue;
			}
			int fx=findfa(e[j].u);
			int fy=findfa(e[j].v);
			if(fx==fy)
			{
				continue;
			}
			num+=e[j].w;
			fa[fx]=fy;
			st--;
			if(!st)
			{
				break;
			}
		}
		sum=min(sum,num);
	}
	cout<<sum<<'\n';
	return 0;
}