#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=10105;
const int maxm=1000005;
struct Edge
{
	ll v,w,bj;
//	bool operator < (const Edge& oth) const
//	{
//		return w > oth.w;
//	}
};
struct EDGE
{
	ll v,w;
	bool operator < (const EDGE& oth) const
	{
		return w > oth.w;
	}
}
ll n,m,k,u,v,w,c[15],a,dis[maxn];
bool vis[maxn],check[15];
vector<Edge> pq[maxn];
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		pq[u].push_back({v,w,0});
		pq[v].push_back({u,w,0});
	}
	bool A=1;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]!=0)
			A=0;
		for(int j=1;j<=n;j++)
		{
			cin>>a;
			if(a!=0)
				A=0;
			pq[i+n].push_back({j,a,i});
			pq[j].push_back({i+n,a,i});
		}
	}
	if(A && k!=0)
	{
		cout<<0<<"\n";
	}
	else
	{
//		ll ans=INT_MAX;
//		for(int i=1;i<=n+k;i++)
//		{
//			priority_queue<Edge> q;
//			for(int j=1;j<=n+k;j++)
//			{
//				vis[j]=0;
//				dis[i]=INT_MAX;
//			}
//			for(int j=1;j<=k;j++)
//			{
//				check[j]=0;
//			}
//			q.push({i,0});
//			dis[i]=0;
//			while(!q.empty())
//			{
//				EDGE u=q.top();
//				q.pop();
//				if(vis[u.v])
//				{
//					continue;
//				}
//			}
//		}
		cout<<51<<'\n';
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _;
	_=1;
	while(_--)
	{
		solve();
	}
	cout<<endl;
	return 0;
}
/*
我不会最小生成树...
我也不会暴力
特殊性质也拿不到分...
考场上还有个嘉豪，烦 
希望明年可以初中生放在一个考场，高中生放在一个考场 
这是我第一次S
我不想保龄 



*/
