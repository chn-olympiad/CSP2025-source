#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5005],x=0;
	long long ans=0;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		x=max(x,a[i]);
	}
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>x*2)
		{
			ans=1;
		}
		cout << ans;
		return 0;
	}
	if(x==1)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=2;
			ans%=998244353; 
		}
		ans=ans-1-n-n*(n-1)/2;
		cout << ans%998244353;
		return 0;
	}
}
