#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
int n, a[5005], ans;
bool flag = 1;

void dfs(int p, int len, int cnt, int sum, int maxn)
{
	if (cnt == len)
	{
		if (sum > maxn * 2) ans++;
		return;
	}
	if (p == n + 1) return;
	if (n - p + 1 < len - cnt) return;
    dfs(p + 1, len, cnt + 1, sum + a[p], a[p]);
    dfs(p + 1, len, cnt, sum, maxn);
}

int solve()
{
	if (flag)
	{
		for (int len = 1; len <= n - 2; len++) ans = (ans + len) % mod;
		return ans;
	}
	sort(a + 1, a + n + 1);
	for (int len = 3; len <= n; len++) dfs(1, len, 0, 0, 0);
	return ans;
}                       
                                                         
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i], flag &= (i == 1 || a[i] == a[i - 1]);
	cout << solve() << "\n";
}