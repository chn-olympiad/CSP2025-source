// 沒有別的選擇了，我必須贏
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 101000;

int n, a[N][4], mx[N][2], b[N];
ll ans = 0;
vector<int> cnt[4];

void solve() {
	cnt[1].clear();
	cnt[2].clear();
	cnt[3].clear();
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
		mx[i][0] = max(max(a[i][1], a[i][2]), a[i][3]);
		if (mx[i][0] == a[i][1]) {
			mx[i][1] = max(a[i][2], a[i][3]);
			b[i] = 1;
		} else if (mx[i][0] == a[i][2]) {
			mx[i][1] = max(a[i][1], a[i][3]);
			b[i] = 2;
		} else {
			mx[i][1] = max(a[i][1], a[i][2]);
			b[i] = 3;
		}
	}
	ans = 0;
	for (int i = 1; i <= n; i++) {
		cnt[b[i]].push_back(mx[i][0] - mx[i][1]);
		ans += mx[i][0];
	}
	if (cnt[1].size() > n / 2) {
		sort(cnt[1].begin(), cnt[1].end());
		int len = cnt[1].size(), i = 0;
		while (len - i > n / 2) {
			ans -= cnt[1][i];
			i++;
		}
	} else if (cnt[2].size() > n / 2) {
		sort(cnt[2].begin(), cnt[2].end());
		int len = cnt[2].size(), i = 0;
		while (len - i > n / 2) {
			ans -= cnt[2][i];
			i++;
		}
	} else if (cnt[3].size() > n / 2) {
		sort(cnt[3].begin(), cnt[3].end());
		int len = cnt[3].size(), i = 0;
		while (len - i > n / 2) {
			ans -= cnt[3][i];
			i++;
		}
	}
	printf("%lld\n", ans);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) solve();
}
