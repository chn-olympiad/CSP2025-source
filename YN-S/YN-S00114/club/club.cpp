#include <bits/stdc++.h>
using namespace std;
int a[5][20005];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	int ans1 = 0, ans2 = 0, ans3 = 0, cnt = 0;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[0][i] >> a[1][i] >> a[2][i];
			if (a[0][i] > a[1][i] && a[0][i] > a[2][i]) {
				if (ans1 < n / 2 ) {
					++ans1;
					cnt = cnt + a[0][i];
					continue;
				} else if (a[0][i] < a[1][i] && a[0][i] < a[2][i]) {
					if (a[1][i] > a[2][i]) {
						if (ans2 < n / 2) {
							++ans1;
							cnt = cnt + a[0][i];
							continue;
						}
					}
				} else {
					if (ans3 < n / 2) {
						++ans1;
						cnt = cnt + a[0][i];
						continue;
					}
				}
			}

			cout << cnt << endl;
			cnt = 0;
		}
		return 0;
	}