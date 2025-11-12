#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+105,M=3e6+5;
int n,m,k;
ll c[N],dis[N],ans=1e18,num,cnt=1;
int to[M],nxt[M],head[M],income[N];
ll val[M],wi,mincost[N];
bool vis[N];
struct po 
{
	ll val;
	int u,laiyuan;
	bool operator <(const po y)const
	{
		if(val==y.val) return laiyuan<y.laiyuan;
		else return val<=y.val;
	}
};
priority_queue<po>q;
inline void addedge(int u,int v,ll w)
{
	to[++cnt]=v;
	val[cnt]=w;
	nxt[cnt]=head[u];
	head[u]=cnt;
	to[++cnt]=u;
	val[cnt]=w;
	nxt[cnt]=head[v];
	head[v]=cnt;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	ll w;
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d%lld",&u,&v,&w);
		addedge(u,v,w);
	}
	memset(mincost,0x3f3f3f,sizeof(mincost));
	for(int i=n+1;i<=n+k;++i)
	{
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;++j)
		{
			scanf("%lld",&wi);
			if(wi<mincost[i])
			{
				mincost[i]=wi;
			}
			to[++cnt]=j;
			val[cnt]=wi;
			nxt[cnt]=head[i];
			head[i]=cnt;
			to[++cnt]=i;
			val[cnt]=wi+c[i];
			nxt[cnt]=head[j];
			head[j]=cnt;
		}
	}
	memset(dis,0x3f3f3f,sizeof(dis));
	num=0;
	int sz=n+k;
		dis[1]=0;
		q.push({0,1,1});
		while(!q.empty())
		{
			int u=q.top().u;
			if(vis[u])
			{
				q.pop();
				continue;
			} 
			num+=-q.top().val;
			income[q.top().laiyuan]++;
			q.pop();
			vis[u]=1;
			sz--;
			if(sz<=0) break;
			for(int i=head[u];i;i=nxt[i])
			{
				int v=to[i];
				if(!vis[v]&&dis[v]>val[i])
				{
					dis[v]=val[i];
					q.push({-val[i],v,u});
				}
			}
		}
	for(int i=n+1;i<=n+k;++i)
	{
		if(income[i]==0) num-=mincost[i]+c[i];
	}
	cout<<num;
	return 0;
} 
