#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,answer=0;
	cin>>n;
	long long a[n];
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long i=3;i<=n;i++)
	{
		for(long long j=0;j<=n-i;j++)
		{
			for(long long k=n-1;k>j+i-2;k--)
			{
				long long q=a[k];
				for(long long w=j;w<=j+i-1;w++)
				{
					q+=a[w];
				}
				if(q>a[k]*2)
				{
					answer++;
				}
			}
		}
	}
	cout<<answer%998244353;
	return 0;
}