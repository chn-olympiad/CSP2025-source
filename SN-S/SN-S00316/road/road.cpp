//李中易 SN-S00316 西安辅轮中学
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=20010;

struct str  { int v;ll w; };

int n,m,k,flag[maxn],need,can[maxn];
ll c[15],ans;
vector<str>mapp[maxn];

priority_queue<pair<ll,int> >q;

ll dij()
{
	memset(flag,0,sizeof(flag));
	while(!q.empty())  q.pop();
	q.push({0,n});
	ll ret=0;
	while(!q.empty())
	{
		pair<ll,int>now=q.top();q.pop();
		ll num=-now.first;int thi=now.second;
		if(can[thi]==1||flag[thi]==1)  continue;
		flag[thi]=1;ret+=num;
		for(int i=0;i<mapp[thi].size();i++)
		{
			int nxt=mapp[thi][i].v;
			if(can[nxt]==1||flag[nxt]==1)  continue;
			q.push({-mapp[thi][i].w,nxt});
		}
	}
	return ret;
}

void dfs(int now,ll add)
{
	if(now>k)
	{
		ans=min(ans,dij()+add);
		return;
	}
	dfs(now+1,add);
	can[now+n]=0;
	dfs(now+1,add+c[now]);
	can[now+n]=1;
	return;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	ans=1e18;
	for(int i=1;i<=m;i++)
	{
		int u,v;ll w;
		cin>>u>>v>>w;
		mapp[u].push_back({v,w});
		mapp[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];can[n+i]=1;
		for(int j=1;j<=n;j++)
		{
			ll a;cin>>a;
			mapp[j].push_back({n+i,a});
			mapp[n+i].push_back({j,a});
		}
	}
	dfs(1,0);
	cout<<ans;
	return 0;
} 
