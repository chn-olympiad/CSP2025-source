#include <bits/stdc++.h>
using namespace std;
int t, n;

struct stu {
	int a, b, c;
} s[100005];

bool cmp(stu x, stu y) {
	return max(x.a, max(x.b, x.c)) > max(y.a, max(y.b, y.c));
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		int ans = 0, ans1 = 0;
		int aa = 0, bb = 0, cc = 0;
		int aa1 = 0, bb1 = 0, cc1 = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> s[i].a >> s[i].b >> s[i].c;
//		sort(s + 1, s + 1 + n, cmp);
		for (int i = 1; i <= n; i++) {
			if (s[i].a > s[i].b && s[i].a > s[i].c)
				aa1++;
			else if (s[i].b > s[i].a && s[i].b > s[i].c)
				bb1++;
			else if (s[i].c > s[i].a && s[i].c > s[i].b)
				cc1++;
		}
		for (int i = 1; i <= n; i++) {
			if (s[i].a > s[i].b && s[i].a > s[i].c && aa < n / 2) {
				aa++;
				ans += s[i].a;
			} else if (s[i].b > s[i].a && s[i].b > s[i].c && bb < n / 2) {
				bb++;
				ans += s[i].b;
			} else if (s[i].c > s[i].a && s[i].c > s[i].b && cc < n / 2) {
				cc++;
				ans += s[i].c;
			} else if (s[i].a > s[i].b && s[i].a > s[i].c && aa >= n / 2) {
				if (s[i].b > s[i].c && bb < n / 2) {
					bb++;
					ans += s[i].b;
				} else {
					cc++;
					ans += s[i].c;
				}
			} else if (s[i].b > s[i].a && s[i].b > s[i].c && bb >= n / 2) {
				if (s[i].c > s[i].a && cc < n / 2) {
					cc++;
					ans += s[i].c;
				} else {
					aa++;
					ans += s[i].a;
				}
			} else if (s[i].c > s[i].a && s[i].c > s[i].b && cc < n / 2) {
				if (s[i].b > s[i].a && bb < n / 2) {
					bb++;
					ans += s[i].b;
				} else {
					aa++;
					ans += s[i].a;
				}
			} else if (s[i].a == s[i].b && s[i].a > s[i].c) {
				if (aa1 < bb1 && aa < n / 2) {
					aa++;
					ans += s[i].a;
				} else {
					bb++;
					ans += s[i].b;
				}
			} else if (s[i].a == s[i].c && s[i].a > s[i].b) {
				if (aa1 < cc1 && aa < n / 2) {
					aa++;
					ans += s[i].a;
				} else {
					cc++;
					ans += s[i].c;
				}
			} else if (s[i].c == s[i].b && s[i].b > s[i].a) {
				if (cc1 < bb1 && cc < n / 2) {
					cc++;
					ans += s[i].c;
				} else {
					bb++;
					ans += s[i].b;
				}
			} else if (s[i].a == s[i].b && s[i].a == s[i].c) {

				if (cc1 < bb1 && cc1 < aa1 && cc < n / 2) {
					cc++;
					ans += s[i].c;
				} else if (cc1 > bb1 && bb1 < aa1 && bb < n / 2) {
					bb++;
					ans += s[i].b;
				} else {
					aa++;
					ans += s[i].a;
				}
			}
		}
		aa = 0, bb = 0, cc = 0;
		for (int i = n; i >= 1; i--) {
			if (s[i].a > s[i].b && s[i].a > s[i].c && aa < n / 2) {
				aa++;
				ans1 += s[i].a;
			} else if (s[i].b > s[i].a && s[i].b > s[i].c && bb < n / 2) {
				bb++;
				ans1 += s[i].b;
			} else if (s[i].c > s[i].a && s[i].c > s[i].b && cc < n / 2) {
				cc++;
				ans1 += s[i].c;
			} else if (s[i].a > s[i].b && s[i].a > s[i].c && aa >= n / 2) {
				if (s[i].b > s[i].c && bb < n / 2) {
					bb++;
					ans1 += s[i].b;
				} else {
					cc++;
					ans1 += s[i].c;
				}
			} else if (s[i].b > s[i].a && s[i].b > s[i].c && bb >= n / 2) {
				if (s[i].c > s[i].a && cc < n / 2) {
					cc++;
					ans1 += s[i].c;
				} else {
					aa++;
					ans1 += s[i].a;
				}
			} else if (s[i].c > s[i].a && s[i].c > s[i].b && cc < n / 2) {
				if (s[i].b > s[i].a && bb < n / 2) {
					bb++;
					ans1 += s[i].b;
				} else {
					aa++;
					ans1 += s[i].a;
				}
			} else if (s[i].a == s[i].b && s[i].a > s[i].c) {
				if (aa1 < bb1 && aa < n / 2) {
					aa++;
					ans1 += s[i].a;
				} else {
					bb++;
					ans1 += s[i].b;
				}
			} else if (s[i].a == s[i].c && s[i].a > s[i].b) {
				if (aa1 < cc1 && aa < n / 2) {
					aa++;
					ans1 += s[i].a;
				} else {
					cc++;
					ans1 += s[i].c;
				}
			} else if (s[i].c == s[i].b && s[i].b > s[i].a) {
				if (cc1 < bb1 && cc < n / 2) {
					cc++;
					ans1 += s[i].c;
				} else {
					bb++;
					ans1 += s[i].b;
				}
			} else if (s[i].a == s[i].b && s[i].a == s[i].c) {

				if (cc1 < bb1 && cc1 < aa1 && cc < n / 2) {
					cc++;
					ans1 += s[i].c;
				} else if (cc1 > bb1 && bb1 < aa1 && bb < n / 2) {
					bb++;
					ans1 += s[i].b;
				} else {
					aa++;
					ans1 += s[i].a;
				}
			}
		}
		cout << max(ans, ans1) << endl;
	}

	return 0;
}
