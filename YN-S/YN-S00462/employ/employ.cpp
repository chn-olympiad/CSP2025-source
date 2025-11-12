#include <bits/stdc++.h>
using namespace std;
int a[505];
int t, s1, f1, f2;

int main(void) {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		int c1, c2, c3 = 1;
		if (s[i] == s[i - 1]) {
			c1++;
			c2++;
		} else {
			c1 = 0;
		}
		if (s[i] == '1') {
			if (a[i] == 0) {
				t++;
				continue;
			}
			if (t < a[i]) {
				s1++;
			} else {
				t++;
			}
			if (s1 >= m) {
				f1++;
			}
			if (c1 == 0) {
				int ans = 1;
				for (int i = c2 - c3; i >= 1; i--) {
					ans *= i;
				}
				f1 *= ans;
				c3 = c2;
				c2 = 0;
			}
		}
		f2 += f1;
		f1 = 0;
		s1 = 0;
	}
	cout << f2;
	return 0;
}