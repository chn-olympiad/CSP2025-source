#include<iostream>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;

const int N=1e4+5,M=1e6+5,K=15;

struct edge
{
	int u,v,w;
}r[M<<1],t[M<<1];

int n,m,k,ans=1e18,cnt;
int a[K][N];
int f[N<<1],sz[N<<1];

bool cmp(edge x,edge y)
{
	return x.w<y.w;
}

int find(int u)
{
	if(u==f[u])
		return u;
	f[u]=find(f[u]);
	return f[u];
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>r[i].u>>r[i].v>>r[i].w;
	bool flag=1;
	for(int i=1;i<=k;i++)
	{
		cin>>a[i][0];
		if(a[i][0])
			flag=0;
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	if(flag)
	{
		ans=0;
		for(int i=1;i<=n;i++)
		{
			f[i]=i;
			sz[i]=1; 
		}
		cnt=m;
		for(int i=1;i<=k;i++)
		{
			f[n+i]=n+i;
			sz[n+i]=1;
			for(int j=1;j<=n;j++)
			{
				cnt++;
				r[cnt].u=n+i;
				r[cnt].v=j;
				r[cnt].w=a[i][j];
			}
		}
		sort(r+1,r+cnt+1,cmp);
		for(int i=1;i<=cnt;i++)
		{
			int u=r[i].u,v=r[i].v;
			int fu=find(u),fv=find(v);
			if(fu==fv)
				continue;
			ans+=r[i].w;
			if(sz[fu]>sz[fv])
				swap(fu,fv);
			f[fu]=fv;
			sz[fv]+=sz[fu];
		}
		cout<<ans<<endl;
		return 0;
	}
	for(int s=0;s<(1<<k);s++)
	{
		int res=0;
		for(int i=1;i<=n;i++)
		{
			f[i]=i;
			sz[i]=1; 
		}
		cnt=0;
		for(int i=1;i<=m;i++)
			t[++cnt]=r[i];
		for(int i=1;i<=k;i++)
		{
			if(!((1<<(i-1))&s))
				continue;
			f[n+i]=n+i;
			sz[n+i]=1;
			res+=a[i][0];
			for(int j=1;j<=n;j++)
			{
				cnt++;
				t[cnt].u=n+i;
				t[cnt].v=j;
				t[cnt].w=a[i][j];
			}
		}
		sort(t+1,t+cnt+1,cmp);
		for(int i=1;i<=cnt;i++)
		{
			int u=t[i].u,v=t[i].v;
			int fu=find(u),fv=find(v);
			if(fu==fv)
				continue;
			res+=t[i].w;
			if(sz[fu]>sz[fv])
				swap(fu,fv);
			f[fu]=fv;
			sz[fv]+=sz[fu];
		}
		ans=min(ans,res);
	}
	cout<<ans<<endl;
	return 0;
}
