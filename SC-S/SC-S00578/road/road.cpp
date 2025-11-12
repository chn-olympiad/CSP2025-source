#include <bits/stdc++.h>
using namespace std;

using ull=unsigned long long;

const int N=1e4+10,M=1e7+10;

struct NODE
{
	ull u,v,w;
	bool operator< (const NODE &b) const
	{
		return w<b.w;
	}
};

int n,m,t,cnt=0;
ull ans=0,c[N];
bool vis[N];
NODE a[M];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>t;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=t;i++)
	{
		int w[N];
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			a[++m].u=n+t;
			a[m].v=j;
			cin>>a[m].w;
		}
	}
	sort(a+1,a+m+1);
	for(int i=1;i<=m;i++)
	{
		if(vis[a[i].u] && vis[a[i].v])
		{
			continue;
		}
		vis[a[i].u]=true;
		vis[a[i].v]=true;
		ans+=a[i].w;
	}
	cout<<ans;
	return 0;
}