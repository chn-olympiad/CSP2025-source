#include<bits/stdc++.h>
#define int long long
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
const int N=1e4+10,P=998244353,Mod=1e9+7,K=10+10;
int n,m,k,fa[N],a[15][N],c[K],answ=0x3f3f3f3f3f3f3f3f;
bool flag;
vector<pair<int,pair<int,int> > >e;
int find(int u)
{
	return fa[u]=(fa[u]==u?u:find(fa[u]));
}
int kruskal(vector<pair<int,pair<int,int> > >ve)
{
	int ans=0;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	sort(ve.begin(),ve.end());
	for(auto edge:ve)
	{
		int fu=find(edge.second.first),fv=find(edge.second.second);
		if(fu!=fv)
		{
			fa[fu]=fv;
			ans+=edge.first;
		}
	}
	return ans;
}
signed main()
{
	FAST
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e.push_back({w,{u,v}});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
		flag=(flag||c[i]);
	}
	if(!flag||!k)
	{
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++)
				e.push_back({a[i][j],{i+n,j}});	
		cout<<kruskal(e);
	}
	else
	{
		for(int i=0;i<(1<<k);i++)
		{
			vector<pair<int,pair<int,int> > >tmp=e;
			int num=0;
			for(int j=0;j<k;j++)if(i&(1<<j))
			{
				num+=c[j+1];
				for(int l=1;l<=n;l++)tmp.push_back({a[j+1][l],{j+1+n,l}});
			}
			num+=kruskal(tmp);
			answ=min(answ,num);
		}
		cout<<answ;
	}
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
