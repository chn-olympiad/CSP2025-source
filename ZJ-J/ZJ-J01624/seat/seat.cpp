#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,ans=1;
int a[1005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>a[1])
		{
			ans++;
		}
	}
	int b=(ans+n-1)/n;
	if(b%2==1)
	{
		if(ans%n==0)
		{
			cout<<b<<" "<<n;
		}
		else
		{
			cout<<b<<" "<<ans%n;
		}
	}
	else
	{
		if(ans%n==0)
		{
			cout<<b<<" "<<1;
		}
		else
		{
			cout<<b<<" "<<n-ans%n+1;
		}
	}
	return 0;
}
