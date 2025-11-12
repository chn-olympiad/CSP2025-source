#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node
{
	int v;
	long long w;
};
vector<node>e[2000005];
long long dis[20005];
int b[20005];
long long c[15];
priority_queue<pair<long long,int> >q;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		long long w;
		scanf("%d%d%lld",&u,&v,&w);
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	bool check=true;
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		if(c[i]!=0)
		{
			check=false;
		}
		for(int j=1;j<=n;j++)
		{
			long long x;
			if(x!=0)
			{
				check=false;
			}
			scanf("%lld",&x);
			e[i+n].push_back({j,x});
			e[j].push_back({i+n,x});
		}
	}
	if(check&&k!=0)
	{
		printf("%d",0);
		return 0;
	} 
	for(int i=1;i<=n+k;i++)
	{
		dis[i]=2000000000000000000;
	}
	q.push({0,1});
	long long ans=0;
	int cnt=0;
	while(q.size())
	{
		long long k=-q.top().first;
		int u=q.top().second;
		q.pop();
		if(b[u])
		{
			continue;
		}
		b[u]=1;
		cnt++;
		ans+=k;
		if(cnt==n)
		{
			printf("%lld",ans);
			return 0;
		}
		for(auto v:e[u])
		{
			if(!b[v.v])
			{
				if(v.v<=n)
				{
					if(dis[v.v]>v.w)
					{
						dis[v.v]=v.w;
						q.push({-dis[v.v],v.v});
					}
				}
				else if(u<=n&&v.v>n)
				{
					for(auto k:e[v.v])
					{
						if(!b[k.v])
						{
							if(dis[k.v]>v.w+c[v.v-n]+k.w)
							{
								dis[k.v]=v.w+c[v.v-n]+k.w;
								q.push({-dis[k.v],k.v});
							}	
						}	
					}	
				} 
			}
		}
	}
	return 0;
}
