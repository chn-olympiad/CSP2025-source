#include <bits/stdc++.h>
using namespace std;
long long n,m,ans=1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=m;i++)
	{
		ans*=(n-i+1);
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}
