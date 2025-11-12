// while (1) csp2025rp++;
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 1e5 + 10;

int n, a[maxn][3], ans, cmpnum;

void dfs(int index, int sum, int v1, int v2, int v3)
{
//	cout << "index=" << index << " sum=" << sum << " ";
//	for (int i = 0 ; i < 3 ; i++) cout << "v[" << i << "]=" << v[i] << " ";
//	cout << "\n";
	if (index == n)
	{
		ans = max(ans, sum);
		return;
	}

	if (v1 < cmpnum)
	{
		dfs(index + 1, sum + a[index + 1][0], v1 + 1, v2, v3);
	}
	if (v2 < cmpnum)
	{
		dfs(index + 1, sum + a[index + 1][1], v1, v2 + 1, v3);
	}
	if (v3 < cmpnum)
	{
		dfs(index + 1, sum + a[index + 1][2], v1, v2, v3 + 1);
	}
}

bool cmp(int x, int y)
{
	return x > y;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	int _;
	cin >> _;

	while (_--)
	{
		ans = -1e9;

		cin >> n;

		cmpnum = n / 2;

		memset(a, 0, sizeof(a));
		char pd = 0;
		for (int i = 0 ; i < n ; i++)
		{
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			if (a[i][1] != 0 || a[i][2] != 0) pd = 1;
		}

		if (pd)
		{
			int temp[n];
			for (int i = 0 ; i < n ; i++) temp[i] = a[i][0];
			sort(temp, temp + n, cmp);
			ans = 0;
			for (int i = 0 ; i < cmpnum ; i++)
			{
				ans += temp[i];
			}
		}

		dfs(0, a[0][0], 1, 0, 0);
		dfs(0, a[0][1], 0, 1, 0);
		dfs(0, a[0][2], 0, 0, 1);

		cout << ans << "\n";
	}

	return 0;
}
