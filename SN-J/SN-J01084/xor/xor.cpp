//SN-J01084 menkeming xi'anfulunzhongxue
#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,k,a[500010],s[5000010],dp[500010];
map<int,int>mp;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],s[i]=s[i-1]^a[i];
	for(int i=1;i<=n;i++)
	{
		mp[s[i]]=i;
		dp[i]=max(dp[i-1],dp[i]);
		if(mp[s[i]^k]==i&&s[i]!=0)
			continue;
		if((s[mp[s[i]^k]]^s[i])!=k)
			continue;
		dp[i]=max(dp[i],dp[mp[s[i]^k]]+1);
	}
	cout<<dp[n];
	return 0;
}
