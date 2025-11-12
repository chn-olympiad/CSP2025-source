#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],mod=998224353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long cnt=0,ans=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	cout<<cnt%mod;	
	return 0;
}
