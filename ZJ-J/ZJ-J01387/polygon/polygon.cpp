#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5005],cnt=0,sum=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==1||n==2)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
		{
			cnt++;
		}
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
	for(int i=3;i<=n;i++)
	{
		long long ans=1,ans2=1;
		for(int j=0;j<i;j++)
		{
			ans*=(n-j);
			ans2*=(j+1);
		}
		sum+=ans/ans2;
	}
	cout<<sum;
	return 0;
}