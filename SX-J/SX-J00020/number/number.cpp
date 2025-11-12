#include <bits/stdc++.h>
using namespace std;
long long cnt, b[1000005], mmax = 0, d, e, f, g, h,  k, j, q, m, sum, c;
string s, a;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int l = s.size();
	for (int i = 0; i < l; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			cnt++;
			a[i] = s[i];
			if (a[i] < a[i + 1]) {
				swap(a[i], a[i + 1]);
			}
			sum = sum * 10 + a[i] - 48;
		}
	}
	cout << sum;

	/*	for (int i = 1; i <= sum; i++) {
			if (sum != 0 ) {
				c++;
				b[i] = sum % 10;
				sum = sum / 10;
			} else {
				break;
			}
		}
		b[c + 1] = sum;


		for (int i = 1; i <= (c + 1); i++) {
			d = b[i];
			e = b[i + 1];
			if (d < e) {
				b[i + 1] = d;
				b[i] = e;
			} else {
				b[i + 1] = e;
				b[i] = d;
			}

		}*/


	return 0;
}
