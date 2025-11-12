#include <bitset>
#include <string>
#include <numeric>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
constexpr int MAXN = 505;
constexpr LL MOD = 998244353;
int n, m, c[MAXN];
bitset<MAXN> s;

namespace BF{

//constexpr int RMAXN = 18;
//int sum0[RMAXN];
//LL f[2][RMAXN + 5][1 << RMAXN];

int od[MAXN];

void Solve()
{
	/*
	for (int i = 1; i <= n; i++)
		sum0[i] = sum0[i - 1] + (s[i] == false);
	
	f[0][0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int s = 0; s < (1 << n); s++)
		{
			for (int j = 1; j <= __builtin_popcount(s); j++)
			{
				for (int k = 1; k <= n; k++)
				{
					if (!((s >> (k - 1)) & 1)) continue;
					if (s[k] < c[i])
					{
						f[i & 1][j][s] += f[i - 1]
					}
				}
			}
		}
	}
	*/
	
	int ans = 0;
	iota(od + 1, od + n + 1, 1);
	do
	{
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (c[od[i]] > i - cnt - 1 && s[i]) cnt++;
		if (cnt >= m) ans++;
	}
	while (next_permutation(od + 1, od + n + 1));
	cout << ans << '\n';
	return;
}

} //namespace BF

namespace SFA{

void Solve()
{
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (c[i] > 0) cnt++;
	cerr << cnt << '\n';
	if (cnt >= m)
	{
		LL ans = 1;
		for (int i = 1; i <= n; i++)
			(ans *= i) %= MOD;
		cout << ans << '\n';
	}
	else cout << 0 << '\n';
	return;
}

} //namespace SFA

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m;
	string rs; cin >> rs;
	for (int i = 1; i <= n; i++)
	{
		s[i] = (bool)(rs[i - 1] - '0');
		cin >> c[i];
	}
	BF::Solve();
	return 0;
}