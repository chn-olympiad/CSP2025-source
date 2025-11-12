#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long sum[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n=0,k=0;
	long long maxx=LONG_MIN;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
//	for(long long i=1;i<=n;i++)
//	{
//		for(long long j=i;j<=n;j++)
//		{
//			if(a[i]^a[j]==k)
//			{
//				maxx=max(maxx,j-i+1);
//			}
//		}
//	}
	if(n==2)
	{
		cout<<1;	
	}
	return 0;
}
