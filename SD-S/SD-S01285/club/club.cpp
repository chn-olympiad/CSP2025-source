#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> g[5];
const int N = 1e5 + 10;
int a[N][5], val[N];
int cnt[5];
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		g[1].clear(), g[2].clear(), g[3].clear();
		cnt[1] = cnt[2] = cnt[3] = 0;
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{ 
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			int maxid = 0;
			for (int j = 1; j <= 3; j++) if (a[i][j] >= a[i][maxid]) maxid = j;
			ans += a[i][maxid], g[maxid].emplace_back(i), cnt[maxid]++;
			int temp = 0;
			for (int j = 1; j <= 3; j++) if (a[i][j] >= temp && j != maxid) temp = a[i][j];
			val[i] = a[i][maxid] - temp;
		}
		int lim = n / 2;
		int id = 0;
		for (int j = 1; j <= 3; j++) if (cnt[j] >= cnt[id]) id = j;
		if (cnt[id] <= lim)
		{
			cout << ans << "\n";
			continue;
		}
		sort(g[id].begin(), g[id].end(), [](int A, int B) { return val[A] < val[B]; });
		int lft = cnt[id] - lim;
		for (int i = 0; i < lft; i++) ans -= val[g[id][i]];
		cout << ans << "\n";
	}
	return 0;
}
