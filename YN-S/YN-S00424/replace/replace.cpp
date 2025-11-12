// file memroy long long
// 16µã18·Ö 25pts

#include <bits/stdc++.h>
#include <ios>
#include <iostream>

using namespace std;

bool st;
map<pair<long long, long long>, int> M;
int OK[200010];

const long long mod = 998244853, P = 131;

long long H(string s)
{
	long long res = 0;
	for (int i = 0; i < (int)s.size(); i++)
	{
		res = (res * P + (s[i] - 'a' + 1)) % mod;
	}

	return res;
}

long long Pow[200010];

struct Hash_string
{
	long long Hash[200010];

	void reset(string s)
	{
		for (int i = 1; i <= (int)s.size(); i++)
		{
			Hash[i] = (Hash[i - 1] * P + (s[i - 1] - 'a' + 1)) % mod;
		}
	}

	long long substr(int l, int len)
	{
		int r = l + len - 1;
		return (Hash[r] - Hash[l - 1] * Pow[len] % mod + mod) % mod;
	}
};

string a, b;
Hash_string Ha, Hb;
bool en;

int main()
{
//	fprintf(stderr, "%.1lf", (&en - &st) / 1024.0 / 1024.0); // 5.3 MB

	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	Pow[0] = 1;
	for (int i = 1; i <= 200000; i++)
	{
		Pow[i] = Pow[i - 1] * P % mod;
	}

	int n, q;

	cin.tie(0);
	cin >> n >> q;

	for (int i = 1; i <= n; i++)
	{
		string x, y;
		cin >> x >> y;
		M[ {H(x), H(y)}]++;
//		fprintf(stderr, "%lld %lld\n", H(x), H(y));
	}

	for (int i = 1; i <= q; i++)
	{
		cin >> a >> b;

		OK[a.size()] = 1;
		for (int i = a.size() - 1; i >= 0; i--)
		{
			OK[i] = OK[i + 1] & (a[i] == b[i]);
		}

		Ha.reset(a);
		Hb.reset(b);

//		fprintf(stderr, "%d\n", i);

		int ans = 0, k = a.size();
		for (int l = 1; l <= k; l++)
		{
			for (int len = k - l + 1; len >= 1; len--)
			{
				if (OK[l + len - 1] == false)
				{
					break;
				}
				ans += M[ {Ha.substr(l, len), Hb.substr(l, len)}]; // TODO: Hash it;
//				if (M[ {Ha.substr(l, len), Hb.substr(l, len)}] != 0)
//				{
//				fprintf(stderr, "%d %d %lld %lld %d\n", l, len, Ha.substr(l, len), Hb.substr(l, len), M[ {Ha.substr(l, len), Hb.substr(l, len)}]);
//				}
			}
			if (a[l - 1] != b[l - 1])
			{
				break;
			}
		}

		printf("%d\n", ans);
//		fprintf(stderr, "%d\n", ans);
	}

	return 0;
}
