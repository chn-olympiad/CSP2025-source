#include <bits/stdc++.h>

using namespace std;

const int MAXN=1e4+10;
const int MAXK=10+5;
const int MAXM=1e6+10;
const int MAXE=MAXM+MAXN*MAXK;

struct Edge
{
	int u,v;
	long long w;
	
	bool operator< (const Edge& other)
	{
		return w<other.w;
	}	
};

class Graph
{
private:
	
	int N,M,K;
	
	Edge e[MAXE*2];
	int idx;
	
	long long c[MAXK];
	
	bool st[MAXK];
	
	long long ans=1e18;
	
	int fa[MAXN+MAXK];
	
	void Init()
	{
		for(int i=1;i<=N+K;i++)
		{
			fa[i]=i;
		}
	}
	
	int Find(int u)
	{
		if(u!=fa[u])
		{
			fa[u]=Find(fa[u]);
		}
		
		return fa[u];
	}
	
	bool Unite(int u,int v)
	{
		int fu=Find(u),fv=Find(v);
		
		if(fu==fv)
		{
			return false;
		}
		else
		{
			fa[fu]=fv;
			return true;
		}
	}
	
	long long Kruskal()
	{
		long long ret=0;
		
		for(int i=1,u,v;i<=idx;i++)
		{
			u=e[i].u,v=e[i].v;
			
			if(u>N)
			{
				if(st[u-N]==false)
				{
					continue;
				}
				
				if(Unite(u,v))
				{
					ret+=e[i].w;
				}
			}
			else if(v>N)
			{
				if(st[v-N]==false)
				{
					continue;
				}
				
				if(Unite(u,v))
				{
					ret+=e[i].w;
				}
			}
			else
			{
				if(Unite(u,v))
				{
					ret+=e[i].w;
				}
			}
		}
		
		return ret;
	}
	
public:
	
	void Solve()
	{
		cin>>N>>M>>K;
		
		for(int i=1,u,v;i<=M;i++)
		{
			long long w;
			cin>>u>>v>>w;
			idx++;
			e[idx]={u,v,w};
		}
		
		for(int i=1;i<=K;i++)
		{
			cin>>c[i];
			
			for(int j=1;j<=N;j++)
			{
				long long w;
				cin>>w;
				idx++;
				e[idx]={j,N+i,w};
			}
		}
		
		sort(e+1,e+1+idx);
		
		for(int mask=0;mask<=(1<<K)-1;mask++)
		{
			long long tmp=0;
			
			for(int j=0;j<K;j++)
			{
				st[j]=false;
				
				if(((mask>>j)&1)==1)
				{
					st[j]=true;
					tmp+=c[j];
				}
			}
			
			Init();
			ans=min(ans,Kruskal()+tmp);
		}
		
		cout<<ans<<'\n';
	}	
};

Graph g;

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0); 
	
	g.Solve();
	
	return 0;
} 