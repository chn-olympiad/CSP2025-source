#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
const int R = 1e3+10;
const int inf = 0x7fffffff;
int n,m,k;
int tot=0;
int a[R][R],c[N];

struct edge{
	int fro,to,val;
}e[N*100];

inline bool cmp(edge a,edge b) 
{
	return a.val<b.val;
}
inline void add(int u,int v,int w)
{
	tot++;
	e[tot].fro=u;e[tot].to=v;e[tot].val=w;
}

inline void Kruskal()
{
	int cnt=0;
	int ans=0; 
	sort(e+1,e+tot+1,cmp);
	for(int i=1;i<=n-1;i++) ans+=e[i].val;
	cout<<ans<<"\n";
}

signed main()
{
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;int u,v,w;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]=inf;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		a[u][v]=min(a[u][v],w);a[v][u]=min(a[v][u],w);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];int val;
		for(int j=1;j<=n;j++) 
		{
			cin>>val;
			a[i][j]=min(a[i][j],val);a[j][i]=min(a[j][i],val);
		}
	}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++) if(a[i][j]!=inf) {add(i,j,a[i][j]);add(j,i,a[j][i]);}
	Kruskal();
	return 0;
}
