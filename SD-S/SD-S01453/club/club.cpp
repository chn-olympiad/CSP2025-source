#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100005;
int n, a[N][3], cnt[3], ty[N], w[N];
void Milthm() {
	for (int j = 0; j < 3; j++) {
		cnt[j] = 0;
	}
	scanf("%d", &n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int mx = 0;
		for (int j = 0; j < 3; j++) {
			scanf("%d", &a[i][j]);
			mx = max(mx, a[i][j]);
		}
		ans += mx;
		for (int j = 0; j < 3; j++) {
			if (a[i][j] == mx) {
				ty[i] = j;
				cnt[j]++;
				break;
			}
		}
	}
	int t = -1;
	for (int j = 0; j < 3; j++) {
		if (cnt[j] > n / 2) {
			t = j;
		}
	}
	if (t != -1) {
		int p = 0, q = 0;
		if (t == 0) {
			p = 1;
			q = 2;
		} else if (t == 1) {
			p = 0;
			q = 2;
		} else {
			p = 0;
			q = 1;
		}
		int m = 0;
		for (int i = 0; i < n; i++) {
			if (ty[i] == t) {
				int w1 = a[i][t] - a[i][p];
				int w2 = a[i][t] - a[i][q];
				w[m] = min(w1, w2);
				m++;
			}
		}
		int k = cnt[t] - n / 2;
		sort(w, w + m);
		for (int i = 0; i < k; i++) {
			ans -= w[i];
		}
	}
	printf("%d\n", ans);
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for (; t != 0; t--) {
		Milthm();
	}
	return 0;
}
/*
Ren5Jie4Di4Ling5%
时间复杂度: O(T n log n).
14:46 过小样例, club2 wa.
14:51 过大样例, 预期得分 100.
*/
