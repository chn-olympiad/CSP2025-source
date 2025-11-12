#include <bits/stdc++.h>
using namespace std;
long long n, k, a[500005], ans;

int df(int s) {
	int ll = a[s];
	if (ll == k)
		return s;
	for (int i = s + 1; i <= n; i++) {
		if (ll == k)
			return i - 1;
		else
			ll = ( ll ^ a[i]);
	}
	return 1e9;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n < 2) {
		cout << 0;
		return 0;
	}
	if (k == 0) {
		cout << n / 2;
		return 0;
	}
	if (k == 1) {
		cout << n;
		return 0;
	}
	int mm;
	int xx = 1e9;
	for (int i = 1; i <= n; i++) {
		mm = df(i);
		if (i >= xx) {
			ans++;
			xx = 1e9;
		}
		if (xx > mm)
			xx = mm;
	}
	cout << ans;

	return 0;
}
