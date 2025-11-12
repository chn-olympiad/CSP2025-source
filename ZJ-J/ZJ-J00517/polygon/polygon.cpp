#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int n,m,x;
int a[5005],y,qw=0,zong=0;
long long ans=0;
int main()
{
	freopen(polygon.in,"r",stdin);
	freopen(polygon.out,"w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1) qw++;
		zong=zong+a[i];
	}
	sort(a+1,a+n+1);
	if(n==3)
	{
		if(a[1]+a[2]>a[3])
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	else if(zong<=a[n]*2)
	{
		cout<<0;
		return 0;
	}
	else 
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=ans*2;
			ans=ans%998244353;
		}
		ans=(ans+998244353-1-n-n*(n-1)/2)%998244353;
		cout<<ans;
	}
	return 0;
}
