#include <bits/stdc++.h>
using namespace std;
int t, n, s1[10005], s2[10005], s3[10005];
int ans1, ans2, ans3, a1[10005], a2[10005], a3[10005], b1, b2, b3;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> s1[i] >> s2[i] >> s3[i];
			if (s1[i] > s2[i] && s1[i] > s3[i]) {
				ans1++;
				a1[ans1] = s1[i];
			}
			if (s2[i] > s1[i] && s2[i] > s3[i]) {
				ans2++;
				a2[ans2] = s2[i];
			}
			if (s3[i] > s2[i] && s3[i] > s1[i]) {
				ans3++;
				a3[ans3] = s3[i];
			}
		}
		if (ans1 <= n / 2) {
			for (int i = 1; i <= ans1; i++) {
				b1 += a1[i];
			}
		} else {
			for (int i = 1; i <= ans1; i++) {
				if (a1[i] < a1[i + 1]) {
					swap(a1[i], a1[i + 1]);
				}
			}
			for (int i = 1; i <= n / 2; i++) {
				b1 += a1[i];
			}
		}
		if (ans2 <= n / 2) {
			for (int i = 1; i <= ans2; i++) {
				b2 += a2[i];
			}
		} else {
			for (int i = 1; i <= ans2; i++) {
				if (a2[i] < a2[i + 1]) {
					swap(a2[i], a2[i + 1]);
				}
			}
			for (int i = 1; i <= n / 2; i++) {
				b2 += a2[i];
			}
		}
		if (ans3 <= n / 2) {
			for (int i = 1; i <= ans3; i++) {
				b3 += a3[i];
			}
		} else {
			for (int i = 1; i <= ans3; i++) {
				if (a3[i] < a3[i + 1]) {
					swap(a3[i], a3[i + 1]);
				}
			}
			for (int i = 1; i <= n / 2; i++) {
				b3 += a3[i];
			}
		}
		cout << b1 + b2 + b3 << endl;
		b1 = 0;
		b2 = 0;
		b3 = 0;
	}
	return 0;
}