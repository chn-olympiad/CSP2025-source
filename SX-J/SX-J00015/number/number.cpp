#include <bits/stdc++.h>
using namespace std;
string a;
char m[100000], b;
int c, n, i;

main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> m;
	for (n; n <= 100000; n++) {
		for (i; i <= 100000; i++) {
			if (m[i] > b) {
				b = m[i];
			}
		}
		a += b;
		b = 0;
	}
	return 0;
}