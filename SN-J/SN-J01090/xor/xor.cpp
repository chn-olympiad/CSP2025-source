#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,k,a[500005],pos[1<<20],dp[500005];

signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 1;i <= n;i++) cin >> a[i];
	memset(pos,-1,sizeof(pos));
	pos[0] = 0;
	int now = 0;
	for (int i = 1;i <= n;i++)
	{
		now ^= a[i];
		dp[i] = dp[i-1];
		if (pos[now^k] != -1) dp[i] = max(dp[i],dp[pos[now^k]]+1);
		pos[now] = i;
	}
	cout << dp[n];
	return 0;
}
