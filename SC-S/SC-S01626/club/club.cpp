#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

constexpr int N = 1e5 + 5;
int T;
int n, a[N][4];
int dj[4][N], idx[4];
ll fnl;
int cnt[4];

inline void solve () {
	cin >> n;
	idx[1] = idx[2] = idx[3] = 0;
	cnt[1] = cnt[2] = cnt[3] = 0;
	fnl = 0;
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i][1] >> a[i][2] >> a[i][3];
		if (a[i][1] >= a[i][2] and a[i][1] >= a[i][3]) {
			fnl += a[i][1];
			cnt[1] ++;
			dj[1][++ idx[1]] = max(a[i][2], a[i][3]) - a[i][1];
		} else if (a[i][2] >= a[i][1] and a[i][2] >= a[i][3]) {
			fnl += a[i][2];
			cnt[2] ++;
			dj[2][++ idx[2]] = max(a[i][1], a[i][3]) - a[i][2];
		} else if (a[i][3] >= a[i][1] and a[i][3] >= a[i][2]) {
			fnl += a[i][3];
			cnt[3] ++;
			dj[3][++ idx[3]] = max(a[i][1], a[i][2]) - a[i][3];
		}
	}
	if (max({idx[1], idx[2], idx[3]}) <= n / 2) {
		cout << fnl << '\n';
		return;
	}
	if (idx[1] > n / 2) {
		sort(dj[1] + 1, dj[1] + idx[1] + 1);
		for (int i = idx[1]; i > n / 2; -- i) fnl += dj[1][i];
	} else if (idx[2] > n / 2) {
		sort(dj[2] + 1, dj[2] + idx[2] + 1);
		for (int i = idx[2]; i > n / 2; -- i) fnl += dj[2][i];
	} else if (idx[3] > n / 2) {
		sort(dj[3] + 1, dj[3] + idx[3] + 1);
		for (int i = idx[3]; i > n / 2; -- i) fnl += dj[3][i];
	}
	cout << fnl << '\n';
}

int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T --) solve();
	return 0;
}