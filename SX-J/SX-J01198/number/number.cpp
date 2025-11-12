#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", "stdin");
	freopen("number.out", "w", "stdout");
	string  s, d;
	string h;
	long long y, k, l = 0;
	cin >> s;
	y = s.size();
	for (int i = 0; i <= y + 1; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			h += s[i];
			k = h.size();
		}
	}
	if (k <= 1) {
		d += h[0];
		l++;
	} else if (h.size() == h.size())
		h[k] += '0';
	if (l != 1) {
		for (int i = 0; i <= k; i++) {
			if (h[i + 1] > h[i] ) {
				d += h[i + 1];
				d += h[i];
			}

			if (h[i + 1] == h[i] ) {
				d += h[i + 1];
				d += h[i];
			}
		}
	}
	cout << d;
	return 0;
}
