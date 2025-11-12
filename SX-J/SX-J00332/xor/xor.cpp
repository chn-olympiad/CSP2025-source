#include <bits/stdc++.h>
using namespace std;

long long n, k, ans1 = 0, ans = 0, x, p, f = 0;

const int N = 5e5+10;

int a[N], v[N];

void me(int l, int r) {
	for (int i = l; i <= r; i++) {
		v[i] = 1;
	}
}

int cme(int l, int r) {
	for (int i = l; i <= r; i++) {
		if (v[i] == 1)
			return 0;
	}
	return 1;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		p = a[i];

		for (int j = i + 1 ; j <= n; j++) {

			if (cme(i, j)) {

				p = p ^a[j];

				if (p == k) {
					ans++;
					me(i, j);
					break;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == k && v[i] == 0) {
			ans++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == k) {
			ans1++;
		}
	}
	cout << max(ans1, ans);
	return 0;
}
