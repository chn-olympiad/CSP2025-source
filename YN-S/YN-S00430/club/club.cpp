#include <bits/stdc++.h>
using namespace std;
int t;

struct g {
	int x, y, z, id;
} s[100005], m[100005];

int cmp(g a, g b) {
	if (a.x == b.x) {
		if (a.y == b.y) {
			return a.z > b.z;
		} else {
			return a.y > b.y;
		}
	} else {
		return a.x < b.x;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "W", stdout);
	cin >> t;
	while (t--) {
		int num1 = 0, num2 = 0, num3 = 0;
		int cnt = 0, ans = 0;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s[i].x >> s[i].y >> s[i].z;
			s[i].id = 0;
			m[i].x = s[i].x;
			m[i].y = s[i].y;
			m[i].z = s[i].z;
			m[i].id = max({s[i].x, s[i].y, s[i].z, s[i].id});
		}
		sort(s, s + n, cmp);
		sort(m, m + n, cmp);
		for (int i = 0; i < n; i++) {
			if (m[i].id == s[i].x) {
				if (num1 < n / 2) {
					num1++;
					ans += s[i].x;
				} else if (s[i].y > s[i].z && num2 < n / 2) {
					num2++;
					ans += s[i].y;
				} else if (num3 < n / 2) {
					num3++;
					ans += s[i].z;
				}
			} else if (m[i].id == s[i].y) {
				if (num2 < n / 2) {
					num2++;
					ans += s[i].y;
				} else if (s[i].x > s[i].z && num1 < n / 2) {
					num1++;
					ans += s[i].x;
				} else if (num3 < n / 2) {
					num3++;
					ans += s[i].z;
				}
			} else {
				if (num3 < n / 2) {
					num3++;
					ans += s[i].z;
				} else if (s[i].x > s[i].y && num1 < n / 2) {
					num1++;
					ans += s[i].x;
				} else if (num2 < n / 2) {
					num2++;
					ans += s[i].y;
				}
			}
		}
		cout  << ans << endl;
	}
	return 0;
}