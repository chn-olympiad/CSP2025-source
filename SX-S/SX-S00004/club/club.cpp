#include <bits/stdc++.h>
using namespace std;
int a[100010][3];
int s[3] = {0, 0, 0}, ans = 0;
int n;
void dfs(int now, int sum)
{
	if (now > n)
	{
  		if (sum > ans)
  		{
			ans = sum;
		}
		return;
	}
	for (int i = 0; i < 3; i++)
	{

		if (s[i]+1 <= n/2)
		{
			++s[i];
			dfs(now + 1, sum + a[now][i]);
			--s[i];
		}
	}
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--)
	{
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < 3; j++)
				cin >> a[i][j];
		dfs(1, 0);
		cout << ans << endl;
	}
	return 0;
}