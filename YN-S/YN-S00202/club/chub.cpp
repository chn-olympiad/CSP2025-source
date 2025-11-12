#include <bits/stdc++.h>
using namespace std;
int a[1000002][3], g[3];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int b, c;
	cin >> b;
	for (int i = 0; i < b; i++) {
		int f = 0;
		for (int j = 0; j < 3; j++)
			g[j] = 0;
		cin >> c;
		for (int j = 0; j < c; j++) {
			for (int o = 0; o < 3; o++)
				cin >> a[j][o];
			int d = max(a[j][0], max(a[j][1], a[j][2])), x = min(min(g[0], g[1]), g[2]), e = 0, k = 0;
			for (int o = 0; o < 3; o++)
				if (d == a[j][o]) {
					e = o;
					break;
				}
			if (g[e] < c / 2) {
				++g[e];
				f += d;
			} else {
				for (int o = 0; o < 3; o++)
					if (d > a[j][o] and x < a[j][o]) {
						e = o;
						break;
					}
				if (g[e] < c / 2) {
					++g[e];
					f += a[j][e];
				} else {
					for (int o = 0; o < 3; o++)
						if (a[j][o] == x) {
							if (g[o] < c / 2) {
								++g[o];
								f += x;
							}
							break;
						}
				}
			}
		}
		cout << f << endl;
	}
	return 0;
}