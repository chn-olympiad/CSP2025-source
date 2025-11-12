#include <bits/stdc++.h>

using namespace std;

int T;

bool is_join (int n, int x) {
	if (x <= n / 2) return true;
	return false;
}

int main () {
	freopen ("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		int n;
		long long ans = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
		long long sum1 = 0, sum2 = 0, sum3 = 0;
		cin >> n;
		int a[10005][5] = {};
		for (int i = 1; i <= n; i++) {
			long long first, second, three;
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
				first = a[i][1];
				second = a[i][2];
				three = a[i][3];
			}
			long long maxn = max (first, max (second, three)), two = 0;
			if (maxn == first) {
				two = max (second, three);
			} else if (maxn == second) {
				two = max (first, three);
			}
			else {
				two = max (first, second);
			}
			if (maxn == first && is_join(n, cnt1) == true) {
				cnt1++;
				sum1 += maxn;
			}
			else if (maxn == second && is_join(n, cnt2) == true) {
				cnt2++;
				sum2 += maxn;
			}
			else if (maxn == three && is_join(n, cnt3) == true) {
				cnt3++;
				sum3 += maxn;
			}
		}
        unsigned long long sbc = sum1 + sum2 + sum3;
		cout << sbc << endl;
	}
	return 0;
}
