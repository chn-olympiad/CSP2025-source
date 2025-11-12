#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long t, n, a[N][3], f[2][N / 2][3];
long long ans;
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				scanf("%lld", &a[i][j]);
			}
		}
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n / 2; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					f[i&1][j][k] = max(f[i&1][j][k], f[i^1][j - 1][k] + a[i][k]);
				}
			}
		}
		ans = 0;
		for (int i = 0; i <= n / 2; i++)
		{
			for (int j = n / 2 - i; j <= n / 2; j++)
			{
				ans = max(ans, f[0][i][0] + f[0][j][1] + f[0][n - i - j][2]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

