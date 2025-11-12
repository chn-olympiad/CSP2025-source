#include <bits/stdc++.h>
using namespace std;

long long n, k, a[10005], b[10005][10005], t[25] = {0, 1}, tn = 1, mn, ans, r;
struct maze {
	long long x, y;
} m[10005];
bool cmp(maze a, maze b) {
	if (a.y != b.y) {
		return a.y < b.y;
	} else {
		return a.x > b.x;
	}
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
		while (a[i] > t[tn]) {
			tn++;
			t[tn] = t[tn - 1] * 2;
		}
		b[i][i] = a[i];
		if (b[i][i] == k) {
			mn++;
			m[mn].x = i;
			m[mn].y = i;
		}
	}
	for (long long w = 1; w < n; w++) {
		for (long long i = 1; i + w <= n; i++) {
			long long tl = b[i][i + w - 1], tr = b[i + w][i + w];
			for (long long j = tn; j >= 1; j--) {
				if ((tl >= t[j] && tr < t[j]) || (tl < t[j] && tr >= t[j])) {
					b[i][i + w] += t[j];
				}
				tl %= t[j], tr %= t[j];
			}
			if (b[i][i + w] == k) {
				mn++;
				m[mn].x = i;
				m[mn].y = i + w;
			}
		}
	}
	if (mn == 0) {
		cout << 0;
		return 0;
	}
	sort(m + 1, m + mn + 1, cmp);
	r = m[1].y, ans = 1;
	for (int i = 2; i <= mn; i++) {
		if (m[i].x > r) {
			ans++;
			r = m[i].y;
		}
	}
	cout << ans;
	return 0;
}
