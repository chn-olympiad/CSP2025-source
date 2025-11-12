#include <bits/stdc++.h>
using namespace std;
int a[5001];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int cnt=0;
	for (int i=1;i<=n;i++)
	{
		for (int j=i+2;j<=n;j++)
		{
			int ans=0;
			int maxx=-1;
			for (int z=i;z<=j;z++)
			{
				ans+=a[z];
				maxx=max(maxx,a[z]);
			}
			if (ans>maxx*2) cnt++;
		}
	}
	cout<<cnt%998244353;
	return 0;
}
