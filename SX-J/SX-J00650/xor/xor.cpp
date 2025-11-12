#include <bits/stdc++.h>
using namespace std;

int a[500010] = {0};

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int cnt_1 = 0, cnt_0 = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			cnt_1++;
		}
		if (a[i] == 0) {
			cnt_0++;
		}
	}
	if (k == 0) {
		if (cnt_1 == n || cnt_0 == n) {
			cout << n / 2;
			return 0;
		} else if (cnt_1 + cnt_0 == n) {
			int t = 0;
			for (int i = 0; i < n; i++) {
				int m = 0;
				if (a[i] == 1) {
					while (a[i] == 1) {
						m++;
						i++;
					}
					t += m / 2;
				}
			}
			cout << cnt_0 + t;
			return 0;
		} else {
			int s_1 = 0;
			int s_2 = 0;
			for (int i = 1; i < n; i += 2) {
				if (a[i] == a[i - 1])
					s_1++;
			}
			for (int i = 2; i <= n; i += 2) {
				if (a[i] == a[i - 1])
					s_2++;
			}
			cout << max({s_1, s_2, cnt_0});
			return 0;
		}
	} else if (k == 1) {
		if (cnt_1 + cnt_0 == n) {
			int s_1 = 0;
			int s_2 = 0;
			for (int i = 1; i < n; i += 2) {
				if (a[i] != a[i - 1])
					s_1++;
			}
			for (int i = 2; i <= n; i += 2) {
				if (a[i] != a[i - 1])
					s_2++;
			}
			cout << max({s_1, s_2, cnt_1});
			return 0;
		}
	} else {
		int t = a[0];
		int s = 0;
		for (int i = 1; i < n; i++) {
			if (t == k) {
				s++;
				t = a[i];
			} else {
				t = t ^a[i];
			}
		}
		cout << s;
	}
	return 0;
}
