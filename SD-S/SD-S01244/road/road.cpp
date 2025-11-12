//road
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;
typedef long long ll;
int const N=1e4+10,M=2e6+10;
ll e[2*M],w[2*M],ne[2*M],h[M],idx;
ll c[20],a[20][N],dis[N],n,m,k;
bool vis[N];
void add(ll u,ll v,ll w0)
{
	e[idx]=v;
	w[idx]=w0;
	ne[idx]=h[u];
	h[u]=idx++; 
}
ll prim()
{
	int ans=0;
	priority_queue<PII,vector<PII>,greater<PII>> q;
	dis[1]=0;
	q.push({0,1});
	while(!q.empty())
	{
		int u=q.top().second; q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=h[u];~i;i=ne[i])
		{
			int v=e[i];
			if(dis[v]>w[i]) dis[v]=w[i];
			q.push({dis[v],v});
		}
	}
	for(int i=1;i<=n;i++)
	{
//		cout<<dis[i]<<' ';
		ans+=dis[i];
	}
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(dis,0x3f,sizeof dis);
	memset(h,-1,sizeof h);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		ll u,v,w;
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	bool f=1;
	for(int j=1;j<=k;j++)
	{
		scanf("%lld",c+j);
		if(c[j]) f=0;
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[j][i]);
	}
	//special A/k=0
	if(f||k==0)
	{
		for(int j=1;j<=k;j++)
			for(int i=1;i<=n;i++)
			{
				add(j+n,i,a[j][i]);
				add(i,j+n,a[j][i]);
			}
		n+=k;
		printf("%lld\n",prim());
	}
	
	return 0;
 }
/*
3 3 1
1 2 1
1 3 3
2 3 3
0 1 2 1
*//*
4 4 1
1 2 10
1 3 3
2 3 4
2 4 3
0 1 1 1 1
*//*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
