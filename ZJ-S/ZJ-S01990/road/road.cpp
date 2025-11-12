#include<bits/stdc++.h>
using namespace std;
int n,m,k,dis[10017];
long long ans;
vector<array<int,2> >e[10017];
queue<int>q;
bool vis[10007],vis2[17];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	scanf("%d%d%d",&n,&m,&k);
	int u,v,c;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&c);
		e[u].push_back({v,c});
		e[v].push_back({u,c});
	}
	e[0].push_back({1,0});
	int f=0;
	for(int i=n+1;i<=k+n;i++)
	{
		scanf("%d",&c);
		if(c!=0) f=1;
//		e[0].push_back({i,c});
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&c);
//			e[i].push_back({j,c});
//			e[j].push_back({i,c});
		}
	}
	vis[1]=1;
	q.push(1);
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		for(auto it:e[p])
		{
			dis[it[0]]=min(dis[it[0]],it[1]);
		}
		f=0;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				if(!f||dis[f]>dis[i]) f=i;
			}
		}
		if(f!=0)
		{
			vis[f]=1;
			q.push(f);
			ans+=dis[f];
		}
	}
	printf("%lld\n",ans);
	return 0;
}
