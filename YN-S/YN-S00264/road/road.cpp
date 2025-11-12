#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
const int N=1e4+15;
const int M=(1e6+N*10)*2;
int sum=0,visnum=0,cnt=0;
int n,m,k;
int vis[N];
int head[N]={};
int c[15];
struct edge
{
	int v,w,nxt;
}e[M];
struct task
{
	int p;
	long long cost;
	short ub;/*use 16 bit number to store 
	10 villages' urbanlization situation*/
};

bool query(task t,int p)
{
	short ubb=t.ub;
	while(p--)
	{
		if(!p)return ubb%2;
		else ubb>>=1;
	}
}
short transfer(task t,int p)
{
	return t.ub+pow(2,p-1);
}

void add(int u,int v,int w)
{
	cnt++;
	e[cnt].v=v;
	e[cnt].w=w;
	e[cnt].nxt=head[u];
	head[u]=cnt;
	cnt++;
	e[cnt].v=u;
	e[cnt].w=w;
	e[cnt].nxt=head[v];
	head[v]=cnt;
}

bool operator<(task a,task b)
{
	return a.cost>=b.cost;
}
priority_queue<task>pq;
void dijkarstra(int s)
{
	pq.push({s,0,0});
	while(pq.size())
	{
		task now=pq.top();
		task debug;
		pq.pop();
		debug=pq.top();
		if(vis[now.p])continue;
		vis[now.p]=true;
		if(now.p<=n)visnum++;
		if(visnum==n)
		{
			bool ok=true;
			for(int i=1;i<=n;i++)
				if(!vis[i])ok=false;
			if(ok)
			{
				printf("%lld\n",now.cost);
				return;
			}
		}
		for(int i=head[now.p];i;i=e[i].nxt)
		{
			if(e[i].v<=n)//get to a city
				pq.push({e[i].v,now.cost+e[i].w,now.ub});
			else//get to a village
			{
				if(query(now,e[i].v-n))//unbanlized
					pq.push({e[i].v,now.cost+e[i].w,now.ub});
				else//not urbanlized
				{
					pq.push({e[i].v,now.cost+e[i].w+c[e[i].v-n],transfer(now,e[i].v-n)});
				}
			}
			debug=pq.top();
		}
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	cin.get();
	int u,v,w,ct;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		cin.get();
		add(u,v,w);
	}
	for(int i=1;i<=k;i++)//i is for village num
	{
		scanf("%d",&c[i]);
		cin.get();
		for(int j=1;j<=n;j++)//j is for city num
		{
			scanf("%d",&ct);
			add(j,n+i,ct);
		}
	}
	dijkarstra(1);
	return 0;
}
