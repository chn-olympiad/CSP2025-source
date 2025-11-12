#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define mod 1000000007
#define pii pair<int,int>
using namespace std;

inline int read()
{
	int x=0,f=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f?-x:x;
}
int n,m,k;
struct sd{
	int u,v,w;
}e[10000005],e2[10000005];
int a[15][10005],c[15];
ll ans=0;
bool cmp(sd x,sd y)
{
	return x.w<y.w;
}
int flag=0;
int la=0,ne[maxn],fa[maxn];
int find(int x)
{
	if(x==fa[x]) return x;
	else return fa[x]=find(fa[x]);
}
int vis[15];
void dfs(int x)
{
	if(x==k+1)
	{
		ll sum=0,cnt=0;
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int i=1;i<=k;i++) 
		{
			if(vis[i]) sum+=c[i],cnt++;
		}
		for(int i=1;i<=m;i++) e2[i]=e[i];
//		cout<<sum<<'\n';
		int now=0;
		sort(e2+1,e2+m+1,cmp);
		for(int i=1;i<=m;i++)
		{
			int x=e2[i].u,y=e2[i].v;
			int fx=find(x),fy=find(y);
			if(fx!=fy)
			{
				sum+=e2[i].w;
				fa[fx]=fy;
				now++;
				if(now==cnt+n-1)
				{
					break;
				}
			}
		}
//		cout<<cnt<<' '<<sum<<'\n';
		ans=min(ans,sum);
		return ;
	}
	vis[x]=1;
	for(int i=1;i<=n;i++)
	{
		e[++m]={x+n,i,a[x][i]};
	}
	dfs(x+1);
	vis[x]=0;
	m-=n;
	dfs(x+1);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		e[i].u=read();e[i].v=read();e[i].w=read();
	}
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		if(c[i]!=0) flag=1;
		for(int j=1;j<=n;j++)
		{
			a[i][j]=read();
		}
	}
	if((flag==0&&n<=1000&&k<=5)||k==0)
	{
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int p=1;p<=n;p++)
				{
					if(j==p) continue;
					e[++m]={j,p,a[i][j]+a[i][p]};
				}
			}
		}
		sort(e+1,e+m+1,cmp);
		for(int i=1;i<=m;i++)
		{
			int x=e[i].u,y=e[i].v;
			int fx=find(x),fy=find(y);
			if(fx!=fy)
			{
				ans+=e[i].w;
				fa[fx]=fy;
			}
		}
		cout<<ans;
	}
	else
	{
		ans=1e18;
		dfs(1);
		cout<<ans;
	}
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