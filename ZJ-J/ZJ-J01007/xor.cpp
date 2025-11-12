#include <bits/stdc++.h>
using namespace std;

const int N = 5 * 1e6 + 5;
long long a[N], s[N], kk, ans;
void dg(long long lft, long long rgh, long long dep)
{
	long long l = lft;
	for (long long i = lft; i + dep - 1 <= rgh; i++)
	{
		if ((s[i - 1]^s[i + dep - 1]) == kk) 
		{
			ans++;
			dg(l, i - 1, dep + 1);
			l = i + dep;
			i = l - 1;
		}
	}
	if (l + dep <= rgh) dg(max(l - 1, lft), rgh, dep + 1);
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	long long n; cin >> n >> kk;
	for (long long i = 1; i <= n; i++)
		cin >> a[i];
	for (long long i = 1; i <= n; i++)
		s[i] = s[i - 1] ^ a[i];
	dg(1, n, 0);
	cout << ans << endl;
	return 0;
}
