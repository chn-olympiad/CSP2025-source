#include <bits/stdc++.h>
using namespace std;
#define file(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
#define int long long
int n, m;
int ans = 1;
const int mod = 998244353;
string s;
int c[505];
int res = 0;
signed main()
{
    file("employ");
    cin >> n >> m;
    cin >> s;
	for (int i = 1; i <= n; ++i)
	{
		cin >> c[i];
	}
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '1')
		{
			res++;
		}
	}
	for (int i = 1; i <= res; ++i)
	{
		ans *= i;
		ans %= mod;
	}
	cout << ans;
    return 0;
}


