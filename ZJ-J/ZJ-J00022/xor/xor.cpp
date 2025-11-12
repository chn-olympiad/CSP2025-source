#include <bits/stdc++.h>
using namespace std;
#define ll long long

int a[500005];
int s[500005];
int dp[500005];
int n, k;

bool initA()
{
	if (k != 0) return 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] != 1) return 0;
	}
	cout << n / 2 << "\n";
	return 1;
}

bool initB()
{
	if (k > 1) return 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] > 1) return 0;
		cnt += a[i];
	}
	if (k == 0) cout << n - cnt << "\n";
	else cout << cnt << '\n';
	return 1;
}

bool check(int x, int y)
{
	if (x == y) return (a[x] == k);
	else return ((s[x] ^ s[y - 1]) == k ? 1 : 0);
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s[1] = a[1];
		if (i != 1) s[i] = s[i - 1] ^ a[i];
	}
	if (initA() || initB()) return 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j >= 1; j--)
		{
			dp[i] = max(dp[i], dp[j - 1] + check(i, j));
		}
		dp[i] = max(dp[i], dp[i - 1]);
	}
	cout << dp[n] << "\n";
	return 0;
}
