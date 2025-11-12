#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+20;
const int MAXM=1e4+10;

int n,m,k,c;
int ne[MAXN],e[MAXN],w[MAXN],h[MAXN],idx;
int a[MAXM][MAXM];
int dist[MAXN];
int f[MAXN];

void add(int u,int v,int ww)
{
	e[idx]=v;
	w[idx]=ww;
	ne[idx]=h[u];
	h[u]=idx++;
}

int dij(int x)
{
	queue<int> q;
	q.push(x);
//	dist[x]=0;
	while(!q.empty())
	{
		int t=q.front();
		if(f[t]) continue;
		q.pop();
		f[t]=1;
		for(int i=h[t];i!=-1;i=ne[i])
		{
			int j=e[i],ddd=w[i]; 
			if(dist[j]>dist[i]+ddd)
			{
				dist[j]=dist[i]+ddd;
				q.push(j);
			}
		}
	}
	return dist[n];
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(h,-1,sizeof(h));
	memset(dist,0x3f,sizeof(dist));
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		dist[u]=w;
		add(u,v,w);
		add(v,u,w);
	}
	scanf("%d",&c);
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
		    scanf("%d",&a[i][j]);
		}
	}
	int res=dij(1);
	printf("%d",res);
	return 0;
}

