#include<bits/stdc++.h>
using namespace std;
#define int long long

class Set_
{
	public:
		int n_;
		int father[100005];
		int size[100005];
		void _f()
		{
			for(int i=1;i<=n_;i++)
			{
				father[i]=i;
				size[i]=1;
			}
			return ;
		}
		int findh(int a)
		{
			if(father[a]==a)
				return a;
			int ans=findh(father[a]);
			father[a]=ans;
			return ans;
		}
		void merge(int a,int b)
		{
//			cout<<"/////";
			if(size[a]<size[b])
			{
				father[findh(a)]=findh(b);
				size[b]=size[a]+size[b];
				size[a]=size[b];
			}
			else
			{
				father[findh(b)]=findh(a);
				size[a]=size[a]+size[b];
				size[b]=size[a];
			}
		}
		bool insame(int a,int b)
		{
			return findh(a)==findh(b);
		}
};
class Edge
{
	public:
		int u;
		int v;
		int w;
		bool operator < (Edge y) const
		{
			return w<y.w;
		}
};

const int INF=0x7fffffffffffffffll;

int n,m,k;
int u,v,w;
int c[15];
int a[15][10005];
vector<Edge> G;
vector<Edge> G1;
int ans=INF;

void dfs(int id,int cnt,int cntc);
void solve(int cnt,int cntc,vector<Edge> g);

void dfs(int id,int cnt,int cntc)
{
	if(id>k)
	{
		solve(cnt,cntc,G);
		return ;
	}
	dfs(id+1,cnt,cntc);
	for(int i=0;i<G1.size();i++)
	{
		G.push_back(G1[i]);
	}
	dfs(id+1,cnt+c[id],cntc+1);
	for(int i=0;i<G1.size();i++)
	{
		G.pop_back();
	}
	return ;
}
void solve(int cnt,int cntc,vector<Edge> g)
{
//	cout<<"-----";
	sort(g.begin(),g.end());
	Set_ s;
	s.n_=n+cntc+10;
	s._f();
	for(int i=0;i<g.size();i++)
	{
		if(!s.insame(g[i].u,g[i].v))
		{
//			cout<<g[i].u<<" "<<g[i].v<<"\n";
			s.merge(g[i].u,g[i].v);
			cnt+=g[i].w;
		}
	}
	ans=min(ans,cnt);
//	for(int i=1;i<=n+cntc;i++)
//		cout<<s.father[i]<<" ";
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		G.push_back((Edge){u,v,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			G1.push_back((Edge){j,n+i+1,a[i][j]});
		}
	}
	dfs(1,0,0);
	cout<<ans;
	
	
	return 0;
}