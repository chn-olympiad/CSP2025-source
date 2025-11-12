#include <bits/stdc++.h>
using namespace std;
int a1[100005], a2[100005], a3[100005];

int pd(int a, int b) {
	if (a > b) {
		return a;
	} else
		return b;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n, mx = -1, cnt1 = 0, cnt2 = 0, cnt3 = 0, ans = 0;
	cin >> t;
	for (int f = 1; f <= t; f++) {
		cin >> n;
		mx = -1;
		cnt1 = 0, cnt2 = 0, cnt3 = 0, ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a1[i] >> a2[i] >> a3[i];
			mx = max(pd(a1[i], a2[i]), a3[i]);
			if (mx == a1[i] && cnt1 <= n / 2) {
				cnt1++;
				ans += mx;
			} else if (mx == a2[i]) {
				cnt2++;
				ans += mx;
			} else if (mx == a3[i]) {
				cnt3++;
				ans += mx;
			}
		}
		cout << ans << endl;
	}
	return 0;
}