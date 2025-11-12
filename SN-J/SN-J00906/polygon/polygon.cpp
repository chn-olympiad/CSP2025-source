#include<bits/stdc++.h>
using namespace std;
long long n,a[10000],sum,ans;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(n==3)
	{
		if((a[1]+a[2]+a[3])>(2*max(max(a[1],a[2]),max(a[1],a[3]))))
		{
			cout<<"1";
			return 0;
		}
		else
		{
			cout<<"0";
			return 0;
		}
	}
	else
	{
		for(int i=3;i<=n;i++)
		{
			ans+=((n-i+1)*(n-i+1+1)/2+(n-i+1)*(n-i+1+1)%2);
		}
		cout<<ans%998244353;
	}
	return 0;
}
