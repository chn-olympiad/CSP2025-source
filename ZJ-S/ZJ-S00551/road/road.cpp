#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5,M=1e6+5;
struct node
{
	int y;
	int w;
};
struct bnode
{
	int u;
	int v;
	int w;
};
bnode b[M];
vector <node> a[N];
int c[N];
bool used[N];
int n,m,k;
int minn=1e9;
int dfs(int x,int sum)
{
	int v=0;
	for(int i=1;i<=n;i++)
	{
		if(!used[i])
		{
			v=1;
			break;
		}
	}
	if(v==0)
	{
		if(sum<minn)
		{
			minn=sum;
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(used[i])
		{
			for(int j=0;j<a[i].size();j++)
			{
				if(!used[a[i][j].y])
				{
					used[a[i][j].y]=1;
					sum+=a[i][j].w;
					dfs(a[i][j].y,sum);
					used[a[i][j].y]=0;
					sum-=a[i][j].w;
				}	
			}
		}
	}

	return sum;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
	used[1]=1;
	dfs(1,0);
	cout<<minn;
}
