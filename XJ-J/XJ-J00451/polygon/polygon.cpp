#include<bits/stdc++.h>
using namespace std;
long long int n,i,a[5005],maxn,t;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>a[i];
	if(n<=3)
	{
		for(i=1;i<=n;i++)
		if(a[i]>maxn)
		maxn=a[i];
		if(a[1]+a[2]+a[3]>maxn*2)
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
	for(i=n-2;i>=1;i--)
	t+=i*i*i;
	cout<<t%998244353;
	return 0;
}
