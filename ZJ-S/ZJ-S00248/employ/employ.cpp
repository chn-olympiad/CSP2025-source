#include	<algorithm>
#include	<iostream>
#define		int		long long
using namespace std;
constexpr int maxn = 504;
constexpr int modd = 998244353;

int n, m;
int c[maxn];
int p[maxn];
char s[maxn];

signed main (void)
{
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	scanf ("%lld%lld%s", &n, &m, s + 1);
	if (m == 1)
	{
		int ans = 1;
		for (int i = 1; i <= n; i++)
			(ans *= i) %= modd;
		cout << ans << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)
		scanf ("%lld", c + i);
	for (int i = 1; i <= n; i++)
		p[i] = i;
	// for (int i = 1; i <= n; i++)
	// 	cout << p[i] << ' ';
	// cout << endl;
	int ans = 0;
	do
	{
		int sum = 0;
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if ((s[i] ^ '0') && cnt < c[p[i]])
				sum++;
			else
				cnt++;
		}
		// if (sum >= m)
		// {
		// 	for (int i = 1; i <= n; i++)
		// 		cout << c[p[i]] << ' ';
		// 	cout << sum << endl;
		// }
		(ans += sum >= m) %= modd;
		// if (c[p[1]] == 6 && c[p[2]] == 0 && c[p[3]] == 4 && c[p[4]] == 2 && c[p[5]] == 1 && c[p[6]] == 2 && c[p[7]] == 3 && c[p[8]] == 3 && c[p[9]] == 5 && c[p[10]] == 4)
		// {
		// 	int sum = 0;
		// 	int cnt = 0;
		// 	for (int i = 1; i <= n; i++)
		// 	{
		// 		if (s[i] ^ '0')
		// 			sum += cnt < c[p[i]];
		// 		else
		// 			cnt++;
		// 		cout << sum << ' ' << cnt << endl;
		// 	}
		// 	return 0;
		// }
	}
	while (next_permutation (p + 1, p + n + 1));
	cout << ans << endl;
	return 0;
}
