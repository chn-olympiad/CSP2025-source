#include<bits/stdc++.h>
#define int long long 
using namespace std;
struct node
{
	int u,v,w;
}a[1000005];
int n,m,k,ans,fa[1000005];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(fa[x]==x)
	{
		return x;
	}
	return find(fa[x]);
}
void kruskal()
{
	sort(a+1,a+m+1,cmp);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		if(cnt==n-1)
		{
			return ;
		}
		if(find(a[i].u)!=find(a[i].v))
		{
			ans+=a[i].w;
			fa[a[i].u]=a[i].v;
			cnt++;
		}
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	}	
	kruscal();
	cout<<ans;
	return 0;
}
