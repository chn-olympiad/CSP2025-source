#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
long long ans=1;
long long A(int a,int b)
{
	long long ret=1;
	for(int i=1;i<=b;i++)
		ret=(ret*(a-i+1))%mod;
	return ret;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=m;i<=n;i++)
	{
		ans=(ans+A(n,i))%mod;
	}
	cout<<ans;
	
	return 0;
}

