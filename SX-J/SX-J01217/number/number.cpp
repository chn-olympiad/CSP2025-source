#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen(char.in, "r", stin);
	freopen(char.out, "w", stout);
	long long y, k;
	cin >> s;
	y = s.size();
	for (int i = 0; i <= y + 1; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			h += s[i];
			k = h.size();
		}
	}
	for (int i = 0; i <= k; i++) {
		if (k <= 1)
			d += h[i + 1];
		if (h[i + 1] > h[i]) {
			d += h[i + 1];
			d += h[i];
		}
	}
	cout << h << endl;
	cout << d << 0;


























	return 0;
}
