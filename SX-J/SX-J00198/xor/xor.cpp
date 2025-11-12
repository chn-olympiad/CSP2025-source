#include <bits/stdc++.h>
using namespace std;
long a, b, c[500010], jsq = 0;
bool d[500010];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		cin >> c[i];
		d[i] = false;
	}
	for (int i = 0; i < a; i++) {
		if (c[i] == b && d[i] != true) {
			jsq++;
			d[i] = true;
		} else {
			for (int j = 0; j < a; j++) {
				if (b - c[j] == c[i] && d[j] != true && d[i] != true) {
					jsq++;
					d[j] = true;
					d[i] = true;
				}
			}
		}
	}
	cout << jsq;
	return 0;
}
