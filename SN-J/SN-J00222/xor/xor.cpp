//tyy tyz 8z03
#include <bits/stdc++.h>
using namespace std;
int n , k , qzxor[500005] , dp[500005] , lst[1 << 20];
int main ()
{
	freopen ("xor.in" , "r" , stdin);
	freopen ("xor.out" , "w" , stdout);
	ios :: sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	cin >> n >> k;
	for (int i = 1;i <= n;i ++)
	{
		int a;
		cin >> a;
		qzxor[i] = qzxor[i - 1] ^ a;
	}
	lst[0] = 1;
	for (int i = 1;i <= n;i ++)
	{
		if (lst[k ^ qzxor[i]]) dp[i] = max (dp[i - 1] , dp[lst[k ^ qzxor[i]] - 1] + 1);
		else dp[i] = dp[i - 1];
		lst[qzxor[i]] = i + 1;
	}
	cout << dp[n];
	return 0;
}
