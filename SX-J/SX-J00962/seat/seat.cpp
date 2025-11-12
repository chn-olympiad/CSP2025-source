#include <bits/stdc++.h>
using namespace std;
long long t = 1, flag = 0, flag1, num, ans, ans1 = 1, ans2 = 0, s, n, m, a1[100010], a[100010], cct = 0;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	s = n * m;
	for (int i = 1; i <= s; i++) {
		cin >> a1[i];
		ans = a1[1];
	}
	sort(a1 + 1, a1 + s + 1);
	for (int i = s; i >= 1; i--) {
		a[t] = a1[i];
		t++;
	}
	for (int i = 1; i <=  s; i++) {
		if (a[i] == ans) {
			num = i;
		}
	}
	for (int i = 1; i <= s; i++) {
		if (num + flag1 != i) {
			if (ans2 < n && flag == 0) {
				ans2++;
				if (ans2 == n) {
					flag1++;
				}
			} else if (ans2 == n && flag == 0) {
				flag = 1;
				ans1++;
				ans2++;
				cct = 1;
			} else if (ans2 > 1 && flag == 1) {
				ans2--;
				cct = 0;
				if (ans2 == 1) {
					cct = 0;
					flag1++;
				}
			} else if (ans2 == 1 && flag == 1) {
				cct = 0;
				flag = 0;
				ans1++;
				ans2++;
			}

		}
		if (num + flag1 == i) {
			if (num == 2) {
				cout << "1" << " " << "2";
				return 0;
			}
			if (num == 1) {
				cout << "1" << " " << "1";
				return 0;
			}
			if (cct = 1) {
				cout << ans1  << " " << ans2 - 1;
				return 0;
			}
			cout << ans1  << " " << ans2;
			return 0;
		}
	}
	return 0;
}
