#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
long long t, n, a[100005][5], fnans;
vector <pair<long long, long long> > ans[5];
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	cout.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n;
		ans[1].clear();
		ans[2].clear();
		ans[3].clear();
		fnans = 0;
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= 3;j++)
			{
				cin >> a[i][j];
			}
			if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3])
			{
				ans[1].emplace_back(make_pair(a[i][1] - max(a[i][2], a[i][3]), a[i][1]));
			}
			else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3])
			{
				ans[2].emplace_back(make_pair(a[i][2] - max(a[i][1], a[i][3]), a[i][2]));
			}
			else
			{
				ans[3].emplace_back(make_pair(a[i][3] - max(a[i][1], a[i][2]), a[i][3]));
			}
			fnans += max(max(a[i][1], a[i][2]), a[i][3]);
		}
		for (int i = 1;i <= 3;i++)
		{
			if (ans[i].size() > n / 2)
			{
				sort(ans[i].begin(), ans[i].end());
				for (int j = 0;j < ans[i].size() - n / 2;j++)
				{
					fnans -= ans[i][j].first;
				}
			}
		}
		cout << fnans << "\n";
	}
	cout << endl;
	return 0;
}
