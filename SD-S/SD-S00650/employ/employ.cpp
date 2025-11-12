#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
const int N = 5e2 + 10;
const int mod = 998244353;

int s[N];
int p[N];
int c[N];

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		char c;
		cin >> c;
		s[i] = c - '0';
	}
	for (int i = 1; i <= n; ++i)
		cin >> c[i];
	if (n <= 10)
	{
		for (int i = 1; i <= n; ++i)
			p[i] = i;
		int ans = 0;
		do
		{
			int cant = 0;
			for (int i = 1; i <= n; ++i)
			{
				if (cant >= c[p[i]] || s[i] == 0)
					cant++;
			}
			if (n - cant >= m)
				ans++;
		} while (std::next_permutation(p + 1, p + n + 1));
		cout << ans << '\n';
	}
	else
	{
		int k = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (c[i] < 1)
				k++;
		}
		int mul = 1;
		for (int i = 1; i <= n - 1; ++i)
			mul = 1ll * mul * i % mod;
		cout << 1ll * k * mul % mod;
	}
	return 0;
}
