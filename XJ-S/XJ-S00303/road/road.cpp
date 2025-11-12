#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=100005;
struct Edge
{
	int u,v,w;
	friend bool operator < (Edge a,Edge b)
	{
		return a.w<b.w;
	}
};
vector<Edge> E;
int fa[maxn],dis[maxn];
int find(int u)
{
	if(fa[u]==u)
	{
		return u;
	}
	return fa[u]=find(fa[u]);
}
void merge(int x,int y)
{
	int u=find(x),v=find(y);
	fa[v]=u;
	dis[u]+=dis[v];
}
bool vis[maxn],cnt;
int n,m,k;
int ans;
void Kruscal()
{
	sort(E.begin(),E.end());
	int ttt=n;
	for(auto t:E)
	{
		int u=t.u,v=t.v,w=t.w;
		int x=find(u);
		int y=find(v);
		if(x!=y)
		{
			ans+=w;
			merge(x,y);
			if(u>n)
			{
				ttt++;
			}
			if(v>n)
			{
				ttt++;
			}
//			cout << ans << '\n';
		}
		if(dis[find(0)]==ttt)
		{
			break;
		}
	}
}
int c[10];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1;i<=100000;i++)
	{
		dis[i]=1;
		fa[i]=i;
	}
	cin >> n >> m >> k;
	for(int i=1,u,v,w;i<=m;i++)
	{
		cin >> u >> v >> w;
		E.push_back({u,v,w});
	}
	for(int i=1,a;i<=k;i++)
	{
		cin >> c[i];
		for(int j=1;j<=n;j++)
		{
			cin >> a;
			E.push_back({n+i,j,a+c[i]});
		}
	}
	Kruscal();
	cout << ans << '\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
