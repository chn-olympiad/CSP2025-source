#include <bits/stdc++.h>
using namespace std;
long a[500005];
long s[500005];
int k, n, sum, q, qq;
bool v[500005], A = true;

bool ss(int l, int r) {
	int x;
	for (int i = l; i <= r; i++) {
		if (v[i]) {
			x++;
		}
	}
	if (x == r - l + 1) {
		return true;
	} else
		return false;

}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		v[i] = true;
		qq = a[1];
		if (a[i] != qq && a[i] != q) {
			A = false;
		}
		if (qq != a[i]) {
			q = a[i];
		}

	}
	for (int i = 1; i <= n; i++) {
		s[i] = a[i] + s[i - 1];
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == k && v[i]) {
			sum++;
			v[i] = false;
		}
	}
	if (A) {
		cout << sum;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (s[j] - s[i - 1] == k && ss(i, j)) {
				sum++;
				for (int h = i; h <= j; h++) {
					v[i] = false;
				}
			}
		}
	}
	cout << sum;
	return 0;
}
