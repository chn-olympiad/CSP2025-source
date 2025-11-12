#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=4;i<=n;i++)
	{
		int g=1,h=1;
		for(int j=n;j>n-i;j--)
		{
			g*=j;
		}
		for(int j=i;j>=2;j--)
		{
			h*=j;
		}
		ans+=g/h;
	}
	cout<<ans%998244353;
	return 0;
}
