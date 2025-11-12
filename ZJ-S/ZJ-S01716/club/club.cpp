#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
	int x;
	int y;
	int z;
	int choose;
	int mines;
};
int T, n, tmp[100005];
node a[100005];
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--)
	{
		int tmp_cnt = 0;
		int cnt1 = 0;
		int cnt2 = 0;
		int cnt3 = 0;
		int ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i].x >> a[i].y >> a[i].z;
		for (int i = 1; i <= n; i++)
		{
			int maxn = max(a[i].x, max(a[i].y, a[i].z));
			if (maxn == a[i].x)
			{
				cnt1++;
				ans += a[i].x;
				a[i].choose = 1;
				if (a[i].y > a[i].z)
					a[i].mines = a[i].x - a[i].y;
				else
					a[i].mines = a[i].x - a[i].z;
			}
			else if (maxn == a[i].y)
			{
				cnt2++;
				ans += a[i].y;
				a[i].choose = 2;
				if (a[i].x > a[i].z)
					a[i].mines = a[i].y - a[i].x;
				else
					a[i].mines = a[i].y - a[i].z;
			}
			else
			{
				cnt3++;
				ans += a[i].z;
				a[i].choose = 3;
				if (a[i].x > a[i].y)
					a[i].mines = a[i].z - a[i].x;
				else
					a[i].mines = a[i].z - a[i].y;
			}
		}
		if (cnt1 > n / 2)
		{
			for (int i = 1; i <= n; i++)
			{
				if (a[i].choose == 1)
				{
					tmp_cnt++;
					tmp[tmp_cnt] = a[i].mines;
				}
			}
			sort(tmp + 1, tmp + tmp_cnt + 1);
			for (int i = 1; cnt1 - i >= n / 2; i++)
				ans -= tmp[i];
		}
		else if (cnt2 > n / 2)
		{
			for (int i = 1; i <= n; i++)
			{
				if (a[i].choose == 2)
				{
					tmp_cnt++;
					tmp[tmp_cnt] = a[i].mines;
				}
			}
			sort(tmp + 1, tmp + tmp_cnt + 1);
			for (int i = 1; cnt2 - i >= n / 2; i++)
				ans -= tmp[i];
		}
		else if (cnt3 > n / 2)
		{
			for (int i = 1; i <= n; i++)
			{
				if (a[i].choose == 3)
				{
					tmp_cnt++;
					tmp[tmp_cnt] = a[i].mines;
				}
			}
			sort(tmp + 1, tmp + tmp_cnt + 1);
			for (int i = 1; cnt3 - i >= n / 2; i++)
				ans -= tmp[i];
		}
		cout << ans << endl;
		for (int i = 1; i <= tmp_cnt; i++)
			tmp[i] = 0;
		for (int i = 1; i <= n; i++)
			a[i].x = a[i].y = a[i].z = a[i].choose = a[i].mines = 0;
	}
	return 0;
}