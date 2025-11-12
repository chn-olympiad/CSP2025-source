#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a[505];
const int MOD = 998244353;

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	ll ans = 1;
	for (int i = 1; i <= n; i++)
	{
		ans *= i;
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}

