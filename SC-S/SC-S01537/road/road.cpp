#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=1e4+10;
int n,m,k;
struct Edge
{
	int u,v,w;
	Edge(int u=0,int v=0,int w=0) : u(u),v(v),w(w) {}
};
vector<Edge> edge;
vector<Edge> nw_edge;
int c[15];
int a[15][N];
int f[N];
vector<Edge> tmp;
vector<int> id;//有用的点的编号 
int find(int x)
{
	if(x==f[x])
		return x;
	else
		return f[x]=find(f[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++)
	{
		cin>>u>>v>>w;
		edge.emplace_back(u,v,w);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	sort(edge.begin(),edge.end(),[](const auto &a,const auto &b){return a.w<b.w;});
	for(int i=1;i<=n;i++)
		f[i]=i;
	long long val_sum=0;
	for(auto e:edge)
	{
		if(find(e.u)!=find(e.v))
		{
			f[find(e.u)]=find(e.v);
			val_sum+=e.w;
			nw_edge.emplace_back(e);
		}
	}
	long long ans=val_sum;
	for(int i=1;i<=k;i++)
	{
		long long res=c[i];
		tmp=nw_edge;
		for(int j=1;j<=n;j++)
			tmp.emplace_back(j,n+1,a[i][j]);
		sort(tmp.begin(),tmp.end(),[](const auto &a,const auto &b){return a.w<b.w;});
		for(int i=1;i<=n+1;i++)
			f[i]=i;
		for(auto e:tmp)
		{
			if(find(e.u)!=find(e.v))
			{
				f[find(e.u)]=find(e.v);
				res+=e.w;
			}
		}
		if(res<val_sum)
			ans=min(ans,res),id.emplace_back(i);
	}
	for(int i=1;i<(1<<id.size());i++)
	{
		if((i&(-i))==i)
			continue;
		tmp=nw_edge;
		int cnt=n;
		long long res=0;
		for(int j=0;j<(signed)id.size();j++)
		{
			if(i>>j&1)
			{
				cnt++;
				for(int k=1;k<=n;k++)
					tmp.emplace_back(k,cnt,a[id[j]][k]);
				res+=c[id[j]];
			}
		}
		sort(tmp.begin(),tmp.end(),[](const auto &a,const auto &b){return a.w<b.w;});
		for(int i=1;i<=cnt;i++)
			f[i]=i;
		for(auto e:tmp)
		{
			if(find(e.u)!=find(e.v))
			{
				f[find(e.u)]=find(e.v);
				res+=e.w;
				if(res>ans)
					break;
			}
		}
		ans=min(ans,res);
	}
	cout<<ans<<endl;
	return 0;
}
