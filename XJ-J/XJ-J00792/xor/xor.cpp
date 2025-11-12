#include <bits/stdc++.h>
using namespace std;
long long n, k, a[500005], ans=0, sum=0;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k) ans++;
	}
	for(long long i=1;i<=n;i++)
	{
		sum=0;
		for(long long j=i;j<=n;j++)
		{
			sum^=a[j];
		}
		if(sum==k)
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
