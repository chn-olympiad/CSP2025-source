#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
struct node
{
	int u,v,w;
	int o;
	bool operator<(const node &x) const
	{
		return w>x.w;
	}
};
priority_queue<node> q;
int fa[N],siz[N];
int a[15][N],orig[15][N];
int find(int x)
{
	return fa[x]=fa[x]==x?x:find(fa[x]); 
}
vector<int> inm[15];
void onion(int x,int y)
{
	x=find(x),y=find(y); 
	if(siz[x]>siz[y])
	{
		swap(x,y); 
	}
	fa[x]=y;
	siz[y]+=siz[x];
}
int n,m,k;
bool vis[N<<1];
int ans=0;
void krus()
{
	int cnt=0;
	while(q.size())
	{
		node now=q.top();
		q.pop();
		int u=now.u,v=now.v,w=now.w,o=now.o;
		if(find(u)==find(v)||(o&&o<n&&!vis[o]))
		{
			continue;
		}
		if(o>n&&!vis[o])
		{
			onion(u,v);
			ans+=w;
			if(++cnt==n-1)
			{
				return;
			}
			vis[o]=1;
			for(auto g:inm[o])
			{
				ans=min(ans,ans-orig[o][g]+a[o][g]);
			}
		}
		else
		{
			onion(u,v);
			ans+=w;
			if(++cnt==n-1)
			{
				return;
			}
		}
		if(u<=k)
		{
			inm[u].push_back(v);
		}
		if(v<=k)
		{
			inm[v].push_back(u);
		}
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		siz[i]=1;
	}
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%lld %lld %lld",&u,&v,&w);
		q.push({u,v,w,0});
		if(u<=k)
		{
			orig[u][v]=w;
		}
		if(v<=k)
		{
			orig[v][u]=w;
		}
	}
	for(int i=1;i<=k;i++)
	{
		int c;
		scanf("%lld",&c);
		for(int j=1;j<=n;j++)
		{
			int w;
			scanf("%lld",&w);
			a[i][j]=w;
			q.push({i,j,w,i});
			q.push({i,j,w+c,i+n});
		}
	}
	krus();
	printf("%lld\n",ans);
	return 0;
}

