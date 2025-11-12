#include<iostream>
#include<vector>
#include<bitset>
#include<cstring>
using namespace std;
long long ans=0x3f3f3f3f3f3f3f3f,inf=0x3f3f3f3f3f3f3f3f;
int n,m,k;
struct ROAD
{
	int to;
	long long w;
};
vector<ROAD> e[10005];

int c[15],town[11][10005];
//not sort n^2;sort: n*nlogn


void tree(bitset<11> t_c)
{
	//cout<<t_c<<"\n";
	bool OK[10005]={0};
	OK[1]=1;
	long long num=0,sum=0;
	long long dis[10005];
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	while(num<n)
	{
		int index=-1,mindis=inf;
		for(int i=1;i<=n;i++)
		{
			if(!OK[i] && dis[i]<mindis)
			{
				index=i;
				mindis=dis[i];
			}	
		}
		if(num==0) index=1;
		if(index==-1) break;
		num++;sum+=dis[index];OK[index]=1;//cout<<index<<"\n";
		
		for(int i=0;i<e[index].size();i++)
		{
			ROAD x=e[index][i];
			if(!OK[x.to])
			{
				dis[x.to]=min(dis[x.to],x.w);
			}
		}
		for(int i=1;i<=k;i++)
		{
			if(t_c[i]==1)
			{
				for(int j=1;j<=n;j++)
				{
					if(j!=index&&!OK[j])
					{
						dis[j]=min(dis[j],dis[index]+town[i][index]+town[i][j]);
					}
					
				}
			}
		}
		//cout<<index<<" "<<dis[1]<<" "<<dis[2]<<" "<<dis[3]<<" "<<dis[4]<<"\n";
	}
	for(int i=1;i<=k;i++)
	{
		if(t_c[i]==1)
		{
			sum+=c[i];	
		}
	}
	ans=min(ans,sum);
}


int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k;
	long long u,v,cost;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>cost;
		e[u].push_back({v,cost});
		e[v].push_back({u,cost});
	}
	bool A=1;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]!=0) A=0;
		for(int j=1;j<=n;j++)
		{
			cin>>town[i][j];
		}
	}
	
	if(A)
	{
		tree(1<<k-1);
		cout<<ans<<endl;
		return 0;
	}
	
	for(int i=0;i<=(1<<k)-1;i++)
		tree(i<<1);
	cout<<ans<<"\n";
	return 0;
}

