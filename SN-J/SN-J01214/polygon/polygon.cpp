#include <bits/stdc++.h>
using namespace std;
int n,a[1000],cnt=0;
int main()
{
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++)
	{
		a[i]=a[i+1];
	}
	for(int i = 1;i<=n;i++)
	{
		cnt+=a[i];
	}
	cout<<cnt%998244353;
	return 0;
}
