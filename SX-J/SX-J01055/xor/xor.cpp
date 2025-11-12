#include <bits/stdc++.h>
using namespace std;
long long a[500005];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	long long n, k;
	cin >> n >> k;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long ans = 0, l = 1, r = 1, s = a[1];
	for (long long i = 2; i <= n; i++) {
		if (s == k) {
			ans++;
			r++;
			l = r;
			s = a[i];
			continue;
		}
		s = s ^a[i];
		r++;
	}
	if (s == k) {
		ans++;
	}
	cout << ans << endl;
	return 0;
}