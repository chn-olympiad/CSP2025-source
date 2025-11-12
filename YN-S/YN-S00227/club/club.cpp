#include <bits/stdc++.h>
using namespace std;
int t, n, za[100005], ans;

struct Stu {
	int a1, a2, a3, maxa, sec, mps;
} s[100005];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> s[i].a1 >> s[i].a2 >> s[i].a3;
			s[i].maxa = max(s[i].a1, max(s[i].a2, s[i].a3));
			if (s[i].a1 != s[i].maxa && (s[i].a1 >= s[i].a2 || s[i].a1 >= s[i].a3)) {
				s[i].sec = s[i].a1;
			}
			if (s[i].a2 != s[i].maxa && (s[i].a2 >= s[i].a1 || s[i].a2 >= s[i].a3)) {
				s[i].sec = s[i].a2;
			}
			if (s[i].a3 != s[i].maxa && (s[i].a3 >= s[i].a2 || s[i].a3 >= s[i].a1)) {
				s[i].sec = s[i].a3;
			}
			if (s[i].a1 == s[i].maxa) {
				s[i].mps = 1;
			} else if (s[i].a2 == s[i].maxa) {
				s[i].mps = 2;
			} else {
				s[i].mps = 3;
			}

		}
		if (n == 2) {
			if (s[1].mps != s[2].mps) {
				cout << s[1].maxa + s[2].maxa << endl;
			} else {
				cout << max(s[1].maxa + s[2].sec, s[1].sec + s[2].maxa) << endl;
			}
		} else {
			for (int i = 1; i <= n; i++) {
				za[i] = s[i].a1;
			}
			sort(za + 1, za + n + 1);
			for (int i = n; i > n / 2; i--) {
				ans += za[i];
			}
			cout << ans << endl;
		}
	}
	return 0;
}