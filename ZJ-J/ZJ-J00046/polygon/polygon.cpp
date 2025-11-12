#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int Mod = 998244353;
const int N = 5e3 + 5;

int a[N], C[N][N], c[N];

void init()
{
	C[1][1] = 1;
	for(int i = 2; i <= N - 4; i++)
		for(int j = 1; j <= i; j++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % Mod;
	for (int i = 1; i <= N - 4; i++)
	{
		c[i] = c[i - 1];
		for (int j = 2; j <= i; j++)
			c[i] = (c[i] + C[i][j]) % Mod;
//		printf("%d ", c[i]);
	}
	return;
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	int n, ans = 0;
	scanf("%d", &n);
	
	init();
	
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
	}
	
	sort(a + 1, a + 1 + n);
	
	int sum = a[1] + a[2];
	
	for (int i = 3; i <= n; i++)
	{
		if(sum <= a[i])
		{
			sum += a[i];
			continue;
		}
			
		vector<int> dp(a[i] + 1);
		for (int j = 1; j < i; j++)
			for(int k = j + 1; k < i; k++)
				if(a[j] + a[k] <= a[i])
					dp[a[j] + a[k]]++;
		for (int j = 1; j < i; j++)
			for (int k = a[i]; k >= a[j]; k--)
				dp[k] = (dp[k - a[j]] + dp[k]) % Mod;
		ans = (ans + c[i - 1] - dp[a[i]]) % Mod;
		sum += a[i];
	}	
	
	printf("%d", ans);
	
	return 0;
}
