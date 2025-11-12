#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e5;
ll n, q;
struct pl{
	string a, b;
}s[N + 5], z[N + 5];
int main ()
{
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	bool f;
	for (int i = 1; i <= n; ++i)
	{
		cin >> s[i].a >> s[i].b;
		for (int j = 0; j < s[i].a.size (); ++j)
		{
			if (s[i].a[j] != 'a' || s[i].a[j] != 'b' || s[i].b[j] != 'a' || s[i].a[j] != 'b')
			{
				f = 0;
			}
		}
	}
	for (int i = 1; i <= q; ++i)
	{
		cin >> z[i].a >> z[i].b;
		for (int j = 0; j < z[i].a.size (); ++j)
		{
			if (z[i].a[j] != 'a' || z[i].a[j] != 'b')
			{
				f = 0;
			}
		}
		for (int j = 0; j < z[i].b.size (); ++j)
		{
			if (z[i].b[j] != 'a' || z[i].b[j] != 'b')
			{
				f = 0;
			}
		}
	}
	if (f)
	{
		for (int i = 1; i <= q; ++i)
		{
			cout << n << '\n';
		}
	}
	else
	{
		for (int i = 1; i <= q; ++i)
		{
			cout << 0 << '\n';
		}
	}
	return 0;
} 