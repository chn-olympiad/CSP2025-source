#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
long long n, k;
long long a[MAXN];
long long Xor[MAXN];
struct ANS
{
	int l, r;
}Ans[MAXN];
int cur = 0;
int dp[3005][3005];

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	// i ~ j
	//cout << "#############################################\n";
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			if (i == j)
			{
				Xor[j] = a[j];
				if (Xor[j] == k) Ans[++cur] = {i, j}, dp[i][j] = 1;
			}
			else
			{
				Xor[j] = Xor[j - 1] ^ a[j];
				if (Xor[j] == k) Ans[++cur] = {i, j}, dp[i][j] = 1;
			}
			//cout << Xor[j] << " ";
		}
		//cout << endl;
	}
	/*
	cout << "#############################################\n";
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}
	cout << "#############################################\n";
	*/
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = dp[i - 1][i - 1] + dp[i][j];
			dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
		}
	/*
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}
	cout << "#############################################\n";
	*/
	cout << dp[n][n];
	return 0;
}
