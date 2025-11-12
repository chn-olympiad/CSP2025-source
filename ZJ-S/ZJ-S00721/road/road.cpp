#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5,M=1e6+5;
int fa[N],n,m,ans,cnt,k,c[15],b[15][N];
struct node{
	int u,v,w;
}a[M];
int find(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
map<int,map<int,int> >f; 
bool cmp(node a,node b)
{
	return a.w<b.w;
}
void kruskal()
{
	for(int i=1;i<=n;i++)
		fa[i]=i;
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		if(find(a[i].u)!=find(a[i].v))
		{
			fa[find(a[i].u)]=fa[find(a[i].v)];
			ans+=a[i].w;
			f[a[i].u][a[i].v]=f[a[i].v][a[i].u]=a[i].w;
			cnt++;
			if(cnt==n-1)
				break;
		}
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie();
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>a[i].u>>a[i].v>>a[i].w;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>b[i][j];
	}
	kruskal();
	cout<<ans<<"\n";
	return 0;
}
