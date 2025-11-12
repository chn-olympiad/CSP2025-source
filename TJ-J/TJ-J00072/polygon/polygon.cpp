#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,mod=998244353;
	cin>>n;
	int a[n+5];
	int sum=0,m=0,k=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int po=3;
	
	for(int i=7;i<pow(2,n);i++)
	{
		if(i==pow(2,po))
		{
			continue;
		}
		if(i==pow(2,po)+1)
		{
			continue;
		}
		if(i==pow(2,po)+2)
		{
			po++;
			continue;
		}
		cout<<i<<endl;
		sum=0,m=0,k=0;
		for(int j=0;j<n;j++)
		{
			if((i>>j)&1)
			{
				sum+=a[j+1];
				m=max(m,a[j+1]);
				k++;
			}
		}
		if(sum>m*2&&k>=3)
		{
			ans++;
		}
		ans=ans%mod;
	}
	cout<<ans;
	return 0;
}
