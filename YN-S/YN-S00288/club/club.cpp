#include <bits\stdc++.h>
using namespace std;

int t;

struct ll {
	int x, y, z, ma, mi;
} a[100005];


bool cmp1(ll o, ll p) {
	return p.mi > o.mi;
}

bool cmp2(ll o, ll p) {
	return p.mi >= o.mi;
}





int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int n, X = 0, Y = 0, Z = 0, ans = 0;
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> a[j].x >> a[j].y >> a[j].z;
			a[j].ma = max({a[j].x, a[j].y, a[j].z});
			a[j].mi = min({a[j].x, a[j].y, a[j].z});
		}
		sort(a + 1, a + 1 + n, cmp1);
		for (int j = 1; j <= n; j++) {
			if (a[j].x > a[j].y && a[j].z < a[j].x && X < n / 2) {
				ans += a[j].x;
				X++;
			} else if (a[j].x < a[j].y && a[j].y > a[j].z && Y < n / 2) {
				ans += a[j].y;
				Y++;
			} else {
				ans += a[j].z;
				Z++;
			}
		}
		X = 0, Y = 0, Z = 0;
		int ans1 = 0;
		sort(a + 1, a + 1 + n, cmp2);
		for (int j = 1; j <= n; j++) {
			if (a[j].x > a[j].y && a[j].z < a[j].x && X < n / 2) {
				ans1 += a[j].x;
				X++;
			} else if (a[j].x < a[j].y && a[j].y > a[j].z && Y < n / 2) {
				ans1 += a[j].y;
				Y++;
			} else {
				ans1 += a[j].z;
				Z++;
			}
		}
		cout << max(ans, ans1) << endl;
	}


	return 0;
}