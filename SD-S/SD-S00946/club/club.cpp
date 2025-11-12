#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
namespace {
using namespace std;
const int N = 1e5 + 5, INF = 0x7f7f7f7f;
int T, n, a[N][3], c[3], ans;
priority_queue<int> Q[3];
} // namespace 
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	while (T--) {
		cin >> n, ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < 3; j++) cin >> a[i][j];
		for (int i = 0; i < 3; i++) c[i] = 0, priority_queue<int>{}.swap(Q[i]);
		int p0 = -1;
		for (int i = 1; i <= n; i++)
			if (!~p0) {
				int p1 = max_element(a[i], a[i] + 3) - a[i], x = a[i][p1];
				a[i][p1] = ~INF;
				int p2 = max_element(a[i], a[i] + 3) - a[i], y = a[i][p2];
				ans += x, Q[p1].emplace(y - x);
				if (++c[p1] == n / 2) p0 = p1;
			} else {
				a[i][p0] += Q[p0].top();
				int p1 = max_element(a[i], a[i] + 3) - a[i], x = a[i][p1];
				if (p1 == p0) {
					a[i][p1] = ~INF;
					int p2 = max_element(a[i], a[i] + 3) - a[i], y = a[i][p2];
					ans += x, x -= Q[p0].top(), Q[p0].pop(), Q[p0].emplace(y - x);
				} else ans += x;
			}
		cout << ans << '\n';
	}
}
