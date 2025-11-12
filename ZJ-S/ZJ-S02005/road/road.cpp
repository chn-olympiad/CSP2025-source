#include<bits/stdc++.h>
#define LL long long
#define Fcin ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1e6+101;
int n,m,k,dis[N];
bool vis[10101];
vector<pair<int,int> > G[N];
priority_queue<pair<int,int> > q;
int main()
{
	Fcin;
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;++i)
	{
		cin>>u>>v>>w;
		G[u].push_back(make_pair(v,w));
		G[v].push_back(make_pair(u,w));
	}
	for(int i=1,x;i<=k;++i)
	{
		cin>>x;
		int cnt=0;
		for(int j=1,w;j<=n;++j)
		{
			cin>>w;
			if(w==0) cnt++;
		}
		if(cnt==n)
		{
			cout<<0;
			return 0;
		}
	}
	memset(dis,0x3f,sizeof dis);
	dis[1]=0,q.push(make_pair(dis[1],1));
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=true;
		for(auto i:G[x])
		{
			int to=i.first,weg=i.second;
			if(vis[to]) continue;
			if(dis[to]>dis[x]+weg)
			{
				dis[to]=dis[x]+weg;
				q.push(make_pair(-dis[to],to));
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i) ans+=dis[i];
	cout<<ans;
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
