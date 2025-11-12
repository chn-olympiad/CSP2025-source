#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int a[100005];
int b[5];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n, x, y, z;
	cin >> t ;
	for (int i = 1; i <= t; i++) {
		cin >> n;
		int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt = 0;
		for (int j = 1; j <= n; j++) {
			cin >> x >> y >> z;
			if (x > y && x > z && n / 2 >= cnt1) {
				a[j] = x;
				cnt1++;
			} else if (y > z && n / 2 >= cnt2) {
				a[j] = y;
				cnt2++;
			} else {
				a[j] = z;
				cnt3++;
			}
			cnt += a[j];
		}
		a[100005] = {};
		cout << cnt << endl;
	}
	return 0;
}

