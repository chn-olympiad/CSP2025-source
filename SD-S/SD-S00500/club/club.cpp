#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 5;
array<int, 5> a[N];
int n, cnt[5], ans;
void dfs(int x, int sum = 0)
{
	if (x > n)
	{
		ans = max(ans, sum);
		return;
	}
	for (int i = 1; i <= 3; i++)
	{
		if (cnt[i] < n / 2)
		{
			cnt[i]++;
			dfs(x + 1, sum + a[x][i]);
			cnt[i]--;
		}
	}
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		bool A = true, B = true;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			A = A && (a[i][2] == 0 && a[i][3] == 0);
			B = B && a[i][3] == 0;
		}
		ans = 0;
		if (n <= 10)
		{
			dfs(1);
			cout << ans;
		}
		else if (A)
		{
			nth_element(a + 1, a + n / 2, a + n + 1, greater<array<int, 5>>());
			for (int i = 1; i <= n / 2; i++) ans += a[i][1];
			cout << ans;
		}
		else if (B)
		{
			int cnt1 = 0, cnt2 = 0;
			for (int i = 1; i <= n; i++)
				if (a[i][1] > a[i][2])
					cnt1++;
				else
					cnt2++;
			if (cnt1 == cnt2)
				for (int i = 1; i <= n; i++)
					ans += max(a[i][1], a[i][2]);
			else
			{
				sort(a + 1, a + n + 1, [](const array<int, 5> &x, const array<int, 5> &y)
				{
					return abs(x[1] - x[2]) > abs(y[1] - y[2]);
				});
				cnt1 = 0, cnt2 = 0;
				for (int i = 1; i <= n; i++)
				{
					if (cnt1 == n / 2) ans += a[i][2];
					else if (cnt2 == n / 2) ans += a[i][1];
					else if (a[i][1] > a[i][2])
					{
						cnt1++;
						ans += a[i][1];
					}
					else
					{
						cnt2++;
						ans += a[i][2];
					}
				}
			}
			cout << ans;
		}
		else
		{
			sort(a + 1, a + n + 1, [](const array<int, 5> &x, const array<int, 5> &y)
			{
				int xmin, xmax;
				tie(xmin, xmax) = minmax({x[1], x[2], x[3]});
				int ymin, ymax;
				tie(ymin, ymax) = minmax({y[1], y[2], y[3]});
				return xmax - xmin > ymax - ymin;
			});
			cnt[1] = cnt[2] = cnt[3] = 0;
			int i, &cnt1 = cnt[1], &cnt2 = cnt[2], &cnt3 = cnt[3], p;
			int flag = 0;
			for (i = 1; i <= n; i++)
			{
				if (cnt1 == n / 2)
				{
					flag = 1;
					break;
				}
				else if (cnt2 == n / 2)
				{
					flag = 2;
					break;
				}
				else if (cnt3 == n / 2)
				{
					flag = 3;
					break;
				}
				else
				{
					p = max_element(a[i].begin() + 1, a[i].begin() + 4) - a[i].begin();
					cnt[p]++;
					ans += a[i][p];
				}
			}
			if (flag == 1)
			{
				sort(a + i, a + n + 1, [](const array<int, 5> &x, const array<int, 5> &y)
				{
					return abs(x[2] - x[3]) > abs(y[2] - y[3]);
				});
				for (int j = i; j <= n; j++)
				{
					if (cnt2 == n / 2) ans += a[j][3];
					else if (cnt3 == n / 2) ans += a[j][2];
					else if (a[j][2] > a[j][3])
					{
						cnt2++;
						ans += a[j][2];
					}
					else
					{
						cnt3++;
						ans += a[j][3];
					}
				}
			}
			else if (flag == 2)
			{
				sort(a + i, a + n + 1, [](const array<int, 5> &x, const array<int, 5> &y)
				{
					return abs(x[1] - x[3]) > abs(y[1] - y[3]);
				});
				for (int j = i; j <= n; j++)
				{
					if (cnt1 == n / 2) ans += a[j][3];
					else if (cnt3 == n / 2) ans += a[j][1];
					else if (a[j][1] > a[j][3])
					{
						cnt1++;
						ans += a[j][1];
					}
					else
					{
						cnt3++;
						ans += a[j][3];
					}
				}
			}
			else if (flag == 3)
			{
				sort(a + i, a + n + 1, [](const array<int, 5> &x, const array<int, 5> &y)
				{
					return abs(x[1] - x[2]) > abs(y[1] - y[2]);
				});
				for (int j = i; j <= n; j++)
				{
					if (cnt1 == n / 2) ans += a[j][2];
					else if (cnt2 == n / 2) ans += a[j][1];
					else if (a[j][1] > a[j][2])
					{
						cnt1++;
						ans += a[j][1];
					}
					else
					{
						cnt2++;
						ans += a[j][2];
					}
				}
			}
			cout << ans;
		}
		cout << '\n';
	}
	return 0;
}
