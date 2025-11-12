#include <bits/stdc++.h>
using namespace std;
const int N = 5e2+10;
long long n, m, e = 0, k = 0, d = 0, o = 1, p = 0, f1 = -1, f = 0, r = 1, er = 0;
string a;
int s[N];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> a;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		if (s[i] <= 0) {
			s[i] = -1;
			p++;
		}
		if (a[i - 1] == '0') {
			f1 = 0;
		} else {
			f = 1;
		}
	}
	sort(s + 1, s + 1 + n);
	if (m == n) {
		if (f1 == 0) {
			cout << 0;
			return 0;
		} else {
			if (s[1] == -1) {
				cout << 0;
				return 0;
			}
		}
	}

	while (s[r] == -1) {
		r++;
	}
	if (n - r < m) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == '0') {
			k++;
		} else {
			if (s[i + 1 + r] <= k) {
				k++;
			} else {
				d++;
			}
		}
		if (d == m) {
			er = 1;
			for (int j = 1; j <= n; j++) {
				if (s[j] > min(er, r)) {
					o = o * (j + min(er, r)) % 998244353;
					er++;
				} else {
					o = o * j % 998244353;
				}
			}
			e = (e + o) % 998244353;
			o = 1;
			break;
		}
	}
	cout << e;
	return 0;
}
