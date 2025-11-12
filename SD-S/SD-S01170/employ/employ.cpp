#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
signed main()
{
    freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin>>n;
	int sum=1;
	for(int i=1;i<=n;i++)
	{
		sum*=i;
		sum%=mod;
	}
	cout<<sum;
	return 0;
}

