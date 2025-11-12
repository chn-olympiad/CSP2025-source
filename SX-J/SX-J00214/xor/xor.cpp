#include<bits/stdc++.h>
using namespace std;
long long n,k,a[99999],sum;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		long long sum1=a[i]|sum1;
		if(sum1==k) sum++;
		for(long long i=1;i<=n;i++)
		{
			sum=sum&a[i];
			if(sum==k)
			{
				sum++;
			}
		}
	}
	cout<<sum-1;
	return 0;
}