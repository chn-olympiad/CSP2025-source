#include<bits/stdc++.h>
using namespace std;
const int N=2e4+9,inf=1e9+7;
const long long Inf=1e18;
#define endl "\n"
int n,m,k,c[20],lenn;
int a[12][N];
int val[N],bel[N],bell[N],le;
bool vis[N];
struct node{
	int to,val;
	node(int a,int b)
	{
		to=a;
		val=b;
	}
};
vector<node> vv[N];
int query()
{
	int id=0;
	for(int i=1;i<=bel[le];i++)
	{
		if(val[id]>val[bell[i]])
			id=bell[i];
	}
	return id;
}
void chougou(int b)
{
	bell[b]=0;
	for(int i=(b-1)*lenn+1;i<=min(le,b*lenn);i++)
	{
		if(vis[i]) continue;
		if(val[bell[b]]>val[i])
			bell[b]=i;
	}
}
#define lowbit(u) ((u)&(-(u)))
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	lenn=sqrt(n+5);
	for(int i=1;i<=n+20;i++)
		bel[i]=(i-1)/lenn+1;
	for(int i=1;i<=m;i++)
	{
		int u,v,val;
		cin>>u>>v>>val;
		vv[u].push_back({v,val});
		vv[v].push_back({u,val});
	}
	int maxx=0;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		maxx=max(maxx,c[i]);
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	val[0]=inf;
	long long ans=Inf;
	for(int i=0;i<(1<<k);i++)
	{
		if(maxx==0)
		{
			if(i!=(1<<k)-1)
				continue;
		}
		if(k>=6)
		{
			if((lowbit(i)!=i) && (i!=(1<<k)-1))
				continue;
		}
		le=n;
		long long anss=0;
		for(int j=1;j<=k;j++)
		{
			if(i&(1<<(j-1)))
			{
				++le;
				anss+=c[j];
				for(int kk=1;kk<=n;kk++)
				{
					vv[le].push_back({kk,a[j][kk]});
					vv[kk].push_back({le,a[j][kk]});
				}
			}
		}
		for(int j=1;j<=le;j++)
			val[j]=inf,bell[j]=0,vis[j]=0;
		val[1]=inf;
		vis[1]=1;
		chougou(bel[1]);
		for(node pos:vv[1])
		{
			int v=pos.to,w=pos.val;
			if(vis[v]) continue;
			val[v]=min(w,val[v]);
			if(val[bell[bel[v]]]>val[v])
				bell[bel[v]]=v;
		}
		for(int j=2;j<=le;j++)
		{
			int u=query();
			anss+=val[u];
			val[u]=inf;
			vis[u]=1;
			chougou(bel[u]);
			for(node pos:vv[u])
			{
				int v=pos.to,w=pos.val;
				if(vis[v]) continue;
				val[v]=min(val[v],w);
				if(val[bell[bel[v]]]>val[v])
					bell[bel[v]]=v;
			}
		}
		ans=min(ans,anss);
		le=n;
		for(int j=1;j<=k;j++)
		{
			if(i&(1<<(j-1)))
			{
				++le;
				vv[le].clear();
				for(int kk=1;kk<=n;kk++)
				{
					vv[kk].pop_back();
				}
			}
		}
	}
	cout<<ans;
	return 0;
}