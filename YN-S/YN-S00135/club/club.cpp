#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, ans, t;
bool flag1, flag2, flag3;
int vis1 = 0, vis2 = 0, vis3 = 0;

struct node {
	int a1, a2, a3;
} s[N];

bool cmp(node a, node b) {
	if (a.a1 > 0 && b.a1 > 0)
		return a.a1 > b.a1;
	if (a.a2 > 0 && b.a2 > 0)
		return a.a2 > b.a2;
	if (a.a3 > 0 && b.a3 > 0)
		return a.a3 > b.a3;
}

bool cmp1(node a, node b) {
	if (a.a1 > 0 && b.a1 > 0)
		return a.a1 < b.a1;
	if (a.a2 > 0 && b.a2 > 0)
		return a.a2 < b.a2;
	if (a.a3 > 0 && b.a3 > 0)
		return a.a3 < b.a3;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		flag1 = true, flag2 = true, flag3 = true;
		vis1 = 0, vis2 = 0, vis3 = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> s[i].a1 >> s[i].a2 >> s[i].a3;
		}
		sort(s + 1, s + n + 1, cmp);
		ans = 0;
		for (int i = 1; i <= n; i++) {
			int mx = INT_MIN;
			mx = max(s[i].a1, max(s[i].a2, s[i].a3));
			if (mx == s[i].a1) {
				if (flag1) {
					vis1++;
					ans += s[i].a1;
				} else {
					if (s[i].a2 > s[i].a3) {
						if (flag2) {
							vis2++;
							ans += s[i].a2;
						}
					} else {
						if (flag3) {
							vis3++;
							ans += s[i].a3;
						}
					}
				}
			} else if (mx == s[i].a2) {
				if (flag2) {
					vis2++;
					ans += s[i].a2;
				} else {
					if (s[i].a1 > s[i].a3) {
						if (flag1) {
							vis1++;
							ans += s[i].a1;
						}
					} else {
						if (flag3) {
							vis3++;
							ans += s[i].a3;
						}
					}
				}
			} else if (mx == s[i].a3) {
				if (flag3) {
					vis3++;
					ans += s[i].a3;
				} else {
					if (s[i].a2 > s[i].a1) {
						if (flag2) {
							vis2++;
							ans += s[i].a2;
						}
					} else {
						if (flag1) {
							vis1++;
							ans += s[i].a1;
						}
					}
				}
			}

			if (vis1 == n / 2)
				flag1 = false;
			if (vis2 == n / 2)
				flag2 = false;
			if (vis3 == n / 2)
				flag3 = false;
		}

		flag1 = true, flag2 = true, flag3 = true;
		vis1 = 0, vis2 = 0, vis3 = 0;
		sort(s + 1, s + n + 1, cmp1);
		int ans1 = 0;
		for (int i = 1; i <= n; i++) {
			int mx = INT_MIN;
			mx = max(s[i].a1, max(s[i].a2, s[i].a3));
			if (mx == s[i].a1) {
				if (flag1) {
					vis1++;
					ans1 += s[i].a1;
				} else {
					if (s[i].a2 > s[i].a3) {
						if (flag2) {
							vis2++;
							ans1 += s[i].a2;
						}
					} else {
						if (flag3) {
							vis3++;
							ans1 += s[i].a3;
						}
					}
				}
			} else if (mx == s[i].a2) {
				if (flag2) {
					vis2++;
					ans1 += s[i].a2;
				} else {
					if (s[i].a1 > s[i].a3) {
						if (flag1) {
							vis1++;
							ans1 += s[i].a1;
						}
					} else {
						if (flag3) {
							vis3++;
							ans1 += s[i].a3;
						}
					}
				}
			} else if (mx == s[i].a3) {
				if (flag3) {
					vis3++;
					ans1 += s[i].a3;
				} else {
					if (s[i].a2 > s[i].a1) {
						if (flag2) {
							vis2++;
							ans1 += s[i].a2;
						}
					} else {
						if (flag1) {
							vis1++;
							ans1 += s[i].a1;
						}
					}
				}
			}

			if (vis1 == n / 2)
				flag1 = false;
			if (vis2 == n / 2)
				flag2 = false;
			if (vis3 == n / 2)
				flag3 = false;
		}
		cout << max(ans, ans1) << '\n';
	}
	return 0;
}