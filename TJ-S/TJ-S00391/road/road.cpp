#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,w[1000005],u[1000005],v[1000005];
bool mp[10005][10005];
int c[15],a[15][10005];
long long ans=0;
int main()
{
	freopen("road.in","r".stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		cin>>w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			scanf("%d",a[i][j]);
		}
	}
	sort(w+1,w+m+1);
	for(int i=1;i<=n-1;i++)
	{
		ans+=w[i];
	}
	cout<<ans;
	return 0;
}
