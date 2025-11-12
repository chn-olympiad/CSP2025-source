#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5*1e6;
int n,m,k,c[N],a[15][10005],cnt,cllnt,nn;
vector<int> G[N],W[N],liantong[N];
map<int,int> mp;
void dfs(int point)
{
	for(auto u : G[point]) if(mp[u]==0)
	{
		mp[u]=mp[point];
		liantong[mp[u]].push_back(u);
		dfs(u);
	}
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
		G[u].push_back(v);
		G[v].push_back(u);
		W[u].push_back(w);
		W[v].push_back(w);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++) scanf("%lld",&a[i][j]);
	}
	//k=0
	if(k==0)
	{
		for(int i=1;i<=n;i++) if(mp[i]==0) 
		{
			mp[i]=++cnt;
			liantong[cnt].push_back(i);
			dfs(i);
		}
		cllnt=cnt;
		while(cllnt)
		{
			int minn=99999999,minn_point;
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<G[i].size();j++)
				{
					if(W[i][j]<minn && mp[i]!=mp[G[i][j]])
					{
						minn_point=G[i][j];
						minn=W[i][j];
					}
				}
				for(int k=1;k<=n;k++) if(mp[k]==mp[minn_point]) mp[k]=mp[i];
				nn+=minn;
			}
		}
		
	}
	return 0;
}