#include <iostream>
#include <cstdio>
using namespace std;
int ans = 0, n, a[100005][4];
void dfs(int x, int cnt1, int cnt2, int cnt3, int sum)
{
	if (x > n)
	{
		ans = max(ans, sum);
		return;
	}
	if (cnt1 < n / 2) dfs(x + 1, cnt1 + 1, cnt2, cnt3, sum + a[x][1]);
	if (cnt2 < n / 2) dfs(x + 1, cnt1, cnt2 + 1, cnt3, sum + a[x][2]);
	if (cnt3 < n / 2) dfs(x + 1, cnt1, cnt2, cnt3 + 1, sum + a[x][3]);
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		dfs(1, 0, 0, 0, 0);
		cout << ans << endl;
		ans = 0;
	}
    return 0;
}
