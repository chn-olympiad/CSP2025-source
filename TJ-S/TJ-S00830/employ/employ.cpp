// stosto pingceji orzorz
// buyao WA TLE RE a
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a),END##i=(b);i<=END##i;++i)
#define pre(i,a,b) for(int i=(a),END##i=(b);i>=END##i;--i)
using namespace std;
typedef long long ll;
// Problem: employ
const int M = 998244353;
int n, m, a[505], p[505], ans; char s[505];
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, s + 1);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, n) p[i] = i;
	do
	{
		int t = 0;
		rep(i, 1, n)
		{
			if (t >= a[p[i]]) { ++ t; continue; }
			t += !(s[i] ^ 48);
		}
		if (n - t >= m) (++ ans) %= M;
	} while (next_permutation(p + 1, p + n + 1));
	printf("%d", ans);
	return 0;
}

