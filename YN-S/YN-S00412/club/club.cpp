#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int t, n;
long long ans;
int cnt1, cnt2, cnt3;

struct xx {
	int d, z, x;
	int db, zb, xb;
};
xx myd[N];

bool cmp(xx a, xx b) {
	if (a.d == b.d) {
		if (a.z == b.z)
			return a.x > b.x;
		return a.z < b.z;
	}
	return a.d > b.d;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		cnt1 = 0, cnt2 = 0, cnt3 = 0, ans = 0;
		int a, b, c;
		for (int i = 1; i <= n; i++) {
			cin >> a >> b >> c;
			myd[i].d = max(max(a, b), c), myd[i].x = min(min(a, b), c);
			if (myd[i].d == a) {
				myd[i].db = 1;
				if (myd[i].x == b)
					myd[i].xb = 2, myd[i].zb = 3, myd[i].z = c;
				else
					myd[i].xb = 3, myd[i].zb = 2, myd[i].z = b;
			} else if (myd[i].d == b) {
				myd[i].db = 2;
				if (myd[i].x == a)
					myd[i].xb = 1, myd[i].zb = 3, myd[i].z = c;
				else
					myd[i].xb = 3, myd[i].zb = 1, myd[i].z = a;
			} else {
				myd[i].db = 3;
				if (myd[i].x == a)
					myd[i].xb = 1, myd[i].zb = 2, myd[i].z = b;
				else
					myd[i].xb = 2, myd[i].zb = 1, myd[i].z = a;
			}
		}
		sort(myd + 1, myd + n + 1, cmp);
//		for (int i = 1; i <= n; i++) {
//			cout << myd[i].d << " " << myd[i].z << " " << myd[i].x << endl;
//			cout << myd[i].db << " " << myd[i].zb << " " << myd[i].xb << endl;
//		}
		for (int i = 1; i <= n; i++) {
			if (myd[i].db == 1) {
				if (cnt1 == n / 2) {
					if (myd[i].zb == 2) {
						if (cnt2 == n / 2) {
							cnt3++, ans += myd[i].x;
						} else
							cnt2++, ans += myd[i].z;
					} else {
						if (cnt3 == n / 2) {
							cnt2++, ans += myd[i].x;
						} else
							cnt3++, ans += myd[i].z;
					}
				} else
					cnt1++, ans += myd[i].d;
			} else if (myd[i].db == 2) {
				if (cnt2 == n / 2) {
					if (myd[i].zb == 1) {
						if (cnt1 == n / 2) {
							cnt3++, ans += myd[i].x;
						} else
							cnt1++, ans += myd[i].z;
					} else {
						if (cnt3 == n / 2) {
							cnt1++, ans += myd[i].x;
						} else
							cnt3++, ans += myd[i].z;
					}
				} else
					cnt2++, ans += myd[i].d;
			} else {
				if (cnt3 == n / 2) {
					if (myd[i].zb == 1) {
						if (cnt1 == n / 2) {
							cnt2++, ans += myd[i].x;
						} else
							cnt1++, ans += myd[i].z;
					} else {
						if (cnt2 == n / 2) {
							cnt1++, ans += myd[i].x;
						} else
							cnt2++, ans += myd[i].z;
					}
				} else
					cnt3++, ans += myd[i].d;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}