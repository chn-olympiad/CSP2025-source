#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int num = 0;
		int gs1 = 0, gs2 = 0, gs3 = 0;
		for (int j = 1; j <= n; j++) {
			int a, b, c;
			cin >> a >> b >> c;
			if (gs1 == n / 2) {
				if (a >= b && a <= c) {
					num += c;
					gs3 += 1;
					continue;
				}
				if (b >= a && b >= c) {
					num += b;
					gs2 += 1;
					continue;
				}
				if (b >= a && b <= c) {
					num += c;
					gs3 += 1;
					continue;
				}
			}
			if (gs2 == n / 2) {
				if (a >= b && a >= c) {
					num += a;
					gs1 += 1;
					continue;
				}
				if (a >= b && a <= c) {
					num += c;
					gs3 += 1;
					continue;
				}
				if (b >= a && b <= c) {
					num += c;
					gs3 += 1;
					continue;
				}
			}
			if (gs3 == n / 2) {
				if (a >= b && a >= c) {
					num += a;
					gs1 += 1;
					continue;
				}
				if (b >= a && b >= c) {
					num += b;
					gs2 += 1;
					continue;
				}
			} else {
				if (a >= b && a >= c) {
					num += a;
					gs1 += 1;
					continue;
				}
				if (a >= b && a <= c) {
					num += c;
					gs3 += 1;
					continue;
				}
				if (b >= a && b >= c) {
					num += b;
					gs2 += 1;
					continue;
				}
				if (b >= a && b <= c) {
					num += c;
					gs3 += 1;
					continue;
				}
			}
		}
		cout << num;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}