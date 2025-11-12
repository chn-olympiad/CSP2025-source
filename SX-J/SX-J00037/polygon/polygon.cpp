#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=998244353;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ll n,ans=0;
	cin>>n;
	for(int i=3;i<=n;i++)
	{
		ll sum=1;
		for(int j=n;j>=n-i+1;j--)
		{
			sum=sum*j/(n+1-j)%N;
		}
		ans=(ans+sum)%N;
	}
	cout<<ans;
	return 0;
}
