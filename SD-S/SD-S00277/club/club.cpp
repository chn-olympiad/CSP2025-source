#include <bits/stdc++.h>

#define int long long

const int N = 1e5 + 10;

using namespace std;

int n;
struct Node {
	int x, y, z;
	int v, i;
} a[N];
int ans;
int sum1, sum2, sum3;

bool cmp(Node x, Node y) {
	return x.v > y.v;
}

void solve() {
	ans = sum1 = sum2 = sum3 = 0;
	cin >> n;
	sum1 = n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y >> a[i].z;
		ans += a[i].x;
		a[i].y -= a[i].x;
		a[i].z -= a[i].x;
		a[i].x  = 0;
		a[i].v = a[i].y + a[i].z;
		a[i].i = 1;
	}
	sort(a + 1, a + n + 1, cmp);
	
	for (int i = 1; i <= n; i++) {
		if (a[i].y < 0) {
			if (a[i].z > 0) {
				ans += a[i].z;
				sum3++;
				sum1--;
				a[i].i = 3;
			}
		} else {
			sum1--;
			if (a[i].z < 0) {
				ans += a[i].y;
				sum2++;
				a[i].i = 2;
			} else {
				if (a[i].y > a[i].z) {
					ans += a[i].y;
					sum2++;
					a[i].i = 2;
				} else {
					ans += a[i].z;
					sum3++;
					a[i].i = 3;
				}
			}
		}
	}
	
	for (int i = 1; i <= n && sum2 + sum3 < n / 2; i++) {
		if (a[i].i != 1) {
			continue;
		}
		if (a[i].y < 0 && a[i].z < 0) {
			if (a[i].y > a[i].z) {
				ans += a[i].y;
				a[i].i = 2;
				sum2++;
			} else {
				ans += a[i].z;
				a[i].i = 3;
				sum3++;
			}
			sum1--;
		}
	}
	
	for (int i = n; i >= 1 && sum1 + sum3 < n / 2; i--) {
		if (a[i].i != 2) {
			continue;
		}
		if (a[i].z > 0) {
			sum3++;
			ans -= a[i].y;
			ans += a[i].z;
			a[i].i = 3;
		} else {
			sum1++;
			ans -= a[i].y;
			a[i].i = 1;
		}
		sum2--;
	}
	
	for (int i = n; i >= 1 && sum1 + sum2 < n / 2; i--) {
		if (a[i].i != 3) {
			continue;
		}
		if (a[i].y > 0) {
			sum2++;
			ans -= a[i].z;
			ans += a[i].y;
			a[i].i = 2;
		} else {
			sum1++;
			ans -= a[i].z;
			a[i].i = 1;
		}
		sum3--;
	}
	
	cout << ans << '\n';
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		solve();
	} 
	return 0;
}
