#include <bits/stdc++.h>
#define ll long long 

using namespace std;

const ll N=20005;

ll n,m,k,vis[N],res=1e18;

ll c[15],a[15][N],len[N];

vector<ll> v[N],vec[N];

struct Node
{
	ll x,step;
	bool operator<(const Node p)const
	{
		return step>p.step;
	}	
};

inline ll solve(ll cnt)
{
	priority_queue<Node> q;
	for(ll i=1;i<=n;i++)
	{
		vis[i]=0;
	}
	vis[1]=1;
	for(ll i=0;i<v[1].size();i++)
	{
		q.push(Node{v[1][i],vec[1][i]});
	}
	ll ans=cnt;
	while(!q.empty())
	{
		ll t=q.top().x,w=q.top().step;
		q.pop();
		if(vis[t]==0)
		{
			vis[t]=1;
			ans+=w;
			for(ll i=0;i<v[t].size();i++)
			{
				q.push(Node{v[t][i],vec[t][i]});
			}
		}
	}
	return ans;
}

/*
inline void dfs(ll x,ll cnt)
{
	if(x==k+1)
	{
		res=min(res,solve(cnt));
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		vec[i][len[i]+x-1]=1e18;
	}
	dfs(x+1,cnt);
	for(int i=1;i<=n;i++)
	{
		vec[i][len[i]+x-1]=a[x][i];
	}
	dfs(x+1,cnt+c[x]);
}
*/

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&k);
	for(ll i=1;i<=m;i++)
	{
		ll x,y,w;scanf("%lld %lld %lld",&x,&y,&w);
		v[x].push_back(y),vec[x].push_back(w);
		v[y].push_back(x),vec[y].push_back(w);
	}
	/*for(int i=1;i<=n;i++)
	{
		len[i]=v[i].size();
	}
	*/
	if(k==0) printf("%lld\n",solve(0));
	else cout<<0<<endl;
	/*else
	{
		for(ll i=1;i<=m;i++)
		{
			scanf("%lld",&c[i]);
			for(int j=1;j<=n;j++)
			{
				scanf("%lld",&a[i][j]);
				v[n+i].push_back(j),vec[n+i].push_back(a[i][j]);
				v[j].push_back(n+i),vec[j].push_back(a[i][j]);
			}
		}
		dfs(1,0);
	}
	cout<<endl<<solve(0)<<endl;
	printf("%lld\n",res);
	*/
	return 0;
}
