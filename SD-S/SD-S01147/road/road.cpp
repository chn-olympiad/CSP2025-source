#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define int long long
using namespace std;
const int N=1e4+5;
struct Node
{
	int w,to,id;
};
vector<Node> q[N];
struct Noke
{
	int g,a[N];
};
Noke c[11];
int n,m,k;
int vis[N],dist[N],lst[N],vis2[N],vis0[N],visb[N];
struct NoDe
{
	int w,to;
	operator <(const NoDe &oth) const&
	{
		return w>oth.w;
	}
};
priority_queue<NoDe> p;
void dij(int now,int cs)
{
	if(cs>n)
	{
		return;
	}
	for(auto v:q[now])
	{
		if(!vis[v.to])
		{
			vis[v.to]=1;
			dist[v.to]=dist[now]+v.w;
			lst[v.to]=now;
			p.push({dist[v.to],v.to});
		}
		else if(dist[v.to]>dist[now]+v.w)
		{
			q[v.to].push_back({0,lst[v.to],0});
			q[lst[v.to]].push_back({0,v.to,0});
			dist[v.to]=dist[now]+v.w;
			p.push({dist[v.to],v.to});
		}
		else
		{
			if(visb[v.id]) continue;
			q[v.to].push_back({0,now,0});
			q[now].push_back({0,v.to,0});
		}
		visb[v.id]=1;
	}
	NoDe nxt=p.top();
	p.pop();
	dij(nxt.to,cs+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		cin >> u >> v >> w;
		q[u].push_back({w,v,i});
		q[v].push_back({w,u,i});
	}
	for(int i=1;i<=k;i++)
	{
		cin >> c[i].g;
		for(int j=1;j<=c[i].g;j++)
		{
			cin >> c[i].a[j];
		}
	}
	vis[1]=1;
	dij(1,1);
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		for(auto v:q[i])
		{
			if(v.id==0)
			{
				//cerr << v.to << " " << v.id << endl; 
				for(auto kk:q[i])
				{
					if(kk.to==v.to&&vis0[kk.id]==0)
					{
						//cerr << kk.id << " ";
						vis0[kk.id]=1;
						ans-=kk.w;
					}
				}
			}
			if(!vis2[v.id])
			{
				vis2[v.id]++;
				ans+=v.w;
			}
		}
	}
	cout << ans;
	return 0;
}
/*
7 9 0
1 2 1
2 4 1
1 3 1
2 3 10
2 5 1
3 6 1
4 5 10
6 7 10
3 7 1
*/
