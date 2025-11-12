#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define pb push_back
const int N=1e4+10,M=1e6+10;
const int P=1e9+7;

int n,m,k,ans,fa[N],c[N];
vector<pii> e[N];
struct Edge
{
	int u,v,w;
};
vector<Edge> kr;
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
int find(int x){
	return(fa[x]==x?x:fa[x]=find(fa[x]));
}

signed main()
{
 	freopen("road.in","r",stdin);
 	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		kr.pb({u,v,w});
	}
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int j=1;j<=k;j++)
	{
		cin>>c[j];
		for(int i=1,w;i<=n;i++){
			cin>>w;
			kr.pb({i,n+j,w});
		}
	}
	sort(kr.begin(),kr.end(),cmp);
	for(Edge x:kr)
	{
		int a=find(x.u),b=find(x.v);
		if(a!=b)
		{
			ans+=x.w;
			fa[a]=fa[b];
		}
	}
	cout<<ans<<'\n';
	return 0;
}

