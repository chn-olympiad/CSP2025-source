#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,f[10005],sz[10005],c[15];
struct edge{
	int u,v,w;
	edge()=default;
	edge(int u_,int v_,int w_):u(u_),v(v_),w(w_){}
	bool operator <(const edge &b) const
	{
		return w<b.w;
	}
};
vector<edge> vec,a[15];
ll ans;
void init()
{
	iota(f+1,f+1+n+k,1);
	fill(sz+1,sz+1+n+k,1);
}
int find(int x)
{
	return f[x]==x?x:f[x]=find(f[x]);
}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return ;
	if(sz[x]<sz[y]) swap(x,y);
	f[y]=x;
	sz[x]+=sz[y];
}
pair<vector<edge>,ll > mst(vector<edge> vec)
{
	vector<edge> res;
	ll sum=0;
	res.reserve(n);
	init();
	for(auto [u,v,w]:vec)
	{
		if(find(u)!=find(v))
		{
			merge(u,v);
			res.emplace_back(u,v,w);
			sum+=w;
		}
	}
	return {res,sum};
}
void dfs(vector<edge> vec,int x,ll s)
{
	if(x>k) return ;
	dfs(vec,x+1,s);
	vector<edge> tmp;
	tmp.resize(vec.size()+a[x].size());
	merge(vec.begin(),vec.end(),a[x].begin(),a[x].end(),tmp.begin());
	auto [nvec,res]=mst(tmp);
	ans=min(ans,res+s+c[x]);
	tmp.clear();
	tmp.shrink_to_fit();
	dfs(nvec,x+1,s+c[x]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		vec.emplace_back(u,v,w);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			int w;
			cin>>w;
			a[i].emplace_back(i+n,j,w);
		}
		sort(a[i].begin(),a[i].end());
	}
	sort(vec.begin(),vec.end());
	auto [vv,sum]=mst(vec);
	vec=vv;
	ans=sum;
	dfs(vv,1,0);
	cout<<ans<<"\n";
}