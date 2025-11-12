#include<bits/stdc++.h>
using namespace std;

const int N=1e4+5;
int n,m,k,ks[11][N],c[11];
long long ans;
bool f[N+11];

struct edge
{
	int v,w;
	edge(int vv,int ww){v=vv;w=ww;}
	bool operator <(const edge&a)
	const{
		return w>a.w;
	}
};
vector<edge> es[N+10];

void kru(int i,vector<edge> es[])
{
	long long cans=0;
	memset(f,0,sizeof(f));
	priority_queue<edge> pq;
	int cnt=0;
	for(int j=0;j<k;j++)
	{
		if(i&1<<j)
		{
			cnt++;
			cans+=c[j+1];
			for(int l=1;l<=n;l++)
			{
				es[n+j+1].push_back(edge(l,ks[j+1][l]));
				es[l].push_back(edge(n+j+1,ks[j+1][l]));
			}
		}
	}
	for(edge i:es[1]) pq.push(i);
	f[1]=1;
	for(int i=0;i<cnt+n-1;i++)
	{
		edge ce=pq.top();pq.pop();
		while(f[ce.v])
		{
			ce=pq.top();pq.pop();
		}
		f[ce.v]=1;
		cans+=ce.w;
		for(edge j:es[ce.v]) if(!f[j.v]) pq.push(j);
	}
	if(ans==0) ans=cans;
	ans=min(ans,cans);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		es[u].push_back(edge(v,w));
		es[v].push_back(edge(u,w));
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%d",&ks[i][j]);
	}
	for(int i=0;i<1<<k;i++)
		kru(i,es);
	cout<<ans;
	return 0;
}