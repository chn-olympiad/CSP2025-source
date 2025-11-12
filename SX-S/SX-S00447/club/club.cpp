#include <bits/stdc++.h>
using namespace std;
int t, n, cnt1, cnt2, cnt3, ans1, ans2, ans3;

struct node {
	int a1, a2, a3, max1;
	bool f = 0;
} c[100005];

bool cmp1(node x, node y) {
	return x.a1 > y.a1;
}

bool cmp2(node x, node y) {
	return x.a2 > y.a2;
}

bool cmp3(node x, node y) {
	return x.a3 > y.a3;
}

bool cmp(node x, node y) {
	return x.f < y.f ;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		if (n == 2) {
			int a_1, a_2, a_3, b_1, b_2, b_3;
			cin >> a_1 >> a_2 >> a_3 >> b_1 >> b_2 >> b_3;
			cout << max(max(a_1 + b_2, a_1 + b_3), max(max(a_2 + b_1, a_2 + b_3), max(a_3 + b_1, a_3 + b_2)));
			continue;
		}
		if (n == 4) {

			continue;
		}
		cnt1 = 0, cnt2 = 0, cnt3 = 0, ans1 = 0, ans2 = 0, ans3 = 0;
		for (int i = 1; i <= n; i++) {
			cin >> c[i].a1 >> c[i].a2 >> c[i].a3 ;
			if (c[i].a1 > c[i].a2 && c[i].a1 > c[i].a3) {
				c[i].max1 = 1;
			} else if (c[i].a2 > c[i].a1 && c[i].a2 > c[i].a3) {
				c[i].max1 = 2;
			} else if (c[i].a3 > c[i].a1 && c[i].a3 > c[i].a2) {
				c[i].max1 = 3;
			} else {
				if (c[i].a1 > c[i].a2 || c[i].a1 > c[i].a3) {
					c[i].max1 = 1;
				} else if (c[i].a2 > c[i].a1 || c[i].a2 > c[i].a3) {
					c[i].max1 = 2;
				} else if (c[i].a3 > c[i].a1 || c[i].a3 > c[i].a2) {
					c[i].max1 = 3;
				} else
					c[i].max1 = 1;
			}
		}
		sort(c + 1, c + n + 1, cmp1);
		for (int i = 1; i <= n; i++) {
			if (c[i].max1 == 1 && cnt1 <= n / 2) {
				ans1 += c[i].a1 ;
				c[i].f = 1;
				cnt1++;
			}
		}
		sort(c + 1, c + n + 1, cmp2);
		for (int i = 1; i <= n; i++) {
			if (c[i].max1 == 2 && cnt2 <= n / 2) {
				ans2 += c[i].a2 ;
				c[i].f = 1;
				cnt2++;
			}
		}
		sort(c + 1, c + n + 1, cmp3);
		for (int i = 1; i <= n; i++) {
			if (c[i].max1 == 3 && cnt3 <= n / 2) {
				ans3 += c[i].a3 ;
				c[i].f = 1;
				cnt3++;
			}
		}
		sort(c + 1, c + n + 1, cmp);
		for (int i = 1; i <= n; i++) {
			if (c[i].f == 1)
				break;
			if (c[i].max1 == 1) {
				if (c[i].a2 > c[i].a3 )
					c[i].max1 = 2;
				else
					c[i].max1 = 3;
			} else if (c[i].max1 == 2) {
				if (c[i].a1 > c[i].a3 )
					c[i].max1 = 1;
				else
					c[i].max1 = 3;
			} else if (c[i].max1 == 3) {
				if (c[i].a1 > c[i].a2 )
					c[i].max1 = 1;
				else
					c[i].max1 = 2;
			}
		}
		int i = 0;
		while (cnt1 + cnt2 + cnt3 < n) {
			i++;
			if (c[i].f == 1)
				break;
			if (c[i].max1 == 1 && cnt1 <= n / 2 ) {
				ans1 += c[i].a1 ;
				c[i].f = 1;
				cnt1++;
			} else if (c[i].max1 == 2 && cnt2 <= n / 2) {
				ans2 += c[i].a2 ;
				c[i].f = 1;
				cnt2++;
			} else if (c[i].max1 == 3 && cnt3 <= n / 2 ) {
				ans3 += c[i].a3 ;
				c[i].f = 1;
				cnt3++;
			} else {
				if ( cnt1 <= n / 2 ) {
					ans1 += c[i].a1 ;
					c[i].f = 1;
					cnt1++;
				} else if ( cnt2 <= n / 2) {
					ans2 += c[i].a2 ;
					c[i].f = 1;
					cnt2++;
				} else if (cnt3 <= n / 2 ) {
					ans3 += c[i].a3 ;
					c[i].f = 1;
					cnt3++;
				}
			}
		}
		cout << ans1 + ans2 + ans3 << endl;
	}
	return 0;
}
