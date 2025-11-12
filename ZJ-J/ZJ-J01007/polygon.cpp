#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
long long a[N], n, ans;
void dg(long long sum, long long maxn, long long dep, long long cnt)
{
	if (dep > n) 
	{
		if (sum > maxn * 2 && cnt >= 3) ans++;
		ans %= 998244353;
		return ;
	}
	dg(sum + a[dep], max(maxn, a[dep]), dep + 1, cnt + 1);
	dg(sum, maxn, dep + 1, cnt);
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (long long i = 1; i <= n; i++)
		cin >> a[i];
	if (n <= 20) 
	{
		dg(0, 0, 1, 0);
		cout << ans % 998244353 << endl;
	}
	else cout << 0 << endl;
	return 0;
}
