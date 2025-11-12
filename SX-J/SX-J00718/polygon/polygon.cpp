#include <bits/stdc++.h>
using namespace std;
long long n, a[5005], r = 1e18, ans, mmax = -1, s, b[5005];

bool dg(int x) {
	long long box, t, box1 = 0, mymax, q;
	for (int i = 1; i <= n; i++) {
		box = a[i], t = 0, mymax = a[i];
		for (int j = 1; j <= n; j++) {
			t++;
			if (a[j] != a[i]) {
				box += a[j];
			}
			mymax = max(a[j], mymax);
			if (box > mymax * 2 && t >= 3) {
				box1++;
				break;
			}
		}
	}
	box1 = box1 + s;
	box1 %= 998244353;
	if (box1 >= x) {
		return 1;
	} else
		return 0;
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[a[i]]++;
		mmax = max(mmax, a[i]);
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= mmax; i++) {
		if (b[i] >= 1) {
			s += b[i] - 1;
		}
	}
	int l = 0;
	while (l <= r) {
		long long mid = (l + r) / 2;
		mid %= 998244353;
		if (dg(mid) == 1) {
			ans = mid, l = mid + 1;
			ans %= 998244353;
		} else
			r = mid - 1;
	}
	cout << ans;
	return 0;
}
