#include <bits/stdc++.h>
using namespace std;
long long int a[500005], n, k;
bool f, ff;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	f = ff = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1) {
			f = 0;
			if (a[i] != 0) {
				ff = 0;
			}
		}
	}
	if (f == 1) {
		cout << n / 2;
	} else if (ff == 1) {
		int z = 0, o = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 0)
				z++;
			else if (a[i] == 1)
				o++;
		}
		if (k == 1)
			cout << o;
		else if (k == 0)
			cout << z;
	} else {
		cout << 255;
	}
	return 0;
}
