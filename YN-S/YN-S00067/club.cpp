#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, ert = 0;
	cin >> t;
	while (t) {
		int v;
		t--;
		cin >> v;
		int q, w, e, a = 0, s = 0, d = 0, asd = 0, b[100050];
		int n[100050], m[100050];
		for (int i = 1; i <= v; ++i) {
			cin >> b[i] >> n[i]  >> m[i] ;
			if (b[i] > n[i]  && b[i] > m[i]) {
				q = b[i];
				a++;
			} else if (n[i] > b[i] && n[i] > m[i] ) {
				w = n[i];
				s++;
			} else if ( m[i] > b[i] &&  m[i] > n[i]) {
				e = m[i];
				d++;
			} else {
				asd++;
			}
			int j = 0, k = 0, l = 0;
			if (a >= v / 2) {
				while (a <= v / 2) {
					j++;
					a--;
				}
				ert += a * q;
			} else if (s >= v / 2) {
				while (s <= v / 2) {
					k++;
					s--;
				}
				ert += s * q;
			} else if (d >= v / 2) {
				while (d <= v / 2) {
					l++;
					d--;
				}
				ert += d * w;
			} else {
				if (a + asd <= v / 2) {
					ert += (a + asd) * q;
				} else if (s + asd <= v / 2) {
					ert += (s + asd) * w;
				} else if (d + asd <= v / 2) {
					ert += (d + asd) * e;
				}
			}
			cout << ert;
		}
	}
	return 0;
}