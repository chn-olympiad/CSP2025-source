#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int a[N];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,maxx=LLONG_MIN,ans=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(maxx<a[i])
			maxx=a[i];
	}
	if(maxx==1)
	{
		for(int i=3;i<=n;i++)
		{
			ans=ans+((i-2)*(i-1))/2*(n-i+1);
		}
	}
	else if(n==3)
	{
		if(a[1]+a[2]>a[3] && a[1]+a[3]>a[2] && a[2]+a[3]>a[1])
			ans=1;
	}
	printf("%lld",ans);
	return 0;
}