#include"bits/stdc++.h"
#define int long long
using namespace std;
const int N = 1e5+5;
int t, n;
int a[N][4];
struct change {
	int d1, d2, id;
	bool operator<(const change &x)const {
		if (min(d1, d2) == min(x.d1, x.d2))
			return max(d1, d2) < max(x.d1, x.d2);
		return min(d1, d2) < min(x.d1, x.d2);
	}
};
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		long long cnt[4] = {0}, sum[4] = {0};
		for (int i = 1; i <= n; i++) {
			if (a[i][1] > a[i][2] && a[i][1] > a[i][3])
				cnt[1]++, sum[1] += a[i][1];
			else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3])
				cnt[2]++, sum[2] += a[i][2];
			else
				cnt[3]++, sum[3] += a[i][3];
		}
		if (cnt[1] <= n / 2 && cnt[2] <= n / 2 && cnt[3] <= n / 2) {
			cout << sum[1] + sum[2] + sum[3] << '\n';
			continue;
		}
		int over;
		if (cnt[1] > n / 2)
			over = 1;
		if (cnt[2] > n / 2)
			over = 2;
		if (cnt[3] > n / 2)
			over = 3;
		vector<change>sc;
		for (int i = 1; i <= n; i++) {
			int id1 = (over == 1 ? 2 : 1), id2 = (over == 3 ? 2 : 3);
			if (a[i][over] >= a[i][id1] && a[i][over] >= a[i][id2])
				sc.push_back({a[i][over] - a[i][id1], a[i][over] - a[i][id2], i});
		}
		sort(sc.begin(), sc.end());
		for (int i = 0; sc.size() - i - 1 >= n / 2; i++) {
			int id1 = (over == 1 ? 2 : 1), id2 = (over == 3 ? 2 : 3);
			if (sc[i].d1 < sc[i].d2 && cnt[id1] < n / 2)
				sum[over] -= a[sc[i].id][over], sum[id1] += a[sc[i].id][id1];
			else
				sum[over] -= a[sc[i].id][over], sum[id2] += a[sc[i].id][id2];
		}
		cout << sum[1] + sum[2] + sum[3] << '\n';
	}
	return 0;
}