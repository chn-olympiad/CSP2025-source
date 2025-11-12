#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e6+5,N=1e5+5;
struct node{
	int u,v,w;
}a[M],b[M];
int f[N],m,n,ans,k,d[15][N],c[N];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(x==f[x])
		return x;
	return f[x]=find(f[x]);
}
int kr(int x)
{
	for(int i=1;i<=m;i++)
		b[i]=a[i];
	sort(b+1,b+1+m,cmp);
	int cnt=0,mi=0;
	for(int i=1;i<=x;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int r1=find(b[i].u);
		int r2=find(b[i].v);
		if(r1!=r2)
		{
			mi+=b[i].w;
			f[r1]=r2;
			cnt++;
		}
		if(cnt==x-1)
			break;
	}
	return mi;
}
void dfs(int x,int s)
{
	ans=min(ans,kr(x+n-1)+s);
	if(x>k)
		return;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
			a[++m]=node{i+n,j,d[i][j]};
		dfs(x+1,s+c[i]);
		for(int j=1;j<=n;j++)
			a[m--]=node{0,0,0};
	}
}
signed main()
{
 	freopen("road.in","r",stdin);
 	freopen("road.out","w",stdout);
 	ios::sync_with_stdio(0);
 	cin.tie(0);
 	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++)
	{
		cin>>u>>v>>w;
		a[i].u=u;
		a[i].v=v;
		a[i].w=w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>d[i][j];
	}
	ans=1e18;
	dfs(1,0);
	cout<<ans;
 	return 0;
}