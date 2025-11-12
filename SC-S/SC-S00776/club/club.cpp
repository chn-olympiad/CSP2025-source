#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N = 1e5;
int t;
struct peo{
	ll num;
	ll mo;
	ll mt;
	ll mr;
}a[N + 5];
bool cmp1 (peo b, peo c)
{
	return b.mo > c.mo;
}
bool cmp2 (peo b, peo c)
{
	return b.mt > c.mt;
}
bool cmp3 (peo b, peo c)
{
	return b.mr > c.mr;
}
int main ()
{
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		bool f = 1;
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i].mo >> a[i].mt >> a[i].mr;
			if (a[i].mt != 0 || a[i].mr) f = 0;
		}
		if (n == 2)
		{
			int d, e;
			if (a[1].mo > a[1].mt && a[1].mo > a[1].mr) d = 1;
			else if (a[1].mt > a[1].mo && a[1].mt > a[1].mr) d = 2;
			else if (a[1].mr > a[1].mt && a[1].mr > a[1].mo) d = 3;
			else if (a[1].mo == a[1].mt) d = 12;
			else if (a[1].mo == a[1].mr) d = 13;
			else d = 23;
			if (a[2].mo > a[2].mt && a[2].mo > a[2].mr) e = 1;
			else if (a[2].mt > a[2].mo && a[1].mt > a[2].mr) e = 2;
			else if (a[2].mr > a[2].mt && a[1].mr > a[2].mo) e = 3;
			else if (a[2].mo == a[2].mt) e = 12;
			else if (a[2].mo == a[2].mr) e = 13;
			else e = 23;
			if (d != e)
			{
				cout << max (max (a[1].mo, a[1].mt), a[1].mr) + max (max (a[2].mo, a[2].mt), a[2].mr) << endl;
				continue;
			}
			else
			{
				if (d == 1)
				{
					cout << max (a[1].mo + max (a[2].mr, a[2].mt), a[2].mo + max (a[1].mr, a[1].mt)) << endl;
					continue;
				}
				else if (d == 2)
				{
					cout << max (a[1].mt + max (a[2].mr, a[2].mo), a[2].mt + max (a[1].mr, a[1].mo)) << endl;
					continue;
				}
				else if (d == 3)
				{
					cout << max (a[1].mr + max (a[2].mt, a[2].mo), a[2].mr + max (a[1].mt, a[1].mo)) << endl;
					continue;
				}
				else if (d == 12)
				{
					cout << a[1].mo + a[2].mt << endl;
					continue;
				}
				else if (d == 13)
				{
					cout << a[1].mo + a[2].mr << endl;
					continue;
				}
				else if (d == 23)
				{
					cout << a[1].mr + a[2].mt << endl;
					continue;
				}
			}
		}
		else if (f)
		{
			sort (a + 1, a + n + 1, cmp1);
			ll ans = 0;
			for (int i = 1; i <= n / 2; ++i)
			{
				ans += a[i].mo;
			}
			cout << ans << endl;
		}
		else
		{
			vector <ll> u(N + 5);
			vector <ll> v(N + 5);
			vector <ll> w(N + 5);
			ll ans = 0;
			int x = 1, y = 1, z = 1;
			for (int i = 1; i <= n; ++i)
			{
				u[i] = a[i].mo;
				v[i] = a[i].mt;
				w[i] = a[i].mr;
			}
			sort (a + 1, a + n + 1, cmp1);
			for (int i = 1; i <= n; ++i)
			{
				if (x - 1 > n / 2) break;
				if (a[i].mo >= a[i].mt && a[i].mo > a[i].mr)
				{
					u[x++] = a[i].mo;
					a[i].mt = -1;
					a[i].mr = -1;
				}
			}
			sort (a + 1, a + n + 1, cmp2);
			for (int i = 1; i <= n; ++i)
			{
				if (y - 1 > n / 2) break;
				if (a[i].mt >= a[i].mo && a[i].mt > a[i].mr)
				{
					u[y++] = a[i].mt;
					a[i].mo = -1;
					a[i].mr = -1;
				}
			}
			sort (a + 1, a + n + 1, cmp3);
			for (int i = 1; i <= n; ++i)
			{
				if (z - 1 > n / 2) break;
				if (a[i].mr >= a[i].mo && a[i].mr > a[i].mt)
				{
					u[z++] = a[i].mr;
					a[i].mt = -1;
					a[i].mo = -1;
				}
			}
			for (int i = 1; i < x; ++i)
			{
				ans += u[i];
			}
			for (int i = 1; i < y; ++i)
			{
				ans += v[i];
			}
			for (int i = 1; i < z; ++i)
			{
				ans += w[i];
			}
			cout << ans << endl;
			continue;
		}
	}
	return 0;
}