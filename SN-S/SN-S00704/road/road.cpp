#include<bits/stdc++.h>
using namespace std;
const int M=1e6+2,K=12;
const int N=1e4+2;
const int P=M+1e7;
struct node{
	int u,v;
	long long z;
}e[P];
inline bool cmp(node x,node y)
{
	return x.z<y.z;
}
int n,m,k,fa[N];
long long c[K],a[K][N];
inline int get(int x)
{
	if(fa[x]==x)return x;
	fa[x]=get(fa[x]);
	return fa[x];
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].z;

	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	int top=m;
	if(n*n*k<P)
	{
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
				for(int s=j+1;s<=n;s++)
					e[++top]={j,s,c[i]+a[i][j]+a[i][s]};
		}
	}
	sort(e+1,e+top+1,cmp);
	int cnt=0,q=0;
	long long ans=0;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=top;i++)
	{
		int u=e[i].u,v=e[i].v;
		long long z=e[i].z;
		fa[u]=get(u);
		fa[v]=get(v);
		if(fa[u]==fa[v])
		{
			q++;
			continue;
		}
		cnt++;
		v=fa[v];
		u=fa[u];
		fa[v]=u;
		ans+=z;
		if(cnt==n-1)
			break;
	}
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
