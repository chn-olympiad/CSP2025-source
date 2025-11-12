#include <bits/stdc++.h>
using namespace std;
long long n, ans = 0, k1, k2, k3;

struct l {
	long long l1, l2, l3, bh;
} a[300005];

bool A(l m) {
	if (m.l2 == 0 && m.l3 == 0)
		return 1;
}

bool B(l m) {
	if (m.l3 == 0)
		return 1;
}

void dfs(long long dep, long long sum, long long p1, long long p2, long long p3) {
	if (dep >= n)
		cout << sum << '\n';
	if (p1 <= n / 2 && p2 <= n / 2 && p3 <= n / 2) {
		if (a[dep].l1 >= a[dep].l2 && a[dep].l1 >= a[dep].l3) {
			dfs(dep + 1, sum + a[dep].l1, p1 + 1, p2, p3);
		}
		if (a[dep].l2 >= a[dep].l1 && a[dep].l2 >= a[dep].l3) {
			dfs(dep + 1, sum + a[dep].l2, p1, p2 + 1, p3);
		}
		if (a[dep].l3 >= a[dep].l1 && a[dep].l3 >= a[dep].l2) {
			dfs(dep + 1, sum + a[dep].l3, p1, p2, p3 + 1);
		}
	} else {
		if (p1 > n / 2) {
			if (a[dep].l2 > a[dep].l3) {
				dfs(dep + 1, sum + a[dep].l2, p1, p2 + 1, p3);
			}
			if (a[dep].l3 > a[dep].l2) {
				dfs(dep + 1, sum + a[dep].l3, p1, p2, p3 + 1);
			}
		}
		if (p2 > n / 2) {
			if (a[dep].l1 > a[dep].l3) {
				dfs(dep + 1, sum + a[dep].l1, p1 + 1, p2, p3);
			}
			if (a[dep].l3 > a[dep].l1) {
				dfs(dep + 1, sum + a[dep].l3, p1, p2, p3 + 1);
			}
		}
		if (p3 > n / 2) {
			if (a[dep].l1 > a[dep].l2) {
				dfs(dep + 1, sum + a[dep].l1, p1 + 1, p2, p3);
			}
			if (a[dep].l2 > a[dep].l1) {
				dfs(dep + 1, sum + a[dep].l2, p1, p2 + 1, p3);
			}
		}
	}
}

int main() {

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	long long t, e = 0, o = 0;
	cin >> t;
	for (long long w = 1; w <= t; w++) {
		cin >> n;
		for (long long i = 1; i <= n; i++) {
			cin >> a[i].l1 >> a[i].l2 >> a[i].l3;
			if (A(a[i]) == 1)
				e++;
			if (B(a[i]) == 1) {
				o++;
			}
		}
		if (e == n) {
			for (long long i = 1; i <= n; i++) {
				ans += a[i].l1;
			}
			cout << ans;
			exit(0);
		}
		if (o == n) {
			for (long long i = 1; i <= n; i++) {
				if (k1 == n / 2) {
					a[i].bh = 2;
					k2++;
				}
				if (a[i].l1 > a[i].l2) {
					a[i].bh = 1;
					k1++;
				} else {
					a[i].bh = 2;
					k2++;
				}
			}
			for (long long i = 1; i <= n; i++) {
				if (a[i].bh == 1)
					ans += a[i].l1;
				else
					ans += a[i].l2;
			}
			cout << ans;
			exit(0);
		}
		dfs(1, 0, 0, 0, 0);
	}

	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
