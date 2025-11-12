#include<bits/stdc++.h>
#define int long long
#define endl '\n' 
using namespace std;
vector<pair<int,int> > g[114514];
int n,m,k,a[1145][1145],c[114514],dis[114514],cost=0,vis[114514],ans1=0x3f3f3f3f3f3f; 
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
signed main()
{ 	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back(make_pair(w,v));
		g[v].push_back(make_pair(w,u));
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			g[j].push_back(make_pair(a[i][j],n+i));
			g[n+i].push_back(make_pair(a[i][j],j));
		}
	}
	for(int e=0;e<(1<<k);e++)
	{
		int j=n+1,b=e,cost=0;
		//for(int i=n+1;i<=n+k;i++) vis[j]=0;
		while(b)
		{
			vis[j]=b%2;
			if(!vis[j]) cost+=c[j];
			j++;
			b/=2;
		}
		for(int s=1;s<=n;s++)
		{
			for(int i=1;i<=n+k;i++) dis[i]=0x3f3f3f3f3f;
			dis[s]=0;
			q.push(make_pair(0,s));
			while(!q.empty())
			{
				int dist=q.top().first,u=q.top().second;
				//cout<<u<<" "<<dis[u]<<endl;
				q.pop();
				if(dist!=dis[u]) continue;
				for(int i=0;i<g[u].size();i++)
				{
					int w=g[u][i].first,v=g[u][i].second;
					if(dis[u]+w+(u>n?c[u-n]:0)<dis[v]&&vis[v]==0)
					{
						dis[v]=dis[u]+w+(u>n?c[u-n]:0);
						q.push(make_pair(dis[v],v));
					}
				}
			}
			int ans=-0x3f3f3f3f3f,sum=0; 
			for(int i=1;i<=n;i++) 
			{
				//cout<<dis[i]<<' '<<i<<endl;
				sum+=dis[i];
			}
			//cout<<sum<<endl<<endl;
			ans1=min(ans1,sum);
			//cout<<endl;
		}
	}
	cout<<ans1;
	return 0;
 } 
