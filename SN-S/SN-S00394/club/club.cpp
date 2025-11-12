#include <bits/stdc++.h>
using namespace std;
int main() {

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int a1[100005], a2[100005], a3[100005], maxx[100005], minn[100005], n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a1[i] >> a2[i] >> a3[i];
			if (a1[i] > a2[i]) {
				if (a1[i] > a3[i]) {
					maxx[i] = 1;
					if (a2[i] >= a3[i]) minn[i] = 2;
					else minn[i] = 3;
				} else  {
					maxx[i] = 3;
					if (a1[i] >= a2[i]) minn[i] = 1;
					else minn[i] = 2;
				}
			} else if (a2[i] > a3[i]) {
				maxx[i] = 2;
				if (a1[i] >= a3[i]) minn[i] = 1;
				else minn[i] = 3;
			} else {
				maxx[i] = 3;
				if (a1[i] >= a2[i]) minn[i] = 1;
				else minn[i] = 2;
			}
		}
		for (int i = 1; i < n; i++) {
			for (int j = i; j <= n; j++) {
				if (a1[i] < a1[j]) {
					swap(a1[i], a1[j]);
					swap(a2[i], a2[j]);
					swap(a3[i], a3[i]);
					swap(maxx[i], maxx[j]);
				} else if (a1[i] == a1[j]) {
					if (a2[i] < a2[j]) {
						swap(a1[i], a1[j]);
						swap(a2[i], a2[j]);
						swap(a3[i], a3[i]);
						swap(maxx[i], maxx[j]);
					} else if (a2[i] == a2[j]) {
						if (a3[i] < a3[j]) {
							swap(a1[i], a1[j]);
							swap(a2[i], a2[j]);
							swap(a3[i], a3[i]);
							swap(maxx[i], maxx[j]);
						}
					}
				}
			}
		}
		int s1 = 0, s2 = 0, s3 = 0, sx = n / 2;
		long long ans = 0, bas = 0;
		for (int i = 1; i <= n; i++) {
			bas = ans;
			if (maxx[i] == 1 && s1 <= sx) {
				ans += a1[i];
				s1++;
			}
			if (maxx[i] == 2 && s2 <= sx + 1) {
				ans += a2[i];
				s2++;
			}
			if (maxx[i] == 3 && s3 <= sx) {
				ans += a3[i];
				s3++;
			}
			if (bas == ans) {
				if (maxx[i] == 1 && s1 > sx) {

					if (minn[i] == 2 && s2 <= sx) {
						ans += a2[i];
						s2++;
					} else {
						ans += a3[i];
						s3++;
					}
					if (minn[i] == 3 && s3 <= sx) {
						ans += a3[i];
						s3++;
					}
				} else if (maxx[i] == 2 && s2 > sx) {
					if (minn[i] == 1 && s1 <= sx) {
						ans += a1[i];
						s1++;
					} else {
						ans += a2[i];
						s2++;
					}
					if (minn[i] == 3 && s3 <= sx) {
						ans += a3[i];
						s3++;
					}
				} else if (maxx[i] == 3 && s3 > sx) {
					if (minn[i] == 1 && s1 <= sx) {
						ans += a1[i];
						s1++;
					} else {
						ans += a2[i];
						s2++;
					}
					if (minn[i] == 2 && s2 <= sx) {
						ans += a2[i];
						s2++;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
