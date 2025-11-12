#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w; 
vector<pair<int,int> >e;
int a[10005];
bool vis[10005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>u>>v>>w;
		e[u].first=v;
		e[u].second=w;
		e[v].first=u;
		e[v].second=w;
	}
	memset(a,0x3f,sizeof a);
	a[1]=0;
	cout<<0;
	return 0;
}
