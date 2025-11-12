#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n, c[5], mem[N][5], ans, a[N][5], sum;
void dfs(int pu, int cu)
{
	c[cu] ++;
	sum += a[pu][cu];
	if (cu > 3)
	{
		return;
	}
	if (mem[pu][cu])
	{
		return;
	}
	if (c[1]*2 > n || c[2]*2 > n || c[3]*2 > n)
	{
		return;
	}
	if (c[1]+c[2]+c[3] == n)
	{
		ans = max(ans, sum);
		return;
	}
	if (c[1]+c[2]+c[3] > n) return;
	mem[pu][cu] = true;
	dfs(pu+1, 1);
	dfs(pu, cu+1);
	mem[pu][cu] = false;
	sum -= a[pu][cu];
	c[cu] --;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	int T; cin >> T;
	while (T--)
	{
		memset(c, 0, sizeof(c)); memset(mem, 0, sizeof(mem));
		cin >> n; ans = 0;
		for (int i = 1; i <= n; i++) cin >> a[i][1] >> a[i][2] >> a[i][3];
		dfs(1, 1);
		cout << ans << '\n';
	}
}