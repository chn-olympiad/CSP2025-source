#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int K = 2e6;
int n,k;
int a[N];
int dp[N];
int lst[K];
int pre[N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],pre[i]=pre[i-1]^a[i];
	memset(lst,-1,sizeof lst);
	lst[0]=0;
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		if(~lst[pre[i]^k]) dp[i]=max(dp[i],dp[lst[pre[i]^k]]+1);
		lst[pre[i]]=i;
	}
	cout<<dp[n];
	return 0;
}
