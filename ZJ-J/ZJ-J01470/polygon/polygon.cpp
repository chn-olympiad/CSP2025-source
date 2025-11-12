#include<bits/stdc++.h>
using namespace std;
long long int maxx,sum;
long long int a[6000];
int ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n-2;i++)
	{
		sum=a[i]+a[i+1]+a[i+2];
		maxx=max(max(a[i],a[i+1]),a[i+2]);
		if(maxx<sum*2)
		{
			ans++;
			ans=ans%=998244353;
		}
		for(int j=i+3;j<=n;j++)
		{
			sum+=a[j];
			maxx=max(maxx,a[j]);
			if(maxx<sum*2)
			{
				ans++;
				ans=ans%=998244353;
			}
		}
	}
	cout<<ans%998244353;
	return 0;
}