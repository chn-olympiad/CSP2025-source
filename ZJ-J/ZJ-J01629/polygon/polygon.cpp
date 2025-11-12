// O(n^2)
// 264pts now
// maybe 2=
#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n;
int a[5005], maks;
long long ans;

long long multi1(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	return (n * multi1(n - 1)) % mod;
}

long long C(int n, int m)
{
	/*
	 m
	C
	 n
	*/
	if (m > n / 2)
	{
		m = n - m;
	}
	return multi1(n) / multi1(n - m) / multi1(m) % mod;
}

void dfs(int step, int nums, int sum, int mx)
{
	if (nums >= 3 && sum > mx * 2)
	{
		++ans;
		ans %= mod;
	}
	if (step == n)
	{
		return;
	}
	for (int i = step + 1; i <= n; ++i)
	{
		dfs(i, nums + 1, sum + a[i], max(mx, a[i]));
	}
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		maks = max(maks, a[i]);
	}
	sort(a + 1, a + 1 + n);
	if (maks == 1)
	{
		// 6/25(24pts)
		for (int i = 3; i <= n; ++i)
		{
			ans += C(n, i) % mod;
			ans %= mod;
		}
	}
	else
	{
		// 10/25(40pts)
		for (int i = 1; i <= n - 2; ++i)
		{
			dfs(i, 1, a[i], a[i]);
		}
	}
	// 64pts all
	cout << ans;
	return 0;

}
