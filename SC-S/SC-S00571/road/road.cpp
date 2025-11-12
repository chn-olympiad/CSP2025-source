#include <bits/stdc++.h>
using namespace std;
long long n,m,k,x[20010],y[20010],sum;
struct node
{
	int u,v,w;
}r[20010];
bool comp(node a,node b)
{
	return a.w<b.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>r[i].u>>r[i].v>>r[i].w;
	}
	sort(r+1,r+1+m,comp);
	for(int i=1;i<=k;i++)
	{
		cin>>x[i];
		for(int j=1;j<=n;j++)
		{
			cin>>y[j];
		}
	}
	for(int i=1;i<=n-1;i++)
	{
		sum+=r[i].w;
	}
	cout<<sum;
	return 0;
} 