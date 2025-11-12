#include <bits/stdc++.h>
using namespace std;
long long a[100000 + 10];
long long b[100000 + 10];
long long c[100000 + 10];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	long long cnts = 0;
	cin >> s;
	long long len = s.size();
	for (long long i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			cnts++;
			a[i] = s[i] - 48;
			c[cnts] = a[i];
		}
	}
	long long maxx = -1, n = 0, m = 0, x = cnts;
	while (cnts) {
		for (long long i = 1; i <= x; i++) {
			if (c[i] > maxx) {
				maxx = c[i];
				m = i;
			}
		}
		c[m] = -1;
		b[n] = maxx;
		n++;
		cnts--;
		maxx = -1;
	}
	for (long long i = 0; i < n; i++) {
		cout << b[i];
	}
	return 0;
}
