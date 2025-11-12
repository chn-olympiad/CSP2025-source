#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;
int n,m,k,mm,f[maxn],cnt,ans;
struct edge{int u,v,w;}; 
vector<edge> e;
bool cmp(edge a,edge b){return a.w<b.w;};
int find(int x){return f[x]==x?x:find(f[x]);}
signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		e.push_back({a,b,c});
	}
	sort(e.begin(),e.end(),cmp);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m&&cnt<n;i++)
	{
		auto x=e[i];
		if(find(x.u)==find(x.v))continue;
		f[x.u]=f[x.v];
		ans+=x.w;
		cnt++;
	}
	cout<<ans;
	return 0;
}
