#include<bits/stdc++.h>
using namespace std;

const int MAX=10020;
const long long maxLL=9000000000000009;

struct TU{
	int v;
	int w;
};
vector<TU> e[1100006];

bool vis[MAX];
long long dis[MAX];
int DJST(int n){
	memset(vis,false,sizeof(0));
	for(int i=0;i<=n;i++) dis[i]=maxLL;
	long long sum=0;
	dis[1]=0;
	for(int i=1;i<=n;i++)
	{
		int k=0;
		for(int j=1;j<=n;j++)
		{
			if(vis[j]==true) continue;
			if(dis[j]<dis[k]){
				k=j;
			}
		}
		vis[k]=true;
		sum+=dis[k];
		for(int j=0;j<e[k].size();j++)
		{
			int v=e[k][j].v;
			int w=e[k][j].w;
			if(vis[v]==true) continue;
			if(dis[v]>w) dis[v]=w;
		}
	}
	return sum;
}
int n,m,k;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		TU x;
		x.v=v;x.w=w;
		e[u].push_back(x);
		x.v=u;x.w=w;
		e[v].push_back(x);
	}
	for(int i=1;i<=k;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=n;j++)
		{
			int w;
			cin>>w;
			TU x;
		    x.v =j;x.w =w;
		    e[n+i].push_back(x);
		    x.v =n+i;x.w =w;
		    e[j].push_back(x);
		}
	}
	long long ans=DJST(n+k);
	cout<<ans<<"\n";
	return 0;
}


