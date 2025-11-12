#include <bits/stdc++.h>
using namespace std;

long long read()
{
	long long ac = 0; char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') ac = (ac << 1) + (ac << 3) + c - 48, c = getchar();
	return ac;
}

long long n, a[5][100005], t, f[5][100005];

long long dp(int i, int j)
{
	if (f[i][j] != -1) return f[i][j];
	f[i][j] = max(dp(1, j - 1) + a[1][j], max(dp(2, j - 1) + a[2][j], dp(3, j - 1) + a[3][j]));
	return f[i][j];
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> t;
	while (t --)
	{
		n = read();
		for (int i = 1; i <= n; ++ i)
			a[1][i] = read(), a[2][i] = read(), a[3][i] = read(), f[1][i] = f[2][i] = f[3][i] = -1;
			
		f[1][0] = f[2][0] = f[3][0] = 0;
		
		if (n == 2)
		{
			long long ans = 0;
			for (int i = 1; i <= 3; ++ i)
				for (int j = 1; j <= 3; ++ j)
					if (i != j) ans = max(ans, a[i][1] + a[j][2]);
			cout << ans << "\n";
		}
		else cout << dp(1, n) << "\n";
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}