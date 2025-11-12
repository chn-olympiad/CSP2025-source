#include <bits/stdc++.h>
using namespace std;
int t, n, ans, cnt1;
int a[114514];

struct club {
	int lk1;
	int lk2;
	int lk3;
	int nt1;
	int nt2;
	int no;
} cb[114514];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		ans = 0;
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> cb[j].lk1;
			cin >> cb[j].lk2;
			cin >> cb[j].lk3;
			a[j] = cb[j].lk1;
		}
		if (n == 2) {
			int maxn = cb[1].lk1 + cb[2].lk2;
			if (maxn < cb[1].lk1 + cb[2].lk3)
				maxn = cb[1].lk1 + cb[2].lk3;
			if (maxn < cb[1].lk2 + cb[2].lk1)
				maxn = cb[1].lk2 + cb[2].lk1;
			if (maxn < cb[1].lk2 + cb[2].lk3)
				maxn = cb[1].lk2 + cb[2].lk3;
			if (maxn < cb[1].lk3 + cb[2].lk1)
				maxn = cb[1].lk3 + cb[2].lk1;
			if (maxn < cb[1].lk3 + cb[2].lk2)
				maxn = cb[1].lk3 + cb[2].lk2;
			ans = maxn;
			cout << ans;
			continue;
		}
		sort(a + 1, a + n + 1);
		for (int k = n; k > n / 2; k--) {
			ans += a[k];
		}
		cout << ans;
	}
	return 0;
}





