#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 505, mod = 998244353;

int n, m, ans10;
char s[N];
int c[N], a10[N], fact[N], inv[N];

int fastPow(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

int C(int n, int m)
{
	return ((fact[n] * inv[m]) % mod * inv[n - m]) % mod;
}

signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%lld%lld%s", &n, &m, s + 1);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &c[i]);
	fact[0] = 1;
	for (int i = 1; i < N; i++)
	{
		fact[i] = (fact[i - 1] * i) % mod;
		inv[i] = fastPow(fact[i], mod - 2);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (s[i] == '1') cnt++;
	if (n <= 10)
	{
		for (int i = 1; i <= n; i++)
			a10[i] = i;
		do
		{
			int cnt_lose = 0, cnt_win = 0;
			for (int i = 1; i <= n; i++)
			{
				if (cnt_lose >= c[a10[i]])
				{
					cnt_lose++;
					continue;
				}
				if (s[i] == '1') cnt_win++;
				else cnt_lose++;
			}
			if (cnt_win >= m) ans10++;
		} while (next_permutation(a10 + 1, a10 + n + 1));
		printf("%lld\n", ans10);
	}
	else if (cnt == n)
	{
		int cnt0 = 0;
		for (int i = 1; i <= n; i++)
			if (c[i] == 0) cnt0++;
		int cnt1 = n - cnt0, ans = 0;
		for (int i = m; i <= cnt1; i++)
		{
			int res = ((C(cnt1, i) * fact[i]) % mod) * fact[n - i] % mod;
//			cout<<C(cnt1,i)<<" "<<fact[i]<<" "<<fact[n - i]<<endl;
			ans = (ans + res) % mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
