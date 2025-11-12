#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int s[500005],dp[500005];
int last[(1<<20)+5];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<(1<<20);i++)
		last[i]=-0x3f3f3f3f;
	last[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		dp[i]=dp[i-1];
		if(last[s[i]^k]!=-0x3f3f3f3f)
			dp[i]=max(dp[i],dp[last[s[i]^k]]+1);
		last[s[i]]=i;
	}
	cout<<dp[n];
	return 0;
}
