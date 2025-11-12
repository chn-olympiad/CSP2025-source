#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX=1e4+10;
//#define test
//最小生成树 
//点1e4边1e6特殊点1e1 
struct r
{
	int val,t;
}cache;
bool operator <(const r& a,const r& b)
{
	return a.val>b.val;
}
vector<r> c[MAX];
priority_queue<r, vector<r> >pq;//小根堆 
int n,m,k;
bool ava[MAX];
int spval[15];
int cnt;
int spcnt;
int u,v,w;
ll ans;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	#ifdef test
	freopen("road3.in","r",stdin);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
		cin>>u>>v>>w,
		cache.val=w,cache.t=v,
		c[u].push_back(cache),
		cache.val=w,cache.t=u,
		c[v].push_back(cache);
	for(int i=1;i<=k;i++)
	{
		cin>>u;
		spval[i]=u;
		for(int f=1;f<=n;f++)
		cin>>v,
		cache.val=v,cache.t=f,
		c[n+i].push_back(cache),
		cache.val=v+u,cache.t=n+i,
		c[f].push_back(cache);
	}
	#else
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
		cin>>u>>v>>w,
		cache.val=w,cache.t=v,
		c[u].emplace_back(cache),
		cache.val=w,cache.t=u,
		c[v].emplace_back(cache);
	for(int i=1;i<=k;i++)
	{
		cin>>u;
		spval[i]=u;
		for(int f=1;f<=n;f++)
		cin>>v,
		cache.val=v,cache.t=f,
		c[n+i].emplace_back(cache),
		cache.val=v+u,cache.t=n+i,
		c[f].emplace_back(cache);
	}
	#endif
	ava[1]=1;
	cnt=1;
	for(int i=0;i<c[1].size();i++)
		pq.push(c[1][i]);
	while(cnt!=n)
	{
		if(ava[pq.top().t])
		{
			pq.pop();
			continue;
		}
		cache=pq.top();
		pq.pop();
		if(cache.t<=n)cnt++;
		else
		spcnt++;
		ans+=cache.val;
		ava[cache.t]=1;
		for(int i=0;i<c[cache.t].size();i++)
		pq.push(c[cache.t][i]);
	}
	cout<<ans;
}