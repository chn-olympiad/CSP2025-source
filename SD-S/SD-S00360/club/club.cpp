#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector <int> club[3];
		int cnt[3] = {0, 0, 0};
		long long ans = 0;
		for (int i = 0; i < n; ++i)
		{
			int tmp[3];
			cin >> tmp[0] >> tmp[1] >> tmp[2];
			if (tmp[0] >= tmp[1] && tmp[0] >= tmp[2])
			{
				++cnt[0];
				int cha = min(tmp[0] - tmp[1], tmp[0] - tmp[2]);
				club[0].push_back(cha);
				ans += tmp[0];
			}
			else if (tmp[1] > tmp[0] && tmp[1] >= tmp[2])
			{
				++cnt[1];
				int cha = min(tmp[1] - tmp[0], tmp[1] - tmp[2]);
				club[1].push_back(cha);
				ans += tmp[1];
			}
			else
			{
				++cnt[2];
				int cha = min(tmp[2] - tmp[0], tmp[2] - tmp[1]);
				club[2].push_back(cha);
				ans += tmp[2];
			}
		}
		int max_cnt = max(max(cnt[0], cnt[1]), cnt[2]);
		if (max_cnt <= n / 2) cout << ans << endl;
		else
		{
			int m = max_cnt - n / 2;
			int c;
			if (max_cnt == cnt[0]) c = 0;
			else if (max_cnt == cnt[1]) c = 1;
			else c = 2;
			sort(club[c].begin(), club[c].end());
			for (int i = 0; i < m; ++i)
			{
				ans -= club[c][i];
			}
			cout << ans << endl;
		}
	}
	return 0;
}
