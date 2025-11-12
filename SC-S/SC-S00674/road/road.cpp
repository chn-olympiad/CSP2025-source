#include<bits/stdc++.h>
using namespace std;
struct node
{
	int u,v,w,sum=0;
}a[1000005];
int n,m,k,ans;
int fa[100005],mm[100005];
int nw[20][100005];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void hb(int x,int y)
{
	mm[find(y)]+=mm[find(x)];
	fa[find(x)]=find(y);
}
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	int cnt=m;
	for(int i=1;i<=k;i++)
	{
		cin>>nw[i][0];
		for(int j=1;j<=n;j++)
		{
			cin>>nw[i][j];
			cnt++;
			a[cnt].u=j;
			a[cnt].v=n+i;
			a[cnt].w=nw[i][j];
		}
	}
	sort(a+1,a+m+k*n+1,cmp);
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=n;i++) mm[i]=1;
	for(int i=1;i<=m+k*n;i++)
	{
		if(find(a[i].u)!=find(a[i].v))
		{
			ans+=a[i].w;
			hb(a[i].u,a[i].v);
		} 
		if(mm[find(a[i].u)]>=n) break;
		
	}
	cout<<ans;
	return 0;
}