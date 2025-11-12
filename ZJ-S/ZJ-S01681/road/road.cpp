// 1.33e8 量级
// 考场机子怎么这么慢 
#include <iostream>
#include <algorithm>
#include <queue>
#define big long long
using namespace std;
big n,m,k,head[20004],cnt,ans,c[20],maxc,dis[20004],vis[20004],INF=1e18;
struct Edge{
	big next,to,val;
}edge[2500006];
struct Node{
	big pos,val;
	friend bool operator < (const Node l,const Node r)
	{
		return l.val > r.val;
	}
}; priority_queue <Node> q;
void add_edge(big u,big v,big w)
{
	edge[++cnt] = {head[u],v,w};
	head[u] = cnt;
}
void Prim(big s,big st)
{
	for(big i = 1;i <= n+k;i++)
	{
		dis[i] = INF;
		vis[i] = 0;
	}
	q.push({s,dis[s]=0});
	while(!q.empty())
	{
		big u = q.top().pos; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(big i = head[u],v;i ;i = edge[i].next)
		{
			v = edge[i].to;
			big flag = 1;
			if(v > n)
			{
				big id = v-n;
				flag = (st>>(id-1))&1;
			}
			if(!flag) continue;
			if(vis[v]) continue;
			if(edge[i].val < dis[v])
			{
				q.push({v,dis[v]=edge[i].val});
			}
		}
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	maxc = 0;
	scanf("%lld %lld %lld",&n,&m,&k);
	for(big i = 1,x,y,z;i <= m;i++)
	{
		scanf("%lld %lld %lld",&x,&y,&z);
		add_edge(x,y,z), add_edge(y,x,z);
	}
	for(big i = 1,x,y,z;i <= k;i++)
	{
		scanf("%lld",c+i); maxc = max(maxc,c[i]);
		for(big j = 1;j <= n;j++)
		{
			x = n+i; y = j; scanf("%lld",&z);
			add_edge(x,y,z), add_edge(y,x,z);
		}
	}
	Prim(1,(1ll<<k)-1);
	for(big i = 1;i <= n+k;i++) ans += dis[i];
	if(maxc == 0) return printf("%lld",ans),0;
	ans = INF;
	for(big st = 0;st < (1ll<<k);st++) // 枚举状态
	{
		// 对每一个状态进行 Prim;
		big tot = 0;
		Prim(1,st);
		for(big j = 1;j <= k;j++)
		{
			if((st>>(j-1))&1) tot += c[j];
		}
		for(big j = 1;j <= n+k;j++)
		{
			if(j <= n) tot += dis[j];
			else if(j > n)
			{
				big id = j-n;
				if((st>>(id-1))&1) tot += dis[j];
			}
		}
		ans = min(ans,tot);
	}
	printf("%lld",ans);
	return 0;
}
