#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 1e5 + 10;
int t, n;
vector<pair<int, int>> a[maxn];
bool cmp(vector<pair<int, int>> &a, vector<pair<int, int>> &b) {
	return a[0].first - a[1].first < b[0].first - b[1].first;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 0; i < n; i++) {
			a[i].clear();
			for(int j = 0; j < 3; j++) {
				int x;
				cin >> x;
				a[i].push_back({x, j});
			}
			sort(a[i].begin(), a[i].end(), greater<pair<int, int>>());
		}
		int ans = 0, cnt[3] = {0, 0, 0};
		for(int i = 0; i < n; i++) {
			ans += a[i][0].first;
			cnt[a[i][0].second]++;
		}
		int maxcnt = 0, maxclub = -1;
		for(int j = 0; j < 3; j++) {
			if(cnt[j] > maxcnt) {
				maxcnt = cnt[j];
				maxclub = j;
			}
		}
		if(maxcnt <= n / 2) {
			cout << ans << endl;
			continue;
		}
		sort(a, a + n, cmp);
		for(int i = 0; i < n; i++) {
			if(a[i][0].second == maxclub) {
				maxcnt--;
				ans -= a[i][0].first - a[i][1].first;
				if(maxcnt <= n / 2) break;
			}
		}
		cout << ans << endl;
	}

	return 0;
}
