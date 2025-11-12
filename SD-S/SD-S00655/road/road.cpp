//fuck ccf
#include<bits/stdc++.h>
using namespace std;
//我连特殊性质都不会写 
//我真是个飞舞
//哈哈哈 
const int maxn=1e4+5;
int n,m,k;
vector<pair<int,int>>g[maxn];
int dis[maxn];
bool vis[maxn];
int spfa(int s)
{
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	queue<int>q;
	q.push(s);
	dis[s]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(vector<pair<int,int>>::iterator it=g[u].begin();it!=g[u].end();it++)
		{
			int v=(*it).first;
			int w=(*it).second;
			if(dis[u]>=dis[v]+w)
			{
				dis[u]=dis[v]+w;
				if(!vis[v])
				{
					q.push(v);
					vis[v]=true;
				}
			}
		}
	}
	return dis[n];
}
int ans=1e9;

struct Node
{
	int x;
	bool operator < (const Node &other) const
	{
		return x>other.x;
	}
	friend operator + (Node &a,Node &b)
	{
		return a.x*b.x;
	}
};
void build(int l,int r);
void pushup(int x);
void pushdown();
void query(int l,int r);
void upd(int l,int r,int d);
void adddd(int x,int y,int tt);
void init_st();
int lca(int a,int b,int x);
int bfs();
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	spfa(1);
	cout<<dis[n];
	#define whk 0
	return whk;
}
