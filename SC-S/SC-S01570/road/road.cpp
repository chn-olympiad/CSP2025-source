#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int,int>
const int N=1e4+200,M=1e6+1e5+1e4;
int n,m,k;
int ans;
vector<PII> g[N];
int f[N];
int tp;
int cnt;
int c[20],a[20][M];
struct node{
	int x,y,w;
}e[M];
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int find(int x)
{
	return x==f[x]?x:f[x]=find(f[x]);
}
bool sg[N];
int num[11];
void work(int x)
{
	int res=0;
	x--;
	tp=n;
	int cntt=cnt;
	for(int i=1;i<=x;i++)
	{
		tp++;
		res+=c[num[i]];
		for(int j=1;j<=n;j++)
		{
			e[++cntt]={tp,j,a[num[i]][j]};
		}
	}
	for(int i=1;i<=tp;i++)	f[i]=i;
	sort(e+1,e+1+cntt,cmp);
	for(int i=1;i<=cntt;i++)
	{
		int x=find(e[i].x),y=find(e[i].y),z=e[i].w;
		if(x!=y)
		{
			f[x]=y;
			res+=z;
		}
	}
	ans=min(ans,res);
}
void dfs(int x)
{
	if(x<=k+1)	work(x);
	for(int i=1;i<=k;i++)
	{
		if(!sg[i]&&i>num[x-1])
		{
			num[x]=i;
			sg[i]=1;
			dfs(x+1);
			sg[i]=0;
		}
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t1=clock();
	cin>>n>>m>>k;
	cnt=m;
	for(int i=1;i<=n+1000;i++)	f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	if(k==0)
	{
		sort(e+1,e+1+m,cmp);
		for(int i=1;i<=m;i++)
		{
			int x=find(e[i].x),y=find(e[i].y),z=e[i].w;
			if(x!=y)
			{
				f[x]=y;
				ans+=z;
			}
		}
		cout<<ans<<'\n';
		return 0;
	}
	else
	{
		bool subA=1;
		tp=n;
		for(int i=1;i<=k;i++)
		{
			bool flag=0;
			cin>>c[i];
			if(c[i])	subA=0;
			++tp;
			for(int j=1;j<=n;j++)
			{
				cin>>a[i][j];
				if(c[i]==0)	e[++cnt]={tp,j,a[i][j]};
			}
		}
		if(subA)
		{
			sort(e+1,e+1+cnt,cmp);
			for(int i=1;i<=cnt;i++)
			{
				int x=find(e[i].x),y=find(e[i].y),z=e[i].w;
				if(x!=y)
				{
					f[x]=y;
					ans+=z;
				}
			}
			cout<<ans<<'\n';
			return 0;
		}
		else
		{
			ans=LLONG_MAX;
			dfs(1);
			cout<<ans<<'\n';
		}
	}
	return 0;
}