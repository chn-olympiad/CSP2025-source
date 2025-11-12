#include <bits/stdc++.h>
using namespace std;
int a1, a2, a3, a4, a51, a52, a53, a511, a522, a533, a6[300005], a7[300005], a71[300005], a8[100005], a9[100005];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> a1;
	for (int i = 0; i < a1; i++) {
		a3 = 0;
		cin >> a2;
		for (int q = 0; q < a2; q++) {
			cin >> a6[a3];
			a3++;
			cin >> a6[a3];
			a3++;
			cin >> a6[a3];
			a3++;
		}
		a3 = 0;
		for (int q = 0; q < a2; q++) {
			a8[q] = a8[q] + a6[a3] + a6[a3 + 1] + a6[a3 + 2];
			a9[q] = a8[q];
			a3 += 3;
		}
		sort(a9, a9 + a2);
		a3 = 0;
		for (int q = a2 - 1; q >= 0; q--) {
			for (int a = 0; a < a2; a++) {
				if (a9[q] == a6[a3] + a6[a3 + 1] + a6[a3 + 2]) {
					a7[a3] = a6[a3];
					a71[a3] = a6[a3];
					a7[a3 + 1] = a6[a3 + 1];
					a71[a3 + 1] = a6[a3 + 1];
					a7[a3 + 2] = a6[a3 + 2];
					a71[a3 + 2] = a6[a3 + 2];
					break;
				}
				a3 += 3;
			}
		}
		a3 = 0;
		for (int q = 0; q < a2; q++) {
			sort(a7 + a3, a7 + a3 + 3);
			for (int w = 0; w < 1; w++) {
				if (a7[a3 + 2] == a71[a3]) {
					if (a511 < a2 / 2)
						a51 += a7[a3 + 2];
					a511++;
					break;
				}
				if (a7[a3 + 2] == a71[a3 + 1]) {
					if (a522 < a2 / 2)
						a52 += a7[a3 + 2];
					a522++;
					break;
				}
				if (a7[a3 + 2] == a71[a3 + 2]) {
					if (a533 < a2 / 2)
						a53 += a7[a3 + 2];
					a533++;
					break;
				}
			}
			a3 += 3;
		}
		cout << a51 + a52 + a53 << endl;
	}
	return 0;
}
