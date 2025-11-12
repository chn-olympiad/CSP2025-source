#include <bits/stdc++.h>
using namespace std;
const int M = 1e5+5;
const int M1 = 2e4+5;
int a[M], b[M], c[M], t[M1];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int tw;
	cin >> tw;
	for (int z = 1; z <= tw; z++) {
		int n, ask = 0;
		cin >> n;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		memset(t, 0, sizeof(t));
		int ar = 0, br = 0, cr = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
			if (a[i] >= b[i] && a[i] >= c[i])
				ar++;
			else if (b[i] >= a[i] && b[i] >= c[i])
				br++;
			else
				cr++;
			int  ls = max(a[i], max(b[i], c[i]));
			ask += ls;
//			//as += yu;yu = min(a[i], min(b[i], c[i])),
//			a[i] -= yu;
//			b[i] -= yu;
//			c[i] -= yu;
		}
		if (ar <= n / 2 && br <= n / 2 && cr <= n / 2) {
			cout << ask << endl;
		} else {
			if (ar >= n / 2) {
				for (int i = 1; i <= n; i++) {
					int ls = max(b[i], c[i]);
					t[a[i] - ls]++;
				}
				for (int i = 0; i < M1; i++) {
					if (t[i] < ar - n / 2) {
						ar -= t[i];
						ask -= t[i] * i;
					} else {
						ask -= i * (ar - n / 2);
						break;
					}
				}
				cout << ask << endl;
			} else if (br >= n / 2) {
				for (int i = 1; i <= n; i++) {
					int ls = max(a[i], c[i]);
					t[b[i] - ls]++;
				}
				for (int i = 0; i < M1; i++) {
					if (t[i] < br - n / 2) {
						br -= t[i];
						ask -= t[i] * i;
					} else {
						ask -= i * (br - n / 2);
						break;
					}
				}
				cout << ask << endl;
			} else if (cr >= n / 2) {
				for (int i = 1; i <= n; i++) {
					int ls = max(a[i], b[i]);
					t[c[i] - ls]++;
				}
				for (int i = 0; i < M1; i++) {
					if (t[i] < cr - n / 2) {
						cr -= t[i];
						ask -= t[i] * i;
					} else {
						ask -= i * (cr - n / 2);
						break;
					}
				}
				cout << ask << endl;
			}
		}
	}
}
