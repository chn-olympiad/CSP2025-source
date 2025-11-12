#include <bits/stdc++.h>
using namespace std;

struct Node {
	pair<int, int> stu[4];
} a[100010];

bool vis[100010];
int cnt[4];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		memset(cnt, 0, sizeof(cnt));
		memset(vis, 0, sizeof(vis));
		int n, ans = 0;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i].stu[1].first >> a[i].stu[2].first >> a[i].stu[3].first;
			a[i].stu[1].second = 1, a[i].stu[2].second = 2, a[i].stu[3].second = 3;
		}
		for (int i = 1; i <= n; ++i) {
			sort(a[i].stu + 1, a[i].stu + 4, [](const pair<int, int>& i, const pair<int, int>& j) {
				return i.first > j.first;
			});
		}
		for (int i = 1; i <= n; ++i) {
			if (cnt[a[i].stu[1].second] < n / 2) {
				ans += a[i].stu[1].first;
				cnt[a[i].stu[1].second]++;
			} else {
				bool flag = false;
				int idx = 0, mx = a[i].stu[2].first;
				for (int j = 1; j < i; ++j) {
					if (a[j].stu[1].second == a[i].stu[1].second) {
						if (a[j].stu[2].first + a[i].stu[1].first - a[j].stu[1].first > mx && !vis[j]) {
							flag = true;
							mx = a[j].stu[2].first + a[i].stu[1].first - a[j].stu[1].first;
							idx = j;
						}
					}
				}
				
				if (flag) {
					ans = ans + mx;
					vis[idx] = true;
					cnt[a[idx].stu[2].second]++;
					cnt[a[i].stu[1].second]++;
				} else {
					vis[i] = true;
					ans += a[i].stu[2].first;
					cnt[a[i].stu[2].second]++;
				}
					
			}
		}
		cout << ans << '\n';
	}
	return 0;
} 
