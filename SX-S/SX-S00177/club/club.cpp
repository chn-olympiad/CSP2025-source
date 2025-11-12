#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int a[100010], b[100010], c[100010], b1[100010], c1[100010];
long long cnt1, cnt2, n, sum = 0, res = 0;

struct xxx {
	int x;
	int y;
} s[100010];

bool cmp(xxx l, xxx l1) {
	return l.y > l1.y;
}

//void dfs(int dep) {
//	if (dep == n) {
//		res = max(res, sum);
//		return;
//	} else {
//		for (int i = 1; i <= 2; i++) {
//			if ((i == 1 && cnt1 < n / 2) || cnt2 >= n / 2) {
//				sum += a[dep];
//				cnt1++;
//				dfs(dep + 1);
//				cnt1--;
//				sum -= a[dep];
//			} else if (i == 2 && cnt2 < n / 2) {
//				sum += b[dep];
//				cnt2++;
//				dfs(dep + 1);
//				cnt2--;
//				sum -= b[dep];
//			}
//		}
//	}
//}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int XH;
	cin >> XH;
	while (XH--) {
		sum = 0, cnt1 = 0, cnt2 = 0, res = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
			s[i].x = i;
			s[i].y = abs(a[i] - b[i]);
			b1[i] = b[i];
			c1[i] = c[i];
		}
		sort(b1 + 1, b1 + n + 1);
		sort(c1 + 1, c1 + n + 1);
		if (1 == 1) {
			if (b1[n] == 0 && c1[n] == 0) {
				sort(a + 1, a + n + 1);
				for (int i = n; i > n / 2; i--) {
					sum += a[i];
				}
				cout << sum << endl;
			} else {
				sort(s + 1, s + n + 1, cmp);
				for (int i = 1; i <= n / 2; i++) {
					sum += max(a[s[i].x], b[s[i].x]);
				}
				for (int i = n / 2 + 1; i <= n; i++) {
					sum += min(a[s[i].x], b[s[i].x]);
				}
				cout << sum << endl;
			}
		}
	}
	return 0;
}
