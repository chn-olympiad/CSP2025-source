#include<bits/stdc++.h>
using namespace std;

struct road
{
	long long to,cost;
};

long long n,m,k;
long long deg[10005];
vector<road>r[10005];
long long c[15],a[15][100005];
long long city[10005];//已联通的城市数 
bool vis[10005];//是否被联通
long long ans;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	
	cin>>n>>m>>k;
	long long u,v;
	road r1;
	for(long long i=1;i<=m;i++)
	{
		cin>>u>>v>>r1.cost;
		r1.to=v;
		r[u].push_back(r1);
		r1.to=u;
		r[v].push_back(r1);
	} 
	for(long long i=1;i<=k;i++)
	{
		cin>>c[i];
		for(long long j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			//cout<<i<<" "<<j<<" "<<a[i][j]<<"\n";
		}
		if(c[i]==0)//A
		{
			for(long long j=1;j<=n;j++)//乡村i城市j=0 
			{
				if(a[i][j]==0)
				{
					for(long long k1=1;k1<=n;k1++)
					{
						if(j==k1)continue;
						
						r1.cost=a[i][k1];
						r1.to=k1;
						r[j].push_back(r1);
						r1.to=j;
						r[k1].push_back(r1);
					}
				}
			}
		}
	}
	
	city[1]=1;
	vis[1]=1;
	for(long long i=2;i<=n;i++)//将联通的城市数 
	{
		long long mincost=1e9;
		long long mincostcity=0;
		
		//long long minfrom=0;//
		
		for(long long j=1;j<=i;j++)//城市city[j] 
		{
			for(long long k1=0;k1<r[city[j]].size();k1++)
			{
				if(vis[ r[city[j]][k1].to ]==0)
				{
					if(r[city[j]][k1].cost<mincost)
					{
						//minfrom=city[j];//
						
						mincost=r[city[j]][k1].cost;
						mincostcity=r[city[j]][k1].to;
					}
				}
			}
		}
		ans+=mincost;
		city[i]=mincostcity;
		vis[mincostcity]=1;
		//cout<<minfrom<<"->"<<mincostcity<<": "<<mincost<<"\n";//
	}
	cout<<ans;
	return 0;
}
