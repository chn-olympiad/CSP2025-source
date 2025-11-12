#include <bits/stdc++.h>
using namespace std;
constexpr int N = 100005;
int t, n;
array<int, 3> a[N], b[N];
int getMid(int x, int y, int z) {
	return x + y + z - max({x, y, z}) - min({x, y, z});
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) cin >> a[i][0] >> a[i][1] >> a[i][2];
		int cnt[3] = {}, sum = 0;
		for (int i = 1; i <= n; ++i) {
			int num = 0, mx = a[i][0];
			if (a[i][1] > mx) {
				num = 1;
				mx = a[i][1];
			}
			if (a[i][2] > mx) {
				num = 2;
				mx = a[i][2];
			}
			++cnt[num];
			sum += mx;
		}
		auto it = max_element(cnt, cnt + 3);
		if (*it > n >> 1) {
			int ind = it - cnt, delta = *it - (n >> 1);
			int ptr = 0;
			for (int i = 1; i <= n; ++i) {
				if (a[i][ind] == max({a[i][0], a[i][1], a[i][2]})) b[++ptr] = a[i];
			}
			sort(b + 1, b + ptr + 1, [&](array<int, 3> x, array<int, 3> y) -> bool {
				int mid1 = getMid(x[0], x[1], x[2]), mid2 = getMid(y[0], y[1], y[2]);
				return x[ind] - mid1 < y[ind] - mid2;
			});
			for (int i = 1; i <= delta; ++i) {
				int mx = b[i][ind];
				int repl = getMid(b[i][0], b[i][1], b[i][2]);
				sum -= mx - repl;
			}
		}
		cout << sum << '\n';
	}
	return 0;
}