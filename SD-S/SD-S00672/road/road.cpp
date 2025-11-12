#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdio> 
#include<vector>
using namespace std;
const int N=1e4+50;
int g[N],a[20][N],c[20],n,m,k,u,v,w;
long long ans=0;
struct Node
{
	int u;
	int v;
	long long w;
};
bool cmp(Node x,Node y)
{
	return x.w<y.w;
}
vector<Node>to;
int findrt(int x)
{
	if(x==g[x])return g[x];
	return g[x]=findrt(g[x]);
}
void init()
{
	for(int i=1;i<=n;i++)
	{
		g[i]=i;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	init();
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		to.push_back(Node{u,v,w});
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(j==k)continue;
				long long t=a[i][j]+a[i][k];
				to.push_back(Node{j,k,t});
			}
		}
	}
	sort(to.begin(),to.end(),cmp);
	int cnt=0;
	for(int i=0;i<to.size();i++)
	{
		u=to[i].u;
		v=to[i].v;
		w=to[i].w;
		int gu=findrt(u);
		int gv=findrt(v);
		if(g[gu]==g[gv])continue;
		cnt++;
		ans+=w;
		g[gu]=gv;
		if(cnt==n-1)
		{
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 6 0
1 2 2
1 3 1
2 4 3
2 5 3
3 5 3
4 5 6
*/
