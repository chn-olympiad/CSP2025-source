#include <bits/stdc++.h>
using namespace std;
const int N=2e4+10;
const int M=2e6+10;

struct Node
{
	int u,v,w;
}g[M];

int f[N],wi[20][N];
bool flag[N];

int find(int x)
{
	if(x==f[x]) return x;
	return f[x]=find(f[x]);
}

void merge(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx==fy) return;
	f[fx]=fy;
}

bool cmp(Node x,Node y)
{
	return x.w<y.w;
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++) f[i]=i;
	for(int i=1;i<=m;i++) cin>>g[i].u>>g[i].v>>g[i].w;
	for(int i=1;i<=k;i++)
	{
		int x;
		cin>>x;
		for(int j=1;j<=n;j++) cin>>wi[i][j];
		for(int j=1;j<=n;j++)
		{
			for(int l=j+1;l<=n;l++)
			{
				g[++m].u=j;
				g[m].v=l;
				g[m].w=wi[i][j]+wi[i][l];
			}
		}
	}
	sort(g+1,g+m+1,cmp);
	int cnt=0,ans=0;
	for(int i=1;i<=m;i++)
	{
		if(cnt==n-1) break;
		if(find(g[i].u)==find(g[i].v)) continue;
		merge(g[i].u,g[i].v);
		ans+=g[i].w;
		cnt++;
	}
	return 0;
}
