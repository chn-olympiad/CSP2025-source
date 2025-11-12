#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,k=0,s=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
		if(a[1]+a[2]+a[3]>2*a[3])
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
		return 0;
	}
	for(int i=1;i<=n-2;i++)
	{
		k=k+i;
		s=s+k;
	}
	cout<<s%998244353;



	return 0;
}