#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[10004];
struct node
{
	int u,v,w;
}a[1000004];
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
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
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n+1;j++)
		{
			int x;
			cin>>x;
		}
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	int ans=0,sum=0;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int tx=find(a[i].u),ty=find(a[i].v);
		if(tx!=ty)
		{
			ty=tx;
			ans+=a[i].w;
			sum++;
			if(sum==n-1)
			{
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 

/*
5 10 0
1 2 3 1 3 4 1 4 5 1 5 6
2 3 1
2 4 7
2 5 1
3 4 2
3 5 3
4 5 6*/
