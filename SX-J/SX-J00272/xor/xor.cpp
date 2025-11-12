#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
long long n,k;
bool Is_A()
{
	for(int i=1; i<=n; i++)
	{
		if(a[i]!=1) return 0;
	}
	return 1;
}
bool Is_B()
{
	for(int i=1; i<=n; i++)
	{
		if(a[i]>1)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","r",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	if(Is_A()) cout<<n/2;
	else if(Is_B())
	{
		sort(a+1,a+n+1,greater<int>());
		int sum0=0,sum1=0;
		for(int i=1; i<=n; i++)
		{
			if(a[i]==1) sum1++;
			else sum0++;
		}
		if(k==0)
		{
			cout<<sum0+sum1/2;
		}
		else
		{
			cout<<sum1;
		}
	}
	return 0;
}
