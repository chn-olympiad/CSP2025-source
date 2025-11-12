#include<bits/stdc++.h>
using namespace std;

struct node { int a, b, c; } s[200005];
int t, n, ans;

void dfs(int p, int cnt1, int cnt2, int cnt3, int sum)
{
	if (cnt1 > n / 2 || cnt2 > n / 2 || cnt3 > n / 2) return;
	if (p == n + 1)
	{
		ans = max(ans, sum);
		return;
	}
	dfs(p + 1, cnt1 + 1, cnt2, cnt3, sum + s[p].a);
	dfs(p + 1, cnt1, cnt2 + 1, cnt3, sum + s[p].b);
	dfs(p + 1, cnt1, cnt2, cnt3 + 1, sum + s[p].c);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--)
	{
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> s[i].a >> s[i].b >> s[i].c;
		dfs(1, 0, 0, 0, 0);
		cout << ans << "\n";
	}
}