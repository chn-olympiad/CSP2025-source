#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pll pair<int,int>
const int inf=1e18;
int n,m,k,x,y,z,ans=inf,c[20005],dis[20005];
vector<int> v[20005],d[20005];
bool flag=false,b[20005],vis[20005];
priority_queue<pll,vector<pll>,greater<pll> > q;
inline int work()
{
	int ret=0;
	for(int i=1;i<=n+k;++i)
	{
	    dis[i]=inf;
	    vis[i]=false;
	}
	dis[1]=0;
	q.push({0,1});
	while(q.size())
	{
		pll p=q.top();
		q.pop();
		int u=p.second;
		if(vis[u]) continue;
		vis[u]=true;
		ret+=p.first;
		for(int i=0;i<v[u].size();++i)
		{
			int l=v[u][i];
			if(b[l]&&(d[u][i]<dis[l]))
			{
				dis[l]=d[u][i];
				q.push({dis[l],l});
			}
		}
	}
	return ret;
}
inline void dfs(int x,int sum)
{
	if(x==k+1)
	{
		ans=min(ans,work()+sum);
		return;
	}
	b[n+x]=false;
	dfs(x+1,sum);
	b[n+x]=true;
	dfs(x+1,sum+c[x]);
	b[n+x]=false;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
	{
		cin>>x>>y>>z;
		v[x].push_back(y);
		v[y].push_back(x);
		d[x].push_back(z);
		d[y].push_back(z);
	}
	for(int i=1;i<=k;++i)
	{
	    cin>>c[i];
	    if(c[i]!=0) flag=true;
	    for(int j=1;j<=n;++j)
	    {
	    	cin>>z;
			v[n+i].push_back(j);
			v[j].push_back(n+i);
			d[n+i].push_back(z);
			d[j].push_back(z);
		}
	}
	for(int i=1;i<=n;++i)
	    b[i]=true;
	if(!flag)
	{
		for(int i=n+1;i<=n+k;++i)
		    b[i]=true;
		cout<<work()<<"\n";
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
