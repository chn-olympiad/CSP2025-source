#include <bits/stdc++.h>

using namespace std;

const int b = 813997, p = 1e9 + 7, M = 5e6 + 10;
char s[M], t[M];
long long pw[M];

map<int, int> mp;

long long qp(long long a, int b)
{
	long long r = 1;
	while (b)
	{
		if (b & 1) r = r * a % p;
		b >>= 1, a = a * a % p;
	}
	return r;
}

int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, q;
	cin >> n >> q;
	pw[0] = 1;
	for (int i = 1;i < M;i++)
		pw[i] = pw[i-1] * b % p;
	for (int i = 1;i <= n;i++)
	{
		cin >> (s + 1);
		int m = strlen(s + 1);
		long long x = 0;
		for (int j = 1;j <= m;j++)
			x = (x * b + s[j] - 'a') % p;
		cin >> (s + 1);
		m = strlen(s + 1);
		long long y = 0;
		for (int j = 1;j <= m;j++)
			y = (y * b + s[j] - 'a') % p;
		mp[x] = y;
	}
	while (q--)
	{
		cin >> (s + 1) >> (t + 1);
		int m = strlen(s + 1);
		long long ans = 0;
		long long c = 0, d = 0;
		for (int i = 1;i <= m;i++)
			c = (c * b + s[i] - 'a') % p, d = (d * b + t[i] - 'a') % p;
		long long x = 0, y = 0;
		for (int i = 1;i <= m;i++)
		{
			x = (x * b + s[i] - 'a') % p, y = (y * b + t[i] - 'a') % p;
			// cout << i << " " << x << " " << y << "\n";
			if ((((c - x * pw[m - i]) % p + p) % p) != (((d - y * pw[m - i]) % p + p) % p)) continue;
			long long e = 0, f = 0;
			for (int j = 1;j <= i;j++)
			{
				e = (e * b + s[j] - 'a') % p, f = (f * b + t[j] - 'a') % p;
				if (e == f && mp[((x - e * pw[j - i]) % p + p) % p] == ((y - f * pw[j - i]) % p + p) % p)
					ans++;
			}
		}
		cout << ans << "\n";
	}

	return 0;
}