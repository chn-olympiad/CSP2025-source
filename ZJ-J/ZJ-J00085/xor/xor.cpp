#include<bits/stdc++.h>
using namespace std;


int n, k, a[2005], ans, dp[1501][1501];

int check(int l, int r)
{
	int sum = 0;
	for (int i = l; i <= r; i++)
	{
		sum ^= a[i];
	}
	if (sum == k) return 1;
	else return 0;
}

void input()
{
	int sum = 0;
	for (int i = n - 1; i >= 1; i--)
	{
		for (int j = i + 1; j <= n; j++)
		{
			for (int k = i; k <= j; k++)
			{
				dp[i][j] = max(check(i, j), max(dp[i][j], dp[i][k] + dp[k + 1][j]));
			}
		}
	}
	cout << dp[1][n] << '\n';
	return ;
}

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0); cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		if (a[i] == k) dp[i][i] = 1;
	}
	input();
	return 0;
}
