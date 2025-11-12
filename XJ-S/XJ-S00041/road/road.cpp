#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,k,ans=INT_MAX;
int u[N],v[N],w[N][N];
int arr[12][N];
int gz[12];
vector<vector<int> >ljb(N);
bool flag[N];

bool jc()
{
	for(int a=1;a<=n;a++)
	{
		if(flag[a]==0)
			return 0;
	}
	return 1;
}

void dfs(int wz,int cnt)
{
	if(jc()==1)
	{
		ans=min(ans,cnt);
		return ;
	}
	for(int a=0;a<ljb[wz].size();a++)
	{
		cnt+=w[wz][ljb[wz][a]];
		flag[a]=1;
		dfs(wz+1,cnt);
		flag[a]=0;
		cnt-=cnt+=w[wz][ljb[wz][a]];
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int a=0;a<m;a++)
	{
		scanf("%d%d",&u[a],&v[a]);
		scanf("%d",&w[u[a]][v[a]]);
		w[v[a]][u[a]]=w[u[a]][v[a]];
		ljb[u[a]].push_back(v[a]);
		ljb[v[a]].push_back(u[a]);
	}
	for(int a=1;a<=k;a++)
	{
		scanf("%d",&gz[a]);
		for(int b=1;b<=n;b++)
		{
			scanf("%d",&arr[a][b]);
		}
	}
	dfs(0,0);
	printf("%d",ans);
	
	return 0;
} 
