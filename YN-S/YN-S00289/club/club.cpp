#include <bits/stdc++.h>
#define int long long
using namespace std;

struct cheny {
	int a1, a2, a3;
} a[100005];
int n, a1sum, a2sum, a3sum;

bool cmp1(cheny a, cheny b) {
	return a.a1 > b.a1;
}

bool cmp2(cheny a, cheny b) {
	return a.a2 > b.a2;
}

bool cmp3(cheny a, cheny b) {
	return a.a3 > b.a3;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			a1sum += a[i].a1, a2sum += a[i].a2, a3sum += a[i].a3;
		}
		if (a1sum > a2sum && a1sum > a3sum) {
			sort(a + 1, a + n + 1, cmp1);
			for (int j = 1; j <= n / 2; j++) {
				ans += a[j].a1;
			}
			for (int j = n / 2 + 1; j <= n; j++) {
				ans += max(a[j].a2, a[j].a3);
			}
		} else if (a2sum > a1sum && a2sum > a3sum) {
			sort(a + 1, a + n + 1, cmp2);
			for (int j = 1; j <= n / 2; j++) {
				ans += a[j].a2;
			}
			for (int j = n / 2 + 1; j <= n; j++) {
				ans += max(a[j].a1, a[j].a3);
			}
		} else if (a3sum > a2sum && a3sum > a1sum) {
			sort(a + 1, a + n + 1, cmp3);
			for (int j = 1; j <= n / 2; j++) {
				ans += a[j].a3;
			}
			for (int j = n / 2 + 1; j <= n; j++) {
				ans += max(a[j].a1, a[j].a2);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
