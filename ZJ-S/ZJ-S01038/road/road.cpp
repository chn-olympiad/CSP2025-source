#include<bits/stdc++.h>
#define int long long
using namespace std;
#define Exit(str,val) {cout<<str<<endl;return val;}
#define Ms(shuzu,val) memset(shuzu,val,sizeof(shuzu))
const int N=1e5+5;
vector<pair<int,int> >G[N];
struct node{
	int u,v,w;
}e[N];
int a[15][N],fa[N];
int findfa(int x){return fa[x]==x?x:fa[x]=findfa(fa[x]);}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
		e[i]={u,v,w};
	}
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	if(k==0)
	{
		for(int i=1;i<=n;i++) fa[i]=i;
		sort(e+1,e+m+1,[&](node x,node y){
			return x.w<y.w;
		});int ans=0;
		for(int i=1;i<=m;i++)
		{
			int u=e[i].u,v=e[i].v,w=e[i].w;
			int fu=findfa(u),fv=findfa(v);
			if(fu==fv) continue;
			fa[fu]=fv,ans+=w;
		}
		cout<<ans<<endl;
	}
	cout<<0<<endl;
}
/*
5 8 0
1 2 2
1 3 4
1 4 3
1 5 1
2 3 2
2 4 1
3 5 3
4 5 3
*/