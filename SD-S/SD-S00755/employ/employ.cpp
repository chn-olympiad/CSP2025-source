#include<bits/stdc++.h>
#define int long long 
using namespace std;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n;
	cin>>n;
	int ans=1; 
	for(int i=1;i<=n;i++)
	{
		ans*=i;
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}

