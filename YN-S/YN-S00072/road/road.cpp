#include <iostream>
using namespace std;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k, a, b, c, d;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
	}
	for (int i = 1; i <= k; i++) {
		for (int i = 0; i <= n; i++) {
			cin >> d;
		}
	}
	for (int i = 1; i <= n; i++) {
		long long n, maxx = -100, cnt[4], ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			maxx = -1;
			maxx = max(a, max(b, c));
			if (maxx == a) {
				cnt[1]++;
			} else if (maxx == b) {
				cnt[2]++;
			} else {
				cnt[3]++;
			}
			if (cnt[1] <= n / 2 && cnt[2] <= n / 2 && cnt[3] <= n / 2) {
				ans += maxx;
			}
		}
		cout << ans << endl;
	}
	return 0;
}