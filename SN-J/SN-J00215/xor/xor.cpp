#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int n, k, a[maxn], dp[maxn], pos[maxn], lst[maxn];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum^=a[i];
		if(pos[(sum^k)]==0&&(sum^k)!=0) lst[i]=-1;
		else lst[i]=pos[(sum^k)];
		pos[sum]=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(lst[i]==-1) dp[i]=dp[i-1];
		else dp[i]=max(dp[i-1], dp[lst[i]]+1);
	}
	cout<<dp[n];
	return 0;
}
