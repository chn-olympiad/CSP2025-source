#include <bits/stdc++.h>
using namespace std;

long long a[5005], sum[5005][5005];
const long long mod = 998244353;
long long maxa[5005][5005];

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	long long ans = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		maxa[i][i] = a[i];
		sum[i][i] = a[i];
		//cout << maxa[i][i] << " " << sum[i][i] << endl;
		for (int j = i + 1; j <= n; j++)
		{
			maxa[i][j] = max(maxa[i][j - 1], a[j]);
			sum[i][j] = sum[i][j - 1] + a[j];
			//cout << maxa[i][j] << " " << sum[i][j] << endl;
		}
	}
	for (int i = 1; i <= n - 2; i++)
	{
		for (int j = i + 2; j <= n; j++)
		{
			if (sum[i][j] > 2 * maxa[i][j])
			{
				ans++;
				ans %= mod;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
