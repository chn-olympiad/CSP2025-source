#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, cnt[4], id, T, a[N][4], ans, c[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		ans = 0, id = 0, cnt[1] = cnt[2] = cnt[3] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			int maxx = max(a[i][1], max(a[i][2], a[i][3]));
			if (maxx == a[i][1])
				cnt[1]++;
			else if (maxx == a[i][2])
				cnt[2]++;
			else
				cnt[3]++;
			ans += maxx;
		}
		int res = max(cnt[1], max(cnt[2], cnt[3]));
		if (res == cnt[1])
			id = 1;
		else if (res == cnt[2])
			id = 2;
		else
			id = 3;
		if (res <= n / 2) {
			cout << ans << "\n";
		} else {
			int tot = 0;
			for (int i = 1; i <= n; i++) {
				int maxx = max(a[i][1], max(a[i][2], a[i][3]));
				if (maxx == a[i][id]) {
					vector<int>tmp;
					tmp.push_back(a[i][1]);
					tmp.push_back(a[i][2]);
					tmp.push_back(a[i][3]);
					sort(tmp.begin(), tmp.end());
					c[++tot] = tmp[2] - tmp[1];
				}
			}
			sort(c + 1, c + 1 + tot);
			for (int i = 1; i <= tot; i++) {
				if (res <= n / 2)
					break;
				res--;
				ans -= c[i];
			}
			cout << ans << "\n";
		}
	}
	return 0;
}