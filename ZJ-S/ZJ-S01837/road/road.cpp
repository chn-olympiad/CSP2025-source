#include<bits/stdc++.h>
using namespace std;
const int maxn=10100;
const int maxm=3000010;
const long long INF=1e18;
typedef long long ll;
int n,m,k,ind;
int head[maxn],c[20],a[20][maxn],vis[maxn];
int fa[maxn];
ll ans=0;
queue<int>q;
queue<ll>dis;
queue<int>visit;

struct node{
	int from,to,val,nxt;
}e[maxm];

bool cmp(node x,node y)
{
	return x.val<y.val;
}

void add_edge(int u,int v,int w)
{
	e[++ind].to=v;
	e[ind].from=u;
	e[ind].val=w;
	e[ind].nxt=head[u];
	head[u]=ind;
}

int find(int x)
{
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}

void kruskal()
{
	int cnt=0;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=ind;i++)
	{
		int u=e[i].from,v=e[i].to;
		int fu=find(u),fv=find(v);
		if(fu!=fv)
		{
			//cout<<u<<" "<<v<<endl;
			ans+=e[i].val;
			cnt++;
			fa[fu]=fv;
			if(cnt==n-1) break;
		}
	}
}


void bfs()
{
	q.push(1);
	dis.push(0);
	visit.push(1);
	vis[1]=1;
	while(!q.empty())
	{
		int u=q.front(),step=visit.front();
		ll res=dis.front();
		//cout<<step<<endl;
		if(step==n)
		{
			ans=min(res,ans);
			//printf("%lld\n",ans);
			q.pop();
			vis[u]=0;
			continue;
		}
		q.pop();
		dis.pop();
		visit.pop();
		vis[u]=0;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].to,w=e[i].val;
			if(!vis[v])
			{
				vis[v]=1;
				q.push(v);
				dis.push(res+w);
				if(1<=v&&v<=n) visit.push(step+1);
				else visit.push(step);
			}
		}
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			int u=n+i,v=j,w=a[i][j];
			add_edge(u,v,w);
			add_edge(v,u,w);
		}
	}
	if(k==0)
	{
		sort(e+1,e+ind+1,cmp);
		kruskal();
	} 
	else
	{
		ans=INF;
		bfs();
		printf("%lld",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
