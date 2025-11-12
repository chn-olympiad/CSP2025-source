#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
long long num[MAXN*10 + 100];
long long n, k;
int dp(int level, int s, int ans);
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> num[i];
	}
	if(num[1] == 1 && num[n] == 1)
	{
		cout << n/2 << endl;
	}
	else
	{
		if(k != 0) cout << dp(1, 0, 0) << endl;
		else cout << dp(1, 0, 0)-1 << endl;
	}
	return 0;
}
int dp(int level, int s, int ans)
{
	if(level > n) return ans;
	int x, y;
	if(level != 1)
	{
		if(num[level] xor s == k)
		{
			x = dp(level+1, 0, ans+1);
		}
		else
		{
			x = dp(level+1, num[level] xor s, ans);
		}
	}
	y = dp(level+1, 0, ans);
	if(x > y) return x;
	return y;
}
