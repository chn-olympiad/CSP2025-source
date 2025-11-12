#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
}a[1050008];
int n,m,l;
struct edge{
	int fa,nu;
}f[10018];
bool cmp(node x,node y)
{
	return x.w<y.w;
}
int ff(int x)
{
	if(f[x].fa==x)
	return x;
	return f[x].fa=ff(f[x].fa);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>l;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	int tt=n;
	for(int j=1;j<=l;j++)
	{
		n++;
		int y;
		cin>>y;
		for(int i=1;i<=tt;i++)
			{
				int x;
				cin>>x;
				m++;
				a[m].u=n;
				a[m].v=i;
				a[m].w=x;
			}
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++)
	{
		f[i].fa=i,f[i].nu=1;
	}
	int k=0;
	long long ans=0;
	for(int i=1;i<=m;i++)
	{
		if(ff(a[i].u)!=ff(a[i].v))
		{
			k++;
			ans+=a[i].w;
			if(f[f[a[i].u].fa].nu>f[f[a[i].v].fa].nu)
			{
				f[a[i].v].fa=ff(f[a[i].u].fa);
				f[f[a[i].u].fa].nu+=f[f[a[i].v].fa].nu;
			}
			else
			{
				f[a[i].u].fa=ff(f[a[i].v].fa);
				f[f[a[i].v].fa].nu+=f[f[a[i].u].fa].nu;
			}
		}
		if(k==n-1)
		{
			break;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
/*
5 7 0
1 2 1
2 3 2
3 4 5
1 4 4
1 3 3
3 5 7
4 5 6
*/



