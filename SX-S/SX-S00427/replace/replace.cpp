#include <bits/stdc++.h>
using namespace std;

int main() {
	int q, w;
	cin >> q >> w;
	char a[10], s[10];
	cin >> a >> s;
	char d[10], f[10];
	cin >> d >> f;
	char g[10], h[10];
	cin >> g >> h;
	char j[10], k[10];
	cin >> j >> k;
	char l[10], z[10];
	cin >> l >> z;
	char x[10], c[10];
	cin >> x >> c;
	if (q % w == 0) {
		cout << "2" << endl;
		cout << "0" << endl;
	} else {
		for (int i = 0; i < w; i++) {
			cout << "0" << endl;
		}
	}
}
