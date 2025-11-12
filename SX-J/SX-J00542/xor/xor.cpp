#include <bits/stdc++.h>
using namespace std;
long long n, m, s, k, b[500105], a[500105], a1, b1, ans;

int TO2(long long sss) {
	int ssss;
	for (int i = 1; sss > 0; i *= 10) {
		ssss += sss % 2 * i;
		sss /= 2;
	}
	return ssss;
}

bool suan(long long x1, long long y1) {
	long long suanans = 0;
	if (x1 == y1)
		return b[x1] == k;
	for (long long i = x1; i <= y1; i++) {
		a1 = a[i];
		b1 = a[i + 1];
		bool breakk;
		while (!breakk) {
			if (a1 == 0 or b1 == 0) {
				if (a1 % 10 != b1 % 10)
					suanans++;
				breakk = 1;
			}
			if (a1 % 10 != b1 % 10)
				suanans++;
			a1 /= 10;
			b1 /= 10;

		}

	}
	return suanans == k;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
		a[i] = TO2(a[i]);
	}
	for (long long i = 1; i <= n; i++) {
		for (long long j = i; j <= n; j++) {
			//cout << i << " " << j << "   " << suan(i, j) << "\n";
			if (suan(i, j)) {
				ans++;
				//cout << i << " " << j << "\n";
				i = j;
				break;
			}

		}
	}
	cout << ans;
	return 0;
}

