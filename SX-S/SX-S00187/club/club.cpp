#include <bits/stdc++.h>
using namespace std;
long long a, s, w, d[7][205], l1[5], l2[5], l3, l4, f, o, l5;

int main() {
	freopen("club.in", "d", stdin);
	freopen("club.out", "w", stdout);
	cin >> a;
	for (int i = 1; i <= a; i++) {
		cin >> s;
		for (int q = 1; q <= s; q++) {
			cin >> d[i][q];
			if (d[i][q] == 0)
				o++;
			else
				l4 = q;
		}
		for (int j = s; j >= 1; j--) {
			if (d[i][j] > d[i][j - 1])
				f = j;
			else
				f = j - 1;
		}
		for (int p = 1; p <= s; p++) {
			if (o == 2) {
				for (int j = s; j >= 1; j--) {
					if (l2[j] > l2[j - 1])
						l5 = j;
					else
						l5 = j - 1;
				}
				if (l2[l4] <= s / 2) {
					l1[f] += d[i][f];
					l2[f] += 1;
				} else {
					l1[l5] += d[i][l4];
					l2[l5] += 1;
				}
			} else {
				l1[f] += d[i][f];
				l2[f] += 1;
			}
		}
		for (int j = s; j >= 1; j--) {
			if (d[i][j] > d[i][j - 1])
				f = j;
			else
				f = j - 1;
		}
		w = l1[f];
		cout << w << endl;
	}
	return 0;
}
