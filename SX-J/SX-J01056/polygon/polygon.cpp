#include <bits/stdc++.h>
using namespace std;
int n, a[5005], maxx;
long long cnt, s[5005], sum;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n == 3) {
		for (int i = 0; i < n; i++) {
			sum += a[i];
			maxx = max(maxx, a[i]);
		}
		if (sum > 2 * maxx) {
			cout << 1;
			return 0;
		} else {
			cout << 0;
			return 0;
		}
	}
	sort(a, a + n);
	cout << cnt;
	return 0;
}
