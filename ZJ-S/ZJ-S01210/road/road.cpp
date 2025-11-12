#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,ans,b[10005][10005],fa[10005],v[10005];
struct Node{
	int f,t,w;
}a[10005];
bool cmp(Node a,Node b)
{
	return a.w<b.w;
}
int find(int x)
{
	if(fa[x]==x)
		return x;
	else	return fa[x]=find(fa[x]);
}
void hb(int x,int y)
{
	fa[find(x)]=find(y);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].f>>a[i].t>>a[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>v[i];
		for(int j=1;j<=n;j++)
		{
			cin>>b[i][j];
		}
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		if(find(a[i].t)!=find(a[i].f))
		{
			ans+=a[i].w;
			hb(a[i].t,a[i].f);
		}
	}
	cout<<ans;
	return 0;
}