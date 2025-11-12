#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+9;
int n,m,k,x,y,z,c[14],vis[N+10],d[14][N],mx;
ll ans,mn=1e18;
vector<pair<int,int> > mp[N];
vector<int> V;
ll prim(int t)
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	ans=0;
	V.clear();
	for(int i=0;i<k;i++)
	{
		if(t&(1<<i))ans+=c[i],V.push_back(n+i+1);
	}
	for(int i=1;i<=n+k+1;i++)vis[i]=0;
	pq.push({0,1});
	while(!pq.empty())
	{
		int u=pq.top().second,w=pq.top().first;
		pq.pop();
		if(vis[u])continue;
		vis[u]=1,ans+=w;
//		cerr<<u<<"    "<<w<<endl;
		if(u>n)
		{
			for(int i=1;i<=n;i++)
			{
				if(!vis[i])pq.push({d[u-n-1][i],i});
			}
		}
		else
		{
			for(auto v:mp[u])
			{
				if(!vis[v.first])pq.push({v.second,v.first});
			}
			for(auto v:V)
			{
				if(!vis[v-n-1])pq.push({d[v-n-1][u],v});
			}
		}
	}
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	while(m--)
	{
		scanf("%d%d%d",&x,&y,&z);
		mp[x].push_back({y,z});
		mp[y].push_back({x,z});
	}
	for(int i=0;i<k;i++)
	{
		scanf("%d",&c[i]);
		mx=max(mx,c[i]);
		for(int j=1;j<=n;j++)scanf("%d",&d[i][j]),mx=max(mx,d[i][j]);
	}
	if(mx==0)
	{
		printf("0");
		return 0;
	}
	for(int i=0;i<1<<k;i++)
	{
		mn=min(mn,prim(i));
	}
	printf("%lld",mn);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
