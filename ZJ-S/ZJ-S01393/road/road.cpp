#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+20;
int n,m,k;
bool vis[N],kl[N];
ll dp[N],from[N],c[N];
vector<pair<int,ll> > to[N];
struct node{
	int u,v,w;
}a[1000005];
bool cmp(node x,node y)
{
	if(x.u==y.u)
	{
		if(x.v==y.v)
			return x.w<y.w;
		return x.v<y.v;
	}
	return x.u<y.u;
}
bool p(int x)
{
	return (x>n&&x<=n+k);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(!(a[i].u==a[i-1].u&&a[i].v==a[i-1].v))
		{
			to[a[i].u].push_back(make_pair(a[i].v,a[i].w));
			to[a[i].v].push_back(make_pair(a[i].u,a[i].w));
		}
	}
	memset(vis,0,sizeof(vis));
	memset(from,0,sizeof(from));
	for(int i=1;i<=k;i++)
	{
		cin>>c[n+i];
		for(int j=1;j<=n;j++)
		{
			ll x;
			cin>>x;
			to[n+i].push_back(make_pair(j,x+c[n+i]));
			to[j].push_back(make_pair(n+i,x+c[n+i]));
		}
	}
	for(int i=1;i<=n+k;i++) dp[i]=1e18;
	dp[1]=0;
	int now=1;
	int finish=0;
	while(finish<n+k)
	{
		ll minn=1e18;
		for(int i=1;i<=n+k;i++)
		{
			if(dp[i]<minn&&!vis[i])
			{
				minn=dp[i];
				now=i;
			}
		}
		if(now>=1&&now<=n+k) finish++;
		vis[now]=1;
		for(auto z:to[now])
		{
			int i=z.first;
			ll l=z.second;
			if(!vis[i]&&
			((l<dp[i]&&!p(now))||(l-c[now]<dp[i]&&p(now))))
			{
				if(p(now)) dp[i]=l-c[now];
				else dp[i]=l;
				from[i]=now;
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		if(p(from[i])&&!kl[from[i]])
			ans+=dp[from[i]],kl[from[i]]=1;
		ans+=dp[i];
	}
	cout<<ans;
	return 0;
}
