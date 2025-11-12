#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;

long long t, n;
long long a[maxn], b[maxn], c[maxn], ans;
bool cmp (long long a, long long b)
{
	return a > b;
}
void dfs (long long now, long long siza, long long sizb, long long sizc, long long value)
{
	//cout << now << ' ' << siza << ' ' << sizb << ' ' << sizc << ' ' << value << ' ' << ans << '\n';
	if (siza > n / 2)
	{
		return;
	}
	if (sizb > n / 2)
	{
		return;
	}
	if (sizc > n / 2)
	{
		return;
	}
	if (now == n)
	{
		ans = max(ans, value);
		return;
	}
	dfs(now + 1, siza + 1, sizb, sizc, value + a[now + 1]);
	dfs(now + 1, siza, sizb + 1, sizc, value + b[now + 1]);
	dfs(now + 1, siza, sizb, sizc + 1, value + c[now + 1]);
	return;
}
int main ()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> t;
	while (t--)
	{
		cin >> n;
		ans = 0;
		long long sumc = 0, sumb = 0, suma = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i] >> b[i] >> c[i];
			suma += a[i], sumb += b[i], sumc += c[i];
		}
		long long o = 0;
		if (sumb == 0 && sumc == 0)
		{
			sort(a + 1, a + 1 + n, cmp);
			for (int i = 1; i <= n / 2; i++)
			{
				o += a[i];
			}
			cout << o << '\n';
			for (int i = 1; i <= n; i++)
			{
				a[i] = b[i] = c[i] = 0;
			}
			continue;
		}
		else if (suma == 0 && sumb == 0)
		{
			sort(a + 1, a + 1 + n, cmp);
			for (int i = 1; i <= n / 2; i+=1)
			{
				o += c[i];
			}
			cout << o << '\n';
			for (int i = 1; i <= n; i++)
			{
				a[i] = b[i] = c[i] = 0;
			}
			continue;
		}
		else if (suma == 0 && sumc == 0)
		{
			sort(b + 1, b + 1 + n, cmp);
			for (int i = 1; i <= n / 2; i++)
			{
				o += b[i];
			}
			cout << o << '\n';
			for (int i = 1; i <= n; i++)
			{
				a[i] = b[i] = c[i] = 0;
			}
			continue;
		}
		dfs(1, 1, 0, 0, a[1]);
		dfs(1, 0, 1, 0, b[1]);
		dfs(1, 0, 0, 1, c[1]);
		cout << ans << '\n';
		for (int i = 1; i <= n; i++)
		{
			a[i] = b[i] = c[i] = 0;
		}
	}
	return 0;
}

