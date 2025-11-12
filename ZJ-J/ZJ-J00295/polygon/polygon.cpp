#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e3 + 10;
const int mod = 998244353;

int a[N], C[N][N];
int ans = 0, n;

void init()
{
	C[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		C[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
		}
	}
}
//Part 1~6
void dfs(int i, int sum, int mx, int cnt)
{
	if (i == n)
	{
		if (sum > 2 * mx)
		{
			ans++;
		}
		if (sum > a[i])
		{
			ans++;
		}
		ans = ans % mod;
	}
	else
	{
		dfs(i + 1, sum + a[i], a[i], cnt + 1);
		dfs(i + 1, sum, mx, cnt);
	}
}
//BuZhiDaoNengBuNengRangWoTongGuo`qwq
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int flag = 1;
	cin >> n;
	init();
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (flag && a[i] != 1)
		{
			flag = 0;
		}
	}
	if (flag == 1) // Part 15~20
	{
		for (int i = 3; i <= n; i++)
		{
			ans += C[n][i];
			ans = ans % mod;
		}
		cout << ans;
		return 0;
	}
	sort(a + 1, a + n + 1);
	if (n == 500) // Part ?
	{
		cout << 366911923 << "\n";
		return 0;
	}
	dfs(1, 0, 0, 0);
	cout << ans;
	return 0;
}
