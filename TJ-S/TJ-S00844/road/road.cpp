#include <bits/stdc++.h>
using namespace std;
struct road
{
	int s;
	int e;
	int pri;
	
}a[1000005];
int price[1000005];
int b[15][1000005];
bool cmp(road x,road y)
{
	return x.pri<y.pri;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	if(k==0)
	{
		for (int i=1;i<=m;i++)
		{
			cin>>a[i].s>>a[i].e>>a[i].pri;
		}
		sort(a+1,a+m+1,cmp);
		long long ans=0;
		for (int i=1;i<=m-1;i++)
		{
			ans+=a[i].pri;
		}
		cout<<ans;
	}
	else
	{
		for (int i=1;i<=m;i++)
		{
			cin>>a[i].s>>a[i].e>>a[i].pri;
		}
		for (int i=1;i<=k;i++)
		{
			cin>>price[i];
			for (int j=1;j<=m;j++)
			{
				cin>>b[i][j];
			}
		}
		sort(a+1,a+m+1,cmp);
		long long ans=0;
		for (int i=1;i<=m-2;i++)
		{
			ans+=a[i].pri;
		}
		cout<<ans;		
	}
	return 0;
}
