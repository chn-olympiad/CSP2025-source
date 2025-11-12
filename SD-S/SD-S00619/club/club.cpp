#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

struct Member{
	int x, y, z;
} a[N];

int n;

bool cmp(Member u, Member v) {
	int cu[3] = {abs(u.x - u.y), abs(u.y - u.z), abs(u.x - u.z)};
	int cv[3] = {abs(v.x - v.y), abs(v.y - v.z), abs(v.x - v.z)};
	sort(cu, cu + 3);
	sort(cv, cv + 3);
	for (int i = 2; i >= 1; i--)
		if (cu[i] != cv[i]) return cu[i] > cv[i];
	return cu[0] >= cv[0];
}

bool cmp1(Member u, Member v) {
	int cu[3] = {u.x, u.y, u.z};
	int cv[3] = {v.x, v.y, v.z};
	sort(cu, cu + 3);
	sort(cv, cv + 3);
	if (cu[2] - cu[1] != cv[2] - cv[1])
		return cu[2] - cu[1] > cv[2] - cv[1];
	return cu[1] - cu[0] >= cv[1] - cv[0];
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x>> a[i].y >> a[i].z;
	}
	
	sort(a + 1, a + n + 1, cmp1);
	
//	for (int i = 1; i <= n; i++) {
//		cout << a[i].x << ' ' << a[i].y << ' ' << a[i].z << '\n';
//	}

	int ans = 0;
	int cx = 0, cy = 0, cz = 0;
	for (int i = 1; i <= n; i++) {
		Member t = a[i];
		if (t.x >= t.y && t.x >= t.z) {
			if (cx < n / 2) {
				ans += t.x;
				cx++;
				continue;
			}
			if (t.y >= t.z) {
				if (cy < n / 2) {
					ans += t.y;
					cy++;
					continue;
				}
			} else {
				ans += t.z;
				cz++;
				continue;
			}
		}
		
		if (t.y >= t.x && t.y >= t.z) {
			if (cy < n / 2) {
				ans += t.y;
				cy++;
				continue;
			}
			if (t.x >= t.z) {
				if (cx < n / 2) {
					ans += t.x;
					cx++;
					continue;
				}
			} else {
				ans += t.z;
				cz++;
				continue;
			}
		}
		
		if (t.z >= t.y && t.z >= t.x) {
			if (cz < n / 2) {
				ans += t.z;
				cz++;
				continue;
			}
			if (t.x >= t.y) {
				if (cx < n / 2) {
					ans += t.x;
					cx++;
					continue;
				}
			} else {
				ans += t.y;
				cy++;
				continue;
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	
	return 0;
}
