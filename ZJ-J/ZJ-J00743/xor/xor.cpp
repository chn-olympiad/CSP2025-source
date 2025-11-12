#include <bits/stdc++.h>

using namespace std;

int a[500010];
int sum[500010];
int dp[500010];
map<int,int> mx;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	int n,k;
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
		cin >> a[i];
		
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] ^ a[i];
		mx[k ^ sum[i]] = -1;
	}
	
	mx[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = max(dp[i],mx[k ^ sum[i]] + 1);
		dp[i] = max(dp[i],dp[i - 1]);
		mx[sum[i]] = max(mx[sum[i]],dp[i]);
	}
	
	cout << dp[n];
	
	return 0;
}