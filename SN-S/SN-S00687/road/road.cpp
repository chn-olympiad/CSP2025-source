#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

inline int read()
{
	int x = 0,f = 1;
	char ch = getchar();
	while('0'>ch||ch>'9')
	{
		if(ch=='-')
		{
			f = -1;
		}
		ch = getchar();
	}
	while('0'<=ch&&ch<='9')
	{
		x = (x<<3) + (x<<1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}

const int inf = 1e18,N = 2e4 + 10;

struct edge
{
	int u,v,w;
	bool operator<(const edge other)
	{
		return w < other.w;
	}
};

int n,m,k,fa[N],a[N],dis[15][N];
vector<edge> g,G[10];

inline int find(int x)
{
	return (fa[x]==x)?(x):(fa[x]=find(fa[x]));
} 

inline int kla(vector<edge> &x,int lim)
{
	for(int i = 1;i<=lim;i++)
	{
		fa[i] = i;
	}
	int cnt = 0,sum = 0;
	for(int i = 0;i<x.size();i++)
	{
		int u = x[i].u,v = x[i].v,w = x[i].w;
		if(find(u)!=find(v))
		{
			fa[find(u)] = find(v);
			sum += w;
			cnt++;
			if(cnt==lim-1)
			{
				return sum;
			}
		}
	}
}

inline void merge(vector<edge> &x,vector<edge> &y)
{
	vector<edge> z;
	int i = 0,j = 0;
	while(i<x.size()&&j<y.size())
	{
		if(x[i].w<y[j].w)
		{
			z.push_back(x[i]);
			i++;
		}
		else
		{
			z.push_back(y[j]);
			j++;
		}
	}
	while(i<x.size())
	{
		z.push_back(x[i]);
		i++;
	}
	while(j<y.size())
	{
		z.push_back(y[j]);
		j++;
	}
	x = z;
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	n = read(),m = read(),k = read();
	g.resize(m);
	for(int i = 0,u,v,w;i<m;i++)
	{
		u = read(),v = read(),w = read();
		g[i] = {u,v,w};
	}
	if(k==0)
	{
		sort(g.begin(),g.end());
		cout<<kla(g,n)<<endl;
	}
	else
	{
		bool check = 1;
		for(int i = 1;i<=k;i++)
		{
			a[i] = read();
			for(int j = 1,w;j<=n;j++)
			{
				w = read();
				G[i].push_back({n+i,j,w});
			}
			sort(G[i].begin(),G[i].end());
			if(a[i]!=0)
			{
				check = 0;
			}
		}
		if(check)
		{
			for(int i = 1;i<=k;i++)
			{
				merge(g,G[i]);
			}
			sort(g.begin(),g.end());
			cout<<kla(g,n+k)<<endl;
		}
		else
		{
			sort(g.begin(),g.end());
			int ans = inf;
			for(int i = 0,cnt,sum;i<(1ll<<k);i++)
			{
				cnt = sum = 0;
				vector<edge> gg = g;
				for(int j = 0;j<k;j++)
				{
					if((i>>j)&1)
					{
						merge(gg,G[j+1]);
						cnt += a[j+1];
						sum++;
					}
				}
				ans = min(ans,cnt+kla(gg,sum+n));
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

*/
